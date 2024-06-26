/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "table_of_symbols.h"

struct SymbolTable mySymbolsTable;

#line 79 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tADD = 3,                       /* tADD  */
  YYSYMBOL_tSUB = 4,                       /* tSUB  */
  YYSYMBOL_tMUL = 5,                       /* tMUL  */
  YYSYMBOL_tDIV = 6,                       /* tDIV  */
  YYSYMBOL_tLT = 7,                        /* tLT  */
  YYSYMBOL_tGT = 8,                        /* tGT  */
  YYSYMBOL_tNE = 9,                        /* tNE  */
  YYSYMBOL_tEQ = 10,                       /* tEQ  */
  YYSYMBOL_tGE = 11,                       /* tGE  */
  YYSYMBOL_tLE = 12,                       /* tLE  */
  YYSYMBOL_tASSIGN = 13,                   /* tASSIGN  */
  YYSYMBOL_tAND = 14,                      /* tAND  */
  YYSYMBOL_tOR = 15,                       /* tOR  */
  YYSYMBOL_tNOT = 16,                      /* tNOT  */
  YYSYMBOL_tLBRACE = 17,                   /* tLBRACE  */
  YYSYMBOL_tRBRACE = 18,                   /* tRBRACE  */
  YYSYMBOL_tLPAR = 19,                     /* tLPAR  */
  YYSYMBOL_tRPAR = 20,                     /* tRPAR  */
  YYSYMBOL_tSEMI = 21,                     /* tSEMI  */
  YYSYMBOL_tCOMMA = 22,                    /* tCOMMA  */
  YYSYMBOL_tIF = 23,                       /* tIF  */
  YYSYMBOL_tELSE = 24,                     /* tELSE  */
  YYSYMBOL_tWHILE = 25,                    /* tWHILE  */
  YYSYMBOL_tPRINT = 26,                    /* tPRINT  */
  YYSYMBOL_tRETURN = 27,                   /* tRETURN  */
  YYSYMBOL_tINT = 28,                      /* tINT  */
  YYSYMBOL_tVOID = 29,                     /* tVOID  */
  YYSYMBOL_tMAIN = 30,                     /* tMAIN  */
  YYSYMBOL_tERROR = 31,                    /* tERROR  */
  YYSYMBOL_tNB = 32,                       /* tNB  */
  YYSYMBOL_tID = 33,                       /* tID  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_main_function = 36,             /* main_function  */
  YYSYMBOL_function_type = 37,             /* function_type  */
  YYSYMBOL_parameter_list = 38,            /* parameter_list  */
  YYSYMBOL_parameter = 39,                 /* parameter  */
  YYSYMBOL_parameter_type = 40,            /* parameter_type  */
  YYSYMBOL_body = 41,                      /* body  */
  YYSYMBOL_instruction_list = 42,          /* instruction_list  */
  YYSYMBOL_declaration_list = 43,          /* declaration_list  */
  YYSYMBOL_declaration = 44,               /* declaration  */
  YYSYMBOL_declaration_type = 45,          /* declaration_type  */
  YYSYMBOL_identifiers_list = 46,          /* identifiers_list  */
  YYSYMBOL_instruction = 47,               /* instruction  */
  YYSYMBOL_assignment_list = 48,           /* assignment_list  */
  YYSYMBOL_ifblock = 49,                   /* ifblock  */
  YYSYMBOL_whileblock = 50,                /* whileblock  */
  YYSYMBOL_printblock = 51,                /* printblock  */
  YYSYMBOL_condition = 52,                 /* condition  */
  YYSYMBOL_equality_expression = 53,       /* equality_expression  */
  YYSYMBOL_compare = 54,                   /* compare  */
  YYSYMBOL_add_sub = 55,                   /* add_sub  */
  YYSYMBOL_div_mul = 56,                   /* div_mul  */
  YYSYMBOL_single_value = 57               /* single_value  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    28,    28,    29,    34,    38,    39,    43,    44,    45,
      46,    50,    51,    55,    59,    60,    61,    62,    66,    67,
      71,    72,    76,    80,    84,    87,    90,    93,    99,   100,
     101,   102,   106,   109,   114,   115,   116,   120,   124,   128,
     129,   130,   131,   135,   136,   137,   141,   142,   143,   144,
     145,   149,   150,   151,   155,   157,   159,   164,   166
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tADD", "tSUB", "tMUL",
  "tDIV", "tLT", "tGT", "tNE", "tEQ", "tGE", "tLE", "tASSIGN", "tAND",
  "tOR", "tNOT", "tLBRACE", "tRBRACE", "tLPAR", "tRPAR", "tSEMI", "tCOMMA",
  "tIF", "tELSE", "tWHILE", "tPRINT", "tRETURN", "tINT", "tVOID", "tMAIN",
  "tERROR", "tNB", "tID", "$accept", "program", "main_function",
  "function_type", "parameter_list", "parameter", "parameter_type", "body",
  "instruction_list", "declaration_list", "declaration",
  "declaration_type", "identifiers_list", "instruction", "assignment_list",
  "ifblock", "whileblock", "printblock", "condition",
  "equality_expression", "compare", "add_sub", "div_mul", "single_value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      24,   -89,   -89,    26,   -89,     3,   -89,    32,    27,   -89,
     -89,    -5,   -89,    13,    19,    35,    61,     2,   -89,    25,
      60,    62,    63,   -89,    64,    65,     6,     2,   -89,    47,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,    50,    37,    58,
      59,   -89,    31,    31,    51,    25,   -89,   -89,     6,   -89,
      72,    45,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    31,    25,    -1,    23,    66,     0,    25,   -89,
      55,    37,    37,    58,    58,    58,    58,    59,    59,   -89,
     -89,    54,    -4,    31,    31,    70,    73,    57,   -89,    56,
      58,    78,   -89,    54,    54,     2,     2,   -89,   -89,    25,
      74,    75,    58,    71,   -89,    17,     2,   -89,    76,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     6,     5,     0,     3,     0,     1,     0,     7,    13,
       8,     0,     9,     0,     0,     0,    11,    14,    10,     0,
       0,     0,     0,    23,     0,     0,    16,    15,    20,     0,
      18,    28,    29,    30,    31,    58,    57,    12,    43,    46,
      51,    54,     0,     0,     0,     0,     4,    19,    17,    21,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    45,    44,    47,    48,    50,    49,    52,    53,    55,
      56,    42,     0,     0,     0,     0,     0,     0,    32,     0,
      25,    26,    39,    40,    41,    14,    14,    38,    33,     0,
       0,     0,    27,    34,    37,     0,    14,    36,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,    81,   -89,   -88,    77,   -89,
      79,   -89,   -89,   -24,     8,    -7,   -89,   -89,   -42,    36,
      18,   -45,    14,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    11,    12,    13,    25,    26,    27,
      28,    29,    51,    30,    31,    32,    33,    34,    64,    37,
      38,    39,    40,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    65,    47,    58,    59,    52,    53,   100,   101,    73,
      74,    75,    76,    83,    84,    14,    92,    15,   108,    85,
      81,    88,    89,    90,    47,    20,     6,    21,    22,    20,
      23,    21,    22,     7,   106,    24,    17,    83,    84,    24,
      20,    93,    94,    86,    54,    55,    16,    62,    56,    57,
      63,     8,     1,     2,   102,     9,    10,    35,    36,    52,
      53,    58,    59,     9,    60,    61,    69,    70,    83,    84,
      71,    72,    77,    78,    19,    79,    80,    45,    97,    42,
      50,    43,    44,    46,    66,    68,    87,    95,    91,    24,
      96,    99,   103,   104,   109,   105,    18,    98,   107,    82,
       0,     0,     0,     0,    48,     0,    49
};

static const yytype_int8 yycheck[] =
{
      45,    43,    26,     3,     4,     9,    10,    95,    96,    54,
      55,    56,    57,    14,    15,    20,    20,    22,   106,    20,
      62,    21,    22,    68,    48,    23,     0,    25,    26,    23,
      28,    25,    26,    30,    17,    33,    17,    14,    15,    33,
      23,    83,    84,    20,     7,     8,    33,    16,    11,    12,
      19,    19,    28,    29,    99,    28,    29,    32,    33,     9,
      10,     3,     4,    28,     5,     6,    21,    22,    14,    15,
      52,    53,    58,    59,    13,    60,    61,    13,    21,    19,
      33,    19,    19,    18,    33,    13,    20,    17,    33,    33,
      17,    13,    18,    18,    18,    24,    15,    89,   105,    63,
      -1,    -1,    -1,    -1,    27,    -1,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    29,    35,    36,    37,     0,    30,    19,    28,
      29,    38,    39,    40,    20,    22,    33,    17,    39,    13,
      23,    25,    26,    28,    33,    41,    42,    43,    44,    45,
      47,    48,    49,    50,    51,    32,    33,    53,    54,    55,
      56,    57,    19,    19,    19,    13,    18,    47,    42,    44,
      33,    46,     9,    10,     7,     8,    11,    12,     3,     4,
       5,     6,    16,    19,    52,    52,    33,    55,    13,    21,
      22,    54,    54,    55,    55,    55,    55,    56,    56,    57,
      57,    52,    53,    14,    15,    20,    20,    20,    21,    22,
      55,    33,    20,    52,    52,    17,    17,    21,    48,    13,
      41,    41,    55,    18,    18,    24,    17,    49,    41,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    36,    37,    37,    38,    38,    38,
      38,    39,    39,    40,    41,    41,    41,    41,    42,    42,
      43,    43,    44,    45,    46,    46,    46,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    50,    51,    52,
      52,    52,    52,    53,    53,    53,    54,    54,    54,    54,
      54,    55,    55,    55,    56,    56,    56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     8,     1,     1,     0,     1,     1,
       3,     2,     4,     1,     0,     1,     1,     2,     1,     2,
       1,     2,     3,     1,     1,     3,     3,     5,     1,     1,
       1,     1,     4,     5,     7,    11,     9,     7,     5,     3,
       3,     3,     2,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: %empty  */
