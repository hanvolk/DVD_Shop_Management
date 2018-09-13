#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "rentInfo.h"

void RegistDVD(void)
{

    char isbn[ISBN_LEN];
    char title[TITLE_LEN];
    int gen;

    printf("ISBN �Է� : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);


    if(IsRegistISBN(isbn))
    {
        puts("�ش� ISBN�� �̹� ��ϵǾ����ϴ�.  ");
        system("pause");
        return;
    }


    printf("���� �Է� : ");
    fgets(title,TITLE_LEN,stdin);
    DelEnter(title);

    printf("�帣�Է�  �׼�(1), �ڹ�(2), SF(3), �θ�ƽ(4) : ");
    scanf("%d",&gen);
    ClearBuf();

    AddDVDInfo(isbn,title,gen);

}

void SearchDVDInfo(void)
{
    dvdInfo* val;
    char isbn[ISBN_LEN];
    printf("ã�� ISBN �Է� : ");
    scanf("%s",isbn);
    ClearBuf();
    val=GetDVDPtrByID(isbn);
    if(val==NULL)
    {
        puts("�ش��ϴ� DVD�� �����ϴ�. ");
    }
    else
    {
        ShowDVDInfo(val);
    }
    system("pause");
}

void RentDVD(void)
{
    char* isbn[ISBN_LEN];
    char* id[ID_LEN];
    unsigned int date;
    dvdInfo* dvd;

    printf("�뿩 DVD ISBN �Է� : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);
    puts(isbn);

    if(!IsRegistISBN(isbn))
    {
        puts("�̵�� ISBN �Դϴ�.");
        system("pause");
        return;
    }

    if(IsRentISBN(isbn)==RENTED)
    {
        puts("�̹� �뿩���� DVD �Դϴ�. ");
        system("pause");
        return;
    }
    else
    {
        puts("�뿩 ���� �մϴ�. �뿩������ ���� �մϴ�. ");

        printf("�뿩 �� ID �Է� : ");
        fgets(id,ID_LEN,stdin);
        DelEnter(id);

        printf("�뿩 ��¥ �Է� : ");
        scanf("%u",&date);
        ClearBuf();

        AddRentList(isbn,id,date);
        SetRentDvd(isbn,id,date);
        StoreRentInfoToFile();
        return;
    }
}

void ReturnDVD(void)
{
    char* isbn[ISBN_LEN];

    printf("�ݳ� DVD ISBN �Է� : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);

    SetReturnDvd(isbn);
    puts("�ݳ��� �Ϸ�Ǿ����ϴ�.");
}

void ShowRentISBN(void)
{
    char* isbn[ISBN_LEN];

    printf("ã�� ISBN �Է� : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);

    if(!IsRegistISBN(isbn))
    {
        puts("�̵�� ISBN �Դϴ�.");
        system("pause");
        return;
    }

    PrintOutRentAllCusInfo(isbn);

}

void StoreDvdData(void)
{
    int sw;
    printf("DVD ������ ���� �Ͻðڽ��ϱ�? (Yes:1  No:0) : ");
    scanf("%d",&sw);
    ClearBuf();

    if(sw)
    {
        StoreDvdDataToFile();
    }
    else
        return;
}

void LoadDvdData(void)
{
    FILE* fp=fopen("DVD_Data.dat","rb");
    if(fp==NULL)
        return;
    else
        LoadDvdDataFromFile(fp);
}
