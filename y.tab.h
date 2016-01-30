
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
     T_Identifier = 307,
     T_IntConstant = 308,
     T_FloatConstant = 309,
     T_BoolConstant = 310
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
#define T_Identifier 307
#define T_IntConstant 308
#define T_FloatConstant 309
#define T_BoolConstant 310




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 41 "parser.y"

    int integerConstant;
    bool boolConstant;
    double floatConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
    Stmt *stmt;
    List<Stmt*> *stmtList;
    Type *type;
    AssignExpr *assignExpr;



/* Line 1676 of yacc.c  */
#line 177 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;