#line 28 "parser.y"
                                                                                   { printf("program: empty\n\n"); }
#line 1189 "parser.tab.c"
    break;

  case 3: /* program: main_function  */
#line 29 "parser.y"
                                                                                   { printf("program: main\n\n"); }
#line 1195 "parser.tab.c"
    break;

  case 4: /* main_function: function_type tMAIN tLPAR parameter_list tRPAR tLBRACE body tRBRACE  */
#line 34 "parser.y"
                                                                                 { printf("main function\n\n"); }
#line 1201 "parser.tab.c"
    break;

  case 5: /* function_type: tVOID  */
#line 38 "parser.y"
                                                                                  { printf("function type: void\n\n"); }
#line 1207 "parser.tab.c"
    break;

  case 6: /* function_type: tINT  */
#line 39 "parser.y"
                                                                                   { printf("function type: int\n\n"); }
#line 1213 "parser.tab.c"
    break;

  case 7: /* parameter_list: %empty  */
#line 43 "parser.y"
                                                                                  { printf("parameter_list: empty\n\n"); }
#line 1219 "parser.tab.c"
    break;

  case 8: /* parameter_list: tVOID  */
#line 44 "parser.y"
                                                                                   { printf("parameter_list: void\n\n"); }
#line 1225 "parser.tab.c"
    break;

  case 9: /* parameter_list: parameter  */
