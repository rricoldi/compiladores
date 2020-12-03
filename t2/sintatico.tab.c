/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

    #include<stdio.h>
    #include<string.h>
    #include <ast.h>

    extern char* yytext;
    extern int yylex();
    extern void clearBuffer();
    void yyerror(char *s);

    int option = -2;
    int auxInt;
    float auxFloat;
    int linhas = 25;
    int colunas = 80;

    char error_matrix[] = "ERROR: Matrix limits out of boundaries.";
    char error_v_view[] = "ERROR: v_view_lo must be smaller than v_view_hi";
    char error_h_view[] = "ERROR: h_view_lo must be smaller than h_view_hi";
    char error_set_int[] = "ERROR: integral_steps must be a positive non-zero integer";
    char error_integrate[] = "ERROR: lower limit must be smaller than upper limit";
    char error_determinant[] = "Matrix format incorrect!";
    char error_linear[] = "Matrix format incorrect!";


    TreeNode* AST = NULL;
    TreeNode* AST_TEMP = NULL;
    Settings* settings = NULL;

    int error = -1;
    int quit = 0;
    int functionInserted = 0;
    int matrixInserted = 0;

    int largura, larguraMax, altura = 1;
    int xMatrix, yMatrix, wMatrix, hMatrix;
    int inicio = 1;

    float matrixX[10][10];

    void printAbout();


#line 114 "sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 45 "sintatico.y"

    int integer;
    float real;
    void* ast;

#line 219 "sintatico.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   125,   129,   133,   137,   148,   159,   164,
     169,   177,   185,   194,   206,   221,   228,   235,   238,   244,
     246,   249,   252,   256,   257,   261,   267,   268,   272,   278,
     279,   283,   289,   290,   294,   300,   301,   305,   309,   313,
     319,   320,   326,   330,   334,   340,   343,   346,   349,   352,
     355,   360,   363,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "ADD", "SUB",
  "MULTIPLY", "DIV", "POWER", "REMAINDER", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "SEN", "COS", "TAN", "ABS",
  "NUM_INTEGER", "NUM_REAL", "VARIABLE", "EOL", "END_OF_FILE",
  "LEXICAL_ERROR", "SHOW", "SETTINGS", "RESET", "QUIT", "SET", "H_VIEW",
  "V_VIEW", "AXIS", "ON", "OFF", "PLOT", "INTEGRAL_STEPS", "INTEGRATE",
  "MATRIX", "SOLVE", "DETERMINANT", "LINEAR_SYSTEM", "ABOUT", "ASSIGN",
  "SEMICOLON", "COLON", "COMMA", "$accept", "calc", "matrix", "matrixAux",
  "exp", "factor", "operator", "signed", "function", "delimit", "term",
  "float", "int", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,    85,    85,    73,    11,    32,    46,    54,  -125,  -125,
    -125,   -24,    -6,    17,    49,    -8,    56,    35,   -25,    38,
      86,     1,    30,    45,  -125,  -125,  -125,  -125,  -125,  -125,
       9,    73,    73,    73,    73,    51,    77,    83,  -125,     5,
       5,    28,     7,    73,    93,     5,   115,    87,    88,    95,
    -125,    73,    73,  -125,    73,    73,    73,    73,  -125,    15,
      29,    41,    71,   107,   108,   111,    78,    92,  -125,  -125,
      89,    90,    94,    96,   117,   118,  -125,    97,   104,  -125,
      98,   126,   120,   122,  -125,    30,    30,    45,    45,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,     5,     5,   123,   125,  -125,  -125,   127,   102,
       5,     5,  -125,  -125,   109,   110,  -125,  -125,  -125,   128,
     105,   112,   130,   133,  -125,    73,     5,   134,  -125,  -125,
     106,   112,   113,   116,  -125,   143,   147,   135,     5,   119,
    -125,   112,   140,   150,  -125,   113,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    26,    29,    32,    35,    40,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     2,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    45,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    10,
       0,     0,     0,     0,    18,    24,    25,    28,    27,    31,
      30,    36,    37,    38,    39,     4,    15,     5,    50,    47,
      49,    46,     0,     0,     0,     0,    53,    52,     0,     0,
       0,     0,    16,    17,     0,     0,     8,     9,    12,     0,
       0,    22,     0,     0,    11,     0,     0,     0,     6,     7,
       0,    22,    20,     0,    21,     0,     0,     0,     0,     0,
      13,    22,     0,     0,    14,    20,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -125,  -125,    20,  -124,    -3,    62,    65,    67,   124,  -125,
    -125,   -39,  -125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,   136,   127,    21,    22,    23,    24,    25,    26,
      27,    70,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    71,    35,    43,    51,    52,    80,   134,    66,    67,
      74,    75,    51,    52,    36,    47,    48,   143,    51,    52,
      37,    58,    31,    53,    68,    69,    76,    91,    59,    60,
      61,    62,    51,    52,     1,     2,    44,    54,    55,    38,
      78,    92,     3,    32,    51,    52,     4,     5,     6,     7,
       8,     9,    10,    93,    56,    57,    11,    33,    12,    13,
      14,    72,    73,   114,   115,    34,    15,    45,    16,    17,
      18,   120,   121,    19,    51,    52,     1,     2,    46,    39,
      40,    41,    49,    94,     3,    42,    50,   131,     4,     5,
       6,     7,     8,     9,    10,    63,     3,    98,    99,   141,
       4,     5,     6,     7,     8,     9,    10,    51,    52,    51,
      52,   100,   101,    85,    86,    79,   109,    84,   133,    87,
      88,    64,   130,    89,    90,    28,    29,    65,    81,    95,
      96,    82,    83,    97,   102,   103,   106,   107,   104,   111,
     105,   108,   112,   110,   113,   116,   119,   117,   132,   118,
     124,   125,   128,   122,   123,   129,   138,   140,   126,   135,
     137,   139,   144,   142,   145,   146
};

