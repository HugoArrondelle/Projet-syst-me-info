%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

    #include "val.h"
	#include "symbol_table.h"
	#include "asm.h"

    void expression_To_condition();
	/* Input stream */
	FILE *yyin;

	int yydebug = 1; 

	extern int yylex();

	int yyerror(char *s) {
		printf("=== \x1B[01;31m[!] YYERROR \x1B[0m  ===\n");
		exit(1);
		return 1;
	}

    
	
%}

%union	{ 
		int integer_nb;
		char *string;
		Symbol *symbol;
		enum symbol_type symbol_type;
		struct _VALEUR VALEUR;
	}

%token
			T_main
			T_printf

	<string>	T_identifier

			T_void
			T_int
			T_double
			T_char

			T_long
			T_signed
			T_unsigned
			T_short
			T_const

	<integer_nb> 	T_integer_number

	<integer_nb>	T_if
			T_else
			T_while
			T_switch
			T_for
			T_do

			T_break
			T_continue
			T_default

			T_return



			T_equal

			T_po
			T_pf
			T_ao
			T_af
			T_co
			T_cf

			T_E_mark
			T_Q_mark

			T_semi_colon
			T_comma
			T_colon

			T_mul
			T_div
			T_add
			T_sub
			T_mod

			T_less_than
			T_less_than_or_equal_to
			T_greater_than
			T_greater_than_or_equal_to
			T_equal_comparison
			T_different

			T_ampersand


%type <symbol>     EXPRESSION
%type <VALEUR>    VALEUR

%type <symbol_type>     DECLARATION_TYPE
%type <symbol>         DECLARATION_AND_ASSIGNMENT

%left T_equal
%left T_less_than T_less_than_or_equal_to T_greater_than T_greater_than_or_equal_to T_different T_equal_comparison
%left T_add T_sub
%left T_mul T_div T_mod
%left T_po T_pf



%%

S : T_void T_main T_po T_pf BODY
    ;

BODY : T_ao
		{ increase_depth(); }
	STATEMENT T_af
		{ decrease_depth(); }
	;

STATEMENT :
		| T_semi_colon
		| BODY STATEMENT

		| IF_STATEMENT STATEMENT
		| WHILE_STATEMENT STATEMENT

            	| DECLARATION T_semi_colon STATEMENT

		| ASSIGNMENT T_semi_colon STATEMENT

		| EXPRESSION T_semi_colon
        
			{
				tmp_table_pop();
			}
		STATEMENT

		| T_return EXPRESSION T_semi_colon STATEMENT
           	;
           

           
EXPRESSION :	T_po EXPRESSION T_pf
			{
				$$ = $2;
			}
		| EXPRESSION T_add EXPRESSION
			{ 
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_ADD(op1->address, op1->address, op2->address);

				$$ = op1;
			}

		| EXPRESSION T_sub EXPRESSION
			{ 
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();
                
				asm_function_SUB(op1->address, op1->address, op2->address);

				$$ = op1;
			}
                
		| EXPRESSION T_mul EXPRESSION
			{ 
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_MUL(op1->address, op1->address, op2->address);

				$$ = op1;
			}

		| EXPRESSION T_div EXPRESSION
			{
                Symbol *op2 = tmp_table_pop();
                Symbol *op1 = tmp_table_peek();

                asm_function_DIV(op1->address, op1->address, op2->address);

                $$ = op1;
			}



		| EXPRESSION T_different EXPRESSION
			{
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_EQU(op1->address, op1->address, op2->address);
        
				asm_push_value(1);
				Symbol *one = tmp_table_pop();
				asm_function_SUB(op1->address, one->address, op1->address);

				$$ = op1;
			}

		| EXPRESSION T_equal_comparison EXPRESSION
			{
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_EQU(op1->address, op1->address, op2->address);

				$$ = op1;
			}
                
                
		| FUNCTION_CALL
			{
			}  


		| T_integer_number
			{ 
				asm_push_value($1);

				$$ = tmp_table_peek();
			}

		| T_identifier
			{
				Symbol *s = get_symbol($1);

				if (s == NULL) {
                    printf("\x1B[01;31m[!] ERROR: \x1B[0m symbole non déclaré '%s'. \n ",$1);
                    exit(1);
				}

				free(yylval.string);
				
				asm_push_from_address(s->address);

				$$ = s;
			}

		;
           
FUNCTION_ARGS :	
		| EXPRESSION
		| EXPRESSION T_comma FUNCTION_NEMPTY
		;
 
FUNCTION_NEMPTY :	EXPRESSION
				| EXPRESSION T_comma FUNCTION_NEMPTY
				;
           
PRINTF :	T_printf T_po
			{
				asm_comment(asm_get_next_line(), "printf");
			}
		FUNCTION_NEMPTY T_pf
			{
				Symbol *addr = tmp_table_pop();
				asm_function_PRI(addr->address);
			}
		;
             
             
FUNCTION_CALL :	PRINTF
		| T_identifier T_po FUNCTION_ARGS T_pf
			{
			}
		;
           
TYPE :	T_int
	| T_double
	| T_char
	;


DECLARATION_TYPE :	TYPE					{ $$ = BASIC_TYPE; }
                
    | T_const TYPE                { $$ = BASIC_CONSTANT_TYPE; }
			;

