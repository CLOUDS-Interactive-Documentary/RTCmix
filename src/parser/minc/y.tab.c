//#include <sys/cdefs.h>
#ifndef lint
#if 1
static char mm_yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#else
__IDSTRING(mm_yyrcsid, "$NetBSD: skeleton.c,v 1.14 1997/10/20 03:41:16 lukem Exp $");
#endif
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX mm_yylex()
#define YYEMPTY -1
#define mm_yyclearin (mm_yychar=(YYEMPTY))
#define mm_yyerrok (mm_yyerrflag=0)
#define YYRECOVERING (mm_yyerrflag!=0)
#define YYPREFIX "mm_yy"
#line 6 "minc.y"
#include <string.h>
#include "minc_internal.h"
#include "lex.yy.c"
#define YYDEBUG 1
#define MAXTOK_IDENTLIST 200

#undef MDEBUG  /* turns on some parser debugging below */

#ifdef MDEBUG
#define MPRINT(x) printf(x "\n")
#define MPRINT1(x,y) printf(x "\n", y)
#else
#define MPRINT(x)
#define MPRINT1(x,y)
#endif

static Tree		program;
static Symbol	*sym;
static int		idcount = 0;	
static char		*idlist[MAXTOK_IDENTLIST];  
static int		flerror;		/* set if there was an error during parsing */
static int		level = 0;	/* keeps track whether we are in a structure */
static void cleanup();
#line 44 "y.tab.c"
#define LOWPRIO 257
#define TOK_MINUSEQU 258
#define TOK_PLUSEQU 259
#define TOK_DIVEQU 260
#define TOK_MULEQU 261
#define TOK_OR 262
#define TOK_AND 263
#define TOK_EQU 264
#define TOK_UNEQU 265
#define TOK_LESSEQU 266
#define TOK_GTREQU 267
#define TOK_POW 268
#define CASTTOKEN 269
#define TOK_FLOAT_DECL 270
#define TOK_STRING_DECL 271
#define TOK_HANDLE_DECL 272
#define TOK_IDENT 273
#define TOK_NUM 274
#define TOK_NOT 275
#define TOK_IF 276
#define TOK_ELSE 277
#define TOK_FOR 278
#define TOK_WHILE 279
#define TOK_TRUE 280
#define TOK_FALSE 281
#define TOK_STRING 282
#define YYERRCODE 256
short mm_yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    1,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,   10,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    9,    9,    8,    5,    5,    5,
    7,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    4,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,
};
short mm_yylen[] = {                                         2,
    0,    1,    1,    2,    2,    3,    1,    2,    2,    2,
    4,    6,    4,   10,    3,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    0,    3,    3,    3,    3,    3,
    4,    3,    4,    6,    1,    3,    1,    1,    3,    0,
    1,    1,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    1,    1,    1,    1,    2,    1,
};
short mm_yydefred[] = {                                      0,
    0,    0,    0,    0,   37,   25,   25,   25,    0,    0,
    0,    0,    7,    0,   16,   17,   18,   19,   23,   21,
   20,   24,   22,   35,    0,    0,    0,    0,    0,    0,
    0,   63,   64,   65,   41,    0,    0,    0,    0,    0,
   62,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   54,    0,    0,    0,
    0,    0,    0,   15,   32,    0,    0,    0,    0,    0,
    0,    0,    6,    0,    0,    0,    0,    0,    0,    0,
   36,   43,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   13,   61,    0,    0,    0,    0,    0,    0,
    0,   31,    0,    0,    0,   46,    0,    0,    0,    0,
    0,    0,    0,    0,   12,    0,    0,    0,    0,    0,
   14,
};
short mm_yydgoto[] = {                                      10,
   11,   12,   57,   58,   39,   59,   41,   42,   25,   28,
};
short mm_yysindex[] = {                                    833,
  -59, -258, -258, -258,    0,    0,    0,    0,  580,    0,
  833,  -42,    0,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -11,  -11,  -11,  160,  -20,  160,
  230,    0,    0,    0,    0,  160,  409,    0,  -36,  -24,
    0,   48,   -1,    0,  230,  230,  230,  230,  230,  230,
  230, -258,  160,    0,    0,  230,    0,  697,  123,  833,
  697,   -2,   -4,    0,    0,  230,  230,  230,  230,  230,
  230,  230,    0,  -24,  -24,  -24,  -24,  -24,    6,  -13,
    0,    0,  160,  160,  160, -222,  230,  230,  230,  230,
  230,   14,    0,    0,  -24,   -6,   -6,  -21,  -21,   -2,
  -24,    0,    4, -257, -205,    0,  833,  -24,  -24,  -24,
  -24,  -24,  160,  230,    0,  -56,  -24,  833,   30,  833,
    0,
};
short mm_yyrindex[] = {                                     75,
    0,    0,    0,    0,    0,    0,    0,    0,  -22,    0,
   76,  299,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  102,  673,  715,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -33,    0,  -39,
    0,    1,  663,    0,    0,    0,    0,    0,    0,   12,
    0,    0,    0,  858,  937,  -22,    0,    0,  814,    0,
    0,   54,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  428,  457,  481,  505,  615,    0,    0,
    0,    0,    0,    0,    0,  785,    0,    0,    0,    0,
    0,    0,    0,    0,    8,  323,  370,  131,  189,   78,
  749,    0,   25, 1103, 1091,    0,    0,  907,  965, 1012,
 1038, 1059,    0,    0,    0,    0,  773,    0,    0,    0,
    0,
};
short mm_yygindex[] = {                                      0,
   68,  389, 1346,   21,   29, 1423,    0, 1340,   24,   32,
};
#define YYTABLESIZE 1537
short mm_yytable[] = {                                      22,
   67,   38,  118,   54,   38,   84,   85,   66,   54,   54,
   54,   54,   72,   54,    5,   72,   44,   69,   67,   60,
   68,   40,   70,   72,   33,    7,   26,   27,   69,   67,
   72,   68,   52,   70,   72,   69,   94,   67,   29,   30,
   70,   67,   67,   67,   67,   67,  102,   67,   39,   66,
   61,   39,   40,   66,  107,   40,   63,   73,   85,   67,
   67,   33,   67,   23,  114,   33,   33,   33,   33,   33,
  120,   33,  113,   82,    1,    2,   37,   55,   79,  103,
    0,    0,    0,   33,   33,   38,   33,   50,   65,    7,
    0,    7,    0,   67,   66,   66,   66,   66,   66,    0,
   66,    8,   40,  104,  105,  106,    0,    0,   45,    0,
    0,    0,   66,   66,    0,   66,    0,   33,   55,   55,
   55,   55,   55,   67,   55,   67,    0,    0,    0,    0,
   56,    0,   39,  116,    0,    0,   55,   55,   51,   55,
    0,    0,    8,    0,    0,    0,   66,   33,    0,   33,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   72,
    8,    0,    0,    0,   69,   67,    0,   68,    0,   70,
   55,   56,   56,   56,   56,   56,   66,   56,   66,    0,
    0,    0,   88,    0,   89,    0,    0,    0,   57,   56,
   56,    0,   56,    0,    0,    0,    0,    0,    0,   36,
   55,    0,   55,    0,   31,   83,   84,   85,    0,    0,
   15,   16,   17,    0,    0,    0,   18,   19,   20,   21,
    0,    0,    7,   56,    8,    0,    8,    0,    0,   57,
   57,   57,   57,   57,   54,   57,    7,    7,    7,    7,
    0,    0,    7,   71,    7,    7,   71,   57,   57,    0,
   57,    0,    0,   56,   71,   56,   67,   83,   84,   85,
    0,   71,   67,   67,   67,   67,   67,   67,   67,   36,
   67,   67,   67,   67,   31,    0,   67,   67,   67,   67,
   33,   57,   56,    0,    0,    0,   33,   33,   33,   33,
   33,   33,   33,    0,   33,   33,   33,   33,    3,    0,
   33,   33,   33,   33,    0,   46,   47,   48,   49,   66,
    0,   57,    0,   57,    0,   66,   66,   66,   66,   66,
   66,   66,   58,   66,   66,   66,   66,    0,    0,   66,
   66,   66,   66,   55,    0,    0,    0,    0,    0,   55,
   55,   55,   55,   55,   55,   55,    0,   55,   55,   55,
   55,    0,   56,   55,   55,   55,   55,    8,    0,    0,
    0,    0,    0,   58,    0,   58,   58,   58,    0,   59,
    0,    8,    8,    8,    8,    0,    0,    8,    8,    8,
    8,   58,   58,    0,   58,    0,   56,   87,   90,   91,
   71,    0,   56,   56,   56,   56,   56,   56,    0,   43,
   56,   56,   56,   56,    0,    0,   56,   56,   56,   56,
   59,    0,   59,   59,   59,   58,    0,    0,    0,    0,
    0,    3,    0,    3,    0,   43,    0,   26,   59,   59,
    0,   59,    5,   32,   53,    0,    0,    0,    0,   54,
   55,   35,    0,    0,   57,   58,   86,   58,   92,   93,
   57,   57,   57,   57,   57,   57,   28,    0,   57,   57,
   57,   57,   59,    0,   57,   57,   57,   57,   26,    0,
    0,   26,    0,    0,    0,    0,    0,    0,    0,    0,
   27,    0,    0,    0,    0,    0,   26,   26,    0,   26,
    0,    0,   59,    0,   59,  115,    0,   28,    0,    0,
   28,    0,    5,   32,   30,    0,  119,    0,  121,   33,
   34,   35,    0,    0,    0,   28,   28,    0,   28,    0,
   26,   27,    0,    0,   27,    0,    0,    0,    0,    0,
    0,    9,    0,   64,    0,    0,    0,    0,    0,   27,
   27,    0,   27,    0,    0,   30,    0,    0,   30,   28,
   26,    0,   26,    0,    3,    0,    0,    0,    0,    0,
    0,    0,    0,   30,   30,    0,   30,    0,    3,    3,
    3,    3,    0,   27,    3,    0,    3,    3,   58,   28,
    0,   28,    0,    0,   58,   58,   58,   58,   58,   58,
    0,    0,   58,   58,   58,   58,    0,   30,   58,   58,
   58,   58,    0,   27,    0,   27,    0,    0,    0,    0,
    0,    0,    0,    0,   29,    0,    0,    0,    0,   36,
    0,    0,    0,    0,   31,   59,    0,   30,    0,   30,
    0,   59,   59,   59,   59,   59,   59,    0,    0,   59,
   59,   59,   59,    0,    0,   59,   59,   59,   59,    0,
    0,    0,    0,    0,    0,   29,    0,    0,   29,    0,
    0,    0,    5,    0,    1,    0,    0,    0,    0,    0,
    0,    0,    9,   29,   29,    0,   29,    0,    2,    3,
    4,    5,    0,   26,    6,    0,    7,    8,    0,   26,
   26,   26,   26,   26,   26,    0,    0,   26,   26,   26,
   26,    0,    9,   26,   26,   26,   26,   29,    0,    0,
    0,    0,   28,    9,   10,    0,    0,    0,   28,   28,
   28,   28,   28,   28,    0,    0,   28,   28,   28,   28,
    0,    9,   28,   28,   28,   28,   27,   29,    0,   29,
    0,    0,   27,   27,   27,   27,   27,   27,   60,    0,
   27,   27,   27,   27,    0,   10,   27,   27,   27,   27,
   30,    0,    0,    0,    0,    0,   30,   30,   30,   30,
   30,   30,   34,   10,   30,   30,   30,   30,    0,    0,
   30,   30,   30,   30,   11,    5,    0,    5,    0,   60,
    0,    0,   60,    0,    0,    9,    0,    9,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   60,   60,    0,
   60,    0,    0,   34,    0,    0,   34,    0,    0,    9,
    0,    0,    0,    0,    0,   11,    0,    0,    0,    0,
    0,   34,   34,    0,   34,    1,    0,   10,    0,   10,
    0,   60,    0,   11,    0,    0,    0,    0,    0,    2,
    3,    4,    5,   32,   42,    6,    0,    7,    8,   33,
   34,   35,    0,    0,    0,   34,    0,    0,    0,    0,
   29,   60,   42,   60,    0,    0,   29,   29,   29,   29,
   29,   29,    0,    0,   29,   29,   29,   29,    0,    0,
   29,   29,   29,   29,   64,   34,    0,   34,   52,   64,
   64,    0,   64,    0,   64,    0,    0,   11,    0,   11,
    0,    0,    0,    0,    0,    0,   52,   64,    5,   64,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
    0,    0,    5,    5,    5,    5,   42,    0,    5,    0,
    5,    5,    9,    9,    9,    9,    0,   47,    9,    9,
    9,    9,    1,    0,    0,    9,    0,    0,   83,   84,
   85,    0,    0,    0,    0,   47,    2,    3,    4,    5,
   10,    0,    6,   65,    7,    8,    0,   53,   65,   65,
   52,   65,    0,   65,   10,   10,   10,   10,    0,    0,
   10,   10,   10,   10,    0,   53,   65,    0,   65,    0,
    0,    0,    0,    0,   60,   48,    0,    0,    0,    0,
   60,   60,   60,   60,   60,   60,    0,    0,   60,   60,
   60,   60,    0,   48,   60,   60,   60,   60,   34,   47,
    0,    0,    0,    0,   34,   34,   34,   34,   34,   34,
   11,    0,   34,   34,   34,   34,    0,    0,   34,   34,
   34,   34,   49,    0,   11,   11,   11,   11,    0,   53,
   11,    0,   11,   11,    0,    0,    0,    0,    0,   42,
   49,    0,    0,    0,    0,   42,   42,   42,   50,    0,
    0,    0,    0,   42,   42,   42,   42,   48,    1,   42,
    0,   42,   42,    0,    0,    0,   50,    0,    0,   51,
    0,    0,    2,    3,    4,    5,    0,    0,    6,    0,
    7,    8,    0,   52,    0,    0,    0,   51,    0,   52,
   52,   52,   64,   64,   64,   64,    0,   52,   52,   52,
   52,   44,    0,   52,   49,   52,   52,    0,    0,    0,
    0,    0,    0,   45,    0,    0,    0,    0,    0,   44,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   50,   45,   47,    0,    0,    0,    0,    0,   47,   47,
   47,    0,    0,    0,    0,    0,   47,   47,   47,   47,
    0,   51,   47,    0,   47,   47,    0,    0,    0,    0,
    0,    0,   53,    0,    0,    0,    0,    0,   53,   53,
   53,   65,   65,   65,   65,    0,   53,   53,   53,   53,
    0,    0,   53,   44,   53,   53,    0,    0,    0,    0,
   48,    0,    0,    0,    0,   45,   48,   48,   48,    0,
    0,    0,    0,    0,   48,   48,   48,   48,    0,    0,
   48,    0,   48,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   49,    0,    0,
    0,    0,    0,   49,   49,   49,    0,    0,    0,    0,
    0,   49,   49,   49,   49,    0,    0,   49,    0,   49,
   49,    0,    0,   50,    0,    0,    0,    0,    0,   50,
   50,   50,    0,    0,    0,    0,    0,   50,   50,   50,
   50,    0,    0,   50,   51,   50,   50,    0,    0,    0,
   51,   51,   51,    0,    0,    0,    0,    0,   51,   51,
   51,   51,    0,    0,   51,    0,   51,   51,    0,   14,
    0,   24,   24,   24,    0,   13,   44,    0,    0,    0,
   14,    0,   44,   44,   38,    0,   13,    0,   45,    0,
   44,   44,   44,   44,   45,    0,   44,    0,   44,   44,
    0,    0,   45,   45,   45,   45,   14,    0,   45,    0,
   45,   45,   13,    0,    0,    0,    0,    0,    0,    0,
    0,   81,    0,    0,    0,    0,    0,   14,    0,   14,
   14,    0,    0,   13,    0,   13,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   40,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   14,    0,    0,    0,
    0,    0,   13,   62,    0,    0,    0,   14,    0,   14,
    0,    0,    0,   13,    0,   13,    0,   74,   75,   76,
   77,   78,   40,   80,    0,    0,    0,    0,   40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   95,   96,
   97,   98,   99,  100,  101,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  108,
  109,  110,  111,  112,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  117,
};
short mm_yycheck[] = {                                      59,
    0,   41,   59,   37,   44,  263,  264,   44,   42,   43,
   44,   45,   37,   47,  273,   37,   59,   42,   43,   40,
   45,   44,   47,   37,    0,   59,    3,    4,   42,   43,
   37,   45,   44,   47,   37,   42,   41,   37,    7,    8,
   47,   41,   42,   43,   44,   45,   41,   47,   41,   44,
   30,   44,   41,    0,  277,   44,   36,   59,  264,   59,
   60,   37,   62,  123,   61,   41,   42,   43,   44,   45,
   41,   47,   59,   53,    0,    0,    9,    0,   50,   93,
   -1,   -1,   -1,   59,   60,  125,   62,   40,  125,  123,
   -1,  125,   -1,   93,   41,   42,   43,   44,   45,   -1,
   47,    0,  125,   83,   84,   85,   -1,   -1,   61,   -1,
   -1,   -1,   59,   60,   -1,   62,   -1,   93,   41,   42,
   43,   44,   45,  123,   47,  125,   -1,   -1,   -1,   -1,
    0,   -1,  125,  113,   -1,   -1,   59,   60,   91,   62,
   -1,   -1,   41,   -1,   -1,   -1,   93,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   37,
   59,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   93,   41,   42,   43,   44,   45,  123,   47,  125,   -1,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,    0,   59,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   40,
  123,   -1,  125,   -1,   45,  262,  263,  264,   -1,   -1,
  270,  271,  272,   -1,   -1,   -1,  276,  277,  278,  279,
   -1,   -1,  256,   93,  123,   -1,  125,   -1,   -1,   41,
   42,   43,   44,   45,  268,   47,  270,  271,  272,  273,
   -1,   -1,  276,  268,  278,  279,  268,   59,   60,   -1,
   62,   -1,   -1,  123,  268,  125,  256,  262,  263,  264,
   -1,  268,  262,  263,  264,  265,  266,  267,  268,   40,
  270,  271,  272,  273,   45,   -1,  276,  277,  278,  279,
  256,   93,  123,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,  268,   -1,  270,  271,  272,  273,    0,   -1,
  276,  277,  278,  279,   -1,  258,  259,  260,  261,  256,
   -1,  123,   -1,  125,   -1,  262,  263,  264,  265,  266,
  267,  268,    0,  270,  271,  272,  273,   -1,   -1,  276,
  277,  278,  279,  256,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,  265,  266,  267,  268,   -1,  270,  271,  272,
  273,   -1,  123,  276,  277,  278,  279,  256,   -1,   -1,
   -1,   -1,   -1,   41,   -1,   43,   44,   45,   -1,    0,
   -1,  270,  271,  272,  273,   -1,   -1,  276,  277,  278,
  279,   59,   60,   -1,   62,   -1,  256,  265,  266,  267,
  268,   -1,  262,  263,  264,  265,  266,  267,   -1,   11,
  270,  271,  272,  273,   -1,   -1,  276,  277,  278,  279,
   41,   -1,   43,   44,   45,   93,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   -1,   37,   -1,    0,   59,   60,
   -1,   62,  273,  274,  275,   -1,   -1,   -1,   -1,  280,
  281,  282,   -1,   -1,  256,  123,   58,  125,   60,   61,
  262,  263,  264,  265,  266,  267,    0,   -1,  270,  271,
  272,  273,   93,   -1,  276,  277,  278,  279,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    0,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,
   -1,   -1,  123,   -1,  125,  107,   -1,   41,   -1,   -1,
   44,   -1,  273,  274,    0,   -1,  118,   -1,  120,  280,
  281,  282,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   93,   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   41,   -1,   -1,   44,   93,
  123,   -1,  125,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,   -1,  270,  271,
  272,  273,   -1,   93,  276,   -1,  278,  279,  256,  123,
   -1,  125,   -1,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,  270,  271,  272,  273,   -1,   93,  276,  277,
  278,  279,   -1,  123,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   -1,   -1,   45,  256,   -1,  123,   -1,  125,
   -1,  262,  263,  264,  265,  266,  267,   -1,   -1,  270,
  271,  272,  273,   -1,   -1,  276,  277,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,
   -1,   -1,    0,   -1,  256,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,    0,   59,   60,   -1,   62,   -1,  270,  271,
  272,  273,   -1,  256,  276,   -1,  278,  279,   -1,  262,
  263,  264,  265,  266,  267,   -1,   -1,  270,  271,  272,
  273,   -1,  123,  276,  277,  278,  279,   93,   -1,   -1,
   -1,   -1,  256,   41,    0,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,   -1,   -1,  270,  271,  272,  273,
   -1,   59,  276,  277,  278,  279,  256,  123,   -1,  125,
   -1,   -1,  262,  263,  264,  265,  266,  267,    0,   -1,
  270,  271,  272,  273,   -1,   41,  276,  277,  278,  279,
  256,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,    0,   59,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,  279,    0,  123,   -1,  125,   -1,   41,
   -1,   -1,   44,   -1,   -1,  123,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,  123,
   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,   -1,   -1,
   -1,   59,   60,   -1,   62,  256,   -1,  123,   -1,  125,
   -1,   93,   -1,   59,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,   41,  276,   -1,  278,  279,  280,
  281,  282,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
  256,  123,   59,  125,   -1,   -1,  262,  263,  264,  265,
  266,  267,   -1,   -1,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,  279,   37,  123,   -1,  125,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,  123,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,  256,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,   -1,
   -1,   -1,  270,  271,  272,  273,  123,   -1,  276,   -1,
  278,  279,  270,  271,  272,  273,   -1,   41,  276,  277,
  278,  279,  256,   -1,   -1,  123,   -1,   -1,  262,  263,
  264,   -1,   -1,   -1,   -1,   59,  270,  271,  272,  273,
  256,   -1,  276,   37,  278,  279,   -1,   41,   42,   43,
  123,   45,   -1,   47,  270,  271,  272,  273,   -1,   -1,
  276,  277,  278,  279,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,  256,   41,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,  266,  267,   -1,   -1,  270,  271,
  272,  273,   -1,   59,  276,  277,  278,  279,  256,  123,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
  256,   -1,  270,  271,  272,  273,   -1,   -1,  276,  277,
  278,  279,   41,   -1,  270,  271,  272,  273,   -1,  123,
  276,   -1,  278,  279,   -1,   -1,   -1,   -1,   -1,  256,
   59,   -1,   -1,   -1,   -1,  262,  263,  264,   41,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,  123,  256,  276,
   -1,  278,  279,   -1,   -1,   -1,   59,   -1,   -1,   41,
   -1,   -1,  270,  271,  272,  273,   -1,   -1,  276,   -1,
  278,  279,   -1,  256,   -1,   -1,   -1,   59,   -1,  262,
  263,  264,  265,  266,  267,  268,   -1,  270,  271,  272,
  273,   41,   -1,  276,  123,  278,  279,   -1,   -1,   -1,
   -1,   -1,   -1,   41,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   59,  256,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,  273,
   -1,  123,  276,   -1,  278,  279,   -1,   -1,   -1,   -1,
   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,  268,   -1,  270,  271,  272,  273,
   -1,   -1,  276,  123,  278,  279,   -1,   -1,   -1,   -1,
  256,   -1,   -1,   -1,   -1,  123,  262,  263,  264,   -1,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,   -1,   -1,
  276,   -1,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,   -1,   -1,
   -1,   -1,   -1,  262,  263,  264,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,   -1,   -1,  276,   -1,  278,
  279,   -1,   -1,  256,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,   -1,   -1,  276,  256,  278,  279,   -1,   -1,   -1,
  262,  263,  264,   -1,   -1,   -1,   -1,   -1,  270,  271,
  272,  273,   -1,   -1,  276,   -1,  278,  279,   -1,    0,
   -1,    2,    3,    4,   -1,    0,  256,   -1,   -1,   -1,
   11,   -1,  262,  263,    9,   -1,   11,   -1,  256,   -1,
  270,  271,  272,  273,  262,   -1,  276,   -1,  278,  279,
   -1,   -1,  270,  271,  272,  273,   37,   -1,  276,   -1,
  278,  279,   37,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   52,   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,
   61,   -1,   -1,   58,   -1,   60,   61,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,    9,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  107,   -1,   -1,   -1,
   -1,   -1,  107,   31,   -1,   -1,   -1,  118,   -1,  120,
   -1,   -1,   -1,  118,   -1,  120,   -1,   45,   46,   47,
   48,   49,   50,   51,   -1,   -1,   -1,   -1,   56,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   66,   67,
   68,   69,   70,   71,   72,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   87,
   88,   89,   90,   91,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  114,
};
#define YYFINAL 10
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#if YYDEBUG
char *mm_yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",
0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LOWPRIO","TOK_MINUSEQU","TOK_PLUSEQU",
"TOK_DIVEQU","TOK_MULEQU","TOK_OR","TOK_AND","TOK_EQU","TOK_UNEQU",
"TOK_LESSEQU","TOK_GTREQU","TOK_POW","CASTTOKEN","TOK_FLOAT_DECL",
"TOK_STRING_DECL","TOK_HANDLE_DECL","TOK_IDENT","TOK_NUM","TOK_NOT","TOK_IF",
"TOK_ELSE","TOK_FOR","TOK_WHILE","TOK_TRUE","TOK_FALSE","TOK_STRING",
};
char *mm_yyrule[] = {
"$accept : prg",
"prg :",
"prg : stml",
"stml : stmt",
"stml : stmt ';'",
"stml : stml stmt",
"stml : stml stmt ';'",
"stmt : rstmt",
"stmt : TOK_FLOAT_DECL idl",
"stmt : TOK_STRING_DECL idl",
"stmt : TOK_HANDLE_DECL idl",
"stmt : TOK_IF level bexp stmt",
"stmt : TOK_IF level bexp stmt TOK_ELSE stmt",
"stmt : TOK_WHILE level bexp stmt",
"stmt : TOK_FOR level '(' stmt ';' bexp ';' stmt ')' stmt",
"stmt : '{' stml '}'",
"stmt : error TOK_FLOAT_DECL",
"stmt : error TOK_STRING_DECL",
"stmt : error TOK_HANDLE_DECL",
"stmt : error TOK_IF",
"stmt : error TOK_WHILE",
"stmt : error TOK_FOR",
"stmt : error '{'",
"stmt : error TOK_ELSE",
"stmt : error ';'",
"level :",
"rstmt : id '=' exp",
"rstmt : id TOK_PLUSEQU exp",
"rstmt : id TOK_MINUSEQU exp",
"rstmt : id TOK_MULEQU exp",
"rstmt : id TOK_DIVEQU exp",
"rstmt : id '(' expl ')'",
"rstmt : '{' expl '}'",
"rstmt : id '[' exp ']'",
"rstmt : id '[' exp ']' '=' exp",
"idl : id",
"idl : idl ',' id",
"id : TOK_IDENT",
"expl : exp",
"expl : expl ',' exp",
"expl :",
"str : TOK_STRING",
"bexp : exp",
"bexp : TOK_NOT bexp",
"bexp : bexp TOK_AND bexp",
"bexp : bexp TOK_OR bexp",
"bexp : bexp TOK_EQU bexp",
"bexp : exp TOK_UNEQU exp",
"bexp : exp '<' exp",
"bexp : exp '>' exp",
"bexp : exp TOK_LESSEQU exp",
"bexp : exp TOK_GTREQU exp",
"bexp : TOK_TRUE",
"bexp : TOK_FALSE",
"exp : rstmt",
"exp : exp TOK_POW exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '%' exp",
"exp : '(' bexp ')'",
"exp : str",
"exp : TOK_NUM",
"exp : TOK_TRUE",
"exp : TOK_FALSE",
"exp : '-' exp",
"exp : id",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int mm_yydebug;
int mm_yynerrs;
int mm_yyerrflag;
int mm_yychar;
short *mm_yyssp;
YYSTYPE *mm_yyvsp;
YYSTYPE mm_yyval;
YYSTYPE mm_yylval;
short *mm_yyss;
short *mm_yysslim;
YYSTYPE *mm_yyvs;
int mm_yystacksize;
#line 252 "minc.y"

void
declare(MincDataType type)
{
	int i;

	for (i = 0; i < idcount; i++) {
	   Symbol *sym = lookup(idlist[i]);
		if (sym != NULL) {
			minc_warn("variable redefined: %s", idlist[i]);
			/* note this handling may be illegal in arbitrary scoping */
			sym->type = type;
		}
		else {
			sym = install(idlist[i], S_GLOBAL);
			sym->type = type;
		}
	}
}

#define FREE_TREES_AT_END

Tree
go(Tree t1)
{
	MPRINT("go()");
	if (level == 0) {
		exct(t1);
#ifndef FREE_TREES_AT_END
		free_tree(t1);
#endif
	}
	return t1;
}

int mm_yywrap()
{
	return 1;
}

static void cleanup()
{
	// BGG mm -- for dynamic memory mgmt
	if (mm_yy_init == 1) return; // minc_memflush() was called prior

#ifdef FREE_TREES_AT_END
	free_tree(program);
#else
	efree(program);
#endif
// BGG mm -- we need to keep the symbols for The Future
//	free_symbols();
// BGG mm -- I think this buffer gets reused, so we don't delete it
/*
	mm_yy_delete_buffer(mm_yy_current_buffer);
	mm_yy_current_buffer = NULL;
*/
}

// BGG mm -- for dynamic memory mgmt (double return for UG_INTRO() macro)
double minc_memflush()
{
	if (mm_yy_init == 1) return 0.0; // memory already flushed

#ifdef FREE_TREES_AT_END
   free_tree(program);
#else
   efree(program);
#endif
	free_symbols();

   mm_yy_delete_buffer(mm_yy_current_buffer);
   mm_yy_current_buffer = NULL;

	mm_yy_init = 1;    /* whether we need to initialize */
	mm_yy_start = 0;   /* start state number */

	return 1.0;
}

#line 622 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */

// BGG mm -- get rid of that macro!
//int mm_yyparse __P((void));
int mm_yyparse(char *buf, int len);

// JRG -- get rid of that macro!
//static int mm_yygrowstack __P((void));
static int mm_yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = mm_yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = mm_yyssp - mm_yyss;
    if ((newss = (short *)realloc(mm_yyss, newsize * sizeof *newss)) == NULL)
        return -1;
    mm_yyss = newss;
    mm_yyssp = newss + i;
    if ((newvs = (YYSTYPE *)realloc(mm_yyvs, newsize * sizeof *newvs)) == NULL)
        return -1;
    mm_yyvs = newvs;
    mm_yyvsp = newvs + i;
    mm_yystacksize = newsize;
    mm_yysslim = mm_yyss + newsize - 1;
    return 0;
}

