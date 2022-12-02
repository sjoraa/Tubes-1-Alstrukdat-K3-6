#include <stdio.h>
#include "mapsnake.c"

int main(){
    MapSNAKE tesmap;
    CreateEmptyMapSNAKE(&tesmap);
    printf("Apakah Map kosong: %d \n",IsEmptyMapSNAKE(tesmap));
    printf("Apakah Map full : %d \n",IsFullSNAKE(tesmap));
    InsertSNAKE(&tesmap,1, "23");
    printf("Apakah anggota map dengan key = 1 ada di map: %d \n",IsMemberSNAKE(tesmap, 1));
    DeleteSNAKE(&tesmap,1);
    printf("Apakah anggota map dengan key = 1 ada di map: %d \n",IsMemberSNAKE(tesmap, 1));


    return 0;
}