DECLARATION_AND_ASSIGNMENT :	DECLARATION_TYPE T_identifier T_equal
					{
						int comment_size = strlen($2) + 55;
						char *comment = malloc(comment_size);
						snprintf(comment, comment_size, "Déclaration et initialisation de la variable '%s'", $2);
						asm_comment(asm_get_next_line(),comment);
					}
				EXPRESSION
					{
						if (!is_available($2)) {
                            printf("\x1B[01;31m[!] ERROR: \x1B[0m  Symbole deja déclaré '%s'. \n ",$2);
                            exit(1);
						}

						enum symbol_type st = $1;

						Symbol *s = new_symbol($2, st);
                        
                        if (s) { s->isInitialized = INITIALIZED; }
						

						Symbol *expr = tmp_table_pop();

						asm_function_COP(s->address, expr->address);

						$$ = s;
					}
				;
       
DECLARATION :	DECLARATION_AND_ASSIGNMENT
		| DECLARATION_TYPE T_identifier
			{
				if (!is_available($2)) {
					printf("\x1B[01;31m[!] ERROR: \x1B[0m  Déclaration symbole deja déclaré '%s'", $2);
                    exit(1);
				}

				enum symbol_type st = $1;

				Symbol *s = new_symbol($2, $1);
                
                if (is_constant(s)) {
                    
                    fprintf(stderr, "\x1B[01;32m[*] WARNING: Symbol '%s' déclaré en 'const' non initialisable \n\x1B[0m",$2);
                }
                

				
			}
		;

VALEUR :	T_identifier
			{
				struct _VALEUR l = {$1, 0};
				$$ = l;
			}
		| T_mul VALEUR
			{
				// Pointer
			}

ASSIGNMENT :	VALEUR T_equal
			{
				int comment_size = strlen($1.identifier) + $1.pointer_depth + 50;
				char *comment = malloc(comment_size);
				int i;
				int comment_current_length = 0;

				snprintf(comment, comment_size, "assignation variable '");
				comment_current_length = strlen(comment);

				snprintf(&(comment[comment_current_length]), comment_size - (comment_current_length), "%s'", $1.identifier);

				asm_comment(asm_get_next_line(),comment);
			}
		EXPRESSION
			{
				struct _VALEUR VALEUR = $1;
				int depth;
				Symbol *s = get_symbol($1.identifier);

				if (s == NULL) {
                    printf("\x1B[01;31m[!] ERROR: \x1B[0m  Symbole non déclaré'%s'", VALEUR.identifier);
                    exit(1);
				}
                
                if (VALEUR.pointer_depth == 0) {

                    if (!is_constant(s)) {
                        Symbol *expr = tmp_table_pop();
                        asm_function_COP(s->address, expr->address);

                    } else {
                        printf("\x1B[01;31m[!] ERROR: \x1B[0m  Symbol '%s' est un 'const' donc non modifiable", VALEUR.identifier);
                        
                    }
                }
				
			}
		;


IF_STATEMENT : 	T_if
			{
				asm_comment(asm_get_next_line(),"if condition avec else ");
			}
        T_po EXPRESSION T_pf
			{
                expression_To_condition();
				asm_comment(asm_get_next_line(),"if block {");

				Symbol *condition = tmp_table_pop();

				$1 = asm_prepare_JMF(condition->address);
			}
		BODY T_else
			{
				asm_update_jmp($1, asm_get_next_line() + 1);

    
				$1 = asm_prepare_JMP();
				asm_comment(asm_get_next_line(),"else condition");
			}
		BODY
			{
				asm_update_jmp($1, asm_get_next_line());
				asm_comment(asm_get_next_line(),"} fin if-else ");
			}

		| T_if
			{
				asm_comment(asm_get_next_line(),"if condition sans else ");
			}
		T_po EXPRESSION T_pf
			{
				asm_comment(asm_get_next_line(),"if block {");

				
                expression_To_condition();

				asm_update_jmp($1, asm_get_next_line());
			}
		BODY
			{
				asm_update_jmp($1, asm_get_next_line());
				asm_comment(asm_get_next_line(),"} fin if ");
			}
		;

		

WHILE_STATEMENT :	T_while T_po
				{
					asm_comment(asm_get_next_line(),"while condition");

					$2 = asm_get_next_line();
				}
			EXPRESSION T_pf
				{

					
                    expression_To_condition();

					Symbol *condition = tmp_table_pop();

					$1 = asm_prepare_JMF(condition->address);
					asm_comment(asm_get_next_line(),"while  {");
				}
			BODY
				{
					asm_update_jmp($1, asm_get_next_line() + 1);
					asm_function_JMP($2);
					asm_comment(asm_get_next_line(),"} fin while ");
				}
			;


%%
    
    
    
    
    void expression_To_condition() {

        asm_comment(asm_get_next_line(),"expression isTrue ? ");

        asm_push_value(0);
        Symbol *zero = tmp_table_pop();
        Symbol *expr = tmp_table_peek();
        
        asm_function_EQU(expr->address, expr->address, zero->address);

        asm_push_value(1);
        Symbol *one = tmp_table_pop();
        asm_function_SUB(expr->address, one->address, expr->address);

    }

int main(int argc, char *argv[])
{
    
	FILE *out_file;
    
    
    out_file = stdout;
    yyin = stdin;
    out = out_file;
	init();
	yylval.string = NULL;
	yyparse();
	display_asm();
}

