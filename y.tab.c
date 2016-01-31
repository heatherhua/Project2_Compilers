
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
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 11 "parser.y"


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine



/* Line 189 of yacc.c  */
#line 90 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Float = 261,
     T_LessEqual = 262,
     T_GreaterEqual = 263,
     T_Equal = 264,
     T_NotEqual = 265,
     T_Dims = 266,
     T_AndOp = 267,
     T_OrOp = 268,
     T_While = 269,
     T_For = 270,
     T_If = 271,
     T_Else = 272,
     T_Return = 273,
     T_Break = 274,
     T_Inc = 275,
     T_Dec = 276,
     T_Switch = 277,
     T_Case = 278,
     T_Default = 279,
     T_LeftParen = 280,
     T_RightParen = 281,
     T_Dot = 282,
     T_FieldSelection = 283,
     T_Vec2 = 284,
     T_Vec3 = 285,
     T_Vec4 = 286,
     T_Mat2 = 287,
     T_Mat3 = 288,
     T_Mat4 = 289,
     T_Continue = 290,
     T_Semicolon = 291,
     T_Colon = 292,
     T_Comma = 293,
     T_AddAssign = 294,
     T_MulAssign = 295,
     T_DivAssign = 296,
     T_SubAssign = 297,
     T_LeftBrace = 298,
     T_RightBrace = 299,
     T_Plus = 300,
     T_Dash = 301,
     T_Star = 302,
     T_Slash = 303,
     T_EqualOp = 304,
     T_LeftAngle = 305,
     T_RightAngle = 306,
     NO_ELSE = 307,
     T_Identifier = 308,
     T_IntConstant = 309,
     T_FloatConstant = 310,
     T_BoolConstant = 311
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Float 261
#define T_LessEqual 262
#define T_GreaterEqual 263
#define T_Equal 264
#define T_NotEqual 265
#define T_Dims 266
#define T_AndOp 267
#define T_OrOp 268
#define T_While 269
#define T_For 270
#define T_If 271
#define T_Else 272
#define T_Return 273
#define T_Break 274
#define T_Inc 275
#define T_Dec 276
#define T_Switch 277
#define T_Case 278
#define T_Default 279
#define T_LeftParen 280
#define T_RightParen 281
#define T_Dot 282
#define T_FieldSelection 283
#define T_Vec2 284
#define T_Vec3 285
#define T_Vec4 286
#define T_Mat2 287
#define T_Mat3 288
#define T_Mat4 289
#define T_Continue 290
#define T_Semicolon 291
#define T_Colon 292
#define T_Comma 293
#define T_AddAssign 294
#define T_MulAssign 295
#define T_DivAssign 296
#define T_SubAssign 297
#define T_LeftBrace 298
#define T_RightBrace 299
#define T_Plus 300
#define T_Dash 301
#define T_Star 302
#define T_Slash 303
#define T_EqualOp 304
#define T_LeftAngle 305
#define T_RightAngle 306
#define NO_ELSE 307
#define T_Identifier 308
#define T_IntConstant 309
#define T_FloatConstant 310
#define T_BoolConstant 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 41 "parser.y"

    int integerConstant;
    bool boolConstant;
    double floatConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
    VarDecl *vardecl;
    Stmt *stmt;
    List<Stmt*> *stmtList;
    Type *type;
    AssignExpr *assignExpr;
    FnDecl *fndecl;
    StmtBlock *stmtblock;
    Operator *op;
    Expr *expr;



