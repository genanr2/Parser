//#pragma message ("\tMake sure you go to Tools.Options.Directories and add the paths to mso97.dll and " \
//	"vbeext1.olb.\n\n\tMso97.dll will usually be in c:\\\"Program Files\"\\\"Microsoft Office\"\\Office, " \
//	"\n\tand vbeext1.olb will be in c:\\\"Program Files\"\\\"Common Files\"\\\"Microsoft Shared\"\\VBA")
//#import <mso97.dll> no_namespace rename("DocumentProperties", "DocumentPropertiesXL")   
//#import <excel8.olb> rename("DialogBox", "DialogBoxXL") rename("RGB", "RBGXL") rename("DocumentProperties", "DocumentPropertiesXL") no_dual_interfaces

//#import<mso9.dll>no_namespace rename("DocumentProperties","DocumentPropertiesXL")
//#import<vbeext1.olb>no_namespace   
//#import<excel9.olb>rename("DialogBox","DialogBoxXL")rename("RGB","RBGXL")rename("DocumentProperties","DocumentPropertiesXL")no_dual_interfaces
//#import<excel9.olb>//no_dual_interfaces
//#pragma warning (disable:4192)
/*
#define OLEVER
#pragma warning (disable:4192)
#include <direct.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<tchar.h>
#include "calc.h"

#ifdef OLEVER
#import<mso9.dll>no_namespace rename("DocumentProperties","DocumentPropertiesXL")
#import<vbeext1.olb>no_namespace   
#import<excel9.olb>rename("DialogBox","DialogBoxXL")rename("RGB","RBGXL")rename("DocumentProperties","DocumentPropertiesXL")no_dual_interfaces
//#pragma warning (disable:4192)
// NOTE: This example will only work with Excel8 in Office97
// Compile with cl /GX comexcel.cpp. TO DO: Edit the #import paths

#pragma hdrstop()
class OleInit {
public:
    OleInit() { OleInitialize(NULL); }
    ~OleInit() { OleUninitialize(); }
} OleInitGlobal;
extern void CharPrintf(char*s);
void dump_com_error(_com_error &e)
{
	char str[64];
	strcpy(str,"О-го-го - ошибка!\n");
	CharToOem(str,str);_tprintf(_T(str));
	sprintf(str,"\a\tКод = %08lx\n",e.Error());
	CharToOem(str,str);_tprintf(_T(str));

	sprintf(str,"\a\tОписание кода = %s\n",e.ErrorMessage());
	CharToOem(str,str);_tprintf(_T(str));

	_bstr_t bstrSource(e.Source());
  _bstr_t bstrDescription(e.Description());

	sprintf(str,"\a\tИсточник = %s\n",(LPCTSTR)bstrSource);
	CharToOem(str,str);_tprintf(_T(str));

	sprintf(str,"\a\tОписание = %s\n",(LPCTSTR)bstrDescription);
	CharToOem(str,str);_tprintf(_T(str));
}
#endif
*/
// If this is placed in the scope of the smart pointers, they must be
// explicitly Release(d) before CoUninitialize() is called.  If any reference
// count is non-zero, a protection fault will occur.
//struct StartOle{StartOle(){CoInitialize(NULL);}~StartOle(){CoUninitialize();}}_inst_StartOle;
extern "C"int main3(int argc,char**argv);
extern "C" Goal*goal;
extern "C"int createDir(char*d);
extern "C"int isTrue(int no,Reminders*rems);
extern "C"int findLineNumber(int partNo,Reminders*rem);
extern "C"int isDelLine(int partNo,int f1,Reminders*rem);
extern "C"SecondSectionList*findSecondList(Regions*part,Region*cc);
extern "C"ThirdSectionList*findThirdList(Regions*part,Region*cc);
extern "C"char*findXyStart(int partNo,Reminders*rem);
extern void writeXls();