#line 45 "parser.y"
                                                                                   { printf("parameter_list: with a parameter\n\n"); }
#line 1231 "parser.tab.c"
    break;

  case 10: /* parameter_list: parameter_list tCOMMA parameter  */
#line 46 "parser.y"
                                                                                   { printf("parameter_list: with several parameters\n\n"); }
#line 1237 "parser.tab.c"
    break;

  case 11: /* parameter: parameter_type tID  */
#line 50 "parser.y"
                                                                                  { printf("parameter: id '%s'\n\n", (yyvsp[0].var)); }
#line 1243 "parser.tab.c"
    break;

  case 12: /* parameter: parameter_type tID tASSIGN equality_expression  */
#line 51 "parser.y"
                                                                                   { printf("parameter and initialization: id '%s'\n\n", (yyvsp[-2].var)); }
#line 1249 "parser.tab.c"
    break;

  case 13: /* parameter_type: tINT  */
#line 55 "parser.y"
                                                                                   { printf("parameter_type: int\n\n"); }
#line 1255 "parser.tab.c"
    break;

  case 14: /* body: %empty  */
#line 59 "parser.y"
                                                                                    { printf("body: empty\n\n"); }
#line 1261 "parser.tab.c"
    break;

  case 15: /* body: declaration_list  */
#line 60 "parser.y"
                                                                                     { printf("body: declaration_list\n\n"); }
#line 1267 "parser.tab.c"
    break;

  case 16: /* body: instruction_list  */
#line 61 "parser.y"
                                                                                     { printf("body: instruction_list\n\n"); }
#line 1273 "parser.tab.c"
    break;

  case 17: /* body: declaration_list instruction_list  */
#line 62 "parser.y"
                                                                                     { printf("body: declaration&instruction list\n\n"); }
