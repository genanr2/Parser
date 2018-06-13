
/*  A Bison parser, made from dct.y
 by  GNU Bison version 
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	filesKey	257
#define	partsKey	258
#define	delKey	259
#define	debugKey	260
#define	excludeKey	261
#define	nl	262
#define	excelKey	263
#define	visualKey	264
#define	xyStartKey	265
#define	DIGIT	266
#define	NAME	267

#line 1 "dct.y"

#include <Windows.h>
#define YYSTATE double
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <ctype.h>
#include "..\FlexDef.h"
#include "..\calc.h"
#define YYDEBUG 1
FILE*file;
char**files;
int standard=0;
Goal*goal=NULL;

#line 16 "dct.y"
typedef union {
	char*val2;int valInt;
	Region*region;			Regions*regions;
	PartList*partList;		Part*part;
	Reminders*reminders;Reminder*reminder;
	DelList*delList;		DelPart*delPart;	DigList*digList;
	Goal*goal;
	FirstSection*firstSection;	FirstSectionList*firstSectionList;
	SecondSection*secondSection;SecondSectionList*secondSectionList;
	ThirdSection*thirdSection;	ThirdSectionList*thirdSectionList;
	XyStartList*xyStartList;XyStart*xyStart;
} YYSTYPE;
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		100
#define	YYFLAG		-32768
#define	YYNTBASE	18

#define YYTRANSLATE(x) ((unsigned)(x) <= 267 ? yytranslate[x] : 38)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    14,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    17,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    16,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    15,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,     9,    12,    15,    17,    20,    24,
    26,    29,    33,    35,    38,    42,    44,    47,    50,    52,
    56,    58,    61,    65,    68,    71,    73,    77,    80,    83,
    85,    89,    91,    94,    95,    97,   101,   104,   106,   110,
   113,   115,   118,   121,   123,   127,   129,   132,   142,   152,
   162,   164,   167,   172,   174,   177,   186,   188,   191
};

static const short yyrhs[] = {    19,
     0,     1,    14,     0,    20,     0,     1,     0,    21,    30,
     0,    30,    21,     0,    22,     0,    21,    22,     0,     3,
    12,    15,     0,     3,     0,     3,    15,     0,     4,    23,
    15,     0,     4,     0,     4,    15,     0,     5,    27,    15,
     0,     5,     0,     5,    15,     0,     6,    12,     0,     6,
     0,     7,    29,    15,     0,     7,     0,     7,    15,     0,
     9,    12,    15,     0,     9,    12,     0,     9,    15,     0,
     9,     0,    10,    12,    15,     0,    10,    12,     0,    10,
    15,     0,    10,     0,    11,    25,    15,     0,    11,     0,
    11,    15,     0,     0,    24,     0,    23,    16,    24,     0,
    12,    12,     0,    26,     0,    25,    16,    26,     0,    12,
    13,     0,    28,     0,    27,    28,     0,    12,    29,     0,
    12,     0,    29,    16,    12,     0,    31,     0,    30,    31,
     0,    17,    12,    12,    12,    12,    12,    12,    15,    32,
     0,    17,    12,    12,    12,    12,    12,    12,    15,    34,
     0,    17,    12,    12,    12,    12,    12,    12,    15,    36,
     0,    33,     0,    32,    33,     0,    12,    12,    12,    15,
     0,    35,     0,    34,    35,     0,    12,    12,    12,    12,
    12,    12,    12,    15,     0,    37,     0,    36,    37,     0,
    12,    12,    12,    12,    15,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    50,    50,    51,    56,    57,    60,    62,    64,    69,    71,
    72,    74,    76,    77,    79,    81,    82,    83,    85,    86,
    88,    89,    91,    92,    93,    94,    96,    97,    98,    99,
   101,   103,   104,   106,   126,   127,   132,   134,   135,   140,
   146,   147,   152,   154,   155,   160,   164,   171,   177,   183,
   189,   194,   201,   205,   210,   217,   222,   226,   233
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","filesKey",
"partsKey","delKey","debugKey","excludeKey","nl","excelKey","visualKey","xyStartKey",
"DIGIT","NAME","'\\n'","';'","','","'!'","input","line","goal","reminders","reminder",
"partList","part","xyStartList","xyStart","delList","delPart","digList","regions",
"region","firstSectionList","firstSection","secondSectionList","secondSection",
"thirdSectionList","thirdSection", NULL
};
#endif

static const short yyr1[] = {     0,
    18,    18,    19,    19,    20,    20,    21,    21,    22,    22,
    22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
    22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
    22,    22,    22,    22,    23,    23,    24,    25,    25,    26,
    27,    27,    28,    29,    29,    30,    30,    31,    31,    31,
    32,    32,    33,    34,    34,    35,    36,    36,    37
};

static const short yyr2[] = {     0,
     1,     2,     1,     1,     2,     2,     1,     2,     3,     1,
     2,     3,     1,     2,     3,     1,     2,     2,     1,     3,
     1,     2,     3,     2,     2,     1,     3,     2,     2,     1,
     3,     1,     2,     0,     1,     3,     2,     1,     3,     2,
     1,     2,     2,     1,     3,     1,     2,     9,     9,     9,
     1,     2,     4,     1,     2,     8,     1,     2,     5
};

static const short yydefact[] = {     0,
     4,    10,    13,    16,    19,    21,    26,    30,    32,     0,
     1,     3,     0,     7,    34,    46,     2,     0,    11,     0,
    14,     0,    35,     0,    17,     0,    41,    18,    44,    22,
     0,    24,    25,    28,    29,     0,    33,     0,    38,     0,
     8,     5,     6,    47,     9,    37,    12,     0,    43,    15,
    42,    20,     0,    23,    27,    40,    31,     0,     0,    36,
    45,    39,     0,     0,     0,     0,     0,     0,    48,    51,
    49,    54,    50,    57,     0,     0,    52,     0,    55,     0,
    58,     0,     0,     0,     0,     0,    53,     0,     0,     0,
     0,    59,     0,     0,     0,     0,    56,     0,     0,     0
};

static const short yydefgoto[] = {    98,
    11,    12,    13,    14,    22,    23,    38,    39,    26,    27,
    31,    15,    16,    69,    70,    71,    72,    73,    74
};

static const short yypact[] = {     1,
   -11,    11,    29,    30,    -3,    31,    35,    36,    37,    17,
-32768,-32768,    10,-32768,    10,-32768,-32768,     7,-32768,    24,
-32768,     9,-32768,    51,-32768,    41,-32768,-32768,-32768,-32768,
    44,    25,-32768,    49,-32768,    52,-32768,    46,-32768,    54,
-32768,    50,    28,-32768,-32768,-32768,-32768,    56,    53,-32768,
-32768,-32768,    58,-32768,-32768,-32768,-32768,    59,    60,-32768,
-32768,-32768,    61,    62,    63,    64,    65,    66,    68,-32768,
    69,-32768,    70,-32768,    71,    72,-32768,    73,-32768,    74,
-32768,    42,    75,    76,    77,    43,-32768,    78,    79,    80,
    82,-32768,    83,    81,    85,    84,-32768,    90,    98,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    86,   -13,-32768,    55,-32768,    18,-32768,    87,
    88,    89,   -14,-32768,    38,-32768,    33,-32768,    27
};


#define	YYLAST		113


static const short yytable[] = {    41,
    44,     1,    17,     2,     3,     4,     5,     6,    28,     7,
     8,     9,     2,     3,     4,     5,     6,    10,     7,     8,
     9,    45,    18,    47,    48,    19,    10,    44,    40,    41,
     2,     3,     4,     5,     6,    46,     7,     8,     9,    54,
    20,    24,    29,    21,    25,    30,    32,    34,    36,    33,
    35,    37,    24,    86,    91,    50,    87,    92,    52,    53,
    57,    58,    29,    55,    56,    59,    10,    20,    53,    61,
    36,    63,    64,    65,    66,    62,    68,    75,    67,    76,
    78,    80,    82,    83,    84,    85,    88,    89,    90,    99,
    93,    94,    87,    95,    91,    92,    96,   100,    97,    81,
    43,    42,    60,    79,     0,     0,    77,     0,     0,     0,
     0,    49,    51
};

static const short yycheck[] = {    13,
    15,     1,    14,     3,     4,     5,     6,     7,    12,     9,
    10,    11,     3,     4,     5,     6,     7,    17,     9,    10,
    11,    15,    12,    15,    16,    15,    17,    42,    12,    43,
     3,     4,     5,     6,     7,    12,     9,    10,    11,    15,
    12,    12,    12,    15,    15,    15,    12,    12,    12,    15,
    15,    15,    12,    12,    12,    15,    15,    15,    15,    16,
    15,    16,    12,    15,    13,    12,    17,    12,    16,    12,
    12,    12,    12,    12,    12,    58,    12,    12,    15,    12,
    12,    12,    12,    12,    12,    12,    12,    12,    12,     0,
    12,    12,    15,    12,    12,    15,    12,     0,    15,    73,
    15,    13,    48,    71,    -1,    -1,    69,    -1,    -1,    -1,
    -1,    24,    26
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"
/* This file comes from bison-@bison_version@.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 216 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 2:
#line 50 "dct.y"
{yyerrok;YYERROR;;
    break;}
case 3:
#line 52 "dct.y"
{
			 goal=yyvsp[0].goal;
			 printRegions(yyvsp[0].goal);
//			 printRegions2($1);
		 ;
    break;}
case 5:
#line 57 "dct.y"
{yyval.goal=(Goal*)malloc(sizeof(Goal));yyval.goal->rems=yyvsp[-1].reminders;yyval.goal->regs=yyvsp[0].regions;;
    break;}
case 6:
#line 60 "dct.y"
{yyval.goal=(Goal*)malloc(sizeof(Goal));yyval.goal->rems=yyvsp[0].reminders;yyval.goal->regs=yyvsp[-1].regions;;
    break;}
case 7:
#line 63 "dct.y"
{yyval.reminders=(Reminders*)malloc(sizeof(Reminders));yyval.reminders->reminder=yyvsp[0].reminder;yyval.reminders->next=NULL;;
    break;}
case 8:
#line 65 "dct.y"
{
			Reminders*bb,*aa;bb=(Reminders*)malloc(sizeof(Reminders));bb->reminder=yyvsp[0].reminder;
			bb->next=NULL;aa=yyvsp[-1].reminders;while(aa->next!=NULL)aa=aa->next;aa->next=bb;yyval.reminders=yyvsp[-1].reminders;
		;
    break;}
case 9:
#line 70 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=fileType;yyval.reminder->gen.files=yyvsp[-1].valInt;;
    break;}
case 10:
#line 71 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=fileType;yyval.reminder->gen.files=0;;
    break;}
case 11:
#line 72 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=fileType;yyval.reminder->gen.files=0;;
    break;}
case 12:
#line 75 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=partType;yyval.reminder->gen.parts=yyvsp[-1].partList;;
    break;}
case 13:
#line 76 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=partType;yyval.reminder->gen.parts=NULL;;
    break;}
case 14:
#line 77 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=partType;yyval.reminder->gen.parts=NULL;;
    break;}
case 15:
#line 80 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=delType;yyval.reminder->gen.delList=yyvsp[-1].delList;;
    break;}
case 16:
#line 81 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=delType;yyval.reminder->gen.delList=NULL;;
    break;}
case 17:
#line 82 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=delType;yyval.reminder->gen.delList=NULL;;
    break;}
case 18:
#line 84 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=debugType;yyval.reminder->gen.debug=yyvsp[0].valInt;;
    break;}
case 19:
#line 85 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=debugType;yyval.reminder->gen.debug=0;;
    break;}
case 20:
#line 87 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=excludeType;yyval.reminder->gen.exludeRegs=yyvsp[-1].digList;;
    break;}
case 21:
#line 88 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=excludeType;yyval.reminder->gen.exludeRegs=NULL;;
    break;}
case 22:
#line 89 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=excludeType;yyval.reminder->gen.exludeRegs=NULL;;
    break;}
case 23:
#line 91 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=excelType;yyval.reminder->gen.excelVer=yyvsp[-1].valInt;;
    break;}
case 24:
#line 92 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=excelType;yyval.reminder->gen.excelVer=yyvsp[0].valInt;;
    break;}
case 25:
#line 93 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=excelType;yyval.reminder->gen.excelVer=8;;
    break;}
case 26:
#line 94 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=excelType;yyval.reminder->gen.excelVer=8;;
    break;}
case 27:
#line 96 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=visualType;yyval.reminder->gen.visual=yyvsp[-1].valInt;;
    break;}
case 28:
#line 97 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=visualType;yyval.reminder->gen.visual=yyvsp[0].valInt;;
    break;}
case 29:
#line 98 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=visualType;yyval.reminder->gen.visual=0;;
    break;}
case 30:
#line 99 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=visualType;yyval.reminder->gen.visual=0;;
    break;}
case 31:
#line 102 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=xyStartType;yyval.reminder->gen.xyStart=yyvsp[-1].xyStartList;;
    break;}
case 32:
#line 103 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=xyStartType;yyval.reminder->gen.xyStart=NULL;;
    break;}
case 33:
#line 104 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=xyStartType;yyval.reminder->gen.xyStart=NULL;;
    break;}
case 34:
#line 106 "dct.y"
{yyval.reminder=(Reminder*)malloc(sizeof(Reminder));yyval.reminder->type=debugType;yyval.reminder->gen.files=0;;
    break;}
case 35:
#line 126 "dct.y"
{yyval.partList=(PartList*)malloc(sizeof(PartList));yyval.partList->part=yyvsp[0].part;yyval.partList->next=NULL;;
    break;}
case 36:
#line 128 "dct.y"
{
				PartList*bb,*aa;bb=(PartList*)malloc(sizeof(PartList));bb->part=yyvsp[0].part;bb->next=NULL;
				aa=yyvsp[-2].partList;while(aa->next!=NULL)aa=aa->next;aa->next=bb;yyval.partList=yyvsp[-2].partList;
			;
    break;}
case 37:
#line 132 "dct.y"
{yyval.part=(Part*)malloc(sizeof(Part));yyval.part->partNo=yyvsp[-1].valInt;yyval.part->lines=yyvsp[0].valInt;;
    break;}
case 38:
#line 134 "dct.y"
{yyval.xyStartList=(XyStartList*)malloc(sizeof(XyStartList));yyval.xyStartList->xy=yyvsp[0].xyStart;yyval.xyStartList->next=NULL;;
    break;}
case 39:
#line 136 "dct.y"
{
				XyStartList*bb,*aa;bb=(XyStartList*)malloc(sizeof(XyStartList));bb->xy=yyvsp[0].xyStart;bb->next=NULL;
				aa=yyvsp[-2].xyStartList;while(aa->next!=NULL)aa=aa->next;aa->next=bb;yyval.xyStartList=yyvsp[-2].xyStartList;
			;
    break;}
case 40:
#line 141 "dct.y"
{
				yyval.xyStart=(XyStart*)malloc(sizeof(XyStart));yyval.xyStart->partNo=yyvsp[-1].valInt;
				yyval.xyStart->xy=(char*)malloc(strlen(yyvsp[0].val2)+1);strcpy(yyval.xyStart->xy,yyvsp[0].val2);
//				MessageBox(NULL,$$->xy,$2,MB_OK);
		 ;
    break;}
case 41:
#line 146 "dct.y"
{yyval.delList=(DelList*)malloc(sizeof(DelList));yyval.delList->del=yyvsp[0].delPart;yyval.delList->next=NULL;;
    break;}
case 42:
#line 148 "dct.y"
{
			DelList*bb,*aa;bb=(DelList*)malloc(sizeof(DelList));bb->del=yyvsp[0].delPart;bb->next=NULL;aa=yyvsp[-1].delList;
			while(aa->next!=NULL)aa=aa->next;aa->next=bb;yyval.delList=yyvsp[-1].delList;
		;
    break;}
case 43:
#line 153 "dct.y"
{yyval.delPart=(DelPart*)malloc(sizeof(DelPart));yyval.delPart->regNo=yyvsp[-1].valInt;yyval.delPart->lines=yyvsp[0].digList;;
    break;}
case 44:
#line 154 "dct.y"
{yyval.digList=(DigList*)malloc(sizeof(DigList));yyval.digList->next=NULL;yyval.digList->dig=yyvsp[0].valInt;;
    break;}
case 45:
#line 156 "dct.y"
{
			DigList*bb,*aa;bb=(DigList*)malloc(sizeof(DigList));bb->next=NULL;bb->dig=yyvsp[0].valInt;
			aa=yyvsp[-2].digList;while(aa->next!=NULL)aa=aa->next;aa->next=bb;yyval.digList=yyvsp[-2].digList;
		;
    break;}
case 46:
#line 161 "dct.y"
{
				yyval.regions=(Regions*)malloc(sizeof(Regions));yyval.regions->region=yyvsp[0].region;yyval.regions->next=NULL;
			;
    break;}
case 47:
#line 165 "dct.y"
{
				Regions*bb,*aa;
				bb=(Regions*)malloc(sizeof(Regions));
				bb->region=yyvsp[0].region;bb->next=NULL;aa=yyvsp[-1].regions;
				while(aa->next!=NULL)aa=aa->next;aa->next=bb;yyval.regions=yyvsp[-1].regions;
			;
    break;}
case 48:
#line 172 "dct.y"
{
			yyval.region=(Region*)malloc(sizeof(Region));
			yyval.region->sectNo=yyvsp[-5].valInt;yyval.region->year=yyvsp[-4].valInt;yyval.region->month=yyvsp[-3].valInt;yyval.region->regionNo=yyvsp[-2].valInt;
			yyval.region->gen.first=yyvsp[0].firstSectionList;yyval.region->type=firstType;
		;
    break;}
case 49:
#line 178 "dct.y"
{
			yyval.region=(Region*)malloc(sizeof(Region));
			yyval.region->sectNo=yyvsp[-5].valInt;yyval.region->year=yyvsp[-4].valInt;yyval.region->month=yyvsp[-3].valInt;yyval.region->regionNo=yyvsp[-2].valInt;
			yyval.region->gen.second=yyvsp[0].secondSectionList;yyval.region->type=secondType;
		;
    break;}
case 50:
#line 184 "dct.y"
{
			yyval.region=(Region*)malloc(sizeof(Region));
			yyval.region->sectNo=yyvsp[-5].valInt;yyval.region->year=yyvsp[-4].valInt;yyval.region->month=yyvsp[-3].valInt;yyval.region->regionNo=yyvsp[-2].valInt;
			yyval.region->gen.third=yyvsp[0].thirdSectionList;yyval.region->type=thirdType;
		;
    break;}
case 51:
#line 190 "dct.y"
{
			yyval.firstSectionList=(FirstSectionList*)malloc(sizeof(FirstSectionList));
			yyval.firstSectionList->first=yyvsp[0].firstSection;yyval.firstSectionList->next=NULL;
		;
    break;}
case 52:
#line 195 "dct.y"
{
			FirstSectionList*bb,*aa;
			bb=(FirstSectionList*)malloc(sizeof(FirstSectionList));
			bb->first=yyvsp[0].firstSection;bb->next=NULL;aa=yyvsp[-1].firstSectionList;
			while(aa->next!=NULL){aa=aa->next;}aa->next=bb;yyval.firstSectionList=yyvsp[-1].firstSectionList;
		;
    break;}
case 53:
#line 202 "dct.y"
{
			yyval.firstSection=(FirstSection*)malloc(sizeof(FirstSection));yyval.firstSection->f1=yyvsp[-3].valInt;yyval.firstSection->f2=yyvsp[-2].valInt;yyval.firstSection->f3=yyvsp[-1].valInt;
		;
    break;}
case 54:
#line 206 "dct.y"
{
			yyval.secondSectionList=(SecondSectionList*)malloc(sizeof(SecondSectionList));
			yyval.secondSectionList->second=yyvsp[0].secondSection;yyval.secondSectionList->next=NULL;
		;
    break;}
case 55:
#line 211 "dct.y"
{
			SecondSectionList*bb,*aa;
			bb=(SecondSectionList*)malloc(sizeof(SecondSectionList));
			bb->second=yyvsp[0].secondSection;bb->next=NULL;aa=yyvsp[-1].secondSectionList;
			while(aa->next!=NULL){aa=aa->next;}aa->next=bb;yyval.secondSectionList=yyvsp[-1].secondSectionList;
		;
    break;}
case 56:
#line 218 "dct.y"
{
			yyval.secondSection=(SecondSection*)malloc(sizeof(SecondSection));
			yyval.secondSection->s1=yyvsp[-7].valInt;yyval.secondSection->s2=yyvsp[-6].valInt;yyval.secondSection->s3=yyvsp[-5].valInt;yyval.secondSection->s4=yyvsp[-4].valInt;yyval.secondSection->s5=yyvsp[-3].valInt;yyval.secondSection->s6=yyvsp[-2].valInt;yyval.secondSection->s7=yyvsp[-1].valInt;
		;
    break;}
case 57:
#line 223 "dct.y"
{
			yyval.thirdSectionList=(ThirdSectionList*)malloc(sizeof(ThirdSectionList));yyval.thirdSectionList->third=yyvsp[0].thirdSection;yyval.thirdSectionList->next=NULL;
		;
    break;}
case 58:
#line 227 "dct.y"
{
			ThirdSectionList*bb,*aa;
			bb=(ThirdSectionList*)malloc(sizeof(ThirdSectionList));
			bb->third=yyvsp[0].thirdSection;bb->next=NULL;aa=yyvsp[-1].thirdSectionList;
			while(aa->next!=NULL){aa=aa->next;}aa->next=bb;yyval.thirdSectionList=yyvsp[-1].thirdSectionList;
		;
    break;}
case 59:
#line 234 "dct.y"
{
		yyval.thirdSection=(ThirdSection*)malloc(sizeof(ThirdSection));yyval.thirdSection->t1=yyvsp[-4].valInt;yyval.thirdSection->t2=yyvsp[-3].valInt;yyval.thirdSection->t3=yyvsp[-2].valInt;yyval.thirdSection->t4=yyvsp[-1].valInt;
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 542 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 237 "dct.y"

void yyerror(char*s)
{
	char str[32];
	if(!standard)
	{
		if(*files==NULL){CharToOem("Не хватает файлов.\n",str);printf(str);}
		else{CharToOem("номер строки",str);printf("\n\t%s:\t%s.\t%s %d\n",*files,s,str,line_num);}
	}
//	else printf("\n\t%s:\t%s.\tLine number %d\n",*files,s,line_num);
}

int main3(int argc,char**argv)
{
	char str[64];
	++argv,--argc;
	files=argv;
	if((file=fopen(*files,"r"))!=NULL)yyin=file;else 
	{
		CharToOem("Вводите, пожалуйста, свои строки (Для выхода: CTRL C):\n",str);
		fprintf(stderr,str);
		yyin=stdin;standard=1;
	}
	while(yyparse()!=0);
	return 0;
}