static const yytype_uint8 yycheck[] =
{
       3,    40,    26,    11,     3,     4,    45,   131,     3,     4,
       3,     4,     3,     4,    38,    40,    41,   141,     3,     4,
      26,    12,    11,    22,    19,    20,    19,    12,    31,    32,
      33,    34,     3,     4,     3,     4,    44,     7,     8,    22,
      43,    12,    11,    11,     3,     4,    15,    16,    17,    18,
      19,    20,    21,    12,     9,    10,    25,    11,    27,    28,
      29,    33,    34,   102,   103,    11,    35,    11,    37,    38,
      39,   110,   111,    42,     3,     4,     3,     4,    43,    30,
      31,    32,    44,    12,    11,    36,     0,   126,    15,    16,
      17,    18,    19,    20,    21,    44,    11,    19,    20,   138,
      15,    16,    17,    18,    19,    20,    21,     3,     4,     3,
       4,    19,    20,    51,    52,    22,    12,    22,    12,    54,
      55,    44,   125,    56,    57,     1,     2,    44,    13,    22,
      22,    44,    44,    22,    45,    45,    19,    19,    44,    13,
      44,    44,    22,    45,    22,    22,    44,    22,    14,    22,
      22,    46,    22,    44,    44,    22,    13,    22,    46,    46,
      44,    14,    22,    44,    14,   145
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    11,    15,    16,    17,    18,    19,    20,
      21,    25,    27,    28,    29,    35,    37,    38,    39,    42,
      48,    51,    52,    53,    54,    55,    56,    57,    55,    55,
      51,    11,    11,    11,    11,    26,    38,    26,    22,    30,
      31,    32,    36,    11,    44,    11,    43,    40,    41,    44,
       0,     3,     4,    22,     7,     8,     9,    10,    12,    51,
      51,    51,    51,    44,    44,    44,     3,     4,    19,    20,
      58,    58,    33,    34,     3,     4,    19,    59,    51,    22,
      58,    13,    44,    44,    22,    52,    52,    53,    53,    54,
      54,    12,    12,    12,    12,    22,    22,    22,    19,    20,
      19,    20,    45,    45,    44,    44,    19,    19,    44,    12,
      45,    13,    22,    22,    58,    58,    22,    22,    22,    44,
      58,    58,    44,    44,    22,    46,    46,    50,    22,    22,
      51,    58,    14,    12,    50,    46,    49,    44,    13,    14,
      22,    58,    44,    50,    22,    14,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    52,    52,    52,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     4,     4,     7,     7,     5,     5,
       3,     6,     5,    10,    11,     4,     4,     4,     3,     6,
       0,     3,     0,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     2,     2,     1,     4,     4,     4,     4,
       1,     3,     1,     1,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 114 "sintatico.y"
              {                                                                                                                 // ✅ | ✅ 
        AST_TEMP = (yyvsp[-1].ast);
        if(AST_TEMP)
        {
            printf("\nFunction in RPN format:\n\n");
            RPN_Walk(AST_TEMP);
            Delete_Tree(AST_TEMP);
            printf("\n\n");
        }
        return 0;
    }
#line 1499 "sintatico.tab.c"
    break;

  case 3:
#line 125 "sintatico.y"
               {                                                                                                                // ✅ | ✅ 
        option = quit;
        return 0;
    }
#line 1508 "sintatico.tab.c"
    break;

  case 4:
#line 129 "sintatico.y"
                                  {                                                                                             // ✅ | ✅ 
        showSettings(settings);    
        return 0;
    }
#line 1517 "sintatico.tab.c"
    break;

  case 5:
#line 133 "sintatico.y"
                                   {                                                                                            // ✅ | ✅ 
        setDefaultSettings(settings);        
        return 0;
    }
#line 1526 "sintatico.tab.c"
    break;

  case 6:
#line 137 "sintatico.y"
                                                 {                                                                              // ✅ | ✅
        if((yyvsp[-2].real) <= (yyvsp[-4].real)) {
            yyerror(error_h_view);
            YYERROR;
        }

        settings->h_view_lo = (yyvsp[-4].real);
        settings->h_view_hi = (yyvsp[-2].real);
        
        return 0;
    }
#line 1542 "sintatico.tab.c"
    break;

  case 7:
#line 148 "sintatico.y"
                                                 {                                                                              // ✅ | ✅
        if((yyvsp[-2].real) <= (yyvsp[-4].real)) {
            yyerror(error_v_view);
            YYERROR;
        }
        
        settings->v_view_lo = (yyvsp[-4].real);
        settings->v_view_hi = (yyvsp[-2].real);
        
        return 0;
    }
#line 1558 "sintatico.tab.c"
    break;

  case 8:
#line 159 "sintatico.y"
                                {                                                                                               // ✅ | ✅ 
        settings->draw_axis = 1;
        
        return 0;
    }
#line 1568 "sintatico.tab.c"
    break;

  case 9:
#line 164 "sintatico.y"
                                 {                                                                                              // ✅ | ✅ 
        settings->draw_axis = 0;
        
        return 0;
    }
#line 1578 "sintatico.tab.c"
    break;

  case 10:
#line 169 "sintatico.y"
                         {                                                                                                      // ✅ | ✅        
        if(!functionInserted) {
            printf("\nNo Function defined!\n\n");
            return 0;
        }
        plot(AST, settings);
        return 0;
    }
#line 1591 "sintatico.tab.c"
    break;

  case 11:
#line 177 "sintatico.y"
                                             {                                                                                  // ✅ | ✅        
        AST = (yyvsp[-3].ast);
        functionInserted = 1;
        if(AST) {
            plot(AST, settings);
        }
        return 0;
    }
#line 1604 "sintatico.tab.c"
    break;

  case 12:
#line 185 "sintatico.y"
                                           {                                                                                    // ✅ | ✅
        if((yyvsp[-2].integer) < 1) {
            yyerror(error_set_int);
            YYERROR;
        }
        settings->integral_steps = (yyvsp[-2].integer);
        
        return 0;
    }
#line 1618 "sintatico.tab.c"
    break;

  case 13:
#line 194 "sintatico.y"
                                                                          {                                                     // ✅ | ✅       
        AST = (yyvsp[-3].ast);
        if((yyvsp[-7].real) >= (yyvsp[-5].real)) {
            yyerror(error_integrate);
            YYERROR;
        }
        if(AST)
        {
            printf("\n%6f\n\n", integrate((yyvsp[-7].real), (yyvsp[-5].real), AST, settings));
        }
        return 0;
    }
#line 1635 "sintatico.tab.c"
    break;

  case 14:
#line 206 "sintatico.y"
                                                                                                                             {  // ⏳ | ⏳       
        matrixX[0][0] = (yyvsp[-6].real);
        wMatrix = larguraMax;
        hMatrix = altura;
        altura = 1;
        larguraMax = 1;
        int i,j;
        for(i=0;i<hMatrix;i++) {
            for(j=0;j<wMatrix;j++) {
                printf("%.6f ", matrixX[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
#line 1655 "sintatico.tab.c"
    break;

  case 15:
#line 221 "sintatico.y"
                                {                                                                                               // ⏳ | ✅        
        if(!matrixInserted) {
            printf("\nNo Matrix defined!\n\n");
            return 0;
        }
        return 0;
    }
#line 1667 "sintatico.tab.c"
    break;

  case 16:
#line 228 "sintatico.y"
                                      {                                                                                         // ⏳ | ✅       
        if(!matrixInserted) {
            printf("\nNo Matrix defined!\n\n");
            return 0;
        }
        return 0;
    }
#line 1679 "sintatico.tab.c"
    break;

  case 17:
#line 235 "sintatico.y"
                                        {                                                                                       // ⏳ | ⏳        
        return 0;
    }
#line 1687 "sintatico.tab.c"
    break;

  case 18:
#line 238 "sintatico.y"
                          {                                                                                                     // ✅ | ✅
        printAbout();        
        return 0;
    }
#line 1696 "sintatico.tab.c"
    break;

  case 19:
#line 244 "sintatico.y"
                                                                       {
    }
#line 1703 "sintatico.tab.c"
    break;

  case 20:
#line 246 "sintatico.y"
      {}
#line 1709 "sintatico.tab.c"
    break;

  case 21:
#line 249 "sintatico.y"
                                 {
    
    }
#line 1717 "sintatico.tab.c"
    break;

  case 22:
#line 252 "sintatico.y"
      {}
#line 1723 "sintatico.tab.c"
    break;

  case 23:
#line 256 "sintatico.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1729 "sintatico.tab.c"
    break;

  case 24:
#line 257 "sintatico.y"
                      {
        TreeNode* aux = createNode(ADD, 0.0, (yyvsp[-2].ast), (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1738 "sintatico.tab.c"
    break;

  case 25:
#line 261 "sintatico.y"
                       {
        TreeNode* aux = createNode(SUB, 0.0, (yyvsp[-2].ast), (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1747 "sintatico.tab.c"
    break;

  case 26:
#line 267 "sintatico.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1753 "sintatico.tab.c"
    break;

  case 27:
#line 268 "sintatico.y"
                          {
        TreeNode* aux = createNode(DIV, 0.0, (yyvsp[-2].ast), (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1762 "sintatico.tab.c"
    break;

  case 28:
#line 272 "sintatico.y"
                               {
        TreeNode* aux = createNode(MULTIPLY, 0.0, (yyvsp[-2].ast), (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1771 "sintatico.tab.c"
    break;

  case 29:
#line 278 "sintatico.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1777 "sintatico.tab.c"
    break;

  case 30:
#line 279 "sintatico.y"
                                {
        TreeNode* aux = createNode(REMAINDER, 0.0, (yyvsp[-2].ast), (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1786 "sintatico.tab.c"
    break;

  case 31:
#line 283 "sintatico.y"
                            {
        TreeNode* aux = createNode(POWER, 0.0, (yyvsp[-2].ast), (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1795 "sintatico.tab.c"
    break;

  case 32:
#line 289 "sintatico.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1801 "sintatico.tab.c"
    break;

  case 33:
#line 290 "sintatico.y"
                    {
        TreeNode* aux = createNode(PLUS, 0.0, NULL, (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1810 "sintatico.tab.c"
    break;

  case 34:
#line 294 "sintatico.y"
                     {
        TreeNode* aux = createNode(MINUS, 0.0, NULL, (yyvsp[0].ast));
        (yyval.ast) = aux;
    }
#line 1819 "sintatico.tab.c"
    break;

  case 35:
#line 300 "sintatico.y"
                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1825 "sintatico.tab.c"
    break;

  case 36:
#line 301 "sintatico.y"
                              {
        TreeNode* aux = createNode(SEN, 0.0, NULL, (yyvsp[-1].ast));
        (yyval.ast) = aux;
    }
#line 1834 "sintatico.tab.c"
    break;

  case 37:
#line 305 "sintatico.y"
                              {
        TreeNode* aux = createNode(COS, 0.0, NULL, (yyvsp[-1].ast));
        (yyval.ast) = aux;
    }
#line 1843 "sintatico.tab.c"
    break;

  case 38:
#line 309 "sintatico.y"
                              {
        TreeNode* aux = createNode(TAN, 0.0, NULL, (yyvsp[-1].ast));
        (yyval.ast) = aux;
    }
#line 1852 "sintatico.tab.c"
    break;

  case 39:
#line 313 "sintatico.y"
                              {
        TreeNode* aux = createNode(ABS, 0.0, NULL, (yyvsp[-1].ast));
        (yyval.ast) = aux;
    }
#line 1861 "sintatico.tab.c"
    break;

  case 40:
#line 319 "sintatico.y"
              { (yyval.ast) = (yyvsp[0].ast); }
#line 1867 "sintatico.tab.c"
    break;

  case 41:
#line 320 "sintatico.y"
                          {
        TreeNode* aux = createNode(L_PAREN, 0.0, NULL, (yyvsp[-1].ast));
        (yyval.ast) = aux;
    }
#line 1876 "sintatico.tab.c"
    break;

  case 42:
#line 326 "sintatico.y"
                  {
        TreeNode* aux = createNode(NUM_INTEGER, (yyvsp[0].integer) * 1.0, NULL, NULL);
        (yyval.ast) = (TreeNode*) aux;
    }
#line 1885 "sintatico.tab.c"
    break;

  case 43:
#line 330 "sintatico.y"
               {
        TreeNode* aux = createNode(NUM_REAL, (yyvsp[0].real), NULL, NULL);
        (yyval.ast) = (TreeNode*) aux;
    }
#line 1894 "sintatico.tab.c"
    break;

  case 44:
#line 334 "sintatico.y"
               {
        TreeNode* aux = createNode(VARIABLE, 0.0, NULL, NULL);
        (yyval.ast) = (TreeNode*) aux;
    }
#line 1903 "sintatico.tab.c"
    break;

  case 45:
#line 340 "sintatico.y"
                {
        (yyval.real) = (yyvsp[0].real);
    }
#line 1911 "sintatico.tab.c"
    break;

  case 46:
#line 343 "sintatico.y"
                     {
        (yyval.real) = -(yyvsp[0].real);
    }
#line 1919 "sintatico.tab.c"
    break;

  case 47:
#line 346 "sintatico.y"
                    {
        (yyval.real) = (yyvsp[0].real);
    }
#line 1927 "sintatico.tab.c"
    break;

  case 48:
#line 349 "sintatico.y"
                  {
        (yyval.real) = (yyvsp[0].integer) * 1.0;
    }
#line 1935 "sintatico.tab.c"
    break;

  case 49:
#line 352 "sintatico.y"
                        {
        (yyval.real) = -(yyvsp[0].integer) * 1.0;
    }
#line 1943 "sintatico.tab.c"
    break;

  case 50:
#line 355 "sintatico.y"
                       {
        (yyval.real) = (yyvsp[0].integer) * 1.0;
    }
#line 1951 "sintatico.tab.c"
    break;

  case 51:
#line 360 "sintatico.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 1959 "sintatico.tab.c"
    break;

  case 52:
#line 363 "sintatico.y"
                        {
        (yyval.integer) = -(yyvsp[0].integer);
    }
#line 1967 "sintatico.tab.c"
    break;

  case 53:
#line 366 "sintatico.y"
                       {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 1975 "sintatico.tab.c"
    break;


#line 1979 "sintatico.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 371 "sintatico.y"


void yyerror(char *s) {
    switch(yychar) {
        case LEXICAL_ERROR:
            printf("Simbolo Invalido -> %s\n\n", yytext);
            option = error;
			break;
        case EOL:
            printf("Erro de Sintaxe: [$]\n\n");
            break;
        default:
            if(!strcmp(s, "syntax error"))
                printf("Erro de Sintaxe: [%s]\n\n", yytext);
            else
                printf("%s\n\n", s);
            option = error;
			break;
    }

    clearBuffer();
}

void printAbout() {
    int i;

    printf("\n+");
    for(i=1;i<colunas-1;i++) {
        printf("-");
    }
    printf("+");
    
    printf("\n|");
    for(i=1;i<colunas-1;i++) {
        printf(" ");
    }
    printf("|");
    
    printf("|                   201800560608 - Renan Ricoldi Fróis Pedro                   |");

    printf("\n|");
    for(i=1;i<colunas-1;i++) {
        printf(" ");
    }
    printf("|");

    printf("\n+");
    for(i=1;i<colunas-1;i++) {
        printf("-");
    }
    printf("+\n\n");
}

int main() {
    // #ifdef YYDEBUG
    //     yydebug = 1;
    // #endif
    settings = createSettings();
    
    int i,j;
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++) {
            matrixX[i][j] = 0.0;
        }
    }

    do {
        // if(option != error)
        printf(">");
        yyparse();
    
        // switch (option) {
        //     case quit:
        //         return 0;
        //     case rpn:
        //         printf("\n");
        //     default:
        //         break;
        // }
        // // printf("\n");
    } while(option != quit);
    
    return 0;
}
