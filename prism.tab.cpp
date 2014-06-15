/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "/home/jesus/Workspace/Prism-geom/prism.y"

    #include <stdio.h>
    #include <QString>
    #include <QHash>
    #include "ast.h"

    //FLEX + BISON variables
    extern int yylex();
    extern char*yytext;
    extern int yyparse();
    extern FILE *yyin;
    extern int line;

    int errors = 0;

    void check_or_insert(QString,DATATYPE,DataType *);
    bool check(QString);
    //QT interface variable;
    QString syntax;

    //Error handling function
    void yyerror(const char *s);

    //ast root
    Root *root;

    //symbol table
    QHash<QString,Identifier*> symbols;


/* Line 268 of yacc.c  */
#line 102 "/home/jesus/Workspace/Prism-geom/prism.tab.cpp"

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
     EJE = 268,
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

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 197 "/home/jesus/Workspace/Prism-geom/prism.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 209 "/home/jesus/Workspace/Prism-geom/prism.tab.cpp"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   313

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNRULES -- Number of states.  */
#define YYNSTATES  216

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    43,    41,    39,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    13,    19,    21,    24,    27,    30,
      33,    37,    41,    45,    49,    55,    63,    73,    81,    91,
     103,   113,   121,   129,   139,   147,   157,   167,   175,   179,
     181,   185,   189,   193,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   220,   225,   230,   236,   240,
     244,   254,   256,   262
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,     3,    49,     4,    -1,     3,     5,     6,
      49,     4,    -1,     3,     5,     7,    49,     4,    -1,    50,
      -1,    49,    50,    -1,    51,    36,    -1,    52,    36,    -1,
      55,    36,    -1,    19,    35,    15,    -1,    17,    35,    62,
      -1,    18,    35,    63,    -1,    16,    35,    61,    -1,    20,
      35,    37,    54,    38,    -1,    21,    35,    37,    54,    39,
      54,    38,    -1,    22,    35,    37,    54,    39,    54,    39,
      54,    38,    -1,    23,    35,    37,    54,    39,    54,    38,
      -1,    24,    35,    37,    54,    39,    54,    39,    54,    38,
      -1,    25,    35,    37,    54,    39,    54,    39,    54,    39,
      54,    38,    -1,    26,    35,    37,    54,    39,    54,    39,
      54,    38,    -1,    27,    35,    37,    54,    39,    54,    38,
      -1,    28,    35,    37,    54,    39,    54,    38,    -1,    29,
      35,    37,    54,    39,    54,    39,    54,    38,    -1,    30,
      35,    37,    54,    39,    54,    38,    -1,    31,    35,    37,
      54,    39,    54,    39,    54,    38,    -1,    32,    35,    37,
      54,    39,    54,    39,    54,    38,    -1,    33,    35,    37,
      54,    39,    54,    38,    -1,    35,    40,    53,    -1,    54,
      -1,    54,    41,    54,    -1,    54,    42,    54,    -1,    54,
      43,    54,    -1,    54,    44,    54,    -1,    61,    -1,    15,
      -1,    62,    -1,    63,    -1,    35,    -1,    56,    -1,    57,
      -1,    58,    -1,    60,    -1,    59,    -1,    14,    54,    -1,
       8,    35,    16,    54,    -1,     9,    35,    16,    54,    -1,
      10,    35,    13,    54,    54,    -1,    12,    35,    54,    -1,
      11,    35,    54,    -1,    45,    15,    39,    15,    39,    15,
      39,    15,    46,    -1,    34,    -1,    45,    15,    39,    15,
      46,    -1,    45,    15,    39,    15,    39,    15,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    86,    89,    93,    94,    97,    98,    99,
     102,   104,   106,   108,   111,   116,   122,   135,   141,   148,
     156,   163,   169,   175,   182,   188,   195,   202,   209,   214,
     215,   217,   219,   221,   225,   226,   227,   228,   229,   232,
     233,   234,   235,   236,   237,   240,   252,   266,   280,   295,
     310,   320,   323,   326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INICIO", "FIN", "ESCENA", "_2D", "_3D",
  "DIBUJAR", "RELLENAR", "ROTAR", "TRASLADAR", "ESCALAR", "EJE", "FONDO",
  "PTO_FLOT", "COLOR", "VECT2D", "VECT3D", "FLOTANTE", "PUNTO", "RECTA",
  "CURVA", "PLANO", "TRIANGULO", "CUADRILATERO", "ELIPSE",
  "CIRCUNFERENCIA", "PARABOLA", "HIPERBOLA", "POLIEDRO", "CILINDRO",
  "CONO", "ESFERA", "COLOR_PREDEF", "ID", "';'", "'{'", "'}'", "','",
  "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "$accept", "Programa",
  "Lista_Sentencias", "Sentencia", "Declaracion", "Asignacion",
  "Expresion", "Param", "Funcion", "Dibujar", "Rellenar", "Rotar",
  "Escalar", "Trasladar", "Color", "Vect2d", "Vect3d", 0
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
     285,   286,   287,   288,   289,   290,    59,   123,   125,    44,
      61,    43,    45,    42,    47,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    57,    58,    59,    60,
      61,    61,    62,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     5,     5,     1,     2,     2,     2,     2,
       3,     3,     3,     3,     5,     7,     9,     7,     9,    11,
       9,     7,     7,     9,     7,     9,     9,     7,     3,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     5,     3,     3,
       9,     1,     5,     7
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,    39,    40,    41,    43,    42,     1,
       0,     0,     0,     0,     0,     0,     0,    35,    51,    38,
       0,    44,    34,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     6,     7,     8,     9,     0,
       0,     0,     0,     0,    49,    48,     0,     0,    13,     0,
      11,     0,    12,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       3,     4,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31,    32,    33,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,    17,     0,     0,     0,    21,    22,     0,
      24,     0,     0,    27,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    18,     0,    20,
      23,    25,    26,    50,     0,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    29,    30,    31,    32,   108,    51,    33,    34,
      35,    36,    37,    38,    52,    53,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int16 yypact[] =
{
       7,   237,    19,     0,   -15,   -12,   -11,   -10,    -9,   -13,
      -8,    -6,    -5,    -4,    -2,    -1,     4,     5,     6,     8,
       9,    10,    11,    12,    13,    30,    31,    32,     2,   148,
     -46,    34,    35,    36,   -46,   -46,   -46,   -46,   -46,   -46,
     103,   103,    52,    57,    22,   -13,   -13,   -46,   -46,   -46,
      59,   -46,   -46,   -46,   -46,   -31,    33,    37,    60,    39,
      40,    42,    43,    44,    46,    47,    48,    49,    50,    55,
      56,    58,    79,   -13,   -46,   -46,   -46,   -46,   -46,   178,
     208,   -13,   -13,   -13,   -46,   -46,   104,    81,   -46,    82,
     -46,   127,   -46,   -46,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -46,   -26,
     -46,   -46,   -46,   -46,   -13,   130,   109,   110,   111,    80,
     112,   114,   115,   116,   122,   145,   146,   152,   154,   175,
     176,   182,   184,   -13,   -13,   -13,   -13,   -46,   -35,   229,
     235,   256,   -46,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -46,   -46,   -46,   -46,
     258,   -46,   213,   228,   236,   238,   239,   241,   242,   243,
     244,   246,   247,   248,   250,   251,   252,   254,   -34,   262,
     265,   -46,   -13,   -46,   -13,   -13,   -13,   -46,   -46,   -13,
     -46,   -13,   -13,   -46,   271,   -46,   255,   249,   259,   260,
     257,   261,   263,   264,   266,   267,   -46,   -46,   -13,   -46,
     -46,   -46,   -46,   -46,   268,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -32,   -16,   -46,   -46,   -46,   -45,   -46,   -46,
     -46,   -46,   -46,   -46,   234,    38,   253
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      84,    85,    47,    48,   160,   194,    40,    41,    79,    80,
       1,   161,   195,    75,    87,   133,   134,   135,   136,    39,
      42,    48,    49,    43,    44,    45,    46,    55,   109,    56,
      57,    58,    50,    59,    60,    83,   112,   113,   114,    61,
      62,    63,    73,    64,    65,    66,    67,    68,    69,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    75,    75,    70,    71,    72,    81,   137,
      76,    77,    78,    82,    86,    93,    94,    95,    89,    96,
      97,    98,    91,    99,   100,   101,   102,   103,   156,   157,
     158,   159,   104,   105,    90,   106,   116,   117,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     4,     5,     6,     7,     8,   107,     9,   142,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   198,    28,   199,
     200,   201,   118,   115,   202,   138,   203,   204,   139,   140,
     141,   143,    74,   144,   145,   146,     4,     5,     6,     7,
       8,   147,     9,   214,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   110,    28,   148,   149,     4,     5,     6,     7,
       8,   150,     9,   151,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   111,    28,   152,   153,     4,     5,     6,     7,
       8,   154,     9,   155,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     3,    28,   162,     4,     5,     6,     7,     8,
     163,     9,   179,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   164,    28,   178,   161,   180,   181,   196,   182,   183,
     197,   184,   185,   186,   187,   188,   205,   189,   190,    88,
     191,   192,   193,     0,   194,   195,   208,   206,   207,   209,
       0,   210,   211,     0,   212,     0,   215,     0,     0,     0,
      92,     0,     0,   213
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-46))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      45,    46,    15,    34,    39,    39,     6,     7,    40,    41,
       3,    46,    46,    29,    45,    41,    42,    43,    44,     0,
      35,    34,    35,    35,    35,    35,    35,    35,    73,    35,
      35,    35,    45,    35,    35,    13,    81,    82,    83,    35,
      35,    35,    40,    35,    35,    35,    35,    35,    35,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    79,    80,    35,    35,    35,    16,   114,
      36,    36,    36,    16,    15,    15,    37,    37,    45,    37,
      37,    37,    45,    37,    37,    37,    37,    37,   133,   134,
     135,   136,    37,    37,    56,    37,    15,    15,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     8,     9,    10,    11,    12,    37,    14,    38,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,   182,    35,   184,
     185,   186,    15,    39,   189,    15,   191,   192,    39,    39,
      39,    39,     4,    39,    39,    39,     8,     9,    10,    11,
      12,    39,    14,   208,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     4,    35,    39,    39,     8,     9,    10,    11,
      12,    39,    14,    39,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     4,    35,    39,    39,     8,     9,    10,    11,
      12,    39,    14,    39,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     5,    35,    15,     8,     9,    10,    11,    12,
      15,    14,    39,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    15,    35,    15,    46,    39,    38,    15,    39,    38,
      15,    39,    39,    39,    38,    38,    15,    39,    38,    55,
      39,    39,    38,    -1,    39,    46,    39,    38,    38,    38,
      -1,    38,    38,    -1,    38,    -1,    38,    -1,    -1,    -1,
      57,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    48,     5,     8,     9,    10,    11,    12,    14,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    35,    49,
      50,    51,    52,    55,    56,    57,    58,    59,    60,     0,
       6,     7,    35,    35,    35,    35,    35,    15,    34,    35,
      45,    54,    61,    62,    63,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    40,     4,    50,    36,    36,    36,    49,
      49,    16,    16,    13,    54,    54,    15,    45,    61,    45,
      62,    45,    63,    15,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    53,    54,
       4,     4,    54,    54,    54,    39,    15,    15,    15,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    41,    42,    43,    44,    54,    15,    39,
      39,    39,    38,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    54,    54,    54,    54,
      39,    46,    15,    15,    15,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    15,    39,
      39,    38,    39,    38,    39,    39,    39,    38,    38,    39,
      38,    39,    39,    38,    39,    46,    15,    15,    54,    54,
      54,    54,    54,    54,    54,    15,    38,    38,    39,    38,
      38,    38,    38,    46,    54,    38
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
        case 2:

