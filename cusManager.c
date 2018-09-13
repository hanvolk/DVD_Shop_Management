/*
    Program : Phone_Number_ Management
    File : cusManager.c
    Description : Definition of functions for handling customer related tasks.
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#include "common.h"
#include "cusInfo.h"
#include "rentInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/*
    Function : void RegistCustomer(void)
    Description : New Membership
    return : void
*/
void RegistCustomer(void)
{
    char ID[ID_LEN];
    char name[NAME_LEN];
    char num[PHONE_LEN];

    printf("ID 입력 : ");
    fgets(ID,ID_LEN,stdin);
    DelEnter(ID);

    if(IsRegistID(ID))
    {
        puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해 주세요 ");
        system("pause");
        RegistCustomer();
    }


    printf("이름 입력 : ");
    fgets(name,NAME_LEN,stdin);
    DelEnter(name);

    printf("전화번호 입력 : ");
    fgets(num,PHONE_LEN,stdin);
    DelEnter(num);

    AddCusInfo(ID,name,num);

}

/*
    Fucntion : void SearchCusInfo(void)
    Description : Retrieve membership information through ID
    return : void
*/
void SearchCusInfo(void)
{

    char ID[ID_LEN];
    cusInfo* pcus;
    printf("찾는 ID 입력 : ");
    scanf("%s",ID);
    ClearBuf();
    pcus=GetCusPtrByID(ID);
    if(pcus==NULL)
        puts("존재하지 않는 ID 입니다. ");
    else
         ShowCustomerInfo(GetCusPtrByID(ID)); // screenout.c
}

void ShowCusRent(void)
{
    char ID[ID_LEN];
    unsigned int startday, endday;

    printf("찾는 ID 입력 : ");
    fgets(ID,ID_LEN,stdin);
    DelEnter(ID);

    printf("대여 기간 입력 : ");
    scanf("%u %u",&startday, &endday);
    ClearBuf();

    PrintOutCusAllRentInfo(ID,startday,endday);
}

void StoreCusData(void)
{
    int sw;
    printf("고객 정보를 저장 하시겠습니까? (Yes:1  No:0) : ");
    scanf("%d",&sw);
    ClearBuf();

    if(sw)
        StoreCusDataToFile();
    else
        return;
}

void LoadCusData(void)
{
    FILE* fp=fopen("CusData.dat","rb");
    if(fp==NULL)
        return;
    else
        LoadCusDataFromFile(fp);
}
