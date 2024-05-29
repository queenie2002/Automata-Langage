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
#line 4 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "table_of_symbols.h"
#include "table_of_instructions.h"
#include "table_of_functions.h"

struct SymbolTable mySymbolsTable;
struct DeletedSymbolsTable myDeletedSymbolsTable;
struct InstructionTable myInstructionTable;
struct FunctionTable myFunctionTable;

#line 84 "parser.tab.c"

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
  YYSYMBOL_tCONST = 31,                    /* tCONST  */
  YYSYMBOL_tERROR = 32,                    /* tERROR  */
  YYSYMBOL_tNB = 33,                       /* tNB  */
  YYSYMBOL_tID = 34,                       /* tID  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_37_action_start = 37,           /* action-start  */
  YYSYMBOL_function_list = 38,             /* function_list  */
  YYSYMBOL_function = 39,                  /* function  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_41_action_inc = 41,             /* action-inc  */
  YYSYMBOL_42_action_dec = 42,             /* action-dec  */
  YYSYMBOL_main_function = 43,             /* main_function  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_function_type = 45,             /* function_type  */
  YYSYMBOL_parameter_list = 46,            /* parameter_list  */
  YYSYMBOL_parameter = 47,                 /* parameter  */
  YYSYMBOL_variable_type = 48,             /* variable_type  */
  YYSYMBOL_functionCall = 49,              /* functionCall  */
  YYSYMBOL_50_action_call0 = 50,           /* action-call0  */
  YYSYMBOL_51_action_call1 = 51,           /* action-call1  */
  YYSYMBOL_argument_list = 52,             /* argument_list  */
  YYSYMBOL_body = 53,                      /* body  */
  YYSYMBOL_return = 54,                    /* return  */
  YYSYMBOL_instruction_list = 55,          /* instruction_list  */
  YYSYMBOL_declaration_list = 56,          /* declaration_list  */
  YYSYMBOL_declaration = 57,               /* declaration  */
  YYSYMBOL_identifiers_list = 58,          /* identifiers_list  */
  YYSYMBOL_instruction = 59,               /* instruction  */
  YYSYMBOL_assignment_list = 60,           /* assignment_list  */
  YYSYMBOL_ifblock = 61,                   /* ifblock  */
  YYSYMBOL_62_action_if = 62,              /* action-if  */
  YYSYMBOL_63_action_else = 63,            /* action-else  */
  YYSYMBOL_64_action_getIndex = 64,        /* action-getIndex  */
  YYSYMBOL_whileblock = 65,                /* whileblock  */
  YYSYMBOL_66_action_condition = 66,       /* action-condition  */
  YYSYMBOL_67_action_while = 67,           /* action-while  */
  YYSYMBOL_printblock = 68,                /* printblock  */
  YYSYMBOL_condition = 69,                 /* condition  */
  YYSYMBOL_equality_expression = 70,       /* equality_expression  */
  YYSYMBOL_compare = 71,                   /* compare  */
  YYSYMBOL_add_sub = 72,                   /* add_sub  */
  YYSYMBOL_div_mul = 73,                   /* div_mul  */
  YYSYMBOL_single_value = 74               /* single_value  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    38,    38,    41,    45,    51,    58,    61,    68,    67,
      79,    83,    89,    88,   103,   106,   111,   112,   113,   114,
     118,   125,   129,   148,   152,   162,   163,   167,   176,   181,
     186,   191,   195,   203,   214,   215,   220,   221,   226,   231,
     235,   244,   248,   262,   263,   264,   265,   270,   278,   291,
     300,   310,   321,   330,   338,   346,   358,   366,   375,   384,
     387,   393,   399,   408,   412,   419,   429,   432,   438,   444,
     450,   461,   465,   475,   488,   492,   502,   515,   522,   535
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
  "tCONST", "tERROR", "tNB", "tID", "$accept", "program", "action-start",
  "function_list", "function", "$@1", "action-inc", "action-dec",
  "main_function", "$@2", "function_type", "parameter_list", "parameter",
  "variable_type", "functionCall", "action-call0", "action-call1",
  "argument_list", "body", "return", "instruction_list",
  "declaration_list", "declaration", "identifiers_list", "instruction",
  "assignment_list", "ifblock", "action-if", "action-else",
  "action-getIndex", "whileblock", "action-condition", "action-while",
  "printblock", "condition", "equality_expression", "compare", "add_sub",
  "div_mul", "single_value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,    14,    44,   -63,   -63,   -63,    44,   -63,   -63,    29,
     -63,   -63,   -63,   -63,   -63,   -63,     6,     8,    46,    46,
     -63,   -63,    30,   -63,     1,    48,    27,    28,    74,    79,
      80,     5,   -63,    43,    66,     5,    84,    85,    86,    43,
      93,     1,    89,   -63,   -10,    15,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,    90,   -63,    69,    50,    77,    78,   -63,
      95,    92,   -12,   -63,   -12,    -1,    43,    64,   -63,   -63,
     -10,   -63,   -63,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,   -63,   -12,    22,    69,   -12,    33,
     -63,    -4,   -63,   -63,   -63,    50,    50,    77,    77,    77,
      77,    78,    78,   -63,   -63,    69,    75,   -12,   -12,   -63,
      40,    91,   -63,    81,    43,   -63,   -63,    94,   -63,   -63,
     -63,    49,    69,     5,    96,   -63,    43,    98,     5,    69,
     -63,    99,    97,   -63,   100,   -63,   101,     5,   102,   -63,
     -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,    15,    14,     0,     6,     3,     0,
       7,     4,    10,    10,    12,     8,     0,     0,    16,    16,
      21,    17,     0,    18,     0,     0,     0,     0,    39,    20,
       0,    28,    19,     0,     0,    28,     0,     0,     0,     0,
       0,     0,     0,    32,    30,    29,    36,    34,    43,    44,
      45,    46,    79,    78,    77,    40,    63,    66,    71,    74,
      41,     0,     0,    56,     0,     0,     0,     0,    11,    35,
      31,    37,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     0,    59,     0,     0,
      33,     0,    38,    13,    24,    65,    64,    67,    68,    70,
      69,    72,    73,    75,    76,    42,    62,     0,     0,    52,
       0,     0,    47,     0,    25,    60,    61,     0,    57,    58,
      48,     0,    27,    28,     0,    22,     0,     0,    28,    26,
      54,     0,    49,    55,    53,    51,     0,    28,     0,    54,
      50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,   108,   -63,   106,   -63,   116,   -63,
     -63,   105,   103,    -8,   -63,   -63,   -63,   -63,   -35,   -63,
      82,   -63,    83,    88,   -41,    13,    -9,   -63,   -63,    -7,
     -63,   -63,   -63,   -63,   -62,   -32,    18,   -11,    16,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,    17,    14,    93,     8,    16,
       9,    22,    23,    41,    54,    94,   114,   121,    42,    43,
      44,    45,    46,    29,    47,    48,    49,   117,   136,   132,
      50,    88,   124,    51,    86,    87,    56,    57,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    55,    89,    69,    85,    73,    74,    65,    73,    74,
      24,    24,    -2,    36,     3,    37,    38,   112,   113,    24,
      90,    52,    53,   106,    40,    18,   110,    19,    36,    69,
      37,    38,    39,    20,    91,    28,   107,   108,    36,    40,
      37,    38,   109,    20,    31,   115,   116,   107,   108,    40,
      26,   105,    27,   111,   107,   108,    20,    75,    76,    12,
     118,    77,    78,    13,    97,    98,    99,   100,    30,   125,
      27,   126,     4,     5,    20,    21,    52,    53,    73,    74,
      79,    80,   122,    81,    82,    92,    34,    33,   127,   107,
     108,    95,    96,   131,   129,   101,   102,    35,   103,   104,
      60,    34,   138,    62,    63,    64,    66,    68,    83,    72,
      84,   123,   119,   128,    10,    40,   130,   133,   137,    15,
     139,   134,    11,    36,    25,   135,   120,    70,    71,    67,
      32,     0,   140
};

static const yytype_int16 yycheck[] =
{
      35,    33,    64,    44,    16,     9,    10,    39,     9,    10,
      18,    19,     0,    23,     0,    25,    26,    21,    22,    27,
      21,    33,    34,    85,    34,    19,    88,    19,    23,    70,
      25,    26,    27,    28,    66,    34,    14,    15,    23,    34,
      25,    26,    20,    28,    17,   107,   108,    14,    15,    34,
      20,    83,    22,    20,    14,    15,    28,     7,     8,    30,
      20,    11,    12,    34,    75,    76,    77,    78,    20,    20,
      22,    22,    28,    29,    28,    29,    33,    34,     9,    10,
       3,     4,   114,     5,     6,    21,    22,    13,   123,    14,
      15,    73,    74,   128,   126,    79,    80,    17,    81,    82,
      34,    22,   137,    19,    19,    19,    13,    18,    13,    19,
      18,    17,    21,    17,     6,    34,    18,    18,    17,    13,
      18,    24,     6,    23,    19,   134,   113,    45,    45,    41,
      27,    -1,   139
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,    28,    29,    38,    39,    43,    45,
      39,    43,    30,    34,    41,    41,    44,    40,    19,    19,
      28,    29,    46,    47,    48,    46,    20,    22,    34,    58,
      20,    17,    47,    13,    22,    17,    23,    25,    26,    27,
      34,    48,    53,    54,    55,    56,    57,    59,    60,    61,
      65,    68,    33,    34,    49,    70,    71,    72,    73,    74,
      34,    53,    19,    19,    19,    70,    13,    58,    18,    59,
      55,    57,    19,     9,    10,     7,     8,    11,    12,     3,
       4,     5,     6,    13,    18,    16,    69,    70,    66,    69,
      21,    70,    21,    42,    50,    71,    71,    72,    72,    72,
      72,    73,    73,    74,    74,    70,    69,    14,    15,    20,
      69,    20,    21,    22,    51,    69,    69,    62,    20,    21,
      60,    52,    70,    17,    67,    20,    22,    53,    17,    70,
      18,    53,    64,    18,    24,    61,    63,    17,    53,    18,
      64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    36,    37,    38,    38,    40,    39,
      41,    42,    44,    43,    45,    45,    46,    46,    46,    46,
      47,    48,    49,    50,    51,    52,    52,    52,    53,    53,
      53,    53,    53,    54,    55,    55,    56,    56,    57,    58,
      58,    58,    58,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    73,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     0,     1,     2,     0,    10,
       0,     0,     0,    11,     1,     1,     0,     1,     1,     3,
       2,     1,     6,     0,     0,     0,     3,     1,     0,     1,
       1,     2,     1,     3,     1,     2,     1,     2,     3,     1,
       3,     3,     5,     1,     1,     1,     1,     4,     5,     9,
      15,    11,     0,     0,     0,     9,     0,     0,     5,     1,
       3,     3,     2,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     1,     1
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
#line 39 "parser.y"
  { printf("\t\t\t\tprogram: empty\n\n"); }
#line 1241 "parser.tab.c"
    break;

  case 3: /* program: action-start main_function  */
