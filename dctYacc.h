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


extern YYSTYPE yylval;
