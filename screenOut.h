/*
    Program : DVD_ShoP_Management
    File : screenOut.h  ver 1.0
    Description : Declaration of functions for output to the Console
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__
#include "cusInfo.h"
#include "dvdInfo.h"
 void ShowMenu(void);
 void ShowCustomerInfo(cusInfo* pCus);
 void ShowDVDInfo(dvdInfo* pDvd);
 void ShowRentInfo(char* isbn);
#endif // __SCREENOUT_H__
