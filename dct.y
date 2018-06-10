%{
#include <Windows.h>
#define YYSTATE double
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <ctype.h>
#include "FlexDef.h"
#include "calc.h"
#define YYDEBUG 1
FILE*file;
char**files;
int standard=0;
Goal*goal=NULL;
%}
%union {
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
}
%token filesKey partsKey delKey debugKey excludeKey nl excelKey visualKey xyStartKey
%token <valInt>DIGIT
%token <val2>NAME
%type <region>region;
%type <regions>regions;
%type <reminders>reminders;
%type <reminder>reminder;
%type <partList>partList;
%type <part>part;
%type <delList>delList;
%type <delPart>delPart;
%type <digList>digList;
%type <goal>goal;
%type <firstSection>firstSection;
%type <firstSectionList>firstSectionList;
%type <secondSection>secondSection;
%type <secondSectionList>secondSectionList;
%type <thirdSection>thirdSection;
%type <thirdSectionList>thirdSectionList;
%type <xyStartList>xyStartList;
%type <xyStart>xyStart;
%%
input:line|error'\n'{yyerrok;YYERROR;};
line:goal
		 {
			 goal=$1;
			 printRegions($1);
//			 printRegions2($1);
		 }|error;
goal:reminders regions{$$=(Goal*)malloc(sizeof(Goal));$$->rems=$1;$$->regs=$2;}
//		 | reminders {$$=(Goal*)malloc(sizeof(Goal));$$->rems=$1;$$->regs=NULL;}
//		 | regions {$$=(Goal*)malloc(sizeof(Goal));$$->rems=NULL;$$->regs=$1;}
			|regions reminders{$$=(Goal*)malloc(sizeof(Goal));$$->rems=$2;$$->regs=$1;}
			;
reminders:reminder
			{$$=(Reminders*)malloc(sizeof(Reminders));$$->reminder=$1;$$->next=NULL;}
		|reminders reminder
		{
			Reminders*bb,*aa;bb=(Reminders*)malloc(sizeof(Reminders));bb->reminder=$2;
			bb->next=NULL;aa=$1;while(aa->next!=NULL)aa=aa->next;aa->next=bb;$$=$1;
		};
reminder:	filesKey DIGIT';'
				 {$$=(Reminder*)malloc(sizeof(Reminder));$$->type=fileType;$$->gen.files=$2;}
			| filesKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=fileType;$$->gen.files=0;}
			| filesKey';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=fileType;$$->gen.files=0;}

			|partsKey partList';'  
				{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=partType;$$->gen.parts=$2;}
			|partsKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=partType;$$->gen.parts=NULL;}
			|partsKey';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=partType;$$->gen.parts=NULL;}

			|delKey delList';'
				{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=delType;$$->gen.delList=$2;}
			|delKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=delType;$$->gen.delList=NULL;}
			|delKey';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=delType;$$->gen.delList=NULL;}
			| debugKey DIGIT
				{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=debugType;$$->gen.debug=$2;}
			| debugKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=debugType;$$->gen.debug=0;}
			| excludeKey digList';'
				{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=excludeType;$$->gen.exludeRegs=$2;}
			| excludeKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=excludeType;$$->gen.exludeRegs=NULL;}
			| excludeKey';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=excludeType;$$->gen.exludeRegs=NULL;}

			| excelKey DIGIT';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=excelType;$$->gen.excelVer=$2;}
			| excelKey DIGIT{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=excelType;$$->gen.excelVer=$2;}
			| excelKey ';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=excelType;$$->gen.excelVer=8;}
			| excelKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=excelType;$$->gen.excelVer=8;} 

			| visualKey DIGIT';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=visualType;$$->gen.visual=$2;}
			| visualKey DIGIT{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=visualType;$$->gen.visual=$2;}
			| visualKey ';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=visualType;$$->gen.visual=0;}
			| visualKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=visualType;$$->gen.visual=0;} 

			|xyStartKey xyStartList';'  
				{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=xyStartType;$$->gen.xyStart=$2;}
			|xyStartKey{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=xyStartType;$$->gen.xyStart=NULL;}
			|xyStartKey';'{$$=(Reminder*)malloc(sizeof(Reminder));$$->type=xyStartType;$$->gen.xyStart=NULL;}

			| {$$=(Reminder*)malloc(sizeof(Reminder));$$->type=debugType;$$->gen.files=0;}
/*			| error
			{
				printf("Error %d in file %s\n",yynerrs,*files);//,yychar);
				if(yychar!=YYEMPTY)
				{
					switch((int)yychar)
					{
						case filesKey:printf("files\n");break;	
						case partsKey:printf("parts\n");break;	
						case delKey:printf("del\n");break;	
						case debugKey:printf("debug\n");break;	
						case excludeKey:printf("exclude\n");break;	
						default:break;
					}
				}
				$$=(Reminder*)malloc(sizeof(Reminder));$$->type=debugType;$$->gen.exludeRegs=NULL;
			}*/
			;

partList:part{$$=(PartList*)malloc(sizeof(PartList));$$->part=$1;$$->next=NULL;}
			|partList','part
			{
				PartList*bb,*aa;bb=(PartList*)malloc(sizeof(PartList));bb->part=$3;bb->next=NULL;
				aa=$1;while(aa->next!=NULL)aa=aa->next;aa->next=bb;$$=$1;
			};
part:DIGIT DIGIT{$$=(Part*)malloc(sizeof(Part));$$->partNo=$1;$$->lines=$2;};

