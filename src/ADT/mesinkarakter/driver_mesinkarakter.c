/*File : mesinkarakter.h*/
/*Driver ADT mesin karakter*/

#include<stdio.h>
#include"mesinkarakter.c"

int main()
{
    START("../../../data/config.txt");
    printf("Hasil GetCC seharusnya : 5\n");
    printf("Hasil test: \n");
    printf("GetCC: %c\n",GetCC());
    printf("IsEop: %d\n",IsEOP());
    ADV();
    printf("Hasil GetCC seharusnya setelah di ADV: new line\n");
    printf("Hasil test: \n");
    printf("GetCC: %c\n",GetCC());
    printf("IsEop: %d\n",IsEOP());
    ADV();
    printf("Hasil GetCC seharusnya setelah di ADV: R\n");
    printf("Hasil test: \n");
    printf("GetCC: %c\n",GetCC());
    printf("IsEop: %d\n",IsEOP());
}