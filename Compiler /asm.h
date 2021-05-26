#ifndef _ASM_H_
#define _ASM_H_

#include <stdio.h>

#include "symbol_table.h"



typedef enum _instruction_ASM_TYPE  {
    ADD,
    MUL,
    SOU,
    DIV,

    COP,
    AFC,
    JMP,
    JMF,

    INF,
    SUP,
    EQU,

    PRI,

    STORE,
    
    NB_OF_INSTRUCTIONS
} instruction_ASM_TYPE ;


typedef struct {

    instruction_ASM_TYPE  opcode;
    int arg1;
    int arg2;
    int arg3;

} instruction_ASM;


typedef struct {
    int line_nb;
    char *comment;
} ASM_comment;



FILE* out;
void init_output(FILE *output);

void display_asm(void);

void asm_function_ADD(int addr_result, int addr_arg1, int addr_arg2);
void asm_function_SUB(int addr_result, int addr_arg1, int addr_arg2);
void asm_function_MUL(int addr_result, int addr_arg1, int addr_arg2);

void asm_function_AFC(int to_addr, int value);
void asm_function_COP(int to_addr, int from_addr);

int asm_prepare_JMP();
int asm_function_JMP(int jmp_to_addr);

int asm_prepare_JMF(int condition_addr);
int asm_function_JMF(int condition_addr, int jmp_to_addr);

void asm_function_INF(int addr_result, int addr_arg1, int addr_arg2);
void asm_function_SUP(int addr_result, int addr_arg1, int addr_arg2);
void asm_function_EQU(int addr_result, int addr_arg1, int addr_arg2);

void asm_function_DIV(int addr_result, int addr_arg1, int addr_arg2);

void asm_function_PRI(int addr);

void asm_function_STORE(int addr_arg1, int addr_arg2);


void asm_push_value(int value);

void asm_push_from_address(int address);
void asm_push_address(int address);

void asm_update_jmp(int jmp_instruction_index, int line_index);
int asm_get_next_line();

void asm_comment(int line_nb, char *comment);

#endif /* _ASM_H_ */
