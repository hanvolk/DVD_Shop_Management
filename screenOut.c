/*
    Program : Phone_Number_ Management
    File : screenOut.c
    Description : Definition of functions for output to the Console
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

/* main menu */
void ShowMenu(void)
{
    system("cls");

    printf("━━━━━━ 메   뉴 ━━━━━━\n\n");
    printf("  1. 신규 가입 \n");
    printf("  2. 고객 검색 \n");
    printf("  3. 고객 정보 삭제 \n");
    printf(" ──────────────────\n");
    printf("  4. DVD 등록 \n");
    printf("  5. DVD 검색 \n");
    printf("  6. DVD 삭제 \n");
    printf(" ──────────────────\n");
    printf("  7. DVD 대여 \n");
    printf("  8. DVD 반납 \n");
    printf(" ──────────────────\n");
    printf("  9. DVD 대여 고객 전체 조회 \n");
    printf(" 10. 고객별 대여 DVD 전체 조회 \n");
    printf(" ──────────────────\n");
    printf(" 11. 종  료 \n");
    printf("━━━━━━━━━━━━━━━━━━━\n");
    printf("원하는 메뉴를 선택해 주세요 : ");
}

/*
    Function : void ShowCustomer(cusInfo* pCus)
    Description :Output basic personal information of customer
 */
void ShowCustomerInfo(cusInfo* pCus)
{
    printf("======================\n");
    printf("▶ ID : %s \n",pCus->ID);
    printf("▶ 이름 : %s \n",pCus->name);
    printf("▶ 전화번호 : %s \n",pCus->phoneNum);
    printf("======================\n");

}

void ShowDVDInfo(dvdInfo* pDvd)
{
    printf("======================\n");
    printf("▶ ISBN : %s \n",pDvd->ISBN);
    printf("▶ 제목 : %s \n",pDvd->title);
    switch(pDvd->genre)
    {
    case ACTION:
        printf("▶ 장르 : %s \n","액션");
        break;
    case COMIC:
        printf("▶ 장르 : %s \n","코믹");
        break;
    case SF:
        printf("▶ 장르 : %s \n","SF");
        break;
    case ROMANTIC:
        printf("▶ 장르 : %s \n","로멘틱");
        break;
    }

    printf("======================\n");
    system("pause");
}
