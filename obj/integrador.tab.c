
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/integrador.y"
 /* seccion de definiciones */

	#include <stdio.h>
	#include <math.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
	#include "tablaDeSimbolos.h"
	#define YYERROR_VERBOSE
	extern FILE* yyin; 
	int my_line=1;
	
	// el mensaje muestre la línea en la que está el error

	int yylex();

	void yyerror (char const *s) {
		agregarErrorSintactico(s,my_line);
		//fprintf(stderr, "hay un error \n", s); 
	}



/* Line 189 of yacc.c  */
#line 97 "integrador.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FOR = 258,
     IF = 259,
     ELSE = 260,
     RETURN = 261,
     SWITCH = 262,
     DECIMAL = 263,
     HEXA = 264,
     OCTAL = 265,
     NUM_R = 266,
     IDENTIFICADOR = 267,
     TIPO_DATO = 268,
     DO = 269,
     WHILE = 270,
     CHAR = 271,
     LITERAL_CADENA = 272,
     MAYOR_IGUAL = 273,
     MENOR_IGUAL = 274,
     IGUALDAD = 275,
     AND = 276,
     OR = 277,
     DESIGUALDAD = 278,
     CASE = 279,
     BREAK = 280,
     DEFAULT = 281,
     MAS_IGUAL = 282,
     MENOS_IGUAL = 283,
     POR_IGUAL = 284,
     DIVIDIDO_IGUAL = 285,
     MAS_MAS = 286,
     MENOS_MENOS = 287,
     ERROR_LEXICO = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 25 "../src/integrador.y"

	struct{
		char cadena[50];
		int tipo;// 0 = int, 1 = char*, 2 = numero, 3 = void
		float numero;
	}s;



