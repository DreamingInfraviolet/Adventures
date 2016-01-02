/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_FYY_GRAMMAR_TAB_HPP_INCLUDED
# define YY_FYY_GRAMMAR_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef FYYDEBUG
# if defined YYDEBUG
#  if YYDEBUG
#   define FYYDEBUG 1
#  else
#   define FYYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define FYYDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined FYYDEBUG */
#if FYYDEBUG
extern int fyydebug;
#endif

/* Tokens.  */
#ifndef FYYTOKENTYPE
# define FYYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum fyytokentype {
     tdiv = 258,
     tbracket_curly_open = 259,
     tbracket_curly_close = 260,
     tbracket_square_open = 261,
     tbracket_square_close = 262,
     tscene = 263,
     tignore = 264,
     tchoice = 265,
     tgoto = 266,
     tfullstop = 267,
     tidentifier = 268,
     tstring = 269
   };
#endif


#if ! defined FYYSTYPE && ! defined FYYSTYPE_IS_DECLARED
typedef union FYYSTYPE
{
/* Line 2058 of yacc.c  */
#line 33 "Grammar.ypp"

    std::string*         stringval;
    char*                charstrval;
    Section*             sectionval;
    String*              fstringval;
    Scene*               sceneval;
    std::vector<Choice*>* choicevectorval;
    Choice*              choiceval;
    int                  intval;
    Header*              headerval;
    Destination*         destinationval;


/* Line 2058 of yacc.c  */
#line 93 "Grammar.tab.hpp"
} FYYSTYPE;
# define FYYSTYPE_IS_TRIVIAL 1
# define fyystype FYYSTYPE /* obsolescent; will be withdrawn */
# define FYYSTYPE_IS_DECLARED 1
#endif

#if ! defined FYYLTYPE && ! defined FYYLTYPE_IS_DECLARED
typedef struct FYYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} FYYLTYPE;
# define fyyltype FYYLTYPE /* obsolescent; will be withdrawn */
# define FYYLTYPE_IS_DECLARED 1
# define FYYLTYPE_IS_TRIVIAL 1
#endif

extern FYYSTYPE fyylval;
extern FYYLTYPE fyylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int fyyparse (void *YYPARSE_PARAM);
#else
int fyyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int fyyparse (void);
#else
int fyyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_FYY_GRAMMAR_TAB_HPP_INCLUDED  */
