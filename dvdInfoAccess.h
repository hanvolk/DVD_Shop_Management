
#ifndef __DVDINFO_H__
#define __DVDINFO_H__

int AddDVDInfo (char* isbn, char* title, int gen);
dvdInfo* GetDVDPtrByID(char* isbn);
int IsRegistDVD(char* isbn);
int IsRegistISBN(char* isbn);
int IsRentISBN(char* isbn);
void SetRentDvd(char* isbn,char* id, unsigned int date);
void SetReturnDvd(char* isbn);
void StoreDvdDataToFile(void);
void LoadDvdDataFromFile(FILE* fp);

#endif // __CUSINFOACCESS_H__
