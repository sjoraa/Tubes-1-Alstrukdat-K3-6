#include <stdio.h>
#include "set.c"
#include "../../ADT/mesinkata/mesinkata.c"

int main()
{
    Set S;
    CreateEmptySet(&S);

    printf("---Menambahkan elemen ke dalam set---\n\n");
    InsertSet(&S, "ALGORITMA");
    InsertSet(&S, "STRUKTUR");
    InsertSet(&S, "DATA");

    printf("[");
    for(int i = 0; i < S.Count-1; i++)
    {
        printf("%s, ", S.Elements[i]);
    }
    printf("%s", S.Elements[S.Count-1]);
    printf("]\n");
    printf("IsEmptySet : %d\n", IsEmptySet(S));
    printf("IsFullSet : %d\n", IsFullSet(S));
    printf("Jumlah elemen dalam set : %d\n", S.Count);


    printf("\n");
    printf("---Memeriksa apakah sebuah element adalah member dari S---\n\n");
    printf("IsMemberSet ALGORITMA : %d\n", IsMemberSet(S, "ALGORITMA"));
    printf("IsMemberSet ALSTRUKDAT : %d\n", IsMemberSet(S, "ALSTRUKDAT"));

    printf("\n");
    printf("---Menghapus element ALGORITMA---\n\n");
    DeleteSet(&S, "ALGORITMA");

    printf("[");
    for(int i = 0; i < S.Count-1; i++)
    {
        printf("%s, ", S.Elements[i]);
    }
    printf("%s", S.Elements[S.Count-1]);
    printf("]\n");
    printf("Jumlah elemen dalam set : %d\n", S.Count);
    printf("IsMemberSet ALGORITMA : %d\n", IsMemberSet(S, "ALGORITMA"));
}