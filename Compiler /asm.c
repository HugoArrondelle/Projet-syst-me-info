#include <stdio.h>

#include "asm.h"



#define JMP_NOT_FINISHED	0
#define JMP_FINISHED		0


#define ADDRESS_SYMBOL_STR_BOOLEAN	0
#define ADDRESS_SYMBOL_STR		"@"
#define LINE_NB				0
#define COMMENTS			0

#ifdef DEBUG
# undef ADDRESS_SYMBOL_STR_BOOLEAN
# define ADDRESS_SYMBOL_STR_BOOLEAN	1
# undef LINE_NB
# define LINE_NB			1
# undef COMMENTS
# define COMMENTS			1
#endif

#define instruction_TABLE_ASM_SIZE	1024
#define ASM_COMMENT_TABLE_SIZE    instruction_TABLE_ASM_SIZE


instruction_ASM instruction_TABLE_ASM[instruction_TABLE_ASM_SIZE];
int index_instruction_TABLE_ASM = 0;
ASM_comment asm_comment_table[ASM_COMMENT_TABLE_SIZE];
int asm_comment_table_index = 0;



static inline instruction_ASM *get_next_instruction()
{
    if (index_instruction_TABLE_ASM < instruction_TABLE_ASM_SIZE)
        return &(instruction_TABLE_ASM[index_instruction_TABLE_ASM++]);
    return NULL;
}