/*
using namespace Excel;
//_ApplicationPtr pXL;
*/
char*getMonth(int i)
{
	switch(i)
	{
		case 1:return "январь";case 2:return "февраль";case 3:return "март";
		case 4:return "май";case 5:return "май";case 6:return "июнь";case 7:return "июль";
		case 8:return "август";case 9:return "сентябрь";case 10:return "октябрь";
		case 11:return "ноябрь";case 12:return "декабрь";default:return "неизвестно";
	}
}
//void printSheet(_Worksheet*pSheet,int dig,int x,int y)
void printSheet(_Worksheet*pSheet,char*start,int dig,int x,int y,_ApplicationPtr pXL)
{
	char dd[10];
	char xx[5];char yy[5];
	itoa(x,xx,10);
	itoa(y,yy,10);
	itoa(dig,dd,10);
	pXL->ActiveCell->Offset[yy][xx]->Value=dd;
}
void printSheetZero(_Worksheet*pSheet,char*start,int countX,int x,int y,_ApplicationPtr pXL)
{
	char xx[5];char yy[5];
	itoa(y,yy,10);
	itoa(x,xx,10);
	int i=0;
	pXL->ActiveCell->Offset[yy][xx]->Value="0";
	for(i=1;i<countX;i++)
	{
		itoa(x+i,xx,10);pXL->ActiveCell->Offset[yy][xx]->Value="0";
	}
}
void FirstSectionSheet(_Worksheet*pSheet,FirstSectionList*first,Reminders*r,_ApplicationPtr pXL)
{
	FirstSectionList*aa=first;
	Reminders*rem=r;
	int i=1,j=1;
	int x=0,y=0;
	char*start="";
	start=findXyStart(1,rem);
	if(strcmp(start,"")==0){start=(char*)malloc(5);strcpy(start,"c13");}
	rem=r;
	FirstSection*bb;
	int lineNum=findLineNumber(1,r);
	pXL->ScreenUpdating=VARIANT_FALSE;
	pSheet->Range[start]->Select();
	while(aa!=NULL)
	{
		bb=aa->first;
		if(bb!=NULL)
		{
			while(bb->f1>i)
			{
				if(!isDelLine(1,i,rem))
				{
					if(lineNum>=j)
					{
						printSheetZero(pSheet,start,2,x,y,pXL);y++;
					}j++;
				}i++;
			}
			if(!isDelLine(1,bb->f1,rem))
			{
				if(lineNum>=j)
				{
					printSheet(pSheet,start,bb->f2,x,y,pXL);x++;
				printSheet(pSheet,start,bb->f3,x,y,pXL);x--;y++;}j++;
			}
		}
		if(aa->next==NULL)
		{
			if(lineNum<(j-1));else 
			while(lineNum>(j-1))
			{
				i++;
				printSheetZero(pSheet,start,2,x,y,pXL);y++;j++;
			}
		}aa=aa->next;i++;
	}
	pXL->ScreenUpdating=VARIANT_TRUE;
//	pSheet->Cells->["1"]["1"];//->Select();
}
void SecondSectionSheet(_Worksheet*pSheet,SecondSectionList*second,Reminders*r,_ApplicationPtr pXL)
{
	SecondSectionList*aa=second;
	SecondSection*bb;
	Reminders*rem=r;
	int i=1,j=1;
	int x=0,y=0;
//	char xx[5];char yy[5];
	int l=0,m=0;
	char ll[10]="";
	char mm[10]="";
	char*start="";
//	char*arr[50][6];
	start=findXyStart(2,rem);
	if(strcmp(start,"")==0){start=(char*)malloc(5);strcpy(start,"e27");}
	rem=r;
	int lineNum=findLineNumber(2,r);
	pXL->ScreenUpdating=VARIANT_FALSE;
	pSheet->Range[start]->Select();
	while(aa!=NULL)
	{
		bb=aa->second;
		if(bb!=NULL)
		{
			while(bb->s1>i)
			{
				if(!isDelLine(2,i,rem))
				{
					if(lineNum>=j)
					{
						printSheetZero(pSheet,start,6,x,y,pXL);y++;}j++;
			}i++;
		}
		if(!isDelLine(2,bb->s1,rem))
		{
			if(lineNum>=j)
			{
//				l=x;m=y;
				printSheet(pSheet,start,bb->s2,x,y,pXL);x++;printSheet(pSheet,start,bb->s3,x,y,pXL);x++;
				printSheet(pSheet,start,bb->s4,x,y,pXL);x++;printSheet(pSheet,start,bb->s5,x,y,pXL);x++;
				printSheet(pSheet,start,bb->s6,x,y,pXL);x++;printSheet(pSheet,start,bb->s7,x,y,pXL);x-=5;y++;
			}j++;
		}
	}
	if(aa->next==NULL)
		{
			if(lineNum<(j-1));else while(lineNum>(j-1)){i++;printSheetZero(pSheet,start,6,x,y,pXL);y++;j++;}
		}aa=aa->next;i++;
	}
	pXL->ScreenUpdating=VARIANT_TRUE;
}
void ThirdSectionSheet(_Worksheet*pSheet,ThirdSectionList*third,Reminders*r,_ApplicationPtr pXL)
{
	ThirdSectionList*aa=third;ThirdSection*bb;Reminders*rem=r;
	int i=1,j=1;
	int x=0,y=0;
	char*start="";//[10];
	start=findXyStart(3,rem);
	if(strcmp(start,"")==0){start=(char*)malloc(5);strcpy(start,"e76");}
	rem=r;
	int lineNum=findLineNumber(3,r);
	pXL->ScreenUpdating=VARIANT_FALSE;
	pSheet->Range[start]->Select();
	while(aa!=NULL)
	{
		bb=aa->third;
		if(bb!=NULL)
		{
			while(bb->t1>i)
				{if(!isDelLine(3,i,rem)){if(lineNum>=j){printSheetZero(pSheet,start,3,x,y,pXL);y++;}j++;}i++;}
			if(!isDelLine(3,bb->t1,rem))
			{
				if(lineNum>=j)
				{
					printSheet(pSheet,start,bb->t2,x,y,pXL);x++;printSheet(pSheet,start,bb->t3,x,y,pXL);x++;
					printSheet(pSheet,start,bb->t4,x,y,pXL);x-=2;y++;
				}j++;
			}
		}
		if(aa->next==NULL)
		{
			if(lineNum<(j-1));else while(lineNum>(j-1)){i++;printSheetZero(pSheet,start,3,x,y,pXL);y++;j++;}
		}aa=aa->next;i++;
	}
	pXL->ScreenUpdating=VARIANT_TRUE;
}

