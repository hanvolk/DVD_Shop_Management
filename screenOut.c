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

    printf("������������ ��   �� ������������\n\n");
    printf("  1. �ű� ���� \n");
    printf("  2. �� �˻� \n");
    printf("  3. �� ���� ���� \n");
    printf(" ������������������������������������\n");
    printf("  4. DVD ��� \n");
    printf("  5. DVD �˻� \n");
    printf("  6. DVD ���� \n");
    printf(" ������������������������������������\n");
    printf("  7. DVD �뿩 \n");
    printf("  8. DVD �ݳ� \n");
    printf(" ������������������������������������\n");
    printf("  9. DVD �뿩 �� ��ü ��ȸ \n");
    printf(" 10. ���� �뿩 DVD ��ü ��ȸ \n");
    printf(" ������������������������������������\n");
    printf(" 11. ��  �� \n");
    printf("��������������������������������������\n");
    printf("���ϴ� �޴��� ������ �ּ��� : ");
}

/*
    Function : void ShowCustomer(cusInfo* pCus)
    Description :Output basic personal information of customer
 */
void ShowCustomerInfo(cusInfo* pCus)
{
    printf("======================\n");
    printf("�� ID : %s \n",pCus->ID);
    printf("�� �̸� : %s \n",pCus->name);
    printf("�� ��ȭ��ȣ : %s \n",pCus->phoneNum);
    printf("======================\n");

}

void ShowDVDInfo(dvdInfo* pDvd)
{
    printf("======================\n");
    printf("�� ISBN : %s \n",pDvd->ISBN);
    printf("�� ���� : %s \n",pDvd->title);
    switch(pDvd->genre)
    {
    case ACTION:
        printf("�� �帣 : %s \n","�׼�");
        break;
    case COMIC:
        printf("�� �帣 : %s \n","�ڹ�");
        break;
    case SF:
        printf("�� �帣 : %s \n","SF");
        break;
    case ROMANTIC:
        printf("�� �帣 : %s \n","�θ�ƽ");
        break;
    }

    printf("======================\n");
    system("pause");
}
