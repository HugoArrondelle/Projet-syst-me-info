#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"

#define SYMBOL_SIZE 4

#define TABLE_SIZE	100
#define TMP_TABLE_SIZE	TABLE_SIZE
#define TMP_TABLE_OFFSET	TABLE_SIZE

Symbol symbol_table[TABLE_SIZE];
int index_symbol_table = 0;
int current_address = 0;
int current_depth = 0;

Symbol tmp_symbol_table[TMP_TABLE_SIZE];
int tmp_index_symbol_table = 0;
int tmp_current_address = TMP_TABLE_OFFSET;


void init()
{
	memset(symbol_table, 0, TABLE_SIZE * sizeof(*symbol_table));
}

static void init_symbol(Symbol *s, char *identifier, int address, enum init_flag i, enum symbol_type type, int depth)
{
	if (s) {
		s->identifier		= identifier;
		s->address			= address;
		s->isInitialized	= i;
		s->type				= type;
		s->depth			= depth;
	}
}

Symbol *new_symbol(char *identifier, enum symbol_type st)
{
	if (index_symbol_table == TABLE_SIZE) {
		return NULL;
	}	

	switch(st) {
		case BASIC_TYPE:
			init_symbol(&(symbol_table[index_symbol_table]),
					strdup(identifier),
					current_address,
					UNINITIALIZED,
					BASIC_TYPE,
					current_depth);
			break;
        case BASIC_CONSTANT_TYPE:
            init_symbol(&(symbol_table[index_symbol_table]),
                    strdup(identifier),
                    current_address,
                    UNINITIALIZED,
                    BASIC_CONSTANT_TYPE,
                    current_depth);
            break;


		default: return NULL;
	}

	current_address += SYMBOL_SIZE;
   
	return &(symbol_table[index_symbol_table++]);
}


int is_available(char *identifier)
{
	int i;
	for (i = index_symbol_table; (i > 0) && (symbol_table[i-1].depth == current_depth); i--) {
		if (strcmp(symbol_table[i-1].identifier, identifier) == 0)
			return 0;
	}

	return 1;
}

Symbol *get_symbol(char *identifier)
{
	int i;
	for (i = index_symbol_table-1; i >= 0; i--) {
		if (strcmp(symbol_table[i].identifier, identifier) == 0)
			return &(symbol_table[i]);
	}

	return NULL;
}

void symbol_table_set_constant(Symbol *s)
{
    if (s) {
        switch (s->type) {
            case BASIC_TYPE:
                s->type = BASIC_CONSTANT_TYPE;
                break;
            default: break;
        }
    }
}

int is_constant(Symbol *s)
{
    if (s) {
        return (s->type == BASIC_CONSTANT_TYPE);
    }

    return -1;
}


int increase_depth()
{
	return (++current_depth);
}

int decrease_depth()
{
	if (current_depth > 0) {
        
        int i;
        for (i = index_symbol_table; (i > 0) && (symbol_table[i-1].depth == current_depth); i--) {}
        index_symbol_table = i;
        current_address = index_symbol_table * SYMBOL_SIZE;
        
		return (--current_depth);
	}
	return -1;
}

Symbol *add_tmp_symbol(void)
{
	if (tmp_index_symbol_table == TMP_TABLE_SIZE) {
		return NULL;
	}

	init_symbol(&(tmp_symbol_table[tmp_index_symbol_table]),
			NULL,
			tmp_current_address,
			UNINITIALIZED,
			BASIC_TYPE,
			current_depth);

	tmp_current_address += SYMBOL_SIZE;

	return &(tmp_symbol_table[tmp_index_symbol_table++]);
}

Symbol *tmp_table_pop(void)
{
	if (tmp_index_symbol_table) {

		tmp_current_address -= SYMBOL_SIZE;
        //printf_table_symbol();
        return &(tmp_symbol_table[--tmp_index_symbol_table]);
	}
    
	return NULL;
}

Symbol *tmp_table_peek(void)
{
	if (tmp_index_symbol_table)
		return &(tmp_symbol_table[tmp_index_symbol_table-1]);

	return NULL;
}



void printf_table_symbol(){
    printf("\n");
    printf("AFFICHAGE SYMBOL TABLE\n");
    printf("\n");
    printf("________________________________________\n");
    printf("| Index | Adress  | Depth | Identifier |\n");
    for(int i = 0; i < index_symbol_table ; i++){
        printf("|   %d   |", i);
        printf("   %d     |",symbol_table[i].address);
        printf("   %d   |",symbol_table[i].depth);
        printf("     %s      |\n",symbol_table[i].identifier);
    }
    printf("______________________________________\n");
}
 

void prinft_tmp_table_symbol(){
    printf("\n");
    printf("AFFICHAGE TMP SYMBOL TABLE\n");
    printf("\n");
    printf("________________________________________\n");
    printf("| Index | Adress  | Depth | Identifier |\n");
    for(int i = 0; i < tmp_index_symbol_table ; i++){
        printf("|   %d   |", i);
        printf("   %d     |",tmp_symbol_table[i].address);
        printf("   %d   |",tmp_symbol_table[i].depth);
        printf("     %s      |\n",tmp_symbol_table[i].identifier);
    }
}