/* Line 1806 of yacc.c  */
#line 83 "/home/jesus/Workspace/Prism-geom/prism.y"
    {root = new Root((yyvsp[(2) - (3)].sentence_list));
                                        if(errors==0)
                                            syntax+="\nSintaxis Correcta\n";}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 86 "/home/jesus/Workspace/Prism-geom/prism.y"
    {root = new Root((yyvsp[(4) - (5)].sentence_list),true);
                                        if(errors==0)
                                            syntax+="\nSintaxis Correcta\n";}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 89 "/home/jesus/Workspace/Prism-geom/prism.y"
    {root = new Root((yyvsp[(4) - (5)].sentence_list),false);
                                        if(errors==0)
                                            syntax+="\nSintaxis Correcta\n";}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 93 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.sentence_list) = new std::vector<Sentence*>(); (yyval.sentence_list)->push_back((yyvsp[(1) - (1)].sentence));}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 94 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.sentence_list)->push_back((yyvsp[(2) - (2)].sentence));}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 97 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.sentence) = (yyvsp[(1) - (2)].declaration);}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 98 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.sentence) = (yyvsp[(1) - (2)].asignation);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 99 "/home/jesus/Workspace/Prism-geom/prism.y"
    { (yyval.sentence) = (yyvsp[(1) - (2)].function); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 102 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (3)].string));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),FLOAT_DT,new Float(*(yyvsp[(3) - (3)].fval)));}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 104 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (3)].string));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),VECT2_DT,(yyvsp[(3) - (3)].vect2d));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 106 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (3)].string));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),VECT3_DT,(yyvsp[(3) - (3)].vect3d));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 108 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (3)].string));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),COLOR_DT,(yyvsp[(3) - (3)].color));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 111 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (5)].string));
                                    check_or_insert(*(yyvsp[(2) - (5)].string),POINT_DT,new Point((yyvsp[(4) - (5)].param)));
                                    if((yyvsp[(4) - (5)].param)->type!=VECT2_DT){yyerror("ERROR: La posicion del punto debe ser Vector2d\nPrototipo: Punto {Vector2d posicion}");}
                                    }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 116 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (7)].string));
                                    check_or_insert(*(yyvsp[(2) - (7)].string),RECT_DT,new Rect((yyvsp[(4) - (7)].param),(yyvsp[(6) - (7)].param)));
                                    if((yyvsp[(4) - (7)].param)->type!=VECT2_DT){yyerror("ERROR: El punto \"a\" debe ser Vector2d\nPrototipo: Recta {Vector2d a,Vector2d b}");}
                                    if((yyvsp[(6) - (7)].param)->type!=VECT2_DT){yyerror("ERROR: El punto \"b\" debe ser Vector2d\nPrototipo: Recta {Vector2d a,Vector2d b}");}
                                    }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 122 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (9)].string));
                                    check_or_insert(*(yyvsp[(2) - (9)].string),CURVE_DT,new Curve((yyvsp[(4) - (9)].param),(yyvsp[(6) - (9)].param),(yyvsp[(8) - (9)].param)));
                                    if((yyvsp[(4) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El punto \"a\" debe ser Vector2d\nPrototipo: Curva {Vector2d a,Vector2d b,Vector2d c}");}
                                    if((yyvsp[(6) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El punto \"b\" debe ser Vector2d\nPrototipo: Curva {Vector2d a,Vector2d b,Vector2d c}");}
                                    if((yyvsp[(8) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El punto \"c\" debe ser Vector2d\nPrototipo: Curva {Vector2d a,Vector2d b,Vector2d c}");}
                                    Vect2d *a,*b,*c;
                                    a = (Vect2d*)(yyvsp[(4) - (9)].param)->value;
                                    b = (Vect2d*)(yyvsp[(6) - (9)].param)->value;
                                    c = (Vect2d*)(yyvsp[(8) - (9)].param)->value;
                                    if(!((a->x<b->x) && (b->x < c->x ))){yyerror("ERROR: La coordenada x de los puntos debe estar ordenada de menor a mayor");}
                                    }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 135 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (7)].string));
                                    check_or_insert(*(yyvsp[(2) - (7)].string),PLANE_DT,new Plane((yyvsp[(4) - (7)].param),(yyvsp[(6) - (7)].param)));
                                    if((yyvsp[(4) - (7)].param)->type!=VECT3_DT){yyerror("ERROR: El centro debe ser Vector3d\nPrototipo: Plano {Vector2d centro,Flotante lado}");}
                                    if((yyvsp[(6) - (7)].param)->type!=FLOAT_DT){yyerror("ERROR: El lado debe ser flotante\nPrototipo: Plano {Vector2d centro,Flotante lado}");}
                                    }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 141 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (9)].string));
                                    check_or_insert(*(yyvsp[(2) - (9)].string),TRIANGLE_DT,new Triangle((yyvsp[(4) - (9)].param),(yyvsp[(6) - (9)].param),(yyvsp[(8) - (9)].param)));
                                    if((yyvsp[(4) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El vertice \"a\" debe ser Vector2d\nPrototipo: Triangulo {Vector2d a,Vector2d b,Vector2d c}");}
                                    if((yyvsp[(6) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El vertice \"b\" debe ser Vector2d\nPrototipo: Triangulo {Vector2d a,Vector2d b,Vector2d c}");}
                                    if((yyvsp[(8) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El vertice \"c\" debe ser Vector2d\nPrototipo: Triangulo {Vector2d a,Vector2d b,Vector2d c}");}
                                    }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 148 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (11)].string));
                                    check_or_insert(*(yyvsp[(2) - (11)].string),QUAD_DT,new Quad((yyvsp[(4) - (11)].param),(yyvsp[(6) - (11)].param),(yyvsp[(8) - (11)].param),(yyvsp[(10) - (11)].param)));
                                    if((yyvsp[(4) - (11)].param)->type!=VECT2_DT){yyerror("ERROR: El vertice \"a\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    if((yyvsp[(6) - (11)].param)->type!=VECT2_DT){yyerror("ERROR: El vertice \"b\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    if((yyvsp[(8) - (11)].param)->type!=VECT2_DT){yyerror("ERROR: El vertice \"c\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    if((yyvsp[(10) - (11)].param)->type!=VECT2_DT){yyerror("ERROR: El vertice \"d\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 156 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (9)].string));
                                    check_or_insert(*(yyvsp[(2) - (9)].string),ELIPSE_DT,new Elipse((yyvsp[(4) - (9)].param),(yyvsp[(6) - (9)].param),(yyvsp[(8) - (9)].param)));
                                    if((yyvsp[(4) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El centro debe ser Vector2d\nPrototipo: Elipse {Vector2d centro,Flotante ancho,Flotante altura}");}
                                    if((yyvsp[(6) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: El ancho debe ser Flotante\nPrototipo: Elipse {Vector2d centro,Flotante ancho,Flotante altura}");}
                                    if((yyvsp[(8) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: La altura debe ser Flotante\nPrototipo: Elipse {Vector2d centro,Flotante ancho,Flotante altura}");}
                                    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 163 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (7)].string));
                                    check_or_insert(*(yyvsp[(2) - (7)].string),CIRC_DT,new Circ((yyvsp[(4) - (7)].param),(yyvsp[(6) - (7)].param)));
                                    if((yyvsp[(4) - (7)].param)->type!=VECT2_DT){yyerror("ERROR: El centro debe ser Vector2d\nPrototipo: Circunferencia {Vector2d centro,Flotante radio}");}
                                    if((yyvsp[(6) - (7)].param)->type!=FLOAT_DT){yyerror("ERROR: El radio debe ser Flotante\nPrototipo: Circunferencia {Vector2d centro,Flotante radio}");}
                                    }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 169 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (7)].string));
                                    check_or_insert(*(yyvsp[(2) - (7)].string),PARABOLE_DT,new Parabole((yyvsp[(4) - (7)].param),(yyvsp[(6) - (7)].param)));
                                    if((yyvsp[(4) - (7)].param)->type!=VECT2_DT){yyerror("ERROR: El punto minimo debe ser Vector2d\nPrototipo: Parabola {Vector2d punto_minimo,Flotante factor_multiplicativo}");}
                                    if((yyvsp[(6) - (7)].param)->type!=FLOAT_DT){yyerror("ERROR: El factor multiplicativo debe ser Flotante\nPrototipo: Parabola {Vector2d punto_minimo,Flotante factor_multiplicativo}");}
                                    }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 175 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (9)].string));
                                    check_or_insert(*(yyvsp[(2) - (9)].string),HYPERBOLE_DT,new Hyperbole((yyvsp[(4) - (9)].param),(yyvsp[(6) - (9)].param),(yyvsp[(8) - (9)].param)));
                                    if((yyvsp[(4) - (9)].param)->type!=VECT2_DT){yyerror("ERROR: El foco debe ser Vector2d\nPrototipo: Hiperbola {Vector2d foco,Flotante factor_multiplicativo,Flotante distancia_focal}");}
                                    if((yyvsp[(6) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: El factor multiplicativo debe ser Flotante\nPrototipo: Hiperbola {Vector2d foco,Flotante factor_multiplicativo,Flotante distancia_focal}");}
                                    if((yyvsp[(8) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: La distancia focal ser Flotante\nPrototipo: Hiperbola {Vector2d foco,Flotante factor_multiplicativo,Flotante distancia_focal}");}
                                    }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 182 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (7)].string));
                                    check_or_insert(*(yyvsp[(2) - (7)].string),POLYHEDRON_DT,new Polyhedron((yyvsp[(4) - (7)].param),(yyvsp[(6) - (7)].param)));
                                    if((yyvsp[(4) - (7)].param)->type!=FLOAT_DT){yyerror("ERROR: El numero de caras debe ser Flotante\nPrototipo: Poliedro {Flotante num_caras,Flotante num_lados}");}
                                    if((yyvsp[(6) - (7)].param)->type!=FLOAT_DT){yyerror("ERROR: El numero de lados debe ser Flotante\nPrototipo: Poliedro {Flotante num_caras,Flotante num_lados}");}
                                    }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 188 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (9)].string));
                                    check_or_insert(*(yyvsp[(2) - (9)].string),CYLINDRE_DT,new Cylindre((yyvsp[(4) - (9)].param),(yyvsp[(6) - (9)].param),(yyvsp[(8) - (9)].param)));
                                    if((yyvsp[(4) - (9)].param)->type!=VECT3_DT){yyerror("ERROR: El centro de la base ser Vector3d\nPrototipo: Cilindro {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if((yyvsp[(6) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: La altura debe ser Flotante\nPrototipo: Cilindro {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if((yyvsp[(8) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: El radio debe ser Flotante\nPrototipo: Cilindro {Vector3d centro,Flotante altura,Flotante radio}");}
                                    }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 195 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (9)].string));
                                    check_or_insert(*(yyvsp[(2) - (9)].string),CONE_DT,new Cone((yyvsp[(4) - (9)].param),(yyvsp[(6) - (9)].param),(yyvsp[(8) - (9)].param)));
                                    if((yyvsp[(4) - (9)].param)->type!=VECT3_DT){yyerror("ERROR: El centro de la base ser Vector3d\nPrototipo: Cono {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if((yyvsp[(6) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: La altura debe ser Flotante\nPrototipo: Cono {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if((yyvsp[(8) - (9)].param)->type!=FLOAT_DT){yyerror("ERROR: El radio de la base debe ser Flotante\nPrototipo: Cono {Vector3d centro,Flotante altura,Flotante radio}");}
                                    }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 202 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.declaration) = new Declaration((yyvsp[(2) - (7)].string));
                                    check_or_insert(*(yyvsp[(2) - (7)].string),SPHERE_DT,new Sphere((yyvsp[(4) - (7)].param),(yyvsp[(6) - (7)].param)));
                                    if((yyvsp[(4) - (7)].param)->type!=VECT3_DT){yyerror("ERROR: El centro de la base ser Vector3d\nPrototipo: Esfera {Vector3d centro,Flotante radio}");}
                                    if((yyvsp[(6) - (7)].param)->type!=FLOAT_DT){yyerror("ERROR: El radio debe ser Flotante\nPrototipo: Esfera {Vector3d centro,Flotante radio}");}
                                    }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 209 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.asignation) = new Asignation((yyvsp[(1) - (3)].string),(yyvsp[(3) - (3)].expresion));
                                check(*(yyvsp[(1) - (3)].string));
                              }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 214 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.expresion) = new ParamExpresion((yyvsp[(1) - (1)].param));}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 215 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.expresion) = new Plus((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("ERROR: Los parametros de la suma no concuerdan");} }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 217 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.expresion) = new Less((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("ERROR: Los parametros de la resta no concuerdan");} }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 219 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.expresion) = new Times((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("ERROR: Los parametros de la multiplicacion no concuerdan");} }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 221 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.expresion) = new Division((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("ERROR: Los parametros de la division no concuerdan");} }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 225 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.param)= new Param(COLOR_DT,(void*)(yyvsp[(1) - (1)].color));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 226 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.param)= new Param(FLOAT_DT,(void*)new Float(*(yyvsp[(1) - (1)].fval)));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 227 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.param)= new Param(VECT2_DT,(void*)(yyvsp[(1) - (1)].vect2d));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 228 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.param)= new Param(VECT3_DT,(void*)(yyvsp[(1) - (1)].vect3d));}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 229 "/home/jesus/Workspace/Prism-geom/prism.y"
    { if(check(*(yyvsp[(1) - (1)].string))) {(yyval.param) = new Param((yyvsp[(1) - (1)].string));} else{ (yyval.param) = new Param(); } }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 232 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].draw);}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 233 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].fill);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 234 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].rotate);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 235 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].translate);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 236 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].scale);}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 237 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.function)= new Background((yyvsp[(2) - (2)].param));}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 240 "/home/jesus/Workspace/Prism-geom/prism.y"
    { (yyval.draw) = new Draw((yyvsp[(2) - (4)].string),(yyvsp[(4) - (4)].param));
    if(check(*(yyvsp[(2) - (4)].string)))
    {
        Identifier* id = symbols.value(*(yyvsp[(2) - (4)].string));
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden dibujar figuras GEOM2D o GEOM3D");
    if((yyvsp[(4) - (4)].param)->type!=COLOR_DT)
        yyerror("ERROR: El parametro de Color debe ser un Color valido rgba o un color predefinido" );
    }
}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 252 "/home/jesus/Workspace/Prism-geom/prism.y"
    { (yyval.fill) = new Fill((yyvsp[(2) - (4)].string),(yyvsp[(4) - (4)].param)); check(*(yyvsp[(2) - (4)].string));
    if(check(*(yyvsp[(2) - (4)].string)))
    {
        Identifier* id = symbols.value(*(yyvsp[(2) - (4)].string));
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden dibujar figuras GEOM2D o GEOM3D");
        if((yyvsp[(4) - (4)].param)->type!=COLOR_DT){
            yyerror("ERROR: El parametro de Color debe ser un Color valido rgba o un color predefinido" );
        }

    }
}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 266 "/home/jesus/Workspace/Prism-geom/prism.y"
    { (yyval.rotate) = new Rotate((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].param),(yyvsp[(5) - (5)].param));
    if(check(*(yyvsp[(2) - (5)].string)))
    {
        Identifier* id = symbols.value(*(yyvsp[(2) - (5)].string));
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden rotar figuras GEOM2D o GEOM3D");
        if((yyvsp[(4) - (5)].param)->type!=VECT3_DT)
            yyerror("ERROR: El eje de rotacion debe ser un Vector3d" );
        if((yyvsp[(5) - (5)].param)->type!=FLOAT_DT)
            yyerror("ERROR: El parametro de rotacion debe ser un Flotante");
    }
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 280 "/home/jesus/Workspace/Prism-geom/prism.y"
    { (yyval.scale) = new Scale((yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].param));