#line 1279 "parser.tab.c"
    break;

  case 18: /* instruction_list: instruction  */
#line 66 "parser.y"
                                                                                    { printf("an instruction\n\n"); }
#line 1285 "parser.tab.c"
    break;

  case 19: /* instruction_list: instruction_list instruction  */
#line 67 "parser.y"
                                                                                     { printf("several instructions\n\n"); }
#line 1291 "parser.tab.c"
    break;

  case 20: /* declaration_list: declaration  */
#line 71 "parser.y"
                                                                                   { printf("a declaration\n\n"); }
#line 1297 "parser.tab.c"
    break;

  case 21: /* declaration_list: declaration_list declaration  */
#line 72 "parser.y"
                                                                                    { printf("several declarations\n\n"); }
#line 1303 "parser.tab.c"
    break;

  case 22: /* declaration: declaration_type identifiers_list tSEMI  */
#line 76 "parser.y"
                                                                                    { printf("declaration\n\n"); }
#line 1309 "parser.tab.c"
    break;

  case 23: /* declaration_type: tINT  */
#line 80 "parser.y"
                                                                                   { printf("declaration_type: int\n\n"); }
#line 1315 "parser.tab.c"
    break;

  case 24: /* identifiers_list: tID  */
#line 85 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[0].var)); 
    printf("identifier: '%s'\n\n", (yyvsp[0].var)); }
#line 1322 "parser.tab.c"
    break;

  case 25: /* identifiers_list: tID tASSIGN add_sub  */
#line 88 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[-2].var)); 
    printf("declaration and initialization: '%s'\n\n", (yyvsp[-2].var)); }
#line 1329 "parser.tab.c"
    break;

  case 26: /* identifiers_list: identifiers_list tCOMMA tID  */
#line 91 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[0].var)); 
    printf("several identifiers: '%s'\n\n", (yyvsp[0].var)); }
#line 1336 "parser.tab.c"
    break;

  case 27: /* identifiers_list: identifiers_list tCOMMA tID tASSIGN add_sub  */
#line 94 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[-2].var)); 
    printf("several identifiers: '%s'\n\n", (yyvsp[-2].var)); }
#line 1343 "parser.tab.c"
    break;

  case 28: /* instruction: assignment_list  */
#line 99 "parser.y"
                                                                                 { printf("instruction: assignment\n\n"); }
#line 1349 "parser.tab.c"
    break;

  case 29: /* instruction: ifblock  */
#line 100 "parser.y"
                                                                                   { printf("instruction: if block\n\n"); }
#line 1355 "parser.tab.c"
    break;

  case 30: /* instruction: whileblock  */
#line 101 "parser.y"
                                                                                   { printf("instruction: while block\n\n"); }
#line 1361 "parser.tab.c"
    break;

  case 31: /* instruction: printblock  */
#line 102 "parser.y"
                                                                                   { printf("instruction: print block\n\n"); }
#line 1367 "parser.tab.c"
    break;

  case 32: /* assignment_list: tID tASSIGN add_sub tSEMI  */
#line 107 "parser.y"
  { printf("assignment: '%s'\n\n", (yyvsp[-3].var)); }
#line 1373 "parser.tab.c"
    break;

  case 33: /* assignment_list: tID tASSIGN add_sub tCOMMA assignment_list  */
#line 110 "parser.y"
  { printf("assignment: '%s'\n\n", (yyvsp[-4].var)); }
#line 1379 "parser.tab.c"
    break;

  case 34: /* ifblock: tIF tLPAR condition tRPAR tLBRACE body tRBRACE  */
#line 114 "parser.y"
                                                                                       { printf("if block: if\n\n"); }
#line 1385 "parser.tab.c"
    break;

  case 35: /* ifblock: tIF tLPAR condition tRPAR tLBRACE body tRBRACE tELSE tLBRACE body tRBRACE  */
#line 115 "parser.y"
                                                                                       { printf("if block: if else \n\n"); }
#line 1391 "parser.tab.c"
    break;

  case 36: /* ifblock: tIF tLPAR condition tRPAR tLBRACE body tRBRACE tELSE ifblock  */
#line 116 "parser.y"
                                                                                       { printf("if block: if else if\n\n"); }
#line 1397 "parser.tab.c"
    break;

  case 37: /* whileblock: tWHILE tLPAR condition tRPAR tLBRACE body tRBRACE  */
#line 120 "parser.y"
                                                                                       { printf("while block\n\n"); }