/* Line 214 of yacc.c  */
#line 258 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 283 "y.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    17,    20,
      24,    27,    31,    33,    36,    38,    40,    42,    44,    46,
      48,    50,    52,    55,    59,    61,    63,    65,    67,    69,
      71,    73,    75,    77,    79,    82,    84,    86,    89,    93,
      97,   100,   102,   104,   107,   109,   111,   115,   117,   119,
     123,   125,   129,   131,   135,   139,   141,   145,   149,   153,
     157,   159,   163,   167,   169,   173,   177,   179,   182,   185,
     188,   190,   192,   194,   198,   201,   204,   206,   208,   210,
     212,   216,   222,   226,   228,   230,   232,   240,   242,   244,
     248,   251,   257,   264,   266,   268,   270,   275,   277,   279,
     281,   284,   288,   290
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    60,    61,    -1,    61,    -1,
      62,    -1,    68,    -1,    70,    63,    -1,    43,    44,    -1,
      43,    65,    44,    -1,    43,    44,    -1,    43,    65,    44,
      -1,    66,    -1,    65,    66,    -1,    64,    -1,    67,    -1,
      68,    -1,    75,    -1,    89,    -1,    92,    -1,    94,    -1,
      95,    -1,    70,    36,    -1,    69,    53,    36,    -1,     3,
      -1,     4,    -1,     6,    -1,     5,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,    71,
      26,    -1,    73,    -1,    72,    -1,    73,    74,    -1,    72,
      38,    74,    -1,    69,    53,    25,    -1,    69,    53,    -1,
      69,    -1,    36,    -1,    76,    36,    -1,    77,    -1,    78,
      -1,    53,     9,    54,    -1,    79,    -1,    80,    -1,    79,
      13,    80,    -1,    81,    -1,    80,    12,    81,    -1,    82,
      -1,    81,    49,    82,    -1,    81,    10,    82,    -1,    83,
      -1,    82,    50,    83,    -1,    82,    51,    83,    -1,    82,
       7,    83,    -1,    82,     8,    83,    -1,    84,    -1,    83,
      45,    84,    -1,    83,    46,    84,    -1,    85,    -1,    84,
      47,    85,    -1,    84,    48,    85,    -1,    87,    -1,    20,
      85,    -1,    21,    85,    -1,    86,    85,    -1,    45,    -1,
      46,    -1,    88,    -1,    87,    27,    28,    -1,    87,    20,
      -1,    87,    21,    -1,    53,    -1,    54,    -1,    55,    -1,
      56,    -1,    25,    76,    26,    -1,    16,    25,    76,    26,
      90,    -1,    91,    17,    91,    -1,    91,    -1,    63,    -1,
      67,    -1,    22,    25,    76,    26,    43,    93,    44,    -1,
      65,    -1,    57,    -1,    23,    76,    37,    -1,    24,    37,
      -1,    14,    25,    97,    26,    96,    -1,    15,    25,    99,
     100,    26,    96,    -1,    63,    -1,    67,    -1,    76,    -1,
      69,    53,     9,    98,    -1,    77,    -1,    75,    -1,    68,
      -1,   101,    36,    -1,   101,    36,    76,    -1,    97,    -1,
      57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   139,   140,   144,   146,   150,   153,   154,
     159,   160,   163,   168,   171,   172,   177,   178,   179,   180,
     181,   182,   191,   193,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   211,   214,   215,   220,   221,   224,
     230,   232,   243,   244,   247,   251,   254,   267,   271,   272,
     279,   280,   286,   287,   291,   298,   299,   304,   309,   314,
     319,   320,   323,   328,   329,   332,   338,   339,   343,   347,
     350,   351,   354,   355,   358,   361,   366,   368,   369,   370,
     371,   382,   386,   389,   394,   395,   406,   411,   413,   424,
     425,   435,   437,   441,   442,   445,   446,   450,   455,   456,
     459,   460,   463,   465
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Float",
  "T_LessEqual", "T_GreaterEqual", "T_Equal", "T_NotEqual", "T_Dims",
  "T_AndOp", "T_OrOp", "T_While", "T_For", "T_If", "T_Else", "T_Return",
  "T_Break", "T_Inc", "T_Dec", "T_Switch", "T_Case", "T_Default",
  "T_LeftParen", "T_RightParen", "T_Dot", "T_FieldSelection", "T_Vec2",
  "T_Vec3", "T_Vec4", "T_Mat2", "T_Mat3", "T_Mat4", "T_Continue",
  "T_Semicolon", "T_Colon", "T_Comma", "T_AddAssign", "T_MulAssign",
  "T_DivAssign", "T_SubAssign", "T_LeftBrace", "T_RightBrace", "T_Plus",
  "T_Dash", "T_Star", "T_Slash", "T_EqualOp", "T_LeftAngle",
  "T_RightAngle", "NO_ELSE", "T_Identifier", "T_IntConstant",
  "T_FloatConstant", "T_BoolConstant", "\";\"", "$accept", "Program",
  "DeclList", "Decl", "FnDef", "CompoundStmtNoNewScope",
  "CompoundStmtWithScope", "StmtList", "Stmt", "SimpleStmt", "VarDecl",
  "TypeSpecifier", "FnPrototype", "FnDeclarator", "FnHeaderWithParameters",
  "FnHeader", "ParameterDecl", "ExprStmt", "Expr", "AssignExpr",
  "ConditionalExpr", "LogicalOrExpr", "LogicalAndExpr", "EqualExpr",
  "RelationalExpr", "AddExpr", "MultExpr", "UnaryExpr", "UnaryOp",
  "PostfixExpr", "PrimExpr", "SelectionStmt", "SelectionRestStmt",
  "StmtWithScope", "SwitchStmt", "SwitchStmtList", "CaseLabel", "IterStmt",
  "StmtNoNewScope", "Condition", "Initializer", "ForInitStmt",
  "ForRestStmt", "Conditionopt", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    79,    79,
      80,    80,    81,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    83,    84,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    90,    90,    91,    91,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    99,    99,
     100,   100,   101,   101
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     2,     3,
       2,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     3,     3,
       2,     1,     1,     2,     1,     1,     3,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     2,     2,     2,
       1,     1,     1,     3,     2,     2,     1,     1,     1,     1,
       3,     5,     3,     1,     1,     1,     7,     1,     1,     3,
       2,     5,     6,     1,     1,     1,     4,     1,     1,     1,
       2,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    25,    27,    26,    28,    29,    30,    31,    32,
      33,     0,     2,     4,     5,     6,     0,     0,     0,    36,
      35,     1,     3,     0,    22,     0,     7,    34,     0,    41,
      37,    39,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     8,    70,    71,    76,    77,    78,
      79,    14,     0,    12,    15,    16,     0,    17,     0,    44,
      45,    47,    48,    50,    52,    55,    60,    63,     0,    66,
      72,    18,    19,    20,    21,    38,    40,     0,     0,     0,
      76,    67,    68,     0,     0,    90,     0,    10,     0,     0,
       9,    13,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    74,    75,     0,     0,
      95,     0,    99,    98,     0,     0,     0,    89,    80,    11,
      46,    49,    51,    54,    53,    58,    59,    56,    57,    61,
      62,    64,    65,    73,     0,     0,   103,   102,     0,     0,
       0,     0,     0,    93,    94,    91,     0,   100,    84,    85,
      81,    83,     0,    97,    96,    92,   101,     0,    88,    87,
       0,    82,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,   143,    51,    52,    53,    54,
      55,    16,    56,    18,    19,    20,    30,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   150,   151,    72,   160,    73,    74,   145,   111,
     154,   114,   138,   139
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -122
static const yytype_int16 yypact[] =
{
      63,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,    13,    63,  -122,  -122,  -122,   -21,   -10,    11,    -3,
      63,  -122,  -122,    -5,  -122,   200,  -122,  -122,    63,   -13,
    -122,  -122,  -122,    17,    21,    35,     3,     3,    56,     9,
      45,     9,  -122,   244,  -122,  -122,  -122,    74,  -122,  -122,
    -122,  -122,   288,  -122,  -122,  -122,    49,  -122,    50,  -122,
    -122,    75,    77,     1,     2,   -24,   -31,  -122,     3,    24,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,   501,   464,     9,
    -122,  -122,  -122,     9,    53,  -122,    61,  -122,   332,    37,
    -122,  -122,  -122,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,  -122,  -122,  -122,    71,    47,
    -122,    76,  -122,  -122,   156,    78,    79,  -122,  -122,  -122,
    -122,    77,     1,     2,     2,   -24,   -24,   -24,   -24,   -31,
     -31,  -122,  -122,  -122,    92,   376,  -122,  -122,    80,    67,
     376,    64,     9,  -122,  -122,  -122,   376,     9,  -122,  -122,
    -122,    91,   112,  -122,  -122,  -122,  -122,   376,  -122,   420,
      68,  -122,  -122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -122,  -122,  -122,   101,  -122,   -17,  -122,   -42,   -50,  -121,
       6,   -16,    15,  -122,  -122,  -122,    86,    41,   -36,   -20,
    -122,  -122,    27,    30,   -19,   -27,   -22,   -29,  -122,  -122,
    -122,  -122,  -122,   -32,  -122,  -122,  -122,  -122,   -25,    16,
    -122,  -122,  -122,  -122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      26,    88,    91,    84,    29,    86,    15,    81,    82,    97,
      98,    95,    29,    21,   144,    17,   103,   104,    15,   149,
      31,   101,   102,    36,    37,   144,    24,    17,    41,    36,
      37,    32,    23,    25,    41,    28,   149,    27,    91,   105,
      76,   110,    77,   115,   106,   107,    78,   116,    45,    46,
      96,   108,    99,   100,    45,    46,    80,    48,    49,    50,
      79,   109,    47,    48,    49,    50,     1,     2,     3,     4,
     125,   126,   127,   128,   131,   132,   123,   124,   110,   129,
     130,    83,    85,    89,   112,    24,    92,   118,    93,    94,
     117,   120,     5,     6,     7,     8,     9,    10,   109,   133,
     134,   142,   135,   147,   140,   141,   146,   152,   157,    91,
     159,   156,   162,    22,    75,     1,     2,     3,     4,   113,
     121,   155,   153,   148,   122,   161,    33,    34,    35,     0,
     137,     0,    36,    37,    38,    39,    40,    41,     0,     0,
     148,     5,     6,     7,     8,     9,    10,     0,    42,     0,
       0,     0,     0,     0,     0,    43,     0,    45,    46,     1,
       2,     3,     4,     0,     0,    47,    48,    49,    50,   158,
       0,     0,     0,     0,     0,     0,    36,    37,     0,     0,
       0,    41,     0,     0,     0,     5,     6,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    46,     1,     2,     3,     4,     0,     0,    47,
      48,    49,    50,   136,    33,    34,    35,     0,     0,     0,
      36,    37,    38,    39,    40,    41,     0,     0,     0,     5,
       6,     7,     8,     9,    10,     0,    42,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,     1,     2,     3,
       4,     0,     0,    47,    48,    49,    50,     0,    33,    34,
      35,     0,     0,     0,    36,    37,    38,    39,    40,    41,
       0,     0,     0,     5,     6,     7,     8,     9,    10,     0,
      42,     0,     0,     0,     0,     0,     0,    43,    87,    45,
      46,     1,     2,     3,     4,     0,     0,    47,    48,    49,
      50,     0,    33,    34,    35,     0,     0,     0,    36,    37,
      38,    39,    40,    41,     0,     0,     0,     5,     6,     7,
       8,     9,    10,     0,    42,     0,     0,     0,     0,     0,
       0,    43,    90,    45,    46,     1,     2,     3,     4,     0,
       0,    47,    48,    49,    50,     0,    33,    34,    35,     0,
       0,     0,    36,    37,    38,    39,    40,    41,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,    42,     0,
       0,     0,     0,     0,     0,    43,   119,    45,    46,     1,
       2,     3,     4,     0,     0,    47,    48,    49,    50,     0,
      33,    34,    35,     0,     0,     0,    36,    37,    38,    39,
      40,    41,     0,     0,     0,     5,     6,     7,     8,     9,
      10,     0,    42,     0,     0,     0,     0,     0,     0,    25,
       0,    45,    46,     1,     2,     3,     4,     0,     0,    47,
      48,    49,    50,     0,    33,    34,    35,     0,     0,     0,
      36,    37,    38,    39,    40,    41,     0,     0,     0,     5,
       6,     7,     8,     9,    10,     0,    42,     0,     0,     0,
       0,     0,     0,    43,     0,    45,    46,     1,     2,     3,
       4,     0,     0,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,    36,    37,     0,     0,     0,    41,
       0,     0,     0,     5,     6,     7,     8,     9,    10,     0,
      42,     0,     0,     0,     1,     2,     3,     4,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    47,    48,    49,
      50,    36,    37,     0,     0,     0,    41,     0,     0,     0,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,    47,    48,    49,    50
};

