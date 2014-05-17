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
#line 1 "/home/jesus/Compiladores/Prism/prism.y"

    #include <stdio.h>
    #include <QDebug>
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

    void check_or_insert(QString,DATATYPE);
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
#line 103 "/home/jesus/Compiladores/Prism/prism.tab.cpp"

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
     DIBUJAR = 260,
     RELLENAR = 261,
     ROTAR = 262,
     TRASLADAR = 263,
     ESCALAR = 264,
     SOBRE = 265,
     FONDO = 266,
     PTO_FLOT = 267,
     COLOR = 268,
     VECT2D = 269,
     VECT3D = 270,
     FLOTANTE = 271,
     PUNTO = 272,
     RECTA = 273,
     CURVA = 274,
     PLANO = 275,
     TRIANGULO = 276,
     CUADRILATERO = 277,
     ELIPSE = 278,
     CIRCUNFERENCIA = 279,
     PARABOLA = 280,
     HIPERBOLA = 281,
     POLIEDRO = 282,
     CILINDRO = 283,
     CONO = 284,
     ESFERA = 285,
     COLOR_PREDEF = 286,
     ID = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 32 "/home/jesus/Compiladores/Prism/prism.y"

        float fval;
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
#line 195 "/home/jesus/Compiladores/Prism/prism.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 207 "/home/jesus/Compiladores/Prism/prism.tab.cpp"

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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    40,    38,    36,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,     9,    12,    15,    18,    21,    25,
      29,    33,    37,    43,    51,    56,    61,    71,    83,    88,
      96,   101,   106,   111,   116,   121,   129,   133,   135,   139,
     143,   147,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   171,   174,   179,   184,   190,   194,   198,   208,
     210,   216
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,     3,    46,     4,    -1,    47,    -1,    46,
      47,    -1,    48,    33,    -1,    49,    33,    -1,    52,    33,
      -1,    16,    32,    12,    -1,    14,    32,    59,    -1,    15,
      32,    60,    -1,    13,    32,    58,    -1,    17,    32,    34,
      51,    35,    -1,    18,    32,    34,    51,    36,    51,    35,
      -1,    19,    32,    34,    35,    -1,    20,    32,    34,    35,
      -1,    21,    32,    34,    51,    36,    51,    36,    51,    35,
      -1,    22,    32,    34,    51,    36,    51,    36,    51,    36,
      51,    35,    -1,    23,    32,    34,    35,    -1,    24,    32,
      34,    51,    36,    51,    35,    -1,    25,    32,    34,    35,
      -1,    26,    32,    34,    35,    -1,    27,    32,    34,    35,
      -1,    28,    32,    34,    35,    -1,    29,    32,    34,    35,
      -1,    30,    32,    34,    51,    36,    51,    35,    -1,    32,
      37,    50,    -1,    51,    -1,    51,    38,    51,    -1,    51,
      39,    51,    -1,    51,    40,    51,    -1,    51,    41,    51,
      -1,    58,    -1,    12,    -1,    59,    -1,    60,    -1,    32,
      -1,    53,    -1,    54,    -1,    55,    -1,    57,    -1,    56,
      -1,    11,    51,    -1,     5,    32,    13,    51,    -1,     6,
      32,    13,    51,    -1,     7,    32,    10,    51,    51,    -1,
       9,    32,    51,    -1,     8,    32,    51,    -1,    42,    12,
      36,    12,    36,    12,    36,    12,    43,    -1,    31,    -1,
      42,    12,    36,    12,    43,    -1,    42,    12,    36,    12,
      36,    12,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    89,    90,    93,    94,    95,    98,   100,
     102,   104,   106,   108,   110,   112,   114,   116,   118,   120,
     122,   124,   126,   128,   130,   132,   136,   141,   142,   144,
     146,   148,   152,   153,   154,   155,   156,   161,   162,   163,
     164,   165,   166,   169,   181,   195,   212,   227,   242,   252,
     255,   258
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INICIO", "FIN", "DIBUJAR", "RELLENAR",
  "ROTAR", "TRASLADAR", "ESCALAR", "SOBRE", "FONDO", "PTO_FLOT", "COLOR",
  "VECT2D", "VECT3D", "FLOTANTE", "PUNTO", "RECTA", "CURVA", "PLANO",
  "TRIANGULO", "CUADRILATERO", "ELIPSE", "CIRCUNFERENCIA", "PARABOLA",
  "HIPERBOLA", "POLIEDRO", "CILINDRO", "CONO", "ESFERA", "COLOR_PREDEF",
  "ID", "';'", "'{'", "'}'", "','", "'='", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "$accept", "Programa", "Lista_Sentencias", "Sentencia",
  "Declaracion", "Asignacion", "Expresion", "Param", "Funcion", "Dibujar",
  "Rellenar", "Rotar", "Escalar", "Trasladar", "Color", "Vect2d", "Vect3d", 0
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
     285,   286,   287,    59,   123,   125,    44,    61,    43,    45,
      42,    47,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    50,    50,    50,
      50,    50,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    53,    54,    55,    56,    57,    58,    58,
      59,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     2,     2,     2,     2,     3,     3,
       3,     3,     5,     7,     4,     4,     9,    11,     4,     7,
       4,     4,     4,     4,     4,     7,     3,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     5,     3,     3,     9,     1,
       5,     7
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,    37,    38,    39,    41,    40,     1,     0,
       0,     0,     0,     0,    33,    49,    36,     0,    42,    32,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     5,     6,     7,     0,     0,     0,    47,
      46,     0,     0,    11,     0,     9,     0,    10,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,    43,    44,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,    18,     0,
      20,    21,    22,    23,    24,     0,     0,     0,     0,     0,
      45,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,    28,    29,    30,    31,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,    19,    25,     0,    51,     0,     0,     0,     0,     0,
      16,     0,    48,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    28,    29,    30,    31,   103,    48,    32,    33,
      34,    35,    36,    37,    49,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
       3,   145,     7,   -24,   -22,   -19,   -13,   -12,   -10,    -9,
      -8,    -7,    -6,    -5,    -3,    -2,    -1,     1,     5,     6,
       8,     9,    10,    11,    12,    13,    14,     2,   117,   -43,
      16,    17,    20,   -43,   -43,   -43,   -43,   -43,   -43,    -4,
      42,    46,   -10,   -10,   -43,   -43,   -43,    45,   -43,   -43,
     -43,   -43,   -28,    19,    21,    47,    24,    28,    30,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    43,
     -10,   -43,   -43,   -43,   -43,   -43,   -10,   -10,   -10,   -43,
     -43,    44,    64,   -43,    66,   -43,    67,   -43,   -43,   -10,
     -10,    48,    53,   -10,   -10,    54,   -10,    55,    56,    57,
      58,    65,   -10,   -43,   -23,   -43,   -43,   -10,    69,    63,
      68,    70,    72,    73,   -43,   -43,    74,    75,   -43,    76,
     -43,   -43,   -43,   -43,   -43,    77,   -10,   -10,   -10,   -10,
     -43,   -32,    89,    90,    91,   -43,   -10,   -10,   -10,   -10,
     -10,   -43,   -43,   -43,   -43,    93,   -43,    78,    84,    79,
      81,    83,   112,    85,   120,   -31,    96,   164,   -43,   -10,
     -10,   -43,   -43,   166,   -43,   121,   136,   146,   144,   139,
     -43,   -10,   -43,   148,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,   156,   -43,   -43,   -43,   -42,   -43,   -43,
     -43,   -43,   -43,   -43,   133,    29,   132
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      79,    80,    44,    45,   145,   163,     1,    38,    39,    76,
      40,   146,   164,    41,    82,   126,   127,   128,   129,    42,
      43,    45,    46,    52,    53,    54,    55,    56,   104,    57,
      58,    59,    47,    60,   105,   106,   107,    61,    62,    70,
      63,    64,    65,    66,    67,    68,    69,   112,   113,    73,
      74,   116,   117,    75,   119,    77,    78,    81,    89,    88,
     125,    84,    90,    86,    91,   130,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   109,   102,   110,   111,
     108,   131,    85,   114,   141,   142,   143,   144,   115,   118,
     120,   121,   122,   123,   150,   151,   152,   153,   154,   132,
     124,   147,   148,   149,   133,   155,   134,   135,   165,   136,
     137,   138,   139,   140,   156,   157,   158,   167,   168,   159,
     161,    71,     3,     4,     5,     6,     7,   146,     8,   173,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   160,    27,
       3,     4,     5,     6,     7,   162,     8,   163,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   166,    27,   169,   164,
     171,   170,   172,   174,    72,    83,    87
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-43))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      42,    43,    12,    31,    36,    36,     3,     0,    32,    13,
      32,    43,    43,    32,    42,    38,    39,    40,    41,    32,
      32,    31,    32,    32,    32,    32,    32,    32,    70,    32,
      32,    32,    42,    32,    76,    77,    78,    32,    32,    37,
      32,    32,    32,    32,    32,    32,    32,    89,    90,    33,
      33,    93,    94,    33,    96,    13,    10,    12,    34,    12,
     102,    42,    34,    42,    34,   107,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    12,    34,    12,    12,
      36,    12,    53,    35,   126,   127,   128,   129,    35,    35,
      35,    35,    35,    35,   136,   137,   138,   139,   140,    36,
      35,    12,    12,    12,    36,    12,    36,    35,    12,    36,
      36,    36,    36,    36,    36,    36,    35,   159,   160,    36,
      35,     4,     5,     6,     7,     8,     9,    43,    11,   171,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    36,    32,
       5,     6,     7,     8,     9,    35,    11,    36,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    12,    32,    12,    43,
      36,    35,    43,    35,    28,    52,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    45,     5,     6,     7,     8,     9,    11,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    32,    46,    47,
      48,    49,    52,    53,    54,    55,    56,    57,     0,    32,
      32,    32,    32,    32,    12,    31,    32,    42,    51,    58,
      59,    60,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      37,     4,    47,    33,    33,    33,    13,    13,    10,    51,
      51,    12,    42,    58,    42,    59,    42,    60,    12,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    50,    51,    51,    51,    51,    36,    12,
      12,    12,    51,    51,    35,    35,    51,    51,    35,    51,
      35,    35,    35,    35,    35,    51,    38,    39,    40,    41,
      51,    12,    36,    36,    36,    35,    36,    36,    36,    36,
      36,    51,    51,    51,    51,    36,    43,    12,    12,    12,
      51,    51,    51,    51,    51,    12,    36,    36,    35,    36,
      36,    35,    35,    36,    43,    12,    12,    51,    51,    12,
      35,    36,    43,    51,    35
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
#line 84 "/home/jesus/Compiladores/Prism/prism.y"
    {root = new Root((yyvsp[(2) - (3)].sentence_list));
                                        if(errors==0)
                                            syntax+="\nSintaxis Correcta\n";}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 89 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.sentence_list) = new std::vector<Sentence*>(); (yyval.sentence_list)->push_back((yyvsp[(1) - (1)].sentence));}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 90 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.sentence_list)->push_back((yyvsp[(2) - (2)].sentence));}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 93 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.sentence) = (yyvsp[(1) - (2)].declaration);}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 94 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.sentence) = (yyvsp[(1) - (2)].asignation);}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 95 "/home/jesus/Compiladores/Prism/prism.y"
    { (yyval.sentence) = (yyvsp[(1) - (2)].function); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 98 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new FloatDeclaration((yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].fval));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),FLOAT_DT);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 100 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Vect2dDeclaration((yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].vect2d));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),VECT2_DT);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 102 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Vect3dDeclaration((yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].vect3d));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),VECT3_DT);}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 104 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new ColorDeclaration((yyvsp[(2) - (3)].string),(yyvsp[(3) - (3)].color));
                                    check_or_insert(*(yyvsp[(2) - (3)].string),COLOR_DT);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 106 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new PointDeclaration((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].param));
                                    check_or_insert(*(yyvsp[(2) - (5)].string),POINT_DT);}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 108 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new RectDeclaration((yyvsp[(2) - (7)].string),(yyvsp[(4) - (7)].param),(yyvsp[(6) - (7)].param));
                                    check_or_insert(*(yyvsp[(2) - (7)].string),RECT_DT);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 110 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),CURVE_DT);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 112 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),PLANE_DT);}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 114 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (9)].string),TRIANGLE_DT);}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 116 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (11)].string),QUAD_DT);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 118 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),ELIPSE_DT);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 120 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (7)].string),CIRC_DT);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 122 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),PARABOLE_DT);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 124 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),HYPERBOLE_DT);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 126 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),POLYHEDRON_DT);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 128 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),CILINDRE_DT);}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 130 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (4)].string),CONE_DT);}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 132 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.declaration) = new Declaration;
                                    check_or_insert(*(yyvsp[(2) - (7)].string),SPHERE_DT);}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 136 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.asignation) = new Asignation((yyvsp[(1) - (3)].string),(yyvsp[(3) - (3)].expresion));
                                check(*(yyvsp[(1) - (3)].string));
                              }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 141 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.expresion) = new ParamExpresion((yyvsp[(1) - (1)].param));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 142 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.expresion) = new Plus((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("Error: Los parametros de la suma no concuerdan");} }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 144 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.expresion) = new Less((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("Error: Los parametros de la resta no concuerdan");} }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 146 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.expresion) = new Times((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("Error: Los parametros de la multiplicacion concuerdan");} }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 148 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.expresion) = new Division((yyvsp[(1) - (3)].param),(yyvsp[(3) - (3)].param));
                                if((yyvsp[(1) - (3)].param)->type != (yyvsp[(3) - (3)].param)->type){yyerror("Error: Los parametros de la division no concuerdan");} }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 152 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.param)= new ColorParam((yyvsp[(1) - (1)].color));}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 153 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.param)= new FloatParam((yyvsp[(1) - (1)].fval));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 154 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.param)= new Vect2dParam((yyvsp[(1) - (1)].vect2d));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 155 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.param)= new Vect3dParam((yyvsp[(1) - (1)].vect3d));}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 156 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.param)= new IdParam((yyvsp[(1) - (1)].string));
                check(*(yyvsp[(1) - (1)].string));
      }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 161 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].draw);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 162 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].fill);}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 163 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].rotate);}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 164 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].translate);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 165 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.function)=(yyvsp[(1) - (1)].scale);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 166 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.function)= new Background((yyvsp[(2) - (2)].param));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 169 "/home/jesus/Compiladores/Prism/prism.y"
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

  case 44:

