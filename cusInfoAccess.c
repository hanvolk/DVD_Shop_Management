/*
    Program : Phone_Number_ Management
    File : cuslInfoAccess.c
    Description : Definition of functions for storing and referencing custom information
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo* cusList[MAX_CUSTOMER];
static int numofcustomer=0;

/*
    Function : int AddCusInfo (char* ID, char* name, char* num)
    Description : cusInfo 의 할당 및 저장
    return : 성공시 '등록된 정보의 갯수', 실패 시 0을 반환
*/
int AddCusInfo (char* ID, char* name, char* num)
{
    if(numofcustomer>=MAX_CUSTOMER)
        return 0;

    cusInfo* buf=(cusInfo*)malloc(sizeof(cusInfo));
    strncpy(buf->ID,ID,ID_LEN);
    strncpy(buf->name,name,NAME_LEN);
    strncpy(buf->phoneNum,num,PHONE_LEN);

    cusList[numofcustomer++]=buf;

    return numofcustomer;
}

/*
    Function : cusInfo* GetCusPtrByID(char* ID)
    Description : Recives ID as parameter and returns a pointer to the corresponding structure
    return : Return NULL pointer if ID is unregistered
*/
cusInfo* GetCusPtrByID(char* ID)
{
    int idx=0;
    for(idx=0;idx<numofcustomer;idx++)
    {
        if(!strncmp(cusList[idx]->ID,ID,ID_LEN))
        {
           return cusList[idx];
        }
    }
    return NULL;

}

/*
    Function : int IsRegist ID(char* ID)
    Description : Recives ID as parameter and check whether it is registered ID
    return : Registered : 1   Unregist : 0
*/
int IsRegistID(char* ID)
{
    cusInfo* pcus=GetCusPtrByID(ID);

    if(pcus==NULL)
        return 0;
    else
        return 1;
}


void StoreCusDataToFile(void)
{
    FILE* fp=fopen("CusData.dat","wb");
    int idx;

    for(idx=0;idx<numofcustomer;idx++)
    {
        fwrite((void*)cusList[idx],sizeof(cusInfo),1,fp);
    }
}

void LoadCusDataFromFile(FILE* fp)
{
    int cnt=0;
    cusInfo* buf;

    while(1)
    {
        buf=(cusInfo*)malloc(sizeof(cusInfo));
        cnt=fread((void*)buf,sizeof(cusInfo),1,fp);

        if(cnt<1)
        {
            break;
        }
        else
        {
           cusList[numofcustomer]=buf;
           numofcustomer++;
        }
    }
    fclose(fp);
}




void ShowAllCusData(void)
{
    int idx;
    printf(" \n ID           성   명          전화번호  \n");
    printf("-----------------------------------------\n");
    for(idx=0;idx<numofcustomer;idx++)
    {
        printf("%-10s %10s %20s \n",cusList[idx]->ID,cusList[idx]->name,cusList[idx]->phoneNum);
    }

    system("pause");
}
