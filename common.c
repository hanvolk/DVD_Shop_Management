/*
    Program : DVD_ShoP_Management
    File : common.h  ver 1.0
    Description : Common ANSI standard header files & Common function
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#include "common.h"

void ClearBuf()
{
    while(getchar()!='\n');
}

void DelEnter(char* str)
{
    str[strlen(str)-1]='\0';
}
