/*
    Program : DVD_Shop_Management
    File : rentlInfoAccess.c
    Description : Definition of functions for storing and referencing DVD rental informaition
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN 100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus=0;

/*
    Function : void AddRentList(char* ISBN, char* cusID, int rentDay)
    Description : Store rental information
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/
void AddRentList(char* ISBN, char* cusID, unsigned int rentDay)
{
    strncpy(rentList[numOfRentCus].cusID,cusID,ID_LEN);
    strncpy(rentList[numOfRentCus].ISBN,ISBN,ISBN_LEN);
    rentList[numOfRentCus].rentDay=rentDay;
    numOfRentCus++;
}

void StoreRentInfoToFile(void)
{
    FILE* fp=fopen("rentinfo.dat","wb");
    int idx;
    dvdRentInfo* rentbuf;

    for(idx=0;idx<numOfRentCus;idx++)
    {
        rentbuf=&rentList[idx];
        fwrite((void*)rentbuf,sizeof(dvdRentInfo),1,fp);
    }

    fclose(fp);
}

void LoadRentInfoFromFile(void)
{
    int cnt=0;
    FILE* fp=fopen("rentinfo.dat","rb");
    dvdRentInfo* buf;
    numOfRentCus=0;

    while(1)
    {
        buf=(dvdRentInfo*)malloc(sizeof(dvdRentInfo));
        cnt=fread((void*)buf,sizeof(dvdRentInfo),1,fp);

        if(cnt<1)
        {
            break;
        }
        else
        {
           rentList[numOfRentCus]=*buf;
           numOfRentCus++;
        }
    }
    fclose(fp);
}

/*
    Function : PrintOutRentAllCusInfo(char* ISBN)
    Description : Show Rental information by ISBN
    return : void
*/
void PrintOutRentAllCusInfo(char* ISBN)
{
    int idx;

    for(idx=0;idx<numOfRentCus;idx++)
    {
        if(!strncmp(rentList[idx].ISBN,ISBN,ISBN_LEN))
        {
            printf("\n대여일 : %u \n",rentList[idx].rentDay);
            ShowCustomerInfo(GetCusPtrByID(rentList[idx].cusID));
        }
    }
    system("pause");
}


/*
    Function : PrintOutRentAllCusInfo(char* ISBN)
    Description : Show Rental information by ISBN
    return : void
*/
void PrintOutCusAllRentInfo(char* ID, unsigned int start, unsigned int end)
{
    int idx;

    for(idx=0;idx<numOfRentCus;idx++)
    {
        if(!strncmp(rentList[idx].cusID,ID,ID_LEN) && (rentList[idx].rentDay >= start && rentList[idx].rentDay<=end) )
        {
            printf("┎──────────────────────\n");
            printf("│ ▶ ISBN : %s \n",rentList[idx].ISBN);
            printf("│ ▶ 대여일 : %u \n",rentList[idx].rentDay);
            printf("└───────────────────────\n");
        }
    }
    system("pause");
}

void ShowAllDVDRental(void)
{
    int idx;
    printf("%d\n\n",numOfRentCus);
    printf("\n    ISBN               ID         대여일   \n");
    printf("===========================================\n");
    for(idx=0;idx<numOfRentCus;idx++)
    {
        printf("%-20s %-10s %u \n",rentList[idx].ISBN,rentList[idx].cusID,rentList[idx].rentDay);
    }
    system("pause");

}
