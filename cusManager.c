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

    printf("ID �Է� : ");
    fgets(ID,ID_LEN,stdin);
    DelEnter(ID);

    if(IsRegistID(ID))
    {
        puts("�ش� ID�� ��� �߿� �ֽ��ϴ�. �ٸ� ID�� ������ �ּ��� ");
        system("pause");
        RegistCustomer();
    }


    printf("�̸� �Է� : ");
    fgets(name,NAME_LEN,stdin);
    DelEnter(name);

    printf("��ȭ��ȣ �Է� : ");
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
    printf("ã�� ID �Է� : ");
    scanf("%s",ID);
    ClearBuf();
    pcus=GetCusPtrByID(ID);
    if(pcus==NULL)
        puts("�������� �ʴ� ID �Դϴ�. ");
    else
         ShowCustomerInfo(GetCusPtrByID(ID)); // screenout.c
}

void ShowCusRent(void)
{
    char ID[ID_LEN];
    unsigned int startday, endday;

    printf("ã�� ID �Է� : ");
    fgets(ID,ID_LEN,stdin);
    DelEnter(ID);

    printf("�뿩 �Ⱓ �Է� : ");
    scanf("%u %u",&startday, &endday);
    ClearBuf();

    PrintOutCusAllRentInfo(ID,startday,endday);
}

void StoreCusData(void)
{
    int sw;
    printf("�� ������ ���� �Ͻðڽ��ϱ�? (Yes:1  No:0) : ");
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
