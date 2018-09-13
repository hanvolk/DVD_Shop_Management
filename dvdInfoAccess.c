
#include "common.h"
#include "screenOut.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"

#define MAX_DVD 100

static dvdInfo* dvdList[MAX_DVD];
static int numofdvd=0;


int AddDVDInfo (char* isbn, char* title, int gen)
{
    if(numofdvd>=MAX_DVD)
        return 0;

    dvdInfo* buf=(dvdInfo*)malloc(sizeof(dvdInfo));
    strncpy(buf->ISBN,isbn,ISBN_LEN);
    strncpy(buf->title,title,TITLE_LEN);
    buf->genre=gen;
    buf->rentState=RETURNED;


    dvdList[numofdvd++]=buf;

    return numofdvd;
}


dvdInfo* GetDVDPtrByID(char* isbn)
{
    int idx=0;
    for(idx=0;idx<numofdvd;idx++)
    {
        if(!strncmp(dvdList[idx]->ISBN,isbn,ISBN_LEN))
        {
            return dvdList[idx];
        }
    }
    return NULL;

}

/*
    Function : int IsRegist ID(char* ID)
    Description : Recives ID as parameter and check whether it is registered ID
    return : Registered : 1   Unregist : 0
*/
int IsRegistISBN(char* isbn)
{

    dvdInfo* pdvd=GetDVDPtrByID(isbn);

    if(pdvd==NULL)
        return 0;
    else
        return 1;
}

int IsRentISBN(char* isbn)
{
    dvdInfo* pdvd=GetDVDPtrByID(isbn);
    return pdvd->rentState;
}

void SetRentDvd(char* isbn,char* id, unsigned int date)
{
    dvdInfo* pdvd=GetDVDPtrByID(isbn);
    pdvd->rentState=RENTED;
}

void SetReturnDvd(char* isbn)
{
    dvdInfo* pdvd=GetDVDPtrByID(isbn);
    pdvd->rentState=RETURNED;
}

void StoreDvdDataToFile(void)
{
    FILE* fp=fopen("DVD_Data.dat","wb");
    int idx;

    for(idx=0;idx<numofdvd;idx++)
    {
        fwrite((void*)dvdList[idx],sizeof(dvdInfo),1,fp);
    }
}

void LoadDvdDataFromFile(FILE* fp)
{
    int cnt=0;
    dvdInfo* buf;
    numofdvd=0;

    while(1)
    {
        buf=(dvdInfo*)malloc(sizeof(dvdInfo));
        cnt=fread((void*)buf,sizeof(dvdInfo),1,fp);

        if(cnt<1)
        {
            break;
        }
        else
        {
           dvdList[numofdvd]=buf;
           numofdvd++;
        }
    }
    fclose(fp);
}


void ShowAllDVDData(void)
{
    int idx;
    printf(" \n   ISBN          제  목      장르     대여상태   \n");
    printf("-----------------------------------------\n");
    for(idx=0;idx<numofdvd;idx++)
    {
        printf("%-15s %-15s %d  %d \n",dvdList[idx]->ISBN,dvdList[idx]->title,dvdList[idx]->genre,dvdList[idx]->rentState);
    }

    system("pause");
}