if(check(*(yyvsp[(2) - (3)].string)))
{
    Identifier* id = symbols.value(*(yyvsp[(2) - (3)].string));
    if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
        yyerror("ERROR: Solo se pueden escalar figuras GEOM2D o GEOM3D");
    else if(id->dimension == Identifier::GEOM2D && (yyvsp[(3) - (3)].param)->type!=VECT2_DT){
        yyerror("ERROR: El parametro de escala debe ser un Vector2d" );
    }else if(id->dimension == Identifier::GEOM3D && (yyvsp[(3) - (3)].param)->type!=VECT3_DT){
        yyerror("ERROR: El parametro de escala debe ser un Vector3d" );
    }
}
}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 295 "/home/jesus/Workspace/Prism-geom/prism.y"
    { (yyval.translate) = new Translate((yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].param));
    if(check(*(yyvsp[(2) - (3)].string)))
    {
        Identifier* id = symbols.value(*(yyvsp[(2) - (3)].string));
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden trasladar figuras GEOM2D o GEOM3D");
        else if(id->dimension == Identifier::GEOM2D && (yyvsp[(3) - (3)].param)->type!=VECT2_DT){
            yyerror("ERROR: El parametro de traslacion debe ser un Vector2d" );
        }else if(id->dimension == Identifier::GEOM3D && (yyvsp[(3) - (3)].param)->type!=VECT3_DT){
            yyerror("ERROR: El parametro de traslacion debe ser un Vector3d" );
        }
    }
}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 310 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.color)=new Color(*(yyvsp[(2) - (9)].fval),*(yyvsp[(4) - (9)].fval),*(yyvsp[(6) - (9)].fval),*(yyvsp[(8) - (9)].fval));
                                                                if(*(yyvsp[(2) - (9)].fval)<0||*(yyvsp[(2) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente de rojo del color debe estar entre 0 y 1");
                                                                if(*(yyvsp[(4) - (9)].fval)<0||*(yyvsp[(4) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente de verde del color debe estar entre 0 y 1");
                                                                if(*(yyvsp[(6) - (9)].fval)<0||*(yyvsp[(6) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente de azul del color debe estar entre 0 y 1");
                                                                if(*(yyvsp[(8) - (9)].fval)<0||*(yyvsp[(8) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente alpha (transparencia) del color debe estar entre 0 y 1");
                                                                }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 320 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.color)=new Color((yyvsp[(1) - (1)].string));}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 323 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.vect2d)=new Vect2d(*(yyvsp[(2) - (5)].fval),*(yyvsp[(4) - (5)].fval));}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 326 "/home/jesus/Workspace/Prism-geom/prism.y"
    {(yyval.vect3d)=new Vect3d(*(yyvsp[(2) - (7)].fval),*(yyvsp[(4) - (7)].fval),*(yyvsp[(6) - (7)].fval));}
    break;



/* Line 1806 of yacc.c  */
#line 2119 "/home/jesus/Workspace/Prism-geom/prism.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 329 "/home/jesus/Workspace/Prism-geom/prism.y"
 

void check_or_insert(QString name,DATATYPE t,DataType * value){
    if(symbols.contains(name))
    {
        yyerror("ERROR: No se puede redefinir una variable ya declarada" );
    }
    else
    {
        symbols.insert(name,new Identifier(name,t,value));
    }
}

bool check(QString name){
    if(!symbols.contains(name))
    {
        yyerror("ERROR: Variable no declarada");
        return false;
    }
    symbols.value(name)->referenced=true;
    return true;
}

int yywrap()  
{  
   return 1;  
}  

void yyerror(const char *s){
    errors++;
    syntax+="En la linea ";
    syntax+=QString::number(line);
    syntax+=":  ";
    if(strcmp (s,"syntax error")==0)
        syntax+="ERROR: Error de sintaxis ";
    else
        syntax+=s;
    syntax+='\n';
}
 