#define YYABORT goto mm_yyabort
#define YYREJECT goto mm_yyabort
#define YYACCEPT goto mm_yyaccept
#define YYERROR goto mm_yyerrlab

// BGG mm
//int
//mm_yyparse()
int mm_yyparse(char *buf, int len)
{
    int mm_yym, mm_yyn, mm_yystate;
#if YYDEBUG
    char *mm_yys;

    if ((mm_yys = getenv("YYDEBUG")) != NULL)
    {
        mm_yyn = *mm_yys;
        if (mm_yyn >= '0' && mm_yyn <= '9')
            mm_yydebug = mm_yyn - '0';
    }
#endif

// BGG mm
// these are declared in lex.yy.c
thebuf = buf;
thelen = len;
bpointer = 0;
mm_yyin = NULL;
// BGG -- added to reset the line # every time a new score buffer is received 
mm_yylineno = 1;

    mm_yynerrs = 0;
    mm_yyerrflag = 0;
    mm_yychar = (-1);

    if (mm_yyss == NULL && mm_yygrowstack()) goto mm_yyoverflow;
    mm_yyssp = mm_yyss;
    mm_yyvsp = mm_yyvs;
    *mm_yyssp = mm_yystate = 0;
mm_yyloop:
    if ((mm_yyn = mm_yydefred[mm_yystate]) != 0) goto mm_yyreduce;
    if (mm_yychar < 0)
    {
        if ((mm_yychar = mm_yylex()) < 0) mm_yychar = 0;
#if YYDEBUG
        if (mm_yydebug)
        {
            mm_yys = 0;
            if (mm_yychar <= YYMAXTOKEN) mm_yys = mm_yyname[mm_yychar];
            if (!mm_yys) mm_yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, mm_yystate, mm_yychar, mm_yys);
        }
#endif
    }

    if ((mm_yyn = mm_yysindex[mm_yystate]) && (mm_yyn += mm_yychar) >= 0 &&
            mm_yyn <= YYTABLESIZE && mm_yycheck[mm_yyn] == mm_yychar)
    {
#if YYDEBUG
        if (mm_yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, mm_yystate, mm_yytable[mm_yyn]);
#endif
        if (mm_yyssp >= mm_yysslim && mm_yygrowstack())
        {
            goto mm_yyoverflow;
        }

        *++mm_yyssp = mm_yystate = mm_yytable[mm_yyn];
        *++mm_yyvsp = mm_yylval;
        mm_yychar = (-1);
        if (mm_yyerrflag > 0)  --mm_yyerrflag;
        goto mm_yyloop;
    }

    if ((mm_yyn = mm_yyrindex[mm_yystate]) && (mm_yyn += mm_yychar) >= 0 &&
            mm_yyn <= YYTABLESIZE && mm_yycheck[mm_yyn] == mm_yychar)
    {
        mm_yyn = mm_yytable[mm_yyn];
        goto mm_yyreduce;
    }

    if (mm_yyerrflag) goto mm_yyinrecovery;
    goto mm_yynewerror;
