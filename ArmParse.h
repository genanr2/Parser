
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ARMPARSE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ARMPARSE_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef ARMPARSE_EXPORTS
#define ARMPARSE_API __declspec(dllexport)
#else
#define ARMPARSE_API __declspec(dllimport)
#endif
/*
// This class is exported from the ArmParse.dll
class ARMPARSE_API CArmParse {
public:
	CArmParse(void);
	// TODO: add your methods here.
};

extern ARMPARSE_API int nArmParse;

ARMPARSE_API int fnArmParse(void);

*/