int main(int argc,char**argv)
{
	int curdrive,j=1;
	char buffer[_MAX_PATH];
	char str[_MAX_PATH];
	char dir[128];
	time_t ltimeStart,ltimeEnd;
	time(&ltimeStart);
	main3(argc,argv);

	if(goal==NULL)return 0;
	Reminders*rem=goal->rems;
	Reminders*rem1=goal->rems;
	Regions*aa=goal->regs;
	Region*bb;
//	SecondSectionList*second;
//	ThirdSectionList*third;
	int files=0,i=1,trueReg=0,excluded=0,excelVer=8,debug=0,visual=0;
	char year[20];
	char aaa[10];
	char fileName[32];

	curdrive=_getdrive();
  if(_getcwd(buffer,_MAX_PATH)== NULL)perror("_getcwd error");
//	using namespace Excel;
/*
  _ApplicationPtr pXL;
  try
	{
		while(rem1!=NULL)
		{
			if(rem1->reminder->type==fileType)files=rem1->reminder->gen.files;
			if(rem1->reminder->type==debugType)debug=rem1->reminder->gen.debug;
			if(rem1->reminder->type==excelType)excelVer=rem1->reminder->gen.excelVer;
			if(rem1->reminder->type==visualType)visual=rem1->reminder->gen.visual;
			
			rem1=rem1->next;
		}
		
//    _ApplicationPtr pXL("Excel.Application");
        
//		pXL.CreateInstance(L"Excel.Application");
		if(excelVer==9)pXL.CreateInstance(L"Excel.Application.9");
		else if(excelVer==8)pXL.CreateInstance(L"Excel.Application.8");
		else if(excelVer==7)pXL.CreateInstance(L"Excel.Application.7");
		else pXL.CreateInstance(L"Excel.Application.8");
		if(!visual)pXL->Visible=VARIANT_FALSE;else pXL->Visible=VARIANT_TRUE;
//		pXL->Visible=VARIANT_TRUE;
		pXL->DisplayAlerts=VARIANT_FALSE;
		pXL->Caption = "Программа преобразования файлов АрмСтат.";

	  WorkbooksPtr pBooks=pXL->Workbooks;
		strcpy(str,buffer);
		strcat(str,"\\gks");
		createDir(str);
		strcpy(str,buffer);
		strcat(str,"\\all.xls");
		_WorkbookPtr pBook;
		try
		{
			pBook=pBooks->Open(str);
		}catch(_com_error&e){dump_com_error(e);}
		_WorksheetPtr pSheet=pXL->ActiveSheet;
		SecondSectionList*second;
		ThirdSectionList*third;
		while(aa!=NULL)
		{
			bb=aa->region;
			if(bb!=NULL&&bb->type==firstType)
			{
				if(trueReg=isTrue(bb->regionNo,goal->rems))
				{
					fprintf(stderr,"================\tC %d %d %d\t================ (%d file)\n",bb->regionNo,bb->year,bb->month,j);
					pSheet->Select();
//					_WorkbookPtr pBook2=pBooks->Add((long)xlWorksheet);
//					_WorksheetPtr pSheet2=pBook2->ActiveSheet;
					pSheet->Copy();//(_Worksheet*)pSheet2);
					_WorkbookPtr pBook2=pXL->ActiveWorkbook;
					_WorksheetPtr pSheet2=pBook2->ActiveSheet;
					pSheet2->Select();
					pSheet2->Range["B3"]->Value=getMonth(bb->month);
					pSheet2->Range["B5"]->Value="13446";
					pSheet2->Range["B6"]->Value=itoa(bb->regionNo,aaa,10);
					if(bb->gen.first!=NULL)FirstSectionSheet((_Worksheet*)pSheet2,bb->gen.first,rem,pXL);
					if((second=findSecondList(goal->regs,bb))!=NULL){SecondSectionSheet((_Worksheet*)pSheet2,second,rem,pXL);}
					if((third=findThirdList(goal->regs,bb))!=NULL){ThirdSectionSheet((_Worksheet*)pSheet2,third,rem,pXL);}
/*
    ActiveWorkbook.SaveAs Filename:= _
        "D:\GENE\DLL\B54M\B50\ArmStat\Release\gks\Книга9.xls", FileFormat:=xlNormal, _
        Password:="", WriteResPassword:="", ReadOnlyRecommended:=False, _
        CreateBackup:=False
    ActiveWindow.Close
*/
			/*
			_WorkbookPtr pBook=pBooks->Open("D:\\GENE\\DLL\\B54M\\B50\\ArmStat\\Release\\all.xls");
			_WorkbookPtr pBook=pBooks->Add((long)xlWorksheet);
			_WorksheetPtr pSheet=pXL->ActiveSheet;
			// This one will fail
			try{pSheet->Name="Market Share?";}catch(_com_error&e){dump_com_error(e);}
			pSheet->Name="Market Share!";
			pSheet->Range["A2"]->Value="Company A";pSheet->Range["B2"]->Value="Company B";
			pSheet->Range["C2"]->Value="Company C";pSheet->Range["D2"]->Value="Company D";
			pSheet->Range["A3"]->Value=75.0;pSheet->Range["B3"]->Value=14.0;
			pSheet->Range["C3"]->Value=7.0; pSheet->Range["D3"]->Value=4.0;
//		Sleep(12000);
			pXL->Visible=VARIANT_TRUE;
			RangePtr pRange=pSheet->Range["A2:D3"];
			_ChartPtr pChart=pBook->Charts->Add();
			pChart->ChartWizard((Range*)pRange,(long)xl3DPie,7L,(long)xlRows,1L,0L,2L,"Market Share");
*/
//		Sleep(12000);
//		pBook->Saved=VARIANT_TRUE;vtMissing
//		str=buffer;
/*
					char regN[20];
					strcpy(fileName,"C");
					if(bb->regionNo<=9)sprintf(regN,"000%d",bb->regionNo);
					else if(bb->regionNo<=99)sprintf(regN,"00%d",bb->regionNo);
					else if(bb->regionNo<=999)sprintf(regN,"0%d",bb->regionNo);
					else sprintf(regN,"%d",bb->regionNo);
					strcat(fileName,regN);
					sprintf(year,"%d",bb->year);sprintf(regN,"%c",year[strlen(year)-1]);
					strcat(fileName,regN);
					if(bb->month<=9)sprintf(regN,"0%d",bb->month);
						else sprintf(regN,"%d",bb->month);
					strcat(fileName,regN);

					strcpy(str,buffer);
					sprintf(dir,"\\gks\\%s.xls",fileName);
					strcat(str,dir);
//					_tprintf(_T(str));_tprintf(_T("\n"));
					pBook2->SaveAs(str,vtMissing,vtMissing,vtMissing,vtMissing,vtMissing,xlNoChange,vtMissing);
					pBook2->Close();
				}
			}
			aa=aa->next;j++;
		}
		try
		{
			pBook->Saved=VARIANT_TRUE;
			pBook->Close();
		}catch(_com_error&e){dump_com_error(e);}
//		try
//		{
//			HRESULT res=pXL->Quit();
//		}
//		catch(_com_error&e){dump_com_error(e);}
//		pXL->Application->Quit();
//		pXL->AltStartupPath(
//		pXL->Visible=true;
//		Sleep(10000);
//		HRESULT res=pXL->Quit();
	}catch(_com_error&e){dump_com_error(e);}
//	time_t ltimeStart,ltimeEnd;
	time(&ltimeEnd);
	ltimeStart=ltimeEnd-ltimeStart;
	char str1[64];
	int min=ltimeStart/60;
	int sec=ltimeStart%60;
	if(min==0)
	{
		sprintf(str1,"\a\tВремя работы = %d сек.\n",ltimeStart);
		CharToOem(str1,str1);_tprintf(_T(str1));
	}
	else
	{
		sprintf(str1,"\a\tВремя работы = %d мин. %d сек.\n",min,sec);
		CharToOem(str1,str1);_tprintf(_T(str1));
	}
*/
	writeXls();
//	pXL->Visible=VARIANT_TRUE;
//	pXL->Release();
//	HRESULT res=pXL->Quit();
//	Sleep(10000);
//	Sleep(6000);
	return 0;
}
