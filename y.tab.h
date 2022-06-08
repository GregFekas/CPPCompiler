
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
     ANDOP = 258,
     NOTOP = 259,
     OROP = 260,
     ADDOP = 261,
     RELOP = 262,
     MULOP = 263,
     LPAREN = 264,
     RPAREN = 265,
     COMMA = 266,
     INCDEC = 267,
     ASSIGN = 268,
     LBRACE = 269,
     RBRACE = 270,
     LBRACK = 271,
     RBRACK = 272,
     SEMI = 273,
     INP = 274,
     OUT = 275,
     METH = 276,
     COLON = 277,
     DOT = 278,
     REFER = 279,
     EQUOP = 280,
     TYPEDEF = 281,
     CHAR = 282,
     INT = 283,
     FLOAT = 284,
     CONST = 285,
     UNION = 286,
     CLASS = 287,
     PRIVATE = 288,
     PROTECTED = 289,
     PUBLIC = 290,
     STATIC = 291,
     VOID = 292,
     LIST = 293,
     CONTINUE = 294,
     BREAK = 295,
     THIS = 296,
     IF = 297,
     ELSE = 298,
     WHILE = 299,
     FOR = 300,
     RETURN = 301,
     LENGTH = 302,
     NEW = 303,
     CIN = 304,
     COUT = 305,
     MAIN = 306,
     SIZEOP = 307,
     ICONST = 308,
     FCONST = 309,
     CCONST = 310,
     ID = 311,
     LISTFUNC = 312,
     STRING = 313
   };
#endif
/* Tokens.  */
#define ANDOP 258
#define NOTOP 259
#define OROP 260
#define ADDOP 261
#define RELOP 262
#define MULOP 263
#define LPAREN 264
#define RPAREN 265
#define COMMA 266
#define INCDEC 267
#define ASSIGN 268
#define LBRACE 269
#define RBRACE 270
#define LBRACK 271
#define RBRACK 272
#define SEMI 273
#define INP 274
#define OUT 275
#define METH 276
#define COLON 277
#define DOT 278
#define REFER 279
#define EQUOP 280
#define TYPEDEF 281
#define CHAR 282
#define INT 283
#define FLOAT 284
#define CONST 285
#define UNION 286
#define CLASS 287
#define PRIVATE 288
#define PROTECTED 289
#define PUBLIC 290
#define STATIC 291
#define VOID 292
#define LIST 293
#define CONTINUE 294
#define BREAK 295
#define THIS 296
#define IF 297
#define ELSE 298
#define WHILE 299
#define FOR 300
#define RETURN 301
#define LENGTH 302
#define NEW 303
#define CIN 304
#define COUT 305
#define MAIN 306
#define SIZEOP 307
#define ICONST 308
#define FCONST 309
#define CCONST 310
#define ID 311
#define LISTFUNC 312
#define STRING 313




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "bisonas.y"

char *string;
char *listfunc;
char *id;
int iconst;
char *fconst;
char cconst;



/* Line 1676 of yacc.c  */
#line 179 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