/* Line 1806 of yacc.c  */
#line 181 "/home/jesus/Compiladores/Prism/prism.y"
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

  case 45:

/* Line 1806 of yacc.c  */
#line 195 "/home/jesus/Compiladores/Prism/prism.y"
    { (yyval.rotate) = new Rotate((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].param),(yyvsp[(5) - (5)].param));
    if(check(*(yyvsp[(2) - (5)].string)))
    {
        Identifier* id = symbols.value(*(yyvsp[(2) - (5)].string));
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden rotar figuras GEOM2D o GEOM3D");
        else if(id->dimension == Identifier::GEOM2D && (yyvsp[(4) - (5)].param)->type!=VECT2_DT){
            yyerror("ERROR: El punto de rotacion ser un Vector2d" );
        }else if(id->dimension == Identifier::GEOM3D && (yyvsp[(4) - (5)].param)->type!=VECT3_DT){
            yyerror("ERROR: El punto de rotacion debe ser un Vector3d" );
        }
        if((yyvsp[(5) - (5)].param)->type!=FLOAT_DT)
            yyerror("ERROR: El parametro de rotacion debe ser un Flotante");
    }
}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 212 "/home/jesus/Compiladores/Prism/prism.y"
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

  case 47:

/* Line 1806 of yacc.c  */
#line 227 "/home/jesus/Compiladores/Prism/prism.y"
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

  case 48:

/* Line 1806 of yacc.c  */
#line 242 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.color)=new Color((yyvsp[(2) - (9)].fval),(yyvsp[(4) - (9)].fval),(yyvsp[(6) - (9)].fval),(yyvsp[(8) - (9)].fval));
                                                                if((yyvsp[(2) - (9)].fval)<0||(yyvsp[(2) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente de rojo del color debe estar entre 0 y 1");
                                                                if((yyvsp[(4) - (9)].fval)<0||(yyvsp[(4) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente de verde del color debe estar entre 0 y 1");
                                                                if((yyvsp[(6) - (9)].fval)<0||(yyvsp[(6) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente de azul del color debe estar entre 0 y 1");
                                                                if((yyvsp[(8) - (9)].fval)<0||(yyvsp[(8) - (9)].fval)>1)
                                                                    yyerror("ERROR: El componente alpha (transparencia) del color debe estar entre 0 y 1");
                                                                }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 252 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.color)=new Color((yyvsp[(1) - (1)].string));}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 255 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.vect2d)=new Vect2d((yyvsp[(2) - (5)].fval),(yyvsp[(4) - (5)].fval));}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 258 "/home/jesus/Compiladores/Prism/prism.y"
    {(yyval.vect3d)=new Vect3d((yyvsp[(2) - (7)].fval),(yyvsp[(4) - (7)].fval),(yyvsp[(6) - (7)].fval));}
    break;



/* Line 1806 of yacc.c  */
#line 2006 "/home/jesus/Compiladores/Prism/prism.tab.cpp"
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
#line 261 "/home/jesus/Compiladores/Prism/prism.y"
 

void check_or_insert(QString name,DATATYPE t){
    if(symbols.contains(name))
    {
        yyerror("ERROR: No se puede redefinir una variable ya declarada" );
    }
    else
    {
        symbols.insert(name,new Identifier(name,t));
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
 