#line 42 "parser.y"
  { printf("\t\t\t\tprogram: main\n\n"); 
  add_instruction(&myInstructionTable, "NOP", 0, 0,0); }
#line 1248 "parser.tab.c"
    break;

  case 4: /* program: action-start function_list main_function  */
#line 46 "parser.y"
  { printf("\t\t\t\tprogram: main + functions\n\n"); 
    add_instruction(&myInstructionTable, "NOP", 0, 0,0); 
  }
#line 1256 "parser.tab.c"
    break;

  case 5: /* action-start: %empty  */
#line 52 "parser.y"
{ printf("\t\t\t\taction-start\n\n"); 
  add_instruction(&myInstructionTable,"JMP",-1,0,0);}
#line 1263 "parser.tab.c"
    break;

  case 6: /* function_list: function  */
#line 59 "parser.y"
  { printf("\t\t\t\t\t\t\t\tfunction_list: a function\n\n"); }
#line 1269 "parser.tab.c"
    break;

  case 7: /* function_list: function_list function  */
#line 62 "parser.y"
  { printf("\t\t\t\tfunction_list: functions\n\n"); }
#line 1275 "parser.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 68 "parser.y"
  {add_function(&myFunctionTable,(yyvsp[-1].var),get_index_actuel_instructions(&myInstructionTable));
  add_symb(&mySymbolsTable,"?ADR");
  add_symb(&mySymbolsTable,"?VAL");}
