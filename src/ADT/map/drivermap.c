#include <stdio.h>
#include "../../console.c"

int main(){
    Map tesmap;
    CreateEmptyMap(&tesmap);
    printf("Apakah Map kosong: %d \n",IsEmptyMap(tesmap));
    printf("Apakah Map full : %d \n",IsFullMap(tesmap));
    InsertMap(&tesmap,"TES",23);
    printmap(tesmap);


    return 0;
}