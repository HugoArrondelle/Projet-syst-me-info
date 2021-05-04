#ifndef _SYMBOL_TABLE_H
#define _SYMBOL_TABLE_H

enum symbol_type {
    BASIC_TYPE,
    BASIC_CONSTANT_TYPE
};

enum init_flag		{UNINITIALIZED,	INITIALIZED};

typedef struct _Symbol {

	char *identifier;
	int address;

	int depth;

	enum init_flag		isInitialized;
	enum symbol_type	type;

} Symbol;


void init();

Symbol *new_symbol(char *identifier, enum symbol_type st);

Symbol *get_symbol(char *identifier);

int is_initialized(Symbol *s);


void symbol_table_set_constant(Symbol *s);
int is_constant(Symbol *s);








int is_available(char *identifier);

int increase_depth();
int decrease_depth();

Symbol *add_tmp_symbol(void);

void printf_table_symbol();
void prinft_tmp_table_symbol();

Symbol *tmp_table_pop(void);
Symbol *tmp_table_peek(void);

#endif /* _SYMBOL_TABLE_H */
