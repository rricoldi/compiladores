/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    ADD = 260,
    SUB = 261,
    MULTIPLY = 262,
    DIV = 263,
    POWER = 264,
    REMAINDER = 265,
    L_PAREN = 266,
    R_PAREN = 267,
    L_SQUARE_BRACKET = 268,
    R_SQUARE_BRACKET = 269,
    SEN = 270,
    COS = 271,
    TAN = 272,
    ABS = 273,
    NUM_INTEGER = 274,
    NUM_REAL = 275,
    VARIABLE = 276,
    EOL = 277,
    END_OF_FILE = 278,
    LEXICAL_ERROR = 279,
    SHOW = 280,
    SETTINGS = 281,
    RESET = 282,
    QUIT = 283,
    SET = 284,
    H_VIEW = 285,
    V_VIEW = 286,
    AXIS = 287,
    ON = 288,
    OFF = 289,
    PLOT = 290,
    INTEGRAL_STEPS = 291,
    INTEGRATE = 292,
    MATRIX = 293,
    SOLVE = 294,
    DETERMINANT = 295,
    LINEAR_SYSTEM = 296,
    ABOUT = 297,
    ASSIGN = 298,
    SEMICOLON = 299,
    COLON = 300,
    COMMA = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "sintatico.y"

    int integer;
    float real;
    void* ast;

#line 110 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