/* Line 214 of yacc.c  */
#line 176 "integrador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "integrador.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,    36,    44,    50,    45,    46,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    37,
      48,    43,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    10,    12,    15,    18,
      21,    24,    27,    30,    33,    36,    39,    42,    45,    48,
      49,    52,    54,    60,    61,    64,    67,    70,    73,    76,
      79,    82,    85,    88,    91,    94,   105,   117,   119,   121,
     124,   127,   131,   135,   136,   147,   150,   151,   157,   166,
     167,   176,   177,   184,   189,   190,   194,   195,   197,   201,
     205,   209,   216,   227,   232,   235,   246,   253,   257,   259,
     264,   269,   274,   279,   284,   287,   289,   291,   295,   297,
     301,   305,   309,   313,   317,   318,   320,   324,   326,   327,
     330,   335,   336,   339,   343,   344,   346,   348,   350,   352,
     356,   360,   364,   368,   372,   376,   380,   384,   388,   390,
     392,   394,   396,   400,   404
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,    52,    53,    -1,    33,    -1,    -1,
      34,    -1,    69,    54,    -1,    55,    54,    -1,    72,    54,
      -1,    71,    54,    -1,    66,    54,    -1,    65,    54,    -1,
      58,    54,    -1,    57,    54,    -1,    62,    54,    -1,    74,
      54,    -1,    61,    54,    -1,     1,    54,    -1,    -1,    34,
      54,    -1,    34,    -1,    12,    35,    80,    36,    37,    -1,
      -1,    66,    56,    -1,    57,    56,    -1,    58,    56,    -1,
      65,    56,    -1,    62,    56,    -1,    74,    56,    -1,    68,
      56,    -1,    69,    56,    -1,    55,    54,    -1,    61,    56,
      -1,    34,    56,    -1,    14,    54,    38,    56,    39,    15,
      35,    82,    36,    37,    -1,     3,    35,    59,    83,    37,
      60,    36,    54,    38,    56,    39,    -1,    74,    -1,    70,
      -1,    12,    31,    -1,    12,    32,    -1,    12,    31,    37,
      -1,    12,    32,    37,    -1,    -1,     4,    35,    82,    36,
      54,    38,    56,    39,    63,    64,    -1,     1,    54,    -1,
      -1,     5,    54,    38,    56,    39,    -1,    15,    35,    82,
      36,    54,    38,    56,    39,    -1,    -1,     7,    35,    82,
      36,    54,    38,    67,    39,    -1,    -1,    24,    82,    40,
      56,    25,    37,    -1,    67,    26,    40,    56,    -1,    -1,
       6,    82,    37,    -1,    -1,    70,    -1,    70,    37,    69,
      -1,    13,    12,    37,    -1,    13,    76,    37,    -1,    13,
      12,    41,    83,    42,    37,    -1,    13,    12,    41,    83,
      42,    43,    38,    73,    39,    37,    -1,    13,    44,    12,
      37,    -1,     1,    54,    -1,    13,    12,    35,    79,    36,
      54,    38,    56,    39,    37,    -1,    13,    12,    35,    78,
      36,    37,    -1,    83,    45,    73,    -1,    83,    -1,    75,
      43,    82,    37,    -1,    75,    27,    82,    37,    -1,    75,
      28,    82,    37,    -1,    75,    29,    82,    37,    -1,    75,
      30,    82,    37,    -1,    13,    12,    -1,    12,    -1,    77,
      -1,    76,    45,    77,    -1,    12,    -1,    12,    43,    82,
      -1,    12,    27,    82,    -1,    12,    28,    82,    -1,    12,
      29,    82,    -1,    12,    30,    82,    -1,    -1,    13,    -1,
      13,    45,    78,    -1,    79,    -1,    -1,    13,    12,    -1,
      13,    12,    45,    79,    -1,    -1,    83,    81,    -1,    45,
      83,    81,    -1,    -1,    17,    -1,    83,    -1,    12,    -1,
      16,    -1,    83,    46,    83,    -1,    83,    47,    83,    -1,
      83,    48,    83,    -1,    83,    20,    83,    -1,    83,    18,
      83,    -1,    83,    19,    83,    -1,    83,    23,    83,    -1,
      83,    21,    83,    -1,    83,    22,    83,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,    83,    44,    83,    -1,
      83,    49,    83,    -1,    83,    50,    83,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   100,   101,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   122,
     123,   124,   128,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   146,   149,   153,   154,   158,
     159,   163,   164,   168,   168,   169,   172,   173,   176,   180,
     181,   185,   186,   187,   190,   191,   194,   195,   196,   199,
     200,   201,   202,   203,   204,   208,   211,   215,   216,   219,
     220,   221,   222,   223,   226,   227,   233,   234,   238,   239,
     240,   241,   242,   243,   247,   248,   249,   250,   253,   254,
     255,   259,   260,   264,   265,   269,   270,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FOR", "IF", "ELSE", "RETURN", "SWITCH",
  "DECIMAL", "HEXA", "OCTAL", "NUM_R", "IDENTIFICADOR", "TIPO_DATO", "DO",
  "WHILE", "CHAR", "LITERAL_CADENA", "MAYOR_IGUAL", "MENOR_IGUAL",
  "IGUALDAD", "AND", "OR", "DESIGUALDAD", "CASE", "BREAK", "DEFAULT",
  "MAS_IGUAL", "MENOS_IGUAL", "POR_IGUAL", "DIVIDIDO_IGUAL", "MAS_MAS",
  "MENOS_MENOS", "ERROR_LEXICO", "'\\n'", "'('", "')'", "';'", "'{'",
  "'}'", "':'", "'['", "']'", "'='", "'*'", "','", "'-'", "'>'", "'<'",
  "'/'", "'+'", "$accept", "input", "line", "saltoOpcional",
  "invocacionFuncion", "listadoDeSentencias", "sentenciaDoWhile",
  "sentenciaFor", "sentenciaDecOAsig", "incrementoParaFor",
  "incrementoDecremento", "sentenciaIfElse", "$@1", "sentenciaElse",
  "sentenciaWhile", "sentenciaSwitch", "sentenciaCase", "sentenciaReturn",
  "listadoDeSentenciasDeDeclaracion", "sentenciaDeclaracion",
  "desarrolloFuncion", "prototipoFuncion", "auxi", "sentenciaAsignacion",
  "parametro", "listaIdentificadores", "identificadorA",
  "listaParametrosPrototipo", "listaParametrosFuncion",
  "listaParametrosInvocacion", "parametroExtra", "exp", "expC", 0
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
     285,   286,   287,   288,    10,    40,    41,    59,   123,   125,
      58,    91,    93,    61,    42,    44,    45,    62,    60,    47,
      43
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    59,    59,    60,
      60,    61,    61,    63,    62,    62,    64,    64,    65,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    71,    72,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       2,     1,     5,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    10,    11,     1,     1,     2,
       2,     3,     3,     0,    10,     2,     0,     5,     8,     0,
       8,     0,     6,     4,     0,     3,     0,     1,     3,     3,
       3,     6,    10,     4,     2,    10,     6,     3,     1,     4,
       4,     4,     4,     4,     2,     1,     1,     3,     1,     3,
       3,     3,     3,     3,     0,     1,     3,     1,     0,     2,
       4,     0,     2,     3,     0,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     4,     0,     1,    19,     0,     0,     0,    75,     0,
      19,     0,     6,     3,    19,    19,    19,    19,    19,    19,
      19,    19,    57,    19,    19,    19,     0,    19,    18,     0,
       0,     0,     0,     0,    91,    78,     0,     0,    76,     0,
       0,     8,    14,    13,    17,    15,    12,    11,     7,     0,
      10,     9,    16,     0,     0,     0,     0,     0,    20,    19,
      75,     0,     0,    38,    37,   108,   109,   110,   111,    97,
      98,    95,     0,    96,     0,    41,    42,     0,    94,     0,
       0,     0,     0,    84,    59,     0,     0,     0,    60,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,    64,
      78,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,    92,    80,
      81,    82,    83,    85,     0,     0,     0,    79,    63,    78,
      77,    19,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    78,    70,    71,    72,
      73,    69,     0,     0,   103,   104,   102,   106,   107,   105,
     112,    99,   100,   101,   113,   114,     0,    22,    94,    89,
      84,     0,    19,     0,    45,     0,    34,    32,     0,    25,
      26,    33,    28,    27,    24,    30,    31,    29,     0,     0,
       0,     0,    51,    93,    88,    86,    87,    66,     0,    61,
       0,    55,     0,     0,    39,    40,    19,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,    43,     0,     0,
      50,     0,     0,    68,     0,    48,     0,    46,     0,     0,
       0,     0,     0,     0,     0,    19,    44,     0,    53,    65,
      62,    67,    35,    36,     0,     0,     0,    52,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    28,   134,   135,   136,   137,    62,   190,
     138,   139,   227,   236,   140,   141,   209,   142,   143,    22,
      23,    24,   222,   144,    26,    37,    38,   124,   125,    77,
     118,    72,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -169
