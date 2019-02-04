#include "ArmParse.h"
typedef ARMPARSE_API struct DelList DelList;
typedef ARMPARSE_API struct DelPart DelPart;
typedef ARMPARSE_API struct Goal Goal;
typedef ARMPARSE_API struct Region Region;
typedef ARMPARSE_API struct Regions Regions;
typedef ARMPARSE_API struct Reminder Reminder;
typedef ARMPARSE_API struct Reminders Reminders;
typedef ARMPARSE_API struct FirstSection FirstSection;
typedef ARMPARSE_API struct FirstSectionList FirstSectionList;
typedef ARMPARSE_API struct Part Part;
typedef ARMPARSE_API struct PartList PartList;
typedef ARMPARSE_API struct DigList DigList;
typedef ARMPARSE_API struct SecondSection SecondSection;
typedef ARMPARSE_API struct SecondSectionList SecondSectionList;
typedef ARMPARSE_API struct ThirdSection ThirdSection;
typedef ARMPARSE_API struct ThirdSectionList ThirdSectionList;
//typedef struct ExludeRegs ExludeRegs;
enum RegionType{firstType=1,secondType=2,thirdType=3};
enum ReminderType{fileType=1,partType=2,delType=3,debugType=4,excludeType=5};
struct Goal{Reminders*rems;Regions*regs;};
struct Reminders{Reminder*reminder;Reminders*next;};
struct Reminder
{
	union
	{
		int files;
		int debug;
		PartList*parts;
		DelList*delList;
		DigList*exludeRegs;
	}gen;
	enum ReminderType type;
};
struct PartList{Part*part;PartList*next;};
struct Part{int partNo;int lines;};
struct DelList{DelPart*del;DelList*next;};
struct DelPart{int regNo;DigList*lines;};
struct DigList{int dig;DigList*next;};
struct Region
{
	int sectNo;int year;int month;int regionNo;
	union{FirstSectionList*first;SecondSectionList*second;ThirdSectionList*third;}gen;
	enum RegionType type;
};
struct Regions{Region*region;Regions*next;};
struct FirstSectionList{FirstSection*first;FirstSectionList*next;};
struct FirstSection{int f1;int f2;int f3;};
struct SecondSectionList{SecondSection*second;SecondSectionList*next;};
struct SecondSection{int s1;int s2;int s3;int s4;int s5;int s6;int s7;};
struct ThirdSectionList{ThirdSection*third;ThirdSectionList*next;};
struct ThirdSection{int t1;int t2;int t3;int t4;};

extern ARMPARSE_API void printRegions(Goal*g);				
extern ARMPARSE_API void printReminders(Reminders*rems);
extern ARMPARSE_API void printPartList(PartList*parts);	
extern ARMPARSE_API void printDelList(DelList*delList);
extern ARMPARSE_API void printExcludeList(DigList*ex);
extern ARMPARSE_API int isInList(int f1,DigList*lines);
extern ARMPARSE_API int createDir(char*d);
extern ARMPARSE_API void printDebug(FILE*f,int a,int b);
extern ARMPARSE_API void printZero(FILE*f,int num);
extern ARMPARSE_API void printfEmpty(int line,int partNo);
extern ARMPARSE_API void printfLineMore(int partNo,int j,int order);
extern ARMPARSE_API void printfPartEnd(FILE*f);
extern ARMPARSE_API void printfNullPart(int d);
//extern ARMPARSE_API int main2(int argc,char**argv);
//extern ARMPARSE_API int main2(char*argc,char*argv);
//extern ARMPARSE_API int main2(char*n);

extern int line_num;