#line 1283 "parser.tab.c"
    break;

  case 9: /* function: function_type tID action-inc $@1 tLPAR parameter_list tRPAR tLBRACE body tRBRACE  */
#line 73 "parser.y"
  {decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
   add_instruction(&myInstructionTable,"RET",0,0,0);
   printf("\t\t\t\tfunction: %s\n\n", (yyvsp[-8].var)); }
#line 1291 "parser.tab.c"
    break;

  case 10: /* action-inc: %empty  */
#line 80 "parser.y"
  {increment_scope(&mySymbolsTable);
  printf("\t\t\t\tincrement scope: \n\n"); }
#line 1298 "parser.tab.c"
    break;

  case 11: /* action-dec: %empty  */
#line 84 "parser.y"
  {decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
  printf("\t\t\t\tdecrement scope: \n\n"); }
#line 1305 "parser.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 89 "parser.y"
  {add_function(&myFunctionTable,"main",get_index_actuel_instructions(&myInstructionTable));
  //WARNING j'ai commenté ces parties parce que le scope marche pas bien avec les fonctions  
  add_symb(&mySymbolsTable,"?ADR");
  add_symb(&mySymbolsTable,"?VAL");
  }
#line 1315 "parser.tab.c"
    break;

  case 13: /* main_function: function_type tMAIN action-inc $@2 tLPAR parameter_list tRPAR tLBRACE body tRBRACE action-dec  */