static const yytype_int16 yypact[] =
{
      -3,  -169,   163,  -169,     5,     9,    18,    22,    33,     4,
       5,    31,  -169,  -169,     5,     5,     5,     5,     5,     5,
       5,     5,     8,     5,     5,     5,    13,     5,    32,    46,
     318,   318,    45,    48,   182,   326,    71,   -13,  -169,    53,
     318,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   103,
    -169,  -169,  -169,   318,   318,   318,   318,   318,  -169,     5,
    -169,    10,   182,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,    72,   302,    75,  -169,  -169,    76,   243,   318,
     318,   318,   318,   101,  -169,   182,   318,    82,  -169,   115,
     216,    94,    11,  -169,    99,   102,   104,   106,   109,  -169,
     343,   262,     5,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,     5,   110,   182,  -169,  -169,
    -169,  -169,  -169,     6,   113,   114,   254,  -169,  -169,    59,
    -169,     5,   318,   119,     5,   112,   119,   119,   119,   119,
     119,   119,   119,   119,   119,     5,   343,  -169,  -169,  -169,
    -169,  -169,   126,   116,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   117,  -169,   243,    95,
     101,   120,     5,   -12,    32,   122,  -169,  -169,   137,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   118,    -4,
     125,   216,   141,  -169,   155,  -169,  -169,  -169,   133,  -169,
     134,  -169,   138,   216,  -169,  -169,     5,   135,   318,    -6,
     167,  -169,   216,   182,   318,   142,   144,  -169,   147,   148,
    -169,   145,   161,   295,   165,  -169,   216,   204,   245,   201,
     169,   173,   182,   174,   179,     5,  -169,   187,  -169,  -169,
    -169,  -169,  -169,  -169,   183,   189,   216,  -169,   185,  -169
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,   -10,   230,   -43,   231,   232,  -169,  -169,
     234,   235,  -169,  -169,   236,   237,  -169,  -169,     1,   212,
    -169,  -169,    12,    17,  -169,  -169,   153,    73,  -168,  -169,
      77,   -19,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      39,    78,   196,    21,    41,    42,    43,    44,    45,    46,
      47,    48,    74,    50,    51,    52,    35,    58,   169,    25,
     219,    91,   100,   146,    88,   199,   211,   204,   205,   101,
       1,   200,    89,   220,    94,    95,    96,    97,    98,    27,
      53,    54,    55,    56,    29,    49,    64,    59,    36,    99,
      93,   170,   126,    30,    36,    36,    57,    31,    60,    61,
     119,   120,   121,   122,    32,    33,    40,   127,    34,   -64,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    75,    87,   168,    76,    79,    80,    81,    82,
     176,    90,   153,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    86,   -56,    59,   166,   -56,   -56,   102,   -56,
     -56,   115,   116,   175,   123,   -56,    92,   -56,   -56,   128,
     131,   174,     5,     6,   177,   132,     7,   129,   -56,   -56,
     145,     8,    61,    10,    11,   188,   147,   -56,   189,   148,
     194,   149,   -56,   150,   -23,   -23,   151,   167,   207,   171,
     172,   178,   202,   133,   191,   192,   203,   197,   -23,   201,
     215,   206,   198,     3,     4,   208,     5,     6,   210,   221,
       7,   212,   213,   214,   217,     8,     9,    10,    11,   169,
     223,   225,   226,   234,   230,   237,   238,   228,   229,   218,
      65,    66,    67,    68,    69,   224,   216,    12,    70,   223,
     231,   233,   131,   248,     5,     6,   239,   132,     7,   235,
     240,   242,   245,     8,    61,    10,    11,   131,   243,     5,
       6,   246,   132,     7,   249,   244,   247,   -23,     8,    61,
      10,    11,    14,    15,    16,   133,    17,    18,    19,    20,
     -23,    63,   130,   195,   241,   193,   131,     0,     5,     6,
     133,   132,     7,     0,     0,   -23,     0,     8,    61,    10,
      11,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     -23,     0,   103,   104,   105,   106,   107,   108,     0,   133,
     103,   104,   105,   106,   107,   108,     0,   109,   117,   110,
     111,   112,   113,   114,     0,     0,   173,     0,   109,   152,
     110,   111,   112,   113,   114,     0,   109,     0,   110,   111,
     112,   113,   114,   103,   104,   105,   106,   107,   108,     0,
     103,   104,   105,   106,   107,   108,    65,    66,    67,    68,
      69,     0,     0,     0,    70,    71,     0,     0,     0,   109,
     232,   110,   111,   112,   113,   114,   109,     0,   110,   111,
     112,   113,   114,    79,    80,    81,    82,     0,     0,     0,
       0,    83,     0,    84,     0,     0,     0,    85,     0,    86,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,    85,     0,    86
};

