%{
	#include <stdlib.h>
	#include <string.h>

	#include "symbol_table.h"
	#include "syntax_parser_data_types.h"
	#include "y.tab.h"

	extern FILE *yyin;
%}

DIGIT	                        [0-9]
INTEGER	                        [+-]?{DIGIT}+

IDENTIFIER                      [_a-zA-Z][_a-zA-Z0-9]*


SPACE	                        [ \t]+
NEWLINE	                        [\n]+
BLANKS	                        (({SPACE})|({NEWLINE}))+

%%

"("		                        { return T_po; }
")"		                        { return T_pf; }
"{"		                        { return T_ao; }
"}"		                        { return T_af; }
"["		                        { return T_co; }
"]"		                        { return T_cf; }

";"		                        { return T_semi_colon; }
","		                        { return T_comma; }
":"		                        { return T_colon; }
"?"		                        { return T_Q_mark; }
"!"		                        { return T_E_mark; }

"<="		                    { return T_less_than_or_equal_to; }
"<"		                        { return T_less_than; }
">="		                    { return T_greater_than_or_equal_to; }
">"		                        { return T_greater_than; }
"!="		                    { return T_different; }
"=="		                    { return T_equal_comparison; }

"&"		                        { return T_ampersand; }

"*"                             { return T_mul; }
"/"                             { return T_div; }
"%"                             { return T_mod; }
"+"                             { return T_add; }
"-"                             { return T_sub; }

"="                             { return T_equal; }

int		                        { return T_int; }
char		                    { return T_char; }
double		                    { return T_double; }
void		                    { return T_void; }

long		                    { return T_long; }
signed		                    { return T_signed; }
unsigned	                    { return T_unsigned; }
short		                    { return T_short; }
const		                    { return T_const; }

if		                        { return T_if; }
else		                    { return T_else; }
while		                    { return T_while; }
for		                        { return T_for; }
do		                        { return T_do; }
switch		                    { return T_switch; }
break 		                    { return T_break; }
continue	                    { return T_continue; }
default		                    { return T_default; }
                       

return		                    { return T_return; }
 
main	                        {
                                    yylval.string = NULL;
                                    return T_main;
                                }
printf		                    { return T_printf; }
       
{INTEGER}	                    {
                                    yylval.integer_nb = atoi(yytext);
                                    return T_integer_number;
                                }

{IDENTIFIER}	                {
                                    yylval.string = strdup(yytext);
                                    return T_identifier;
                                }


{NEWLINE}	{ }    
{SPACE}		{ }

%%

int yywrap(void) {}