#line 1403 "parser.tab.c"
    break;

  case 38: /* printblock: tPRINT tLPAR tID tRPAR tSEMI  */
#line 124 "parser.y"
                                                                                         { printf("print block: '%s'\n\n", (yyvsp[-2].var)); }
#line 1409 "parser.tab.c"
    break;

  case 39: /* condition: tLPAR equality_expression tRPAR  */
#line 128 "parser.y"
                                                                                        { printf("condition\n\n"); }
#line 1415 "parser.tab.c"
    break;

  case 40: /* condition: condition tAND condition  */
#line 129 "parser.y"
                                                                                        { printf("condition: and\n\n"); }
#line 1421 "parser.tab.c"
    break;

  case 41: /* condition: condition tOR condition  */
#line 130 "parser.y"
                                                                                        { printf("condition: or\n\n"); }
#line 1427 "parser.tab.c"
    break;

  case 42: /* condition: tNOT condition  */
#line 131 "parser.y"
                                                                                        { printf("condition: not\n\n"); }
#line 1433 "parser.tab.c"
    break;

  case 43: /* equality_expression: compare  */
#line 135 "parser.y"
                                                                                  { printf("equality_expression: compare\n\n"); }
#line 1439 "parser.tab.c"
    break;

  case 44: /* equality_expression: equality_expression tEQ compare  */
#line 136 "parser.y"
                                                                                  { printf("equality_expression: equal\n\n"); }
#line 1445 "parser.tab.c"
    break;

  case 45: /* equality_expression: equality_expression tNE compare  */
#line 137 "parser.y"
                                                                                  { printf("equality_expression: not equal\n\n"); }
#line 1451 "parser.tab.c"
    break;

  case 46: /* compare: add_sub  */
#line 141 "parser.y"
                                                                                        { printf("compare: add_sub\n\n"); }
#line 1457 "parser.tab.c"
    break;

  case 47: /* compare: compare tLT add_sub  */
#line 142 "parser.y"
                                                                                        { printf("compare: less than\n\n"); }
#line 1463 "parser.tab.c"
    break;

  case 48: /* compare: compare tGT add_sub  */
#line 143 "parser.y"
                                                                                        { printf("compare: greater than\n\n"); }
#line 1469 "parser.tab.c"
    break;

  case 49: /* compare: compare tLE add_sub  */
#line 144 "parser.y"
                                                                                        { printf("compare: less or equal\n\n"); }
#line 1475 "parser.tab.c"
    break;

  case 50: /* compare: compare tGE add_sub  */
#line 145 "parser.y"
                                                                                        { printf("compare: greater or equal\n\n"); }
#line 1481 "parser.tab.c"
    break;

  case 51: /* add_sub: div_mul  */
#line 149 "parser.y"
                                                                                 { printf("add_sub: div_mul\n\n"); }
#line 1487 "parser.tab.c"
    break;

  case 52: /* add_sub: add_sub tADD div_mul  */
#line 150 "parser.y"
                                                                                        { printf("add_sub: addition\n\n"); }
#line 1493 "parser.tab.c"
    break;

  case 53: /* add_sub: add_sub tSUB div_mul  */
#line 151 "parser.y"
                                                                                        { printf("add_sub: substraction\n\n"); }
#line 1499 "parser.tab.c"
    break;

  case 54: /* div_mul: single_value  */
#line 156 "parser.y"
  { printf("div_mul: single_value %d\n\n", (yyvsp[0].nb)); }
#line 1505 "parser.tab.c"
    break;

  case 55: /* div_mul: div_mul tMUL single_value  */
#line 158 "parser.y"
  { printf("div_mul: multiplication\n\n"); }
#line 1511 "parser.tab.c"
    break;

  case 56: /* div_mul: div_mul tDIV single_value  */
#line 160 "parser.y"
  { printf("div_mul: division\n\n"); }
#line 1517 "parser.tab.c"
    break;

  case 57: /* single_value: tID  */
#line 165 "parser.y"
  { printf("single_value: identifier '%s'\n\n", (yyvsp[0].var)); }
#line 1523 "parser.tab.c"
    break;

  case 58: /* single_value: tNB  */
#line 167 "parser.y"
  { printf("single_value: number '%d'\n\n", (yyvsp[0].nb)); }
#line 1529 "parser.tab.c"
    break;


#line 1533 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 175 "parser.y"


void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
  initialize_table(&mySymbolsTable);
  yyparse();
  return 0;
}
