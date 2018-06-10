%{
#include <Windows.h>
#include "stdio.h"
#include <process.h>
#include <direct.h>
#include <stdlib.h>
#include <tchar.h>
#include <wchar.h>
#include "calc.h"
#include "dctYacc.h"
#define yywrap() 1
#define YY_SKIP_YYWRAP
#include "FlexDef.h"
extern int YYLVAL;
int line_num=1;
int comment_caller;
int aa=0;
FILE*file;
extern char**files;
extern int standard;
char str[128];
%}
%x comment comment2 foo
WS		[[:blank:]]+
NL		\r?\n
dig	[0-9]
files		[Ff][Ii][Ll][Ee][Ss]
parts		[Pp][Aa][Rr][Tt][Ss]
del			[Dd][Ee][Ll]
debug		[Dd][Ee][Bb][Uu][Gg]
exclude [Ee][Xx][Cc][Ll][Uu][Dd][Ee]
excel		[Ee][Xx][Cc][Ee][Ll]
visual  [Vv][Ii][Ss][Uu][Aa][Ll]
xyStart	[xX][yY][sS][tT][aA][rR][tT]

polisNumber		[pP][oO][lL][iI][sS][nN][uU][mM][bB][eE][rR]
mkbCode				[mM][kK][bB][cC][oO][dD][eE]
errorMsg			[eE][rR][rR][oO][rR][mM][sS][gG]
results				[rR][eE][sS][uU][lL][tT][sS]

lpuServiceCode	[lL][pP][uU][sS][eE][rR][vV][iI][cC][eE][cC][oO][dD][eE]
answerType			[aA][nN][sS][wW][eE][rR][tT][yY][pP][eE]
reasonType			[rR][eE][aA][sS][oO][nN][tT][yY][pP][eE]
comment					[cC][oO][mM][mM][eE][nN][tT]

alpha	[A-Za-zа-яА-ЯёЁ]
NAME	({alpha}|{dig}|\$)({alpha}|{dig}|\_|\.|\-|\/|\$)*

	/*DIGIT [[:digit:]]+*/
punc	[[:punct:]]{1}
%%
[\^]+	{return '^';}
"/*" {comment_caller=INITIAL;BEGIN(comment);}
<foo>"/*" {comment_caller=foo;BEGIN(comment); }
<comment>[^*\n]*
<comment>"*"+[^*/\n]*  
<comment>\n			++line_num;
<comment>"*"+"/"	BEGIN(comment_caller);
<comment><<EOF>> {
			strcpy(str,*files);strcat(str,": незаконченный комментарий в конце файла. ");
			strcat(str,"\n\t\t\tДолжно стоять */ и перевод строки.\n");
			CharToOem(str,str);
//			printf("\t%s: Unterminated comment at EOF. Must be '*/CR'\n",*files);
			printf("\t%s",str);
			yyterminate();}

"//"							{BEGIN(comment2);}
<comment2>[^\n]*
<comment2>\n		{line_num++;BEGIN(INITIAL);}
<comment2><<EOF>> {
//				printf("\t%s: Unterminated  comment at EOF. Must be 'CR'.\n",*files);
			strcpy(str,*files);strcat(str,": незаконченный комментарий в конце файла. ");
			strcat(str,"\n\t\t\tДолжен стоять перевод строки.\n");
			CharToOem(str,str);
			printf("\t%s",str);
			yyterminate();
	}

[;]+	{return ';';}
	/*{DIGIT}+ {*/
{dig}+ {yylval.valInt=atoi(yytext);return DIGIT;}
{files}		{return filesKey;}
{parts}		{return partsKey;}
{del}			{return delKey;}
{debug}		{return debugKey;}
{exclude}	{return excludeKey;}
{excel}		{return excelKey;}
{visual}  {return visualKey;}
{xyStart} {return xyStartKey;}

/*{polisNumber}			{return polisNumbersKey;}
{mkbCode}					{return mkbCodeKey;}
{errorMsg}				{return errorMsgKey;}
{results}					{return resultsKey;}
   
{lpuServiceCode}	{return lpuServiceCodeKey;}
{answerType}			{return answerTypeKey;}
{reasonType}			{return reasonTypeKey;}
{comment}					{return commentKey;}
*/
{NAME}	{yylval.val2=(char*)malloc(strlen(yytext)+1);strcpy(yylval.val2,yytext);return NAME;}
{punc} {
		char c=yytext[0];
		if(c=='\'')return '\'';else if(c=='!')return '!';else if(c==';')return ';';
		else if(c==',')return ',';
	}
{NL}	{
				line_num++;//fprintf(stderr,"\n%s\n",secondFile);
//				if(yychar!=YYEMPTY){return nl;}
			}/*return nl;}/*if(YYSTATE!=1)return '\n';}*/
{WS}  {;}
<<EOF>> {
//					char str[64];
//					wchar_t
//					fprintf(stderr,"File %s finished\n",*files);
					strcpy(str,"Файл ");strcat(str,*files);strcat(str," обработан.\n");
					CharToOem(str,str);
					_ftprintf(stderr,_T(str));
//					fprintf(stderr,str);
					if(*++files!=NULL)
					{
						if(file=fopen(*files,"r")){yyin=fopen(*files,"r");YY_NEW_FILE;}
						else 
						{
							yyin=stdin;
							CharToOem("Вводите, пожалуйста, свои строки (Для выхода: CTRL C):\n",str);
							fprintf(stderr,str);
							standard=1;
						}
						line_num=1;
					}else yyterminate();
				}
.|\n
%%
