#ifndef __RENTINFO__
#define __RENTINFO__

#include "cusInfo.h"
#include "dvdInfo.h"

 typedef struct __dvdRentInfo
 {
     char cusID[ID_LEN];
     char ISBN[ISBN_LEN];
     unsigned int rentDay;
 }dvdRentInfo;

void AddRentList(char* ISBN, char* cusID, unsigned int rentDay);
 void PrintOutRentAllCusInfo(char* ISBN);
 void PrintOutCusAllRentInfo(char* ID, unsigned int start, unsigned int end);
 void ShowAllDVDRental(void);
 void StoreRentInfoToFile(void);
 void LoadRentInfoFromFile(void);
#endif // __RENTINFO__
