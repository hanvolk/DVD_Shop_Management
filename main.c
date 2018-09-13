/*
    Program : Phone_Number_ Management
    File : main.c
    Description : Enter the choice of User
    Author : Gyeong Jin Computer Academy
    Enviorment : win 10 64bit, Code::Blocks
    Revisions : ver 1.0  (Gjcom)  First  release
*/

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"
#include "dvdManager.h"
#include "cusInfoAccess.h"
#include "dvdInfoAccess.h"
#include "rentInfo.h"

enum{CUS_REGIST=1, CUS_SEARCH, CUS_DEL, DVD_REGIST, DVD_SEARCH, DVD_DEL, DVD_RENT, DVD_RETURN, ShowRent_ISBN, SHOW_CUS_RENT, QUIT};

int main()
{
    int inputMenu=0;
    LoadCusData();
    LoadDvdData();
    LoadRentInfoFromFile();


    while(1)
    {
        ShowMenu();
        scanf("%d",&inputMenu);
        ClearBuf();

        switch(inputMenu)
        {
        case CUS_REGIST:
            RegistCustomer();
            break;
        case CUS_SEARCH:
            SearchCusInfo();
            break;
        case DVD_REGIST:
            RegistDVD();
            break;
        case DVD_SEARCH:
            SearchDVDInfo();
            break;
        case DVD_RENT:
            RentDVD();
            StoreDvdData();
            break;
        case DVD_RETURN:
            ReturnDVD();
            StoreDvdData();
            break;
        case ShowRent_ISBN:
            ShowRentISBN();
            break;
        case SHOW_CUS_RENT:
            ShowCusRent();
            break;


        }

        if(inputMenu==QUIT)
        {
            StoreCusData();
            StoreDvdData();
            puts("이용해 주셔서 감사합니다.");
            break;
        }

        if(inputMenu==21)
        {
            ShowAllCusData();
        }
        if(inputMenu==22)
        {
            ShowAllDVDData();
        }
        if(inputMenu==23)
        {
            ShowAllDVDRental();
        }


    }
    return 0;
}