#line 96 "parser.y"
  { add_instruction(&myInstructionTable,"RET",0,0,0);
    int mainADDR = get_function_address(&myFunctionTable,"main");
    patch_instruction_arg1(&myInstructionTable,0,mainADDR);
    printf("\t\t\t\tmain function\n\n"); }
#line 1324 "parser.tab.c"
    break;

  case 14: /* function_type: tVOID  */
#line 104 "parser.y"
  { printf("\t\t\t\tfunction type: void\n\n"); }
#line 1330 "parser.tab.c"
    break;

  case 15: /* function_type: tINT  */
#line 107 "parser.y"
  { printf("\t\t\t\tfunction type: int\n\n"); }
#line 1336 "parser.tab.c"
    break;

  case 16: /* parameter_list: %empty  */
#line 111 "parser.y"
                                                                                  { printf("\t\t\t\tparameter_list: empty\n\n"); }
#line 1342 "parser.tab.c"
    break;

  case 17: /* parameter_list: tVOID  */
#line 112 "parser.y"
                                                                                  { printf("\t\t\t\tparameter_list: void\n\n"); }
#line 1348 "parser.tab.c"
    break;

  case 18: /* parameter_list: parameter  */
#line 113 "parser.y"
                                                                                  { printf("\t\t\t\tparameter_list: with a parameter\n\n"); }
#line 1354 "parser.tab.c"
    break;

  case 19: /* parameter_list: parameter_list tCOMMA parameter  */
#line 114 "parser.y"
                                                                                  { printf("\t\t\t\tparameter_list: with several parameters\n\n"); }
#line 1360 "parser.tab.c"
    break;

  case 20: /* parameter: variable_type identifiers_list  */
#line 119 "parser.y"
  { printf("\t\t\t\tparameters: \n\n"); }
#line 1366 "parser.tab.c"
    break;

  case 21: /* variable_type: tINT  */
#line 125 "parser.y"
                                                                                   { printf("\t\t\t\tvariable_type: int\n\n"); }
#line 1372 "parser.tab.c"
    break;

  case 22: /* functionCall: tID tLPAR action-call0 action-call1 argument_list tRPAR  */
#line 130 "parser.y"
  {printf("\t\t\t\tfunction Call\n");

  int line = get_index_actuel_instructions(&myInstructionTable);
  char* caller = get_current_function(&myFunctionTable,line);
  int calleeFrame = (yyvsp[-2].nb);
  int callerFrame = (yyvsp[-3].nb);
  int calleeADDR = get_function_address(&myFunctionTable,(yyvsp[-5].var));
  add_instruction(&myInstructionTable,"PUSH",callerFrame+1,0,0);
  add_instruction(&myInstructionTable,"CALL",calleeADDR,0,0);
  add_instruction(&myInstructionTable,"POP",callerFrame+1,0,0);
  add_tmp(&mySymbolsTable);
  int temp = get_last_tmp(&mySymbolsTable);
  //copy return value !VAL of callee into temp
  add_instruction(&myInstructionTable,"COP",temp,callerFrame+2,0);;
  (yyval.nb) = temp;}
#line 1392 "parser.tab.c"
    break;

  case 23: /* action-call0: %empty  */
#line 149 "parser.y"
  {  (yyval.nb) = get_symbol_table_size(&mySymbolsTable);}
#line 1398 "parser.tab.c"
    break;

  case 24: /* action-call1: %empty  */
#line 153 "parser.y"
  {increment_scope(&mySymbolsTable);
  add_symb(&mySymbolsTable,"!ADR");
  add_symb(&mySymbolsTable,"!VAL");
  add_tmp(&mySymbolsTable);
  (yyval.nb) = get_symbol_table_size(&mySymbolsTable);
  decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);}
#line 1409 "parser.tab.c"
    break;

  case 26: /* argument_list: argument_list tCOMMA equality_expression  */
#line 164 "parser.y"
  { 
    printf("\t\t\t\targumentlist\n\n");
  }
#line 1417 "parser.tab.c"
    break;

  case 27: /* argument_list: equality_expression  */
#line 168 "parser.y"
  { 
    printf("\t\t\t\targument\n\n");
  }
#line 1425 "parser.tab.c"
    break;

  case 28: /* body: %empty  */
#line 177 "parser.y"
  { 
    printf("\t\t\t\tbody: empty\n\n");
  }
#line 1433 "parser.tab.c"
    break;

  case 29: /* body: declaration_list  */
#line 182 "parser.y"
  { 
    printf("\t\t\t\tbody: declaration_list\n\n"); 
  }
#line 1441 "parser.tab.c"
    break;

  case 30: /* body: instruction_list  */