void display_asm(void)
{
	int i;
	int comments_index = 0;
	for (i = 0; i < index_instruction_TABLE_ASM; i++) {

		instruction_ASM *ins = &instruction_TABLE_ASM[i];

		char line_nb[10] = "";
		char *address_symbol = "";
#if LINE_NB
		snprintf(line_nb, 10, "%3d: ", i);
#endif
#if ADDRESS_SYMBOL_STR_BOOLEAN
		address_symbol = ADDRESS_SYMBOL_STR;
#endif

#if COMMENTS
		while (i == asm_comment_table[comments_index].line_nb) {
			fprintf(out, "\x1b[0;33m; %s\n\x1b[0m", asm_comment_table[comments_index].comment);
			if (comments_index < asm_comment_table_index)
				comments_index++;
			else
				break;
		}
#endif
        
		switch (ins->opcode) {
			
			case ADD:
				fprintf(out, "%s\x1B[01;36mADD\x1B[0m %s%d %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2, address_symbol, ins->arg3);
				break;
			case SOU:
				fprintf(out, "%s\x1B[01;36mSOU\x1B[0m %s%d %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2, address_symbol, ins->arg3);
				break;
			case MUL:
				fprintf(out, "%s\x1B[01;36mMUL\x1B[0m %s%d %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2, address_symbol, ins->arg3);
				break;


			case AFC:
				fprintf(out, "%s\x1B[01;36mAFC\x1B[0m %s%d %d\n", line_nb, address_symbol, ins->arg1, ins->arg2);
				break;
			case COP:
				fprintf(out, "%s\x1B[01;36mCOP\x1B[0m %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2);
				break;


			case JMF:
				fprintf(out, "%s\x1B[01;36mJMF\x1B[0m %s%d %d\n", line_nb, address_symbol, ins->arg1, ins->arg2);
				break;
			case JMP:
				fprintf(out, "%s\x1B[01;36mJMP\x1B[0m %d\n", line_nb, ins->arg2);
				break;


			case INF:
				fprintf(out, "%s\x1B[01;36mINF\x1B[0m %s%d %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2, address_symbol, ins->arg3);
				break;
			case SUP:
				fprintf(out, "%s\x1B[01;36mSUP\x1B[0m %s%d %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2, address_symbol, ins->arg3);
				break;
			case EQU:
				fprintf(out, "%s\x1B[01;36mEQU\x1B[0m %s%d %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2, address_symbol, ins->arg3);
				break;


			case PRI:
				fprintf(out, "%s\x1B[01;36mPRI\x1B[0m %s%d\n", line_nb, address_symbol, ins->arg1);
				break;

			case STORE:
				fprintf(out, "%s\x1B[01;36mSTORE\x1B[0m %s%d %s%d\n", line_nb, address_symbol, ins->arg1, address_symbol, ins->arg2);
				break;
			
	
			default:
				break;
		}
	}
}



void asm_function_ADD(int addr_result, int addr_arg1, int arg2_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= ADD;
	i->arg1			= addr_result;
	i->arg2			= addr_arg1;
	i->arg3			= arg2_addr;
}

void asm_function_SUB(int addr_result, int addr_arg1, int arg2_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= SOU;
	i->arg1			= addr_result;
	i->arg2			= addr_arg1;
	i->arg3			= arg2_addr;
}

void asm_function_MUL(int addr_result, int addr_arg1, int arg2_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= MUL;
	i->arg1			= addr_result;
	i->arg2			= addr_arg1;
	i->arg3			= arg2_addr;
}



void asm_function_AFC(int to_addr, int value)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= AFC;
	i->arg1			= to_addr;
	i->arg2			= value;
}

void asm_function_COP(int to_addr, int from_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= COP;
	i->arg1			= to_addr;
	i->arg2			= from_addr;
}

int asm_prepare_JMP()
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= JMP;
	/*i->arg1		= condition_addr; simple jmp is condition-less*/
	/*i->arg2		= unknown for now;*/
	i->arg3			= JMP_NOT_FINISHED;

	return (index_instruction_TABLE_ASM - 1);
}

int asm_function_JMP(int jmp_to_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= JMP;
	/*i->arg1		= condition_addr; simple jmp is condition-less*/
	i->arg2			= jmp_to_addr;
	i->arg3			= JMP_FINISHED;

	return (index_instruction_TABLE_ASM - 1);
}

int asm_prepare_JMF(int condition_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= JMF;
	i->arg1			= condition_addr;
	/*i->arg2		= unknown for now;*/
	i->arg3			= JMP_NOT_FINISHED;

	return (index_instruction_TABLE_ASM - 1);
}

int asm_function_JMF(int condition_addr, int jmp_to_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= JMF;
	i->arg1			= condition_addr;
	i->arg2			= jmp_to_addr;
	i->arg3			= JMP_FINISHED;

	return (index_instruction_TABLE_ASM - 1);
}

void asm_function_INF(int addr_result, int addr_arg1, int arg2_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= INF;
	i->arg1			= addr_result;
	i->arg2			= addr_arg1;
	i->arg3			= arg2_addr;
}

void asm_function_SUP(int addr_result, int addr_arg1, int arg2_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= SUP;
	i->arg1			= addr_result;
	i->arg2			= addr_arg1;
	i->arg3			= arg2_addr;
}

void asm_function_EQU(int addr_result, int addr_arg1, int arg2_addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= EQU;
	i->arg1			= addr_result;
	i->arg2			= addr_arg1;
	i->arg3			= arg2_addr;
}

void asm_function_PRI(int addr)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= PRI;
	i->arg1			= addr;
}

void asm_function_STORE(int addr1, int addr2)
{
	instruction_ASM *i = get_next_instruction();

	i->opcode	 	= STORE;
	i->arg1			= addr1;
	i->arg2			= addr2;
}



void asm_update_jmp(int jmp_instruction_index, int line_offset)
{
	instruction_ASM *i = &(instruction_TABLE_ASM[jmp_instruction_index]);

	i->arg2	= line_offset;
	i->arg3	= JMP_FINISHED;
}

int asm_get_next_line()
{
	return index_instruction_TABLE_ASM;
}


void asm_push_value(int value)
{
	Symbol *s = add_tmp_symbol();

	asm_function_AFC(s->address, value);
}

void asm_push_from_address(int address)
{
	Symbol *s = add_tmp_symbol();

	asm_function_COP(s->address, address);
}

void asm_push_address(int address)
{
	Symbol *s = add_tmp_symbol();

	asm_function_AFC(s->address, address);
}


void asm_comment(int line_nb, char *comment)
{
    
    ASM_comment *c ;
    if (asm_comment_table_index < ASM_COMMENT_TABLE_SIZE)
        c =  &(asm_comment_table[asm_comment_table_index++]);
    
    c->line_nb = line_nb;
	c->comment = comment;
}