xyStartList:xyStart{$$=(XyStartList*)malloc(sizeof(XyStartList));$$->xy=$1;$$->next=NULL;}
			|xyStartList','xyStart
			{
				XyStartList*bb,*aa;bb=(XyStartList*)malloc(sizeof(XyStartList));bb->xy=$3;bb->next=NULL;
				aa=$1;while(aa->next!=NULL)aa=aa->next;aa->next=bb;$$=$1;
			};
xyStart:DIGIT NAME
			{
				$$=(XyStart*)malloc(sizeof(XyStart));$$->partNo=$1;
				$$->xy=(char*)malloc(strlen($2)+1);strcpy($$->xy,$2);
//				MessageBox(NULL,$$->xy,$2,MB_OK);
		 };
delList:delPart{$$=(DelList*)malloc(sizeof(DelList));$$->del=$1;$$->next=NULL;}
		| delList delPart
		{
			DelList*bb,*aa;bb=(DelList*)malloc(sizeof(DelList));bb->del=$2;bb->next=NULL;aa=$1;
			while(aa->next!=NULL)aa=aa->next;aa->next=bb;$$=$1;
		};
delPart:DIGIT digList
		{$$=(DelPart*)malloc(sizeof(DelPart));$$->regNo=$1;$$->lines=$2;};
digList:DIGIT{$$=(DigList*)malloc(sizeof(DigList));$$->next=NULL;$$->dig=$1;}
		| digList','DIGIT
		{
			DigList*bb,*aa;bb=(DigList*)malloc(sizeof(DigList));bb->next=NULL;bb->dig=$3;
			aa=$1;while(aa->next!=NULL)aa=aa->next;aa->next=bb;$$=$1;
		};
regions:region
			{
				$$=(Regions*)malloc(sizeof(Regions));$$->region=$1;$$->next=NULL;
			}
			| regions region
			{
				Regions*bb,*aa;
				bb=(Regions*)malloc(sizeof(Regions));
				bb->region=$2;bb->next=NULL;aa=$1;
				while(aa->next!=NULL)aa=aa->next;aa->next=bb;$$=$1;
			};
region:'!'DIGIT DIGIT DIGIT DIGIT DIGIT DIGIT';'firstSectionList
		{
			$$=(Region*)malloc(sizeof(Region));
			$$->sectNo=$4;$$->year=$5;$$->month=$6;$$->regionNo=$7;
			$$->gen.first=$9;$$->type=firstType;
		}
		| '!'DIGIT DIGIT DIGIT DIGIT DIGIT DIGIT';'secondSectionList
		{
			$$=(Region*)malloc(sizeof(Region));
			$$->sectNo=$4;$$->year=$5;$$->month=$6;$$->regionNo=$7;
			$$->gen.second=$9;$$->type=secondType;
		}
		| '!'DIGIT DIGIT DIGIT DIGIT DIGIT DIGIT';'thirdSectionList
		{
			$$=(Region*)malloc(sizeof(Region));
			$$->sectNo=$4;$$->year=$5;$$->month=$6;$$->regionNo=$7;
			$$->gen.third=$9;$$->type=thirdType;
		};
firstSectionList:firstSection
		{
			$$=(FirstSectionList*)malloc(sizeof(FirstSectionList));
			$$->first=$1;$$->next=NULL;
		}
		| firstSectionList firstSection
		{
			FirstSectionList*bb,*aa;
			bb=(FirstSectionList*)malloc(sizeof(FirstSectionList));
			bb->first=$2;bb->next=NULL;aa=$1;
			while(aa->next!=NULL){aa=aa->next;}aa->next=bb;$$=$1;
		};
firstSection:DIGIT DIGIT DIGIT';'
		{
			$$=(FirstSection*)malloc(sizeof(FirstSection));$$->f1=$1;$$->f2=$2;$$->f3=$3;
		};
secondSectionList: secondSection
		{
			$$=(SecondSectionList*)malloc(sizeof(SecondSectionList));
			$$->second=$1;$$->next=NULL;
		}
		| secondSectionList secondSection
		{
			SecondSectionList*bb,*aa;
			bb=(SecondSectionList*)malloc(sizeof(SecondSectionList));
			bb->second=$2;bb->next=NULL;aa=$1;
			while(aa->next!=NULL){aa=aa->next;}aa->next=bb;$$=$1;
		};
secondSection:DIGIT DIGIT DIGIT DIGIT DIGIT DIGIT DIGIT';'
		{
			$$=(SecondSection*)malloc(sizeof(SecondSection));
			$$->s1=$1;$$->s2=$2;$$->s3=$3;$$->s4=$4;$$->s5=$5;$$->s6=$6;$$->s7=$7;
		};
thirdSectionList:thirdSection
		{
			$$=(ThirdSectionList*)malloc(sizeof(ThirdSectionList));$$->third=$1;$$->next=NULL;
		}
		| thirdSectionList thirdSection
		{
			ThirdSectionList*bb,*aa;
			bb=(ThirdSectionList*)malloc(sizeof(ThirdSectionList));
			bb->third=$2;bb->next=NULL;aa=$1;
			while(aa->next!=NULL){aa=aa->next;}aa->next=bb;$$=$1;
		};
thirdSection: DIGIT DIGIT DIGIT DIGIT';'
	{
		$$=(ThirdSection*)malloc(sizeof(ThirdSection));$$->t1=$1;$$->t2=$2;$$->t3=$3;$$->t4=$4;
	};
%%
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