#line 187 "parser.y"
  { 
    printf("\t\t\t\tbody: instruction_list\n\n"); 
  }
#line 1449 "parser.tab.c"
    break;

  case 31: /* body: declaration_list instruction_list  */
#line 192 "parser.y"
  { 
    printf("\t\t\t\tbody: declaration&instruction list\n\n"); 
  }
#line 1457 "parser.tab.c"
    break;

  case 32: /* body: return  */
#line 196 "parser.y"
  { 
    printf("\t\t\t\tbody: return\n\n"); 
  }
#line 1465 "parser.tab.c"
    break;

  case 33: /* return: tRETURN equality_expression tSEMI  */
#line 204 "parser.y"
  {
    printf("\t\t\t\ttRETURN\n");
    int val = get_symb(&mySymbolsTable,"?VAL");
    add_instruction(&myInstructionTable,"COP",val,(yyvsp[-1].nb),0);
    add_instruction(&myInstructionTable,"RET",0,0,0);
  }
#line 1476 "parser.tab.c"
    break;

  case 34: /* instruction_list: instruction  */
#line 214 "parser.y"
                                                                                    { printf("\t\t\t\tan instruction\n\n"); }
#line 1482 "parser.tab.c"
    break;

  case 35: /* instruction_list: instruction_list instruction  */
#line 215 "parser.y"
                                                                                    { printf("\t\t\t\tseveral instructions\n\n"); }
#line 1488 "parser.tab.c"
    break;

  case 36: /* declaration_list: declaration  */
#line 220 "parser.y"
                                                                                   { printf("\t\t\t\ta declaration\n\n"); }
#line 1494 "parser.tab.c"
    break;

  case 37: /* declaration_list: declaration_list declaration  */
#line 221 "parser.y"
                                                                                   { printf("\t\t\t\tseveral declarations\n\n"); }
#line 1500 "parser.tab.c"
    break;

  case 38: /* declaration: variable_type identifiers_list tSEMI  */
#line 226 "parser.y"
                                                                                 { printf("\t\t\t\tdeclaration\n\n"); }
#line 1506 "parser.tab.c"
    break;

  case 39: /* identifiers_list: tID  */
#line 232 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[0].var)); 
    printf("\t\t\t\tidentifier: '%s'\n\n", (yyvsp[0].var)); }
#line 1513 "parser.tab.c"
    break;

  case 40: /* identifiers_list: tID tASSIGN equality_expression  */
#line 236 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[-2].var)); 

    int address_nb = get_symb(&mySymbolsTable,(yyvsp[-2].var));
    add_instruction(&myInstructionTable, "COP", address_nb, (yyvsp[0].nb),0);   
    free_last_tmp(&mySymbolsTable);
    printf("\t\t\t\tdeclaration and initialization: '%s'\n\n", (yyvsp[-2].var)); }
#line 1524 "parser.tab.c"
    break;

  case 41: /* identifiers_list: identifiers_list tCOMMA tID  */
#line 245 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[0].var)); 
    printf("\t\t\t\tseveral identifiers: '%s'\n\n", (yyvsp[0].var)); }
#line 1531 "parser.tab.c"
    break;

  case 42: /* identifiers_list: identifiers_list tCOMMA tID tASSIGN equality_expression  */
#line 249 "parser.y"
  { add_symb(&mySymbolsTable, (yyvsp[-2].var)); 

    int address_nb = get_symb(&mySymbolsTable,(yyvsp[-2].var));
    add_instruction(&myInstructionTable, "COP", address_nb, (yyvsp[0].nb),0);
    free_last_tmp(&mySymbolsTable);
    printf("\t\t\t\tseveral identifiers: '%s'\n\n", (yyvsp[-2].var)); 
  }
#line 1543 "parser.tab.c"
    break;

  case 43: /* instruction: assignment_list  */
#line 262 "parser.y"
                                                                                  { printf("\t\t\t\tinstruction: assignment\n\n"); }
#line 1549 "parser.tab.c"
    break;

  case 44: /* instruction: ifblock  */
#line 263 "parser.y"
                                                                                  { printf("\t\t\t\tinstruction: if block\n\n"); }
#line 1555 "parser.tab.c"
    break;

  case 45: /* instruction: whileblock  */
#line 264 "parser.y"
                                                                                  { printf("\t\t\t\tinstruction: while block\n\n"); }
#line 1561 "parser.tab.c"
    break;

  case 46: /* instruction: printblock  */
#line 265 "parser.y"
                                                                                  { printf("\t\t\t\tinstruction: print block\n\n"); }
#line 1567 "parser.tab.c"
    break;

  case 47: /* assignment_list: tID tASSIGN equality_expression tSEMI  */
