/*
    Program : DVD_ShoP_Management
    File : cusInfoAccess.h  ver 1.0
    Description : Definition of functions for storing and referencing custom information
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#ifndef __CUSINFOACCESS_H__
#define __CUSINFOACCESS_H__

int AddCusInfo (char* ID, char* name, char* num);
cusInfo* GetCusPtrByID(char* ID);
int IsRegistID(char* ID);
void StoreCusDataToFile(void);
void LoadCusDataFromFile(FILE* fp);
void ShowAllCusData(void);

#endif // __CUSINFOACCESS_H__