mm_yynewerror:
    mm_yyerror("syntax error");
    goto mm_yyerrlab;
mm_yyerrlab:
    ++mm_yynerrs;
mm_yyinrecovery:
    if (mm_yyerrflag < 3)
    {
        mm_yyerrflag = 3;
        for (;;)
        {
            if ((mm_yyn = mm_yysindex[*mm_yyssp]) && (mm_yyn += YYERRCODE) >= 0 &&
                    mm_yyn <= YYTABLESIZE && mm_yycheck[mm_yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (mm_yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *mm_yyssp, mm_yytable[mm_yyn]);
#endif
                if (mm_yyssp >= mm_yysslim && mm_yygrowstack())
                {
                    goto mm_yyoverflow;
                }
                *++mm_yyssp = mm_yystate = mm_yytable[mm_yyn];
                *++mm_yyvsp = mm_yylval;
                goto mm_yyloop;
            }
            else
            {
#if YYDEBUG
                if (mm_yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *mm_yyssp);
#endif
                if (mm_yyssp <= mm_yyss) goto mm_yyabort;
                --mm_yyssp;
                --mm_yyvsp;
            }
        }
    }
    else
    {
        if (mm_yychar == 0) goto mm_yyabort;
#if YYDEBUG
        if (mm_yydebug)
        {
            mm_yys = 0;
            if (mm_yychar <= YYMAXTOKEN) mm_yys = mm_yyname[mm_yychar];
            if (!mm_yys) mm_yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, mm_yystate, mm_yychar, mm_yys);
        }
#endif
        mm_yychar = (-1);
        goto mm_yyloop;
    }