static const yytype_int16 yycheck[] =
{
      17,    43,    52,    39,    20,    41,     0,    36,    37,     7,
       8,    10,    28,     0,   135,     0,    47,    48,    12,   140,
      25,    45,    46,    20,    21,   146,    36,    12,    25,    20,
      21,    36,    53,    43,    25,    38,   157,    26,    88,    68,
      53,    77,    25,    79,    20,    21,    25,    83,    45,    46,
      49,    27,    50,    51,    45,    46,    53,    54,    55,    56,
      25,    77,    53,    54,    55,    56,     3,     4,     5,     6,
      97,    98,    99,   100,   103,   104,    95,    96,   114,   101,
     102,    25,    37,     9,    78,    36,    36,    26,    13,    12,
      37,    54,    29,    30,    31,    32,    33,    34,   114,    28,
      53,     9,    26,    36,    26,    26,    26,    43,    17,   159,
     152,   147,    44,    12,    28,     3,     4,     5,     6,    78,
      93,   146,   142,   140,    94,   157,    14,    15,    16,    -1,
     114,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
     157,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,     3,
       4,     5,     6,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,     3,     4,     5,     6,    -1,    -1,    53,
      54,    55,    56,    57,    14,    15,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,     3,     4,     5,
       6,    -1,    -1,    53,    54,    55,    56,    -1,    14,    15,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,     3,     4,     5,     6,    -1,    -1,    53,    54,    55,
      56,    -1,    14,    15,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,     3,     4,     5,     6,    -1,
      -1,    53,    54,    55,    56,    -1,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,     3,
       4,     5,     6,    -1,    -1,    53,    54,    55,    56,    -1,
      14,    15,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,     3,     4,     5,     6,    -1,    -1,    53,
      54,    55,    56,    -1,    14,    15,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,     3,     4,     5,
       6,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    20,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    29,    30,    31,    32,    33,
      34,    59,    60,    61,    62,    68,    69,    70,    71,    72,
      73,     0,    61,    53,    36,    43,    63,    26,    38,    69,
      74,    25,    36,    14,    15,    16,    20,    21,    22,    23,
      24,    25,    36,    43,    44,    45,    46,    53,    54,    55,
      56,    64,    65,    66,    67,    68,    70,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    92,    94,    95,    74,    53,    25,    25,    25,
      53,    85,    85,    25,    76,    37,    76,    44,    65,     9,
      44,    66,    36,    13,    12,    10,    49,     7,     8,    50,
      51,    45,    46,    47,    48,    85,    20,    21,    27,    69,
      76,    97,    68,    75,    99,    76,    76,    37,    26,    44,
      54,    80,    81,    82,    82,    83,    83,    83,    83,    84,
      84,    85,    85,    28,    53,    26,    57,    97,   100,   101,
      26,    26,     9,    63,    67,    96,    26,    36,    63,    67,
      90,    91,    43,    77,    98,    96,    76,    17,    57,    65,
      93,    91,    44
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { 
                                                    (yylsp[(1) - (1)]); 
                                                    /* pp2: The @1 is needed to convince 
                                                     * yacc to set up yylloc. You can remove 
                                                     * it once you have other uses of @n*/
                                                    Program *program = new Program((yyvsp[(1) - (1)].declList));
                                                    // if no errors, advance to next phase
                                                    if (ReportError::NumErrors() == 0) 
                                                        program->Print(0);
                                                  }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { printf("FnDef\n"); (yyvsp[(1) - (2)].fndecl)->SetFunctionBody(new StmtBlock(new List<VarDecl*>, new List<Stmt*>)); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval.stmtblock) = new StmtBlock(new List<VarDecl*>, new List<Stmt*>);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { printf("Compound Num Elements: %d\n", (yyvsp[(2) - (3)].stmtList)->NumElements()); 
                                                             (yyval.stmtblock) = new StmtBlock(new List<VarDecl*>, (yyvsp[(2) - (3)].stmtList)); 
                                                             printf("Num Elements: %d\n", (yyvsp[(2) - (3)].stmtList)->NumElements());}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { (yyval.stmtblock) = new StmtBlock(new List<VarDecl*>, new List<Stmt*>); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { printf("compound scope \n"); (yyval.stmtblock) = new StmtBlock(new List<VarDecl*>, (yyvsp[(2) - (3)].stmtList)); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {   List<Stmt*> *stmtList = new List<Stmt*>;
                    stmtList->Append((yyvsp[(1) - (1)].stmt));
                    (yyval.stmtList) = stmtList;
//                    ($$ = new List<Stmt*>)->Append($1); 
                    printf("Num Elements: %d\n", (yyval.stmtList)->NumElements());}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { ((yyval.stmtList)=(yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].stmt));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { printf("I am expr\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {(yyval.vardecl) = new VarDecl(new Identifier(yylloc, (yyvsp[(2) - (3)].identifier)), (yyvsp[(1) - (3)].type)); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { (yyval.type) = Type::voidType;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    { (yyval.type) = Type::boolType;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { (yyval.type) = Type::floatType;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    { (yyval.type) = Type::intType; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { (yyval.type) = Type::vec2Type;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval.type) = Type::vec3Type;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    { (yyval.type) = Type::vec4Type;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    { (yyval.type) = Type::mat2Type;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    { (yyval.type) = Type::mat3Type;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    { (yyval.type) = Type::mat4Type;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    { }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { (yyvsp[(1) - (2)].fndecl)->AddFormal((yyvsp[(2) - (2)].vardecl));}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { (yyvsp[(1) - (3)].fndecl)->AddFormal((yyvsp[(3) - (3)].vardecl)); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { (yyval.fndecl) = new FnDecl(new Identifier(yylloc, (yyvsp[(2) - (3)].identifier)), (yyvsp[(1) - (3)].type), new List<VarDecl*>);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    { (yyval.vardecl) = new VarDecl( new Identifier(yylloc, (yyvsp[(2) - (2)].identifier)), (yyvsp[(1) - (2)].type)); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { printf("Reaches Expr statement\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { printf( "Reaches Assign Expr \n"); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    { 
                         Operator *op = new Operator(yylloc, "=");       
                         printf("got here\n"); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    {}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    {}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {
                                const char *tok = "||";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {
                                const char *tok = "&&";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr)); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    {}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    { 
                                const char *tok = "==";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    {
                                const char *tok = "!=";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    { 
                                const char *tok = "<";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                            }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    {
                                const char *tok = ">";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {
                                const char *tok = "<=";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {
                                const char *tok = ">=";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    {}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {  const char *tok = "+";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { const char *tok = "-";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { const char *tok = "*";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 332 "parser.y"
    { const char *tok = "/";
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    {}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 339 "parser.y"
    {   const char *tok = "++"; 
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new LogicalExpr(op, (yyvsp[(2) - (2)].expr));
                            }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 343 "parser.y"
    {   const char *tok = "--"; 
                                Operator *op = new Operator(yylloc, tok);
                                (yyval.expr) = new LogicalExpr(op, (yyvsp[(2) - (2)].expr));
                            }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 347 "parser.y"
    { (yyval.expr) = new LogicalExpr((yyvsp[(1) - (2)].op), (yyvsp[(2) - (2)].expr));}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 350 "parser.y"
    { const char *tok = "+"; (yyval.op) = new Operator(yylloc, tok);}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    { const char *tok = "-"; (yyval.op) = new Operator(yylloc, tok);}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 354 "parser.y"
    {}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 355 "parser.y"
    { 
                                    const char *text = &yytext[2];
                                    (yyval.expr) = new FieldAccess((yyvsp[(1) - (3)].expr), new Identifier(yylloc, text));}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 358 "parser.y"
    {   const char *tok = "++";
                                    Operator *op = new Operator(yylloc, tok);
                                    (yyval.expr) = new PostfixExpr((yyvsp[(1) - (2)].expr), op);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {   const char *tok = "--";
                                    Operator *op = new Operator(yylloc, tok);
                                    (yyval.expr) = new PostfixExpr((yyvsp[(1) - (2)].expr), op);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 366 "parser.y"
    { printf("got to primexpr"); 
                            (yyval.expr) = new FieldAccess(new EmptyExpr(), new Identifier(yylloc,(yyvsp[(1) - (1)].identifier)));}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 368 "parser.y"
    { (yyval.expr) = new IntConstant(yylloc, (yyvsp[(1) - (1)].integerConstant));}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    { (yyval.expr) = new FloatConstant(yylloc, (yyvsp[(1) - (1)].floatConstant)); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    { (yyval.expr) = new BoolConstant(yylloc, (yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 382 "parser.y"
    { 
                (yyval.stmt) = new IfStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmtList)->Nth(0), (yyvsp[(5) - (5)].stmtList)->Nth(1)); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    { 
                                ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (3)].stmt));
                                (yyval.stmtList)->Append((yyvsp[(3) - (3)].stmt));}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    { 
                                ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].stmt)); 
                                (yyval.stmtList)->Append(NULL); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 394 "parser.y"
    {}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 395 "parser.y"
    {}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 407 "parser.y"
    {}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 411 "parser.y"
    {}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    {printf("EMPTY");}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 424 "parser.y"
    {}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 425 "parser.y"
    {}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 436 "parser.y"
    {}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 438 "parser.y"
    {}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    {}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 442 "parser.y"
    {}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 445 "parser.y"
    {}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 450 "parser.y"
    {}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 455 "parser.y"
    {}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 456 "parser.y"
    {}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 459 "parser.y"
    {}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 460 "parser.y"
    {}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 463 "parser.y"
    {}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 465 "parser.y"
    {}
    break;



/* Line 1455 of yacc.c  */
#line 2537 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
#line 533 "parser.y"



/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}