static const yytype_int16 yycheck[] =
{
      10,    34,   170,     2,    14,    15,    16,    17,    18,    19,
      20,    21,    31,    23,    24,    25,    12,    27,    12,     2,
      26,    40,    12,    12,    37,    37,   194,    31,    32,    62,
      33,    43,    45,    39,    53,    54,    55,    56,    57,    34,
      27,    28,    29,    30,    35,    37,    29,     1,    44,    59,
      49,    45,    85,    35,    44,    44,    43,    35,    12,    13,
      79,    80,    81,    82,    31,    32,    35,    86,    35,    37,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    37,    12,   117,    37,    27,    28,    29,    30,
     133,    38,   102,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    43,     0,     1,   115,     3,     4,    36,     6,
       7,    36,    36,   132,    13,    12,    13,    14,    15,    37,
       1,   131,     3,     4,   134,     6,     7,    12,    25,    26,
      36,    12,    13,    14,    15,   145,    37,    34,    12,    37,
      45,    37,    39,    37,    25,    26,    37,    37,   191,    36,
      36,    39,    15,    34,    38,    38,    38,    37,    39,    37,
     203,    36,   172,     0,     1,    24,     3,     4,    13,   212,
       7,    38,    38,    35,    39,    12,    13,    14,    15,    12,
     213,    39,    38,   226,    39,   228,   229,    40,    40,   208,
       8,     9,    10,    11,    12,   214,   206,    34,    16,   232,
      39,    36,     1,   246,     3,     4,    37,     6,     7,     5,
      37,    37,    25,    12,    13,    14,    15,     1,    39,     3,
       4,    38,     6,     7,    39,   235,    37,    26,    12,    13,
      14,    15,     2,     2,     2,    34,     2,     2,     2,     2,
      39,    29,    89,   170,   232,   168,     1,    -1,     3,     4,
      34,     6,     7,    -1,    -1,    39,    -1,    12,    13,    14,
      15,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      25,    -1,    18,    19,    20,    21,    22,    23,    -1,    34,
      18,    19,    20,    21,    22,    23,    -1,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    42,    -1,    44,    37,
      46,    47,    48,    49,    50,    -1,    44,    -1,    46,    47,
      48,    49,    50,    18,    19,    20,    21,    22,    23,    -1,
      18,    19,    20,    21,    22,    23,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    44,    -1,    46,    47,
      48,    49,    50,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35,    -1,    37,    -1,    -1,    -1,    41,    -1,    43,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    52,     0,     1,     3,     4,     7,    12,    13,
      14,    15,    34,    53,    55,    57,    58,    61,    62,    65,
      66,    69,    70,    71,    72,    74,    75,    34,    54,    35,
      35,    35,    31,    32,    35,    12,    44,    76,    77,    54,
      35,    54,    54,    54,    54,    54,    54,    54,    54,    37,
      54,    54,    54,    27,    28,    29,    30,    43,    54,     1,
      12,    13,    59,    70,    74,     8,     9,    10,    11,    12,
      16,    17,    82,    83,    82,    37,    37,    80,    83,    27,
      28,    29,    30,    35,    37,    41,    43,    12,    37,    45,
      38,    82,    13,    69,    82,    82,    82,    82,    82,    54,
      12,    83,    36,    18,    19,    20,    21,    22,    23,    44,
      46,    47,    48,    49,    50,    36,    36,    45,    81,    82,
      82,    82,    82,    13,    78,    79,    83,    82,    37,    12,
      77,     1,     6,    34,    55,    56,    57,    58,    61,    62,
      65,    66,    68,    69,    74,    36,    12,    37,    37,    37,
      37,    37,    37,    54,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    54,    37,    83,    12,
      45,    36,    36,    42,    54,    82,    56,    54,    39,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    54,    12,
      60,    38,    38,    81,    45,    78,    79,    37,    54,    37,
      43,    37,    15,    38,    31,    32,    36,    56,    24,    67,
      13,    79,    38,    38,    35,    56,    54,    39,    82,    26,
      39,    56,    73,    83,    82,    39,    38,    63,    40,    40,
      39,    39,    45,    36,    56,     5,    64,    56,    56,    37,
      37,    73,    37,    39,    54,    25,    38,    37,    56,    39
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 4:

/* Line 1455 of yacc.c  */
#line 101 "../src/integrador.y"
    { agregarErrorLexico((yyvsp[(1) - (1)].s.cadena));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 105 "../src/integrador.y"
    {my_line++;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 117 "../src/integrador.y"
    { yyerrok;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 123 "../src/integrador.y"
    {my_line++;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 124 "../src/integrador.y"
    {my_line++;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 144 "../src/integrador.y"
    {my_line++;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 146 "../src/integrador.y"
    {printf( "Se ha declarado una sentencia do-while \n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 149 "../src/integrador.y"
    {printf("Se ha declarado una sentencia for\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 158 "../src/integrador.y"
    {printf("Se ha incrementado la variable %s \n",(yyvsp[(1) - (2)].s.cadena));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 159 "../src/integrador.y"
    {printf("Se ha decrementado la variable %s\n",(yyvsp[(1) - (2)].s.cadena));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 163 "../src/integrador.y"
    {printf("Se ha incrementado la variable %s \n",(yyvsp[(1) - (3)].s.cadena));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 164 "../src/integrador.y"
    {printf("Se ha decrementado la variable %s\n",(yyvsp[(1) - (3)].s.cadena));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 168 "../src/integrador.y"
    {printf ("Se declaro un if \n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 169 "../src/integrador.y"
    { yyerrok; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 173 "../src/integrador.y"
    {printf ("Se declaron un else \n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 176 "../src/integrador.y"
    {printf ("Se declaro un while \n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 181 "../src/integrador.y"
    {printf ("Se declaro un switch \n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 186 "../src/integrador.y"
    {printf ("Se declaro un case \n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 187 "../src/integrador.y"
    {printf ("Se declaro el default \n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 191 "../src/integrador.y"
    {printf ("Se declaro un return \n ");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 199 "../src/integrador.y"
    { agregarIdentificador((yyvsp[(2) - (3)].s.cadena), (yyvsp[(1) - (3)].s.cadena));}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 201 "../src/integrador.y"
    {agregarIdentificador((yyvsp[(2) - (6)].s.cadena), (yyvsp[(1) - (6)].s.cadena));}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 202 "../src/integrador.y"
    { agregarIdentificador((yyvsp[(2) - (10)].s.cadena), (yyvsp[(1) - (10)].s.cadena));}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 203 "../src/integrador.y"
    {agregarIdentificador((yyvsp[(2) - (4)].s.cadena), (yyvsp[(1) - (4)].s.cadena));}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 204 "../src/integrador.y"
    { yyerrok; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 208 "../src/integrador.y"
    {printf ("Se declaro el desarrollo de una funcion ??? \n",  (yyvsp[(1) - (10)].s.cadena), (yyvsp[(2) - (10)].s.cadena));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 211 "../src/integrador.y"
    {agregarFuncion((yyvsp[(1) - (6)].s.cadena),(yyvsp[(2) - (6)].s.cadena));}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 219 "../src/integrador.y"
    {printf ("Se le asigno  %s y se le asigno el valor %s \n",(yyvsp[(1) - (4)].s.cadena),(yyvsp[(3) - (4)].s.cadena));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 220 "../src/integrador.y"
    {printf ("Se le asigno  %s y se le asigno su valor mas %s \n",(yyvsp[(1) - (4)].s.cadena),(yyvsp[(3) - (4)].s.cadena));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 221 "../src/integrador.y"
    {printf ("Se le asigno  %s y se le asigno su valor menos %s \n",(yyvsp[(1) - (4)].s.cadena),(yyvsp[(3) - (4)].s.cadena));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 222 "../src/integrador.y"
    {printf ("Se le asigno  %s y se le asigno su valor por %s \n",(yyvsp[(1) - (4)].s.cadena),(yyvsp[(3) - (4)].s.cadena));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 223 "../src/integrador.y"
    {printf ("Se le asigno  %s y se le asigno su valor dividido %s \n",(yyvsp[(1) - (4)].s.cadena),(yyvsp[(3) - (4)].s.cadena));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 238 "../src/integrador.y"
    {printf ("Se declaro una variable llamada %s \n",(yyvsp[(1) - (1)].s.cadena));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 239 "../src/integrador.y"
    {printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 240 "../src/integrador.y"
    {printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 241 "../src/integrador.y"
    {printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 242 "../src/integrador.y"
    {printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena));;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 243 "../src/integrador.y"
    {printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",(yyvsp[(1) - (3)].s.cadena),(yyvsp[(3) - (3)].s.cadena));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 248 "../src/integrador.y"
    { ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 276 "../src/integrador.y"
    {printf ("Se escribio una expresion usando una resta \n");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 277 "../src/integrador.y"
    {printf ("Se escribio una expresion con signo de desigualdad \n");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 278 "../src/integrador.y"
    {printf ("Se escribio una expresion con signo de desigualdad \n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 279 "../src/integrador.y"
    {printf ("Se escribio una expresion con signo de igualdad \n");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 280 "../src/integrador.y"
    {printf ("Se escribio una expresion con signo de desigualdad \n");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 281 "../src/integrador.y"
    {printf ("Se escribio una expresion con signo de desigualdad \n");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 282 "../src/integrador.y"
    {printf ("Se escribio una expresion con signo de distinto \n");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 283 "../src/integrador.y"
    {printf ("Se escribio una expresion con la operacion logica and \n");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 284 "../src/integrador.y"
    {printf ("Se escribio una expresion con la operacion logica or \n");;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 289 "../src/integrador.y"
    {printf ("Se escribio una expresion  \n");;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 290 "../src/integrador.y"
    {printf ("Se escribio una expresion  \n");;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 291 "../src/integrador.y"
    {printf ("Se escribio una expresion  \n");;}
    break;



/* Line 1455 of yacc.c  */
#line 1983 "integrador.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 299 "../src/integrador.y"


int main ()
{

	yyin=fopen("entrada.c","r");
	printf("antes de entrar al parser");
   	yyparse();
 
	printf("dsp de entrar al parser");
	#ifdef BISON_DEBUG
        yydebug = 1;
	#endif
	fclose(yyin);
	system("pause");
	//generarReporte();
	return 0;

}