#line 271 "parser.y"
  { 
    int address_nb = get_symb(&mySymbolsTable,(yyvsp[-3].var));
    add_instruction(&myInstructionTable, "COP", address_nb, (yyvsp[-1].nb),0);
    free_last_tmp(&mySymbolsTable);
    printf("\t\t\t\tassignment: '%s'\n\n", (yyvsp[-3].var)); 
  }
#line 1578 "parser.tab.c"
    break;

  case 48: /* assignment_list: tID tASSIGN equality_expression tCOMMA assignment_list  */
#line 279 "parser.y"
    { 
      get_symb(&mySymbolsTable,(yyvsp[-4].var));
      int address_nb = get_symb(&mySymbolsTable,(yyvsp[-4].var));
      add_instruction(&myInstructionTable, "COP", address_nb, (yyvsp[-2].nb),0);  
      free_last_tmp(&mySymbolsTable);
      printf("\t\t\t\tassignment: '%s'\n\n", (yyvsp[-4].var)); 
    }
#line 1590 "parser.tab.c"
    break;

  case 49: /* ifblock: tIF tLPAR condition tRPAR action-if tLBRACE body tRBRACE action-getIndex  */
#line 292 "parser.y"
    {
      patch_instruction_arg1(&myInstructionTable,(yyvsp[-4].nb),(yyvsp[-6].nb));
      free_last_tmp(&mySymbolsTable); // free temp of condition
      patch_instruction_arg2(&myInstructionTable,(yyvsp[-4].nb),(yyvsp[0].nb));
      decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
      printf("\t\t\t\tif block: if\n\n"); 
    }
#line 1602 "parser.tab.c"
    break;

  case 50: /* ifblock: tIF tLPAR condition tRPAR action-if tLBRACE body tRBRACE action-getIndex tELSE action-else tLBRACE body tRBRACE action-getIndex  */
#line 301 "parser.y"
    {
      patch_instruction_arg1(&myInstructionTable,(yyvsp[-10].nb),(yyvsp[-12].nb)); //patch jump of if
      free_last_tmp(&mySymbolsTable); // free temp of condition
      patch_instruction_arg2(&myInstructionTable,(yyvsp[-10].nb),(yyvsp[-6].nb)+1);  
      patch_instruction_arg1(&myInstructionTable,(yyvsp[-4].nb),(yyvsp[0].nb));  //patch jump    
      decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
      printf("\t\t\t\tif block: if else\n\n"); 
    }
#line 1615 "parser.tab.c"
    break;

  case 51: /* ifblock: tIF tLPAR condition tRPAR action-if tLBRACE body tRBRACE action-getIndex tELSE ifblock  */
#line 311 "parser.y"
    {
      patch_instruction_arg1(&myInstructionTable,(yyvsp[-6].nb),(yyvsp[-8].nb));
      free_last_tmp(&mySymbolsTable); // free temp of condition
      patch_instruction_arg2(&myInstructionTable,(yyvsp[-6].nb),(yyvsp[-2].nb));
      decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
      printf("\t\t\t\tif block: if else if\n\n"); 
    }
#line 1627 "parser.tab.c"
    break;

  case 52: /* action-if: %empty  */
#line 322 "parser.y"
  { 
    add_instruction(&myInstructionTable,"JMF",-1,-1,0);  
    (yyval.nb) = get_index_actuel_instructions(&myInstructionTable)-1;
    increment_scope(&mySymbolsTable);
  }
#line 1637 "parser.tab.c"
    break;

  case 53: /* action-else: %empty  */
#line 331 "parser.y"
  {
    add_instruction(&myInstructionTable,"JMP",-1,0,0);    
    (yyval.nb) = get_index_actuel_instructions(&myInstructionTable)-1;
  }
#line 1646 "parser.tab.c"
    break;

  case 54: /* action-getIndex: %empty  */
#line 339 "parser.y"
  { 
    (yyval.nb) = get_index_actuel_instructions(&myInstructionTable);
  }
#line 1654 "parser.tab.c"
    break;

  case 55: /* whileblock: tWHILE tLPAR action-condition condition tRPAR action-while tLBRACE body tRBRACE  */
#line 347 "parser.y"
  {
    add_instruction(&myInstructionTable,"JMP",(yyvsp[-6].nb),0,0); //backward jump
    patch_instruction_arg1(&myInstructionTable,(yyvsp[-3].nb),(yyvsp[-5].nb));
    free_last_tmp(&mySymbolsTable); // free temp of condition
    patch_instruction_arg2(&myInstructionTable,(yyvsp[-3].nb),get_index_actuel_instructions(&myInstructionTable));
    decrement_scope(&mySymbolsTable,&myDeletedSymbolsTable);
    printf("\t\t\t\twhile block\n\n"); 
  }
