/*
    Program : Phone_Number_ Management
    File : cusInfo.h  ver 1.0
    Description : Structure for customer management
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#ifndef __CUSINFO_H__
#define __CUSINFO_H__

#define ID_LEN 20
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __cusInfo
{
    char ID[ID_LEN];
    char name[NAME_LEN];
    char phoneNum[PHONE_LEN];
}cusInfo;

#endif // __CUSINFO_H__
