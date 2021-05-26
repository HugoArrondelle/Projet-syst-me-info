/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_main = 258,
     T_printf = 259,
     T_identifier = 260,
     T_void = 261,
     T_int = 262,
     T_double = 263,
     T_char = 264,
     T_long = 265,
     T_signed = 266,
     T_unsigned = 267,
     T_short = 268,
     T_const = 269,
     T_integer_number = 270,
     T_if = 271,
     T_else = 272,
     T_while = 273,
     T_switch = 274,
     T_for = 275,
     T_do = 276,
     T_break = 277,
     T_continue = 278,
     T_default = 279,
     T_return = 280,
     T_equal = 281,
     T_po = 282,
     T_pf = 283,
     T_ao = 284,
     T_af = 285,
     T_co = 286,
     T_cf = 287,
     T_E_mark = 288,
     T_Q_mark = 289,
     T_semi_colon = 290,
     T_comma = 291,
     T_colon = 292,
     T_mul = 293,
     T_div = 294,
     T_add = 295,
     T_sub = 296,
     T_mod = 297,
     T_less_than = 298,
     T_less_than_or_equal_to = 299,
     T_greater_than = 300,
     T_greater_than_or_equal_to = 301,
     T_equal_comparison = 302,
     T_different = 303,
     T_ampersand = 304
   };
#endif
/* Tokens.  */
#define T_main 258
#define T_printf 259
#define T_identifier 260
#define T_void 261
#define T_int 262
#define T_double 263
#define T_char 264
#define T_long 265
#define T_signed 266
#define T_unsigned 267
#define T_short 268
#define T_const 269
#define T_integer_number 270
#define T_if 271
#define T_else 272
#define T_while 273
#define T_switch 274
#define T_for 275
#define T_do 276
#define T_break 277
#define T_continue 278
#define T_default 279
#define T_return 280
#define T_equal 281
#define T_po 282
#define T_pf 283
#define T_ao 284
#define T_af 285
#define T_co 286
#define T_cf 287
#define T_E_mark 288
#define T_Q_mark 289
#define T_semi_colon 290
#define T_comma 291
#define T_colon 292
#define T_mul 293
#define T_div 294
#define T_add 295
#define T_sub 296
#define T_mod 297
#define T_less_than 298
#define T_less_than_or_equal_to 299
#define T_greater_than 300
#define T_greater_than_or_equal_to 301
#define T_equal_comparison 302
#define T_different 303
#define T_ampersand 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "syntax.y"
{ 
		int integer_nb;
		char *string;
		Symbol *symbol;
		enum symbol_type symbol_type;
		struct _VALEUR VALEUR;
	}
/* Line 1529 of yacc.c.  */
#line 155 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