#line 1667 "parser.tab.c"
    break;

  case 56: /* action-condition: %empty  */
#line 359 "parser.y"
  {
    (yyval.nb) = get_index_actuel_instructions(&myInstructionTable);
  }
#line 1675 "parser.tab.c"
    break;

  case 57: /* action-while: %empty  */
#line 367 "parser.y"
  { add_instruction(&myInstructionTable,"JMF",-1,-1,0);    //arg1 ?
    (yyval.nb) = get_index_actuel_instructions(&myInstructionTable) - 1;
    increment_scope(&mySymbolsTable);
  }
#line 1684 "parser.tab.c"
    break;

  case 58: /* printblock: tPRINT tLPAR condition tRPAR tSEMI  */
#line 376 "parser.y"
  { //prints value   
    add_instruction(&myInstructionTable,"PRI",(yyvsp[-2].nb),0,0);
    printf("\t\t\t\tprint block\n\n");
  }
#line 1693 "parser.tab.c"
    break;

  case 59: /* condition: equality_expression  */
#line 385 "parser.y"
  { //we push forward the value of compare
    (yyval.nb) = (yyvsp[0].nb);}
#line 1700 "parser.tab.c"
    break;

  case 60: /* condition: condition tAND condition  */
#line 388 "parser.y"
  { //we return the @condition and condition
    add_instruction(&myInstructionTable,"AND",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tcondition: and\n\n");}
#line 1710 "parser.tab.c"
    break;

  case 61: /* condition: condition tOR condition  */
#line 394 "parser.y"
  { //we return the @condition and condition
    add_instruction(&myInstructionTable,"ORR",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tcondition: or\n\n"); }
#line 1720 "parser.tab.c"
    break;

  case 62: /* condition: tNOT condition  */
#line 400 "parser.y"
  { //we return the @condition and condition
    add_instruction(&myInstructionTable,"NOT",(yyvsp[0].nb),(yyvsp[0].nb),0);
    (yyval.nb) = (yyvsp[0].nb);
    printf("\t\t\t\tcondition: not\n\n");}
#line 1729 "parser.tab.c"
    break;

  case 63: /* equality_expression: compare  */
#line 409 "parser.y"
  { //we push forward the value of compare
    (yyval.nb) = (yyvsp[0].nb);}
#line 1736 "parser.tab.c"
    break;

  case 64: /* equality_expression: equality_expression tEQ compare  */
#line 413 "parser.y"
  { //we return the @equality_expression == equality_expression
    add_instruction(&myInstructionTable,"EQU",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tequality_expression: equal\n\n"); }
#line 1746 "parser.tab.c"
    break;

  case 65: /* equality_expression: equality_expression tNE compare  */
#line 420 "parser.y"
  { //we return the @equality_expression != equality_expression
    add_instruction(&myInstructionTable,"NEQ",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tequality_expression: not equal\n\n");}
#line 1756 "parser.tab.c"
    break;

  case 66: /* compare: add_sub  */
#line 430 "parser.y"
  { //we push forward the value of add_sub
    (yyval.nb) = (yyvsp[0].nb);}
#line 1763 "parser.tab.c"
    break;

  case 67: /* compare: compare tLT add_sub  */
#line 433 "parser.y"
  { //we return the @compare<add_sub
    add_instruction(&myInstructionTable,"INF",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tcompare: less than\n\n"); }
#line 1773 "parser.tab.c"
    break;

  case 68: /* compare: compare tGT add_sub  */
#line 439 "parser.y"
  { //we return the @compare>add_sub
    add_instruction(&myInstructionTable,"SUP",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tcompare: greater than\n\n"); }
#line 1783 "parser.tab.c"
    break;

  case 69: /* compare: compare tLE add_sub  */
#line 445 "parser.y"
  { //we return the @compare<=add_sub
    add_instruction(&myInstructionTable,"LEQ",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tcompare: less or equal\n\n");}
#line 1793 "parser.tab.c"
    break;

  case 70: /* compare: compare tGE add_sub  */
#line 451 "parser.y"
  { //we return the @compare>=add_sub
    add_instruction(&myInstructionTable,"GEQ",(yyvsp[-2].nb),(yyvsp[-2].nb),(yyvsp[0].nb));
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tcompare: greater or equal\n\n");}
#line 1803 "parser.tab.c"
    break;

  case 71: /* add_sub: div_mul  */
#line 462 "parser.y"
  { //we push forward the value of div_mul
      (yyval.nb) = (yyvsp[0].nb);}
#line 1810 "parser.tab.c"
    break;

  case 72: /* add_sub: add_sub tADD div_mul  */
#line 466 "parser.y"
  { //we return the @add_sub+div_mul
    //we assign the value of @div_mul + @add_sub to @add_sub
    add_instruction(&myInstructionTable, "ADD", (yyvsp[-2].nb),(yyvsp[-2].nb), (yyvsp[0].nb));

    //we free the tmp @div_mul
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tadd_sub: addition\n\n"); }
#line 1823 "parser.tab.c"
    break;

  case 73: /* add_sub: add_sub tSUB div_mul  */
#line 476 "parser.y"
  { //we return the @add_sub-div_mul
    //we assign the value of @div_mul - @add_sub to @add_sub
    add_instruction(&myInstructionTable, "SUB", (yyvsp[-2].nb),(yyvsp[-2].nb), (yyvsp[0].nb)); 

    //we free the tmp @div_mul
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tadd_sub: substraction\n\n"); }
#line 1836 "parser.tab.c"
    break;

  case 74: /* div_mul: single_value  */
#line 489 "parser.y"
  { //we push forward the value of single_value
    (yyval.nb) = (yyvsp[0].nb);}
#line 1843 "parser.tab.c"
    break;

  case 75: /* div_mul: div_mul tMUL single_value  */
#line 493 "parser.y"
  { //we return the @divmul*single_value
    //we assign the value of @single_value * @div_mul to @div_mul
    add_instruction(&myInstructionTable, "MUL", (yyvsp[-2].nb),(yyvsp[-2].nb), (yyvsp[0].nb));

    //we free the tmp @single_value
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tdiv_mul: multiplication\n\n"); }
#line 1856 "parser.tab.c"
    break;

  case 76: /* div_mul: div_mul tDIV single_value  */
#line 503 "parser.y"
  { //we return the @divmul/single_value
    //we assign the value of @single_value / @div_mul to @div_mul
    add_instruction(&myInstructionTable, "DIV", (yyvsp[-2].nb), (yyvsp[-2].nb),(yyvsp[0].nb));

    //we free the tmp @single_value
    free_last_tmp(&mySymbolsTable);
    (yyval.nb) = (yyvsp[-2].nb);
    printf("\t\t\t\tdiv_mul: division\n\n"); }
#line 1869 "parser.tab.c"
    break;

  case 77: /* single_value: functionCall  */
#line 516 "parser.y"
  { add_tmp(&mySymbolsTable);
    int temp = get_last_tmp(&mySymbolsTable);
    (yyval.nb) = temp;
    add_instruction(&myInstructionTable, "COP", temp, (yyvsp[0].nb),0); 
    printf("\t\t\t\treducing functionCall to single value\n");}
#line 1879 "parser.tab.c"
    break;

  case 78: /* single_value: tID  */
#line 523 "parser.y"
  { //we return the @tmp that holds the value of tID
    //we create a variable to put the value of tID in
    //we get the address of ID and adress of the tmp we created
    //copy the value of ID in tmp 
    add_tmp(&mySymbolsTable);
    int temp = get_last_tmp(&mySymbolsTable);
    int addr = get_symb(&mySymbolsTable,(yyvsp[0].var));
    (yyval.nb) = temp;
    add_instruction(&myInstructionTable, "COP", temp, addr,0); 
    printf("\t\t\t\tsingle_value: identifier '%s'\n\n", (yyvsp[0].var)); }
#line 1894 "parser.tab.c"
    break;

  case 79: /* single_value: tNB  */
#line 536 "parser.y"
  { //we return the @tmp that holds the value tNB
    //we create a tmp to ST
    //we assign the value of tNB to tmp
    add_tmp(&mySymbolsTable);

    int address_nb = get_last_tmp(&mySymbolsTable);
    add_instruction(&myInstructionTable, "AFC", address_nb, (yyvsp[0].nb),0);  

    (yyval.nb) = address_nb;
    printf("\t\t\t\tsingle_value: number '%d'\n\n", (yyvsp[0].nb)); }
#line 1909 "parser.tab.c"
    break;


#line 1913 "parser.tab.c"

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

#line 551 "parser.y"


void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
  //Initialize Tables
  initialize_symbol_table(&mySymbolsTable);
  initialize_instruction_table(&myInstructionTable);
  initialize_function_table(&myFunctionTable);

  //Parse
  yyparse();

  //Print final tables in terminal
  print_table(&mySymbolsTable);
  print_deleted_symbols_table(&myDeletedSymbolsTable);
  print_instruction_table(&myInstructionTable);
  print_function_table(&myFunctionTable);

  //Creates and writes into the files
  //WARNING following lines smashes the stack when there are functions in the code to compile
  write_instructions_to_file(myInstructionTable);
  write_instructions_to_file_read(myInstructionTable);
  write_instructions_to_file_VHDL(myInstructionTable);
  return 0;
}
