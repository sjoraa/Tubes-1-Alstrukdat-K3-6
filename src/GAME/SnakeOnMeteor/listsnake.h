#ifndef listsnake_H
#define listsnake_H

#include "boolean.h"

#define Nil 0
typedef struct tElmtlistSNAKE *addressSNAKE;
typedef struct tElmtlistSNAKE{ 
    int x;
    int y;
	addressSNAKE next;
} ElmtListSNAKE;
typedef struct {
	addressSNAKE Tail;
} ListSNAKE;

#define x(P) (P)->x
#define y(P) (P)->y
#define Next(P) (P)->next
#define Tail(L) ((L).Tail)

boolean IsEmptyListSNAKE(ListSNAKE L);

void CreateEmptyListSNAKE(ListSNAKE *L);

addressSNAKE AlokasiSNAKE(int X, int Y);

void DealokasiSNAKE(addressSNAKE *P);

addressSNAKE SearchSNAKE(ListSNAKE L, int X, int Y);

void InsVTailSNAKE(ListSNAKE *L, int X, int Y);

void InsertTailSNAKE(ListSNAKE *L, addressSNAKE P);

void DelTailSNAKE(ListSNAKE *L, addressSNAKE *P);

void DelAfterSNAKE(ListSNAKE *L, addressSNAKE *Pdel, addressSNAKE Prec);

void DelPSNAKE(ListSNAKE *L, int X, int Y);


#endif