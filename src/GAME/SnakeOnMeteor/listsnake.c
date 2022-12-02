#include "stdio.h"
#include "stdlib.h"
#include "listsnake.h"

boolean IsEmptyListSNAKE(ListSNAKE L)
{
    return Tail(L) == Nil;
}

void CreateEmptyListSNAKE(ListSNAKE *L)
{
    Tail(*L) = Nil;
}

addressSNAKE AlokasiSNAKE(int X, int Y)
{
    addressSNAKE P = (addressSNAKE)malloc(1 * sizeof(ElmtListSNAKE));
    if (P != Nil)
    {
        x(P) = X;
        y(P) = Y;
        Next(P) = Nil;
        return P;
    }
    {
        return Nil;
    }
}

void DealokasiSNAKE(addressSNAKE *P)
{
    free(*P);
}

addressSNAKE SearchSNAKE(ListSNAKE L, int X, int Y)
{
    addressSNAKE P;
    boolean bFound = false;

    if (!IsEmptyListSNAKE(L))
    {
        P = Tail(L);
        while (!bFound && P != Nil)
        {
            if (X == x(P) && Y == y(P))
            {
                bFound = true;
            }
            else
            {
                P = Next(P);
            }
        }

        if (bFound)
        {
            return P;
        }
        else
        {
            return Nil;
        }
    }
    else
    {
        return Nil;
    }
}

void InsVTailSNAKE(ListSNAKE *L, int X, int Y)
{
    addressSNAKE P = AlokasiSNAKE(X,Y);
    if (P != Nil)
    {
        InsertTailSNAKE(L, P);
    }
}

void InsertTailSNAKE(ListSNAKE *L, addressSNAKE P)
{
    Next(P) = Tail(*L);
    Tail(*L) = P;
}

void DelTailSNAKE(ListSNAKE *L, addressSNAKE *P)
{
    *P = Tail(*L);
    Tail(*L) = Next(Tail(*L));
    Next(*P) = Nil;
}

void DelAfterSNAKE(ListSNAKE *L, addressSNAKE *Pdel, addressSNAKE Prec)
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}

void DelPSNAKE(ListSNAKE *L, int X, int Y)
{
    addressSNAKE Prec;
    addressSNAKE P;
    boolean bFound = false;

    if (!IsEmptyListSNAKE(*L))
    {
        if (X == x(Tail(*L)) && X == x(Tail(*L)))
        {
            DelTailSNAKE(L, &P);
            DealokasiSNAKE(&P);
        }
        else
        {
            P = Tail(*L);
            while (!bFound && P != Nil)
            {
                if (x(P) == X && y(P) == Y)
                {
                    bFound = true;
                }
                else
                {
                    Prec = P;
                    P = Next(P);
                }
            }

            if (bFound)
            {
                DelAfterSNAKE(L, &P, Prec);
                DealokasiSNAKE(&P);
            }
        }
    }
}