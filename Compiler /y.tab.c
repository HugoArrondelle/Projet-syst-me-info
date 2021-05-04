/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "syntax.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "syntax_parser_data_types.h"
	#include "symbol_table.h"
	#include "asm.h"


	/* Input stream */
	FILE *yyin;

	int yydebug = 1; 

	extern int yylex();

	int yyerror(char *s) {
		printf("=== \x1B[01;31m[!] YYERROR \x1B[0m  ===\n");
		exit(1);
		return 1;
	}

	
	void
expression_To_condition() {

		asm_comment(asm_get_next_line(),"Translate expression to condition");

		asm_push_value(0);
		Symbol *zero = tmp_table_pop();
		Symbol *expr = tmp_table_peek();
        
		asm_function_EQU(expr->address, expr->address, zero->address);

		asm_push_value(1);
		Symbol *one = tmp_table_pop();
		asm_function_SUB(expr->address, one->address, expr->address);

	}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 44 "syntax.y"
{ 
		int integer_nb;
		char *string;
		Symbol *symbol;
		enum symbol_type symbol_type;
		struct _lvalue lvalue;
	}
/* Line 193 of yacc.c.  */
#line 244 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 257 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    10,    15,    16,    18,    21,    24,
      27,    31,    35,    36,    41,    46,    50,    54,    58,    62,
      66,    70,    74,    78,    82,    86,    90,    94,    96,    98,
     100,   101,   103,   107,   109,   113,   114,   120,   122,   127,
     129,   131,   133,   135,   138,   139,   145,   147,   150,   152,
     155,   156,   161,   162,   163,   164,   175,   176,   177,   185,
     186,   187
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,     6,     3,    27,    28,    52,    -1,    -1,
      29,    53,    54,    30,    -1,    -1,    35,    -1,    52,    54,
      -1,    70,    54,    -1,    76,    54,    -1,    66,    35,    54,
      -1,    68,    35,    54,    -1,    -1,    56,    35,    55,    54,
      -1,    25,    56,    35,    54,    -1,    27,    56,    28,    -1,
      56,    40,    56,    -1,    56,    41,    56,    -1,    56,    38,
      56,    -1,    56,    39,    56,    -1,    56,    42,    56,    -1,
      56,    43,    56,    -1,    56,    44,    56,    -1,    56,    45,
      56,    -1,    56,    46,    56,    -1,    56,    48,    56,    -1,
      56,    47,    56,    -1,    61,    -1,    15,    -1,     5,    -1,
      -1,    56,    -1,    56,    36,    58,    -1,    56,    -1,    56,
      36,    58,    -1,    -1,     4,    27,    60,    58,    28,    -1,
      59,    -1,     5,    27,    57,    28,    -1,     7,    -1,     8,
      -1,     9,    -1,    62,    -1,    14,    62,    -1,    -1,    63,
       5,    26,    65,    56,    -1,    64,    -1,    63,     5,    -1,
       5,    -1,    38,    67,    -1,    -1,    67,    26,    69,    56,
      -1,    -1,    -1,    -1,    16,    71,    27,    56,    28,    72,
      52,    17,    73,    52,    -1,    -1,    -1,    16,    74,    27,
      56,    28,    75,    52,    -1,    -1,    -1,    18,    27,    77,
      56,    28,    78,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   136,   135,   141,   142,   143,   145,   146,
     148,   150,   154,   152,   159,   164,   168,   178,   188,   198,
     202,   206,   215,   229,   238,   253,   267,   278,   283,   290,
     308,   309,   310,   313,   314,   318,   317,   329,   330,   335,
     336,   337,   341,   343,   347,   346,   375,   376,   397,   402,
     408,   407,   449,   453,   464,   448,   479,   483,   478,   501,
     507,   500
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_main", "T_printf", "T_identifier",
  "T_void", "T_int", "T_double", "T_char", "T_long", "T_signed",
  "T_unsigned", "T_short", "T_const", "T_integer_number", "T_if", "T_else",
  "T_while", "T_switch", "T_for", "T_do", "T_break", "T_continue",
  "T_default", "T_return", "T_equal", "T_po", "T_pf", "T_ao", "T_af",
  "T_co", "T_cf", "T_E_mark", "T_Q_mark", "T_semi_colon", "T_comma",
  "T_colon", "T_mul", "T_div", "T_add", "T_sub", "T_mod", "T_less_than",
  "T_less_than_or_equal_to", "T_greater_than",
  "T_greater_than_or_equal_to", "T_equal_comparison", "T_different",
  "T_ampersand", "$accept", "S", "BODY", "@1", "STATEMENT", "@2",
  "EXPRESSION", "FUNCTION_ARGS", "FUNCTION_ARGS_NOT_EMPTY", "PRINTF", "@3",
  "FUNCTION_CALL", "TYPE", "DECLARATION_TYPE",
  "DECLARATION_AND_ASSIGNMENT", "@4", "DECLARATION", "LVALUE",
  "ASSIGNMENT", "@5", "IF_STATEMENT", "@6", "@7", "@8", "@9", "@10",
  "WHILE_STATEMENT", "@11", "@12", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    53,    52,    54,    54,    54,    54,    54,
      54,    54,    55,    54,    54,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    58,    58,    60,    59,    61,    61,    62,
      62,    62,    63,    63,    65,    64,    66,    66,    67,    67,
      69,    68,    71,    72,    73,    70,    74,    75,    70,    77,
      78,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     4,     0,     1,     2,     2,     2,
       3,     3,     0,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       0,     1,     3,     1,     3,     0,     5,     1,     4,     1,
       1,     1,     1,     2,     0,     5,     1,     2,     1,     2,
       0,     4,     0,     0,     0,    10,     0,     0,     7,     0,
       0,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     2,     5,
       0,    29,    39,    40,    41,     0,    28,    52,     0,     0,
       0,     6,     0,     5,     0,     0,    37,    27,    42,     0,
      46,     0,     0,     0,     5,     5,    35,    30,    43,     0,
       0,    59,    29,     0,     0,    48,    49,     7,     4,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     5,    50,     5,     8,     9,     0,    31,     0,
       0,     0,     0,     5,    15,     5,    18,    19,    16,    17,
      20,    21,    22,    23,    24,    26,    25,    44,    10,     0,
      11,    33,     0,     0,    38,     0,     0,     0,    14,    13,
       0,    51,     0,    36,    32,    53,    57,    60,    45,    34,
       0,     0,     0,     0,    58,    61,    54,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    23,     9,    24,    75,    25,    69,    92,    26,
      67,    27,    28,    29,    30,   100,    31,    32,    33,    89,
      34,    39,   110,   117,    40,   111,    35,    72,   112
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int16 yypact[] =
{
       7,     2,    11,   -12,   -87,    16,    -4,   -87,   -87,    58,
      19,    -3,   -87,   -87,   -87,    13,   -87,   -87,    21,    -1,
      -1,   -87,     5,    58,    20,   151,   -87,   -87,   -87,    46,
     -87,    22,    29,    24,    58,    58,   -87,    -1,   -87,    33,
      34,   -87,    37,   165,    74,   -87,   -87,   -87,   -87,   -87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    58,   -87,    58,   -87,   -87,    -1,   178,    41,
      -1,    -1,    -1,    58,   -87,    58,   -87,   -87,   -30,   -30,
     -87,   -11,   -11,   -11,   -11,   -11,   -11,   -87,   -87,    -1,
     -87,   191,    49,    -1,   -87,    95,   116,   137,   -87,   -87,
      -1,   202,    -1,   -87,   -87,   -87,   -87,   -87,   202,   -87,
      -4,    -4,    -4,    53,   -87,   -87,   -87,    -4,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,    -6,   -87,   -17,   -87,   -18,   -87,   -86,   -87,
     -87,   -87,    63,   -87,   -87,   -87,   -87,    57,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int8 yytable[] =
{
       8,    43,    44,    10,    42,     3,    47,   104,    50,    51,
      45,     4,    54,     1,    16,     5,   109,    65,    66,    68,
      12,    13,    14,   -48,    37,     7,    20,    50,    51,    52,
      53,    54,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    22,     6,    88,    36,    90,    41,    91,
      48,    61,    95,    96,    97,    63,    98,    62,    99,    64,
      70,    71,    10,    11,    37,    12,    13,    14,    87,    94,
     116,   101,    15,    16,    17,    91,    18,   103,    38,    46,
       0,     0,   108,    19,    91,    20,     0,     7,     0,     0,
       0,     0,     0,    21,     0,     0,    22,     0,     0,     0,
       0,     0,    74,     0,   113,   114,   115,     0,     0,     0,
       0,   118,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    49,     0,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      73,     0,     0,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    93,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   102,     0,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60
};

static const yytype_int8 yycheck[] =
{
       6,    19,    20,     4,     5,     3,    23,    93,    38,    39,
       5,     0,    42,     6,    15,    27,   102,    34,    35,    37,
       7,     8,     9,    26,    27,    29,    27,    38,    39,    40,
      41,    42,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    38,    28,    62,    27,    64,    27,    67,
      30,     5,    70,    71,    72,    26,    73,    35,    75,    35,
      27,    27,     4,     5,    27,     7,     8,     9,    26,    28,
      17,    89,    14,    15,    16,    93,    18,    28,    15,    22,
      -1,    -1,   100,    25,   102,    27,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    28,    -1,   110,   111,   112,    -1,    -1,    -1,
      -1,   117,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      35,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    51,     3,     0,    27,    28,    29,    52,    53,
       4,     5,     7,     8,     9,    14,    15,    16,    18,    25,
      27,    35,    38,    52,    54,    56,    59,    61,    62,    63,
      64,    66,    67,    68,    70,    76,    27,    27,    62,    71,
      74,    27,     5,    56,    56,     5,    67,    54,    30,    35,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     5,    35,    26,    35,    54,    54,    60,    56,    57,
      27,    27,    77,    35,    28,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    26,    54,    69,
      54,    56,    58,    36,    28,    56,    56,    56,    54,    54,
      65,    56,    36,    28,    58,    28,    28,    28,    56,    58,
      72,    75,    78,    52,    52,    52,    17,    73,    52
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 136 "syntax.y"
    { increase_depth(); }
    break;

  case 4:
#line 138 "syntax.y"
    { decrease_depth(); }
    break;

  case 12:
#line 154 "syntax.y"
    {
				tmp_table_pop();
			}
    break;

  case 15:
#line 165 "syntax.y"
    {
				(yyval.symbol) = (yyvsp[(2) - (3)].symbol);
			}
    break;

  case 16:
#line 169 "syntax.y"
    { 
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_ADD(op1->address, op1->address, op2->address);

				(yyval.symbol) = op1;
			}
    break;

  case 17:
#line 179 "syntax.y"
    { 
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();
                
				asm_function_SUB(op1->address, op1->address, op2->address);

				(yyval.symbol) = op1;
			}
    break;

  case 18:
#line 189 "syntax.y"
    { 
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_MUL(op1->address, op1->address, op2->address);

				(yyval.symbol) = op1;
			}
    break;

  case 19:
#line 199 "syntax.y"
    { 
			}
    break;

  case 20:
#line 203 "syntax.y"
    { 
			}
    break;

  case 21:
#line 207 "syntax.y"
    {
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_INF(op1->address, op1->address, op2->address);
				(yyval.symbol) = op1;
			}
    break;

  case 22:
#line 216 "syntax.y"
    {
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_SUP(op1->address, op1->address, op2->address);

				asm_push_value(1);
				op2 = tmp_table_pop();

				asm_function_SUB(op1->address, 1, op1->address);
				(yyval.symbol) = op1;
			}
    break;

  case 23:
#line 230 "syntax.y"
    {
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_SUP(op1->address, op1->address, op2->address);
				(yyval.symbol) = op1;
			}
    break;

  case 24:
#line 239 "syntax.y"
    {
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_INF(op1->address, op1->address, op2->address);

				asm_push_value(1);
				op2 = tmp_table_pop();

				asm_function_SUB(op1->address, 1, op1->address);

				(yyval.symbol) = op1;
			}
    break;

  case 25:
#line 254 "syntax.y"
    {
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_EQU(op1->address, op1->address, op2->address);
        
				asm_push_value(1);
				Symbol *one = tmp_table_pop();
				asm_function_SUB(op1->address, one->address, op1->address);

				(yyval.symbol) = op1;
			}
    break;

  case 26:
#line 268 "syntax.y"
    {
				Symbol *op2 = tmp_table_pop();
				Symbol *op1 = tmp_table_peek();

				asm_function_EQU(op1->address, op1->address, op2->address);

				(yyval.symbol) = op1;
			}
    break;

  case 27:
#line 279 "syntax.y"
    {
			}
    break;

  case 28:
#line 284 "syntax.y"
    { 
				asm_push_value((yyvsp[(1) - (1)].integer_nb));

				(yyval.symbol) = tmp_table_peek();
			}
    break;

  case 29:
#line 291 "syntax.y"
    {
				Symbol *s = get_symbol((yyvsp[(1) - (1)].string));

				if (s == NULL) {
                    printf("\x1B[01;31m[!] ERROR: \x1B[0m  Undeclared symbol '%s'. \n ",(yyvsp[(1) - (1)].string));
                    exit(1);
				}

				free(yylval.string);
				
				asm_push_from_address(s->address);

				(yyval.symbol) = s;
			}
    break;

  case 35:
#line 318 "syntax.y"
    {
				asm_comment(asm_get_next_line(), "printf");
			}
    break;

  case 36:
#line 322 "syntax.y"
    {
				Symbol *addr = tmp_table_pop();
				asm_function_PRI(addr->address);
			}
    break;

  case 38:
#line 331 "syntax.y"
    {
			}
    break;

  case 42:
#line 341 "syntax.y"
    { (yyval.symbol_type) = BASIC_TYPE; }
    break;

  case 43:
#line 343 "syntax.y"
    { (yyval.symbol_type) = BASIC_CONSTANT_TYPE; }
    break;

  case 44:
#line 347 "syntax.y"
    {
						int comment_size = strlen((yyvsp[(2) - (3)].string)) + 55;
						char *comment = malloc(comment_size);
						snprintf(comment, comment_size, "declaration and initialization of variable '%s'", (yyvsp[(2) - (3)].string));
						asm_comment(asm_get_next_line(),comment);
					}
    break;

  case 45:
#line 354 "syntax.y"
    {
						if (!is_available((yyvsp[(2) - (5)].string))) {
                            printf("\x1B[01;31m[!] ERROR: \x1B[0m  UDeclaration of the already declared symbol '%s'. \n ",(yyvsp[(2) - (5)].string));
                            exit(1);
						}

						enum symbol_type st = (yyvsp[(1) - (5)].symbol_type);

						Symbol *s = new_symbol((yyvsp[(2) - (5)].string), st);
                        
                        if (s) { s->isInitialized = INITIALIZED; }
						

						Symbol *expr = tmp_table_pop();

						asm_function_COP(s->address, expr->address);

						(yyval.symbol) = s;
					}
    break;

  case 47:
#line 377 "syntax.y"
    {
				if (!is_available((yyvsp[(2) - (2)].string))) {
					printf("\x1B[01;31m[!] ERROR: \x1B[0m  Declaration of the already declared symbol '%s'", (yyvsp[(2) - (2)].string));
                    exit(1);
				}

				enum symbol_type st = (yyvsp[(1) - (2)].symbol_type);

				Symbol *s = new_symbol((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].symbol_type));
                
                if (is_constant(s)) {
                    
                    fprintf(stderr, "\x1B[01;32m[*] WARNING: Symbol '%s' declared with 'const' class not initialized \n\x1B[0m",(yyvsp[(2) - (2)].string));
                }
                

				
			}
    break;

  case 48:
#line 398 "syntax.y"
    {
				struct _lvalue l = {(yyvsp[(1) - (1)].string), 0};
				(yyval.lvalue) = l;
			}
    break;

  case 49:
#line 403 "syntax.y"
    {
				// Pointer
			}
    break;

  case 50:
#line 408 "syntax.y"
    {
				int comment_size = strlen((yyvsp[(1) - (2)].lvalue).identifier) + (yyvsp[(1) - (2)].lvalue).pointer_depth + 50;
				char *comment = malloc(comment_size);
				int i;
				int comment_current_length = 0;

				snprintf(comment, comment_size, "assignment of variable '");
				comment_current_length = strlen(comment);

				snprintf(&(comment[comment_current_length]), comment_size - (comment_current_length), "%s'", (yyvsp[(1) - (2)].lvalue).identifier);

				asm_comment(asm_get_next_line(),comment);
			}
    break;

  case 51:
#line 422 "syntax.y"
    {
				struct _lvalue lvalue = (yyvsp[(1) - (4)].lvalue);
				int depth;
				Symbol *s = get_symbol((yyvsp[(1) - (4)].lvalue).identifier);

				if (s == NULL) {
                    printf("\x1B[01;31m[!] ERROR: \x1B[0m  Undeclared symbol '%s'", lvalue.identifier);
                    exit(1);
				}
                
                if (lvalue.pointer_depth == 0) {

                    if (!is_constant(s)) {
                        Symbol *expr = tmp_table_pop();
                        asm_function_COP(s->address, expr->address);

                    } else {
                        printf("\x1B[01;31m[!] ERROR: \x1B[0m  Symbol '%s' declared with 'const' class is not mutable", lvalue.identifier);
                        
                    }
                }
				
			}
    break;

  case 52:
#line 449 "syntax.y"
    {
				asm_comment(asm_get_next_line(),"if statement");
			}
    break;

  case 53:
#line 453 "syntax.y"
    {
				
				
expression_To_condition();
				asm_comment(asm_get_next_line(),"if block {");

				Symbol *condition = tmp_table_pop();

				(yyvsp[(1) - (5)].integer_nb) = asm_prepare_JMF(condition->address);
			}
    break;

  case 54:
#line 464 "syntax.y"
    {
            
				asm_update_jmp((yyvsp[(1) - (8)].integer_nb), asm_get_next_line() + 1);

    
				(yyvsp[(1) - (8)].integer_nb) = asm_prepare_JMP();
				asm_comment(asm_get_next_line(),"else statement");
			}
    break;

  case 55:
#line 473 "syntax.y"
    {
				asm_update_jmp((yyvsp[(1) - (10)].integer_nb), asm_get_next_line());
				asm_comment(asm_get_next_line(),"} end of if-else statement");
			}
    break;

  case 56:
#line 479 "syntax.y"
    {
				asm_comment(asm_get_next_line(),"if statement");
			}
    break;

  case 57:
#line 483 "syntax.y"
    {
				asm_comment(asm_get_next_line(),"if block {");

				
expression_To_condition();

				asm_update_jmp((yyvsp[(1) - (5)].integer_nb), asm_get_next_line());
			}
    break;

  case 58:
#line 492 "syntax.y"
    {
				asm_update_jmp((yyvsp[(1) - (7)].integer_nb), asm_get_next_line());
				asm_comment(asm_get_next_line(),"} end of if statement");
			}
    break;

  case 59:
#line 501 "syntax.y"
    {
					asm_comment(asm_get_next_line(),"while statement");

					(yyvsp[(2) - (2)].integer_nb) = asm_get_next_line();
				}
    break;

  case 60:
#line 507 "syntax.y"
    {

					
expression_To_condition();

					Symbol *condition = tmp_table_pop();

					(yyvsp[(1) - (5)].integer_nb) = asm_prepare_JMF(condition->address);
					asm_comment(asm_get_next_line(),"while block {");
				}
    break;

  case 61:
#line 518 "syntax.y"
    {
					asm_update_jmp((yyvsp[(1) - (7)].integer_nb), asm_get_next_line() + 1);
					asm_function_JMP((yyvsp[(2) - (7)].integer_nb));
					asm_comment(asm_get_next_line(),"} end of while statement");
				}
    break;


/* Line 1267 of yacc.c.  */
#line 2021 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 526 "syntax.y"


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

