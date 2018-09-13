/*
    Program : Phone_Number_ Management
    File : dvdInfo.h  ver 1.0
    Description : Structure for DVD management
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

 #define ISBN_LEN 30
 #define TITLE_LEN 30


 enum{ACTION=1,COMIC,SF,ROMANTIC};
 enum{RENTED, RETURNED};



 typedef struct __dvdInfo
 {
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;  // 장르
    int rentState;
 }dvdInfo;

#endif // __DVDINFO_H__