mm_yyreduce:
#if YYDEBUG
    if (mm_yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, mm_yystate, mm_yyn, mm_yyrule[mm_yyn]);
#endif
    mm_yym = mm_yylen[mm_yyn];
    mm_yyval = mm_yyvsp[1-mm_yym];
    switch (mm_yyn)
    {
case 2:
#line 55 "minc.y"
{ MPRINT("prg:"); program = mm_yyvsp[0].trees; cleanup(); return 0; }
break;
case 3:
#line 59 "minc.y"
{ MPRINT("<stmt>"); mm_yyval.trees = mm_yyvsp[0].trees; }
break;
case 4:
#line 60 "minc.y"
{ MPRINT("<stmt;>"); mm_yyval.trees = mm_yyvsp[-1].trees; }
break;
case 5:
#line 61 "minc.y"
{ MPRINT("<stml stmt>"); mm_yyval.trees = tseq(mm_yyvsp[-1].trees, mm_yyvsp[0].trees); }
break;
case 6:
#line 62 "minc.y"
{ MPRINT("<stml stmt;>"); mm_yyval.trees = tseq(mm_yyvsp[-2].trees, mm_yyvsp[-1].trees); }
break;
case 7:
#line 66 "minc.y"
{ MPRINT("<rstmt>");
								if (level == 0) 
									mm_yyval.trees = go(mm_yyvsp[0].trees); 
								else
									mm_yyval.trees = mm_yyvsp[0].trees;
							}
break;
case 8:
#line 72 "minc.y"
{ declare(MincFloatType); idcount = 0; }
break;
case 9:
#line 73 "minc.y"
{ declare(MincStringType); idcount = 0; }
break;
case 10:
#line 74 "minc.y"
{ declare(MincHandleType); idcount = 0; }
break;
case 11:
#line 75 "minc.y"
{
								level--; MPRINT1("level %d", level);
								mm_yyval.trees = go(tif(mm_yyvsp[-1].trees, mm_yyvsp[0].trees));
							}
break;
case 12:
#line 79 "minc.y"
{
								level--; MPRINT1("level %d", level);
								mm_yyval.trees = go(tifelse(mm_yyvsp[-3].trees, mm_yyvsp[-2].trees, mm_yyvsp[0].trees));
							}
break;
case 13:
#line 83 "minc.y"
{
								level--; MPRINT1("level %d", level);
								mm_yyval.trees = go(twhile(mm_yyvsp[-1].trees, mm_yyvsp[0].trees));
							}
break;
case 14:
#line 87 "minc.y"
{
								level--; MPRINT1("level %d", level);
								mm_yyval.trees = go(tfor(mm_yyvsp[-6].trees, mm_yyvsp[-4].trees, mm_yyvsp[-2].trees, mm_yyvsp[0].trees));
							}
break;
case 15:
#line 91 "minc.y"
{ mm_yyval.trees = mm_yyvsp[-1].trees; }
break;
case 16:
#line 92 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 17:
#line 93 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 18:
#line 94 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 19:
#line 95 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 20:
#line 96 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 21:
#line 97 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 22:
#line 98 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 23:
#line 99 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 24:
#line 100 "minc.y"
{ flerror = 1; mm_yyval.trees = tnoop(); }
break;
case 25:
#line 104 "minc.y"
{ level++; MPRINT1("level %d", level); }
break;
case 26:
#line 108 "minc.y"
{
								sym = lookup(mm_yyvsp[-2].str);
								if (sym == NULL)	/* then autodeclare it */
									sym = install(mm_yyvsp[-2].str, S_GLOBAL);
								mm_yyval.trees = tstore(tname(sym), mm_yyvsp[0].trees);
							}
break;
case 27:
#line 114 "minc.y"
{
								sym = lookup(mm_yyvsp[-2].str);
								if (sym == NULL) {
									minc_die("'%s' is not declared", mm_yyvsp[-2].str);
									mm_yyval.trees = tnoop();
								}
								else
									mm_yyval.trees = topassign(tname(sym), mm_yyvsp[0].trees, OpPlus);
							}
break;
case 28:
#line 123 "minc.y"
{
								sym = lookup(mm_yyvsp[-2].str);
								if (sym == NULL) {
									minc_die("'%s' is not declared", mm_yyvsp[-2].str);
									mm_yyval.trees = tnoop();
								}
								else
									mm_yyval.trees = topassign(tname(sym), mm_yyvsp[0].trees, OpMinus);
							}
break;
case 29:
#line 132 "minc.y"
{
								sym = lookup(mm_yyvsp[-2].str);
								if (sym == NULL) {
									minc_die("'%s' is not declared", mm_yyvsp[-2].str);
									mm_yyval.trees = tnoop();
								}
								else
									mm_yyval.trees = topassign(tname(sym), mm_yyvsp[0].trees, OpMul);
							}
break;
case 30:
#line 141 "minc.y"
{
								sym = lookup(mm_yyvsp[-2].str);
								if (sym == NULL) {
									minc_die("'%s' is not declared", mm_yyvsp[-2].str);
									mm_yyval.trees = tnoop();
								}
								else
									mm_yyval.trees = topassign(tname(sym), mm_yyvsp[0].trees, OpDiv);
							}
break;
case 31:
#line 151 "minc.y"
{ mm_yyval.trees = tcall(mm_yyvsp[-1].trees, mm_yyvsp[-3].str); }
break;
case 32:
#line 154 "minc.y"
{ mm_yyval.trees = tlist(mm_yyvsp[-1].trees); }
break;
case 33:
#line 156 "minc.y"
{
								sym = lookup(mm_yyvsp[-3].str);
								if (sym == NULL) {
									minc_die("'%s' is not declared", mm_yyvsp[-3].str);
									mm_yyval.trees = tnoop();
								}
								else
									mm_yyval.trees = tsubscriptread(tname(sym), mm_yyvsp[-1].trees);
							}
break;
case 34:
#line 165 "minc.y"
{
								sym = lookup(mm_yyvsp[-5].str);
								if (sym == NULL) {
									minc_die("'%s' is not declared", mm_yyvsp[-5].str);
									mm_yyval.trees = tnoop();
								}
								else
									mm_yyval.trees = tsubscriptwrite(tname(sym), mm_yyvsp[-3].trees, mm_yyvsp[0].trees);
							}
break;
case 35:
#line 177 "minc.y"
{ idlist[idcount++] = mm_yyvsp[0].str; }
break;
case 36:
#line 178 "minc.y"
{ idlist[idcount++] = mm_yyvsp[0].str; }
break;
case 37:
#line 182 "minc.y"
{ mm_yyval.str = strsave(mm_yytext); }
break;
case 38:
#line 186 "minc.y"
{ mm_yyval.trees = tlistelem(temptylistelem(), mm_yyvsp[0].trees); }
break;
case 39:
#line 187 "minc.y"
{ mm_yyval.trees = tlistelem(mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 40:
#line 192 "minc.y"
{ mm_yyval.trees = temptylistelem(); }
break;
case 41:
#line 196 "minc.y"
{
								char *s = mm_yytext + 1;
								s[strlen(s) - 1] = '\0';
								mm_yyval.trees = tstring(strsave(s));
							}
break;
case 42:
#line 204 "minc.y"
{ mm_yyval.trees = mm_yyvsp[0].trees; }
break;
case 43:
#line 205 "minc.y"
{ mm_yyval.trees = tnot(mm_yyvsp[0].trees); }
break;
case 44:
#line 206 "minc.y"
{ mm_yyval.trees = tcand(mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 45:
#line 207 "minc.y"
{ mm_yyval.trees = tcor(mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 46:
#line 208 "minc.y"
{ mm_yyval.trees = trel(OpEqual, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 47:
#line 209 "minc.y"
{ mm_yyval.trees = trel(OpNotEqual, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 48:
#line 210 "minc.y"
{ mm_yyval.trees = trel(OpLess, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 49:
#line 211 "minc.y"
{ mm_yyval.trees = trel(OpGreater, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 50:
#line 212 "minc.y"
{ mm_yyval.trees = trel(OpLessEqual, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 51:
#line 213 "minc.y"
{ mm_yyval.trees = trel(OpGreaterEqual, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 52:
#line 214 "minc.y"
{ mm_yyval.trees = trel(OpEqual, tconstf(1.0), tconstf(1.0)); }
break;
case 53:
#line 215 "minc.y"
{ mm_yyval.trees = trel(OpNotEqual, tconstf(1.0), tconstf(1.0)); }
break;
case 54:
#line 219 "minc.y"
{ mm_yyval.trees = mm_yyvsp[0].trees; }
break;
case 55:
#line 220 "minc.y"
{ mm_yyval.trees = top(OpPow, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 56:
#line 221 "minc.y"
{ mm_yyval.trees = top(OpMul, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 57:
#line 222 "minc.y"
{ mm_yyval.trees = top(OpDiv, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 58:
#line 223 "minc.y"
{ mm_yyval.trees = top(OpPlus, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 59:
#line 224 "minc.y"
{ mm_yyval.trees = top(OpMinus, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 60:
#line 225 "minc.y"
{ mm_yyval.trees = top(OpMod, mm_yyvsp[-2].trees, mm_yyvsp[0].trees); }
break;
case 61:
#line 226 "minc.y"
{ mm_yyval.trees = mm_yyvsp[-1].trees; }
break;
case 62:
#line 227 "minc.y"
{ mm_yyval.trees = mm_yyvsp[0].trees; }
break;
case 63:
#line 228 "minc.y"
{
								double f = atof(mm_yytext);
								mm_yyval.trees = tconstf(f);
							}
break;
case 64:
#line 232 "minc.y"
{ mm_yyval.trees = tconstf(1.0); }
break;
case 65:
#line 233 "minc.y"
{ mm_yyval.trees = tconstf(0.0); }
break;
case 66:
#line 234 "minc.y"
{
								/* tconstf is a dummy; makes exct_operator work */
								mm_yyval.trees = top(OpNeg, mm_yyvsp[0].trees, tconstf(0.0));
							}
break;
case 67:
#line 238 "minc.y"
{
								sym = lookup(mm_yyvsp[0].str);
								if (sym == NULL) {
/* FIXME: install id w/ value of 0, then warn??*/
									minc_die("'%s' is not declared", mm_yyvsp[0].str);
									mm_yyval.trees = tconstf(0.0);
								}
								else
									mm_yyval.trees = tname(sym);
							}
break;
#line 1141 "y.tab.c"
    }
    mm_yyssp -= mm_yym;
    mm_yystate = *mm_yyssp;
    mm_yyvsp -= mm_yym;
    mm_yym = mm_yylhs[mm_yyn];
    if (mm_yystate == 0 && mm_yym == 0)
    {
#if YYDEBUG
        if (mm_yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        mm_yystate = YYFINAL;
        *++mm_yyssp = YYFINAL;
        *++mm_yyvsp = mm_yyval;
        if (mm_yychar < 0)
        {
            if ((mm_yychar = mm_yylex()) < 0) mm_yychar = 0;
#if YYDEBUG
            if (mm_yydebug)
            {
                mm_yys = 0;
                if (mm_yychar <= YYMAXTOKEN) mm_yys = mm_yyname[mm_yychar];
                if (!mm_yys) mm_yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, mm_yychar, mm_yys);
            }
#endif
        }
        if (mm_yychar == 0) goto mm_yyaccept;
        goto mm_yyloop;
    }

    if ((mm_yyn = mm_yygindex[mm_yym]) && (mm_yyn += mm_yystate) >= 0 &&
            mm_yyn <= YYTABLESIZE && mm_yycheck[mm_yyn] == mm_yystate)
        mm_yystate = mm_yytable[mm_yyn];
    else
        mm_yystate = mm_yydgoto[mm_yym];
#if YYDEBUG
    if (mm_yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *mm_yyssp, mm_yystate);
#endif
    if (mm_yyssp >= mm_yysslim && mm_yygrowstack())
    {
        goto mm_yyoverflow;
    }

    *++mm_yyssp = mm_yystate;
    *++mm_yyvsp = mm_yyval;
    goto mm_yyloop;
mm_yyoverflow:
    mm_yyerror("yacc stack overflow");
mm_yyabort:
    return (1);
mm_yyaccept:
    return (0);
}
