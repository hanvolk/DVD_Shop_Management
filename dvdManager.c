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

    printf("ISBN 입력 : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);


    if(IsRegistISBN(isbn))
    {
        puts("해당 ISBN은 이미 등록되었습니다.  ");
        system("pause");
        return;
    }


    printf("제목 입력 : ");
    fgets(title,TITLE_LEN,stdin);
    DelEnter(title);

    printf("장르입력  액션(1), 코믹(2), SF(3), 로맨틱(4) : ");
    scanf("%d",&gen);
    ClearBuf();

    AddDVDInfo(isbn,title,gen);

}

void SearchDVDInfo(void)
{
    dvdInfo* val;
    char isbn[ISBN_LEN];
    printf("찾는 ISBN 입력 : ");
    scanf("%s",isbn);
    ClearBuf();
    val=GetDVDPtrByID(isbn);
    if(val==NULL)
    {
        puts("해당하는 DVD가 없습니다. ");
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

    printf("대여 DVD ISBN 입력 : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);
    puts(isbn);

    if(!IsRegistISBN(isbn))
    {
        puts("미등록 ISBN 입니다.");
        system("pause");
        return;
    }

    if(IsRentISBN(isbn)==RENTED)
    {
        puts("이미 대여중인 DVD 입니다. ");
        system("pause");
        return;
    }
    else
    {
        puts("대여 가능 합니다. 대여과정을 진행 합니다. ");

        printf("대여 고객 ID 입력 : ");
        fgets(id,ID_LEN,stdin);
        DelEnter(id);

        printf("대여 날짜 입력 : ");
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

    printf("반납 DVD ISBN 입력 : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);

    SetReturnDvd(isbn);
    puts("반납이 완료되었습니다.");
}

void ShowRentISBN(void)
{
    char* isbn[ISBN_LEN];

    printf("찾는 ISBN 입력 : ");
    fgets(isbn,ISBN_LEN,stdin);
    DelEnter(isbn);

    if(!IsRegistISBN(isbn))
    {
        puts("미등록 ISBN 입니다.");
        system("pause");
        return;
    }

    PrintOutRentAllCusInfo(isbn);

}

void StoreDvdData(void)
{
    int sw;
    printf("DVD 정보를 저장 하시겠습니까? (Yes:1  No:0) : ");
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
