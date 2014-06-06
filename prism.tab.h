/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
     INICIO = 258,
     FIN = 259,
     ESCENA = 260,
     _2D = 261,
     _3D = 262,
     DIBUJAR = 263,
     RELLENAR = 264,
     ROTAR = 265,
     TRASLADAR = 266,
     ESCALAR = 267,
     SOBRE = 268,
     FONDO = 269,
     PTO_FLOT = 270,
     COLOR = 271,
     VECT2D = 272,
     VECT3D = 273,
     FLOTANTE = 274,
     PUNTO = 275,
     RECTA = 276,
     CURVA = 277,
     PLANO = 278,
     TRIANGULO = 279,
     CUADRILATERO = 280,
     ELIPSE = 281,
     CIRCUNFERENCIA = 282,
     PARABOLA = 283,
     HIPERBOLA = 284,
     POLIEDRO = 285,
     CILINDRO = 286,
     CONO = 287,
     ESFERA = 288,
     COLOR_PREDEF = 289,
     ID = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 31 "/home/jesus/Workspace/Prism-geom/prism.y"

        float* fval;
        QString* string;
        std::vector<Sentence*>* sentence_list;
        Sentence* sentence;
        Declaration* declaration;
        Asignation* asignation;
        Function* function;
        Draw* draw;
        Background* background;
        Fill* fill;
        Rotate* rotate;
        Translate* translate;
        Scale* scale;
        Param* param;
        Vect* vect;
        Vect2d* vect2d;
        Vect3d* vect3d;
        Color * color;
        Expresion* expresion;



/* Line 2068 of yacc.c  */
#line 109 "/home/jesus/Workspace/Prism-geom/prism.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


