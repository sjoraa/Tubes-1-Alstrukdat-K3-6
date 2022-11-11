/*File : mesinkarakter.h*/
/*Driver ADT mesin karakter*/

#include<stdio.h>
#include"mesinkarakter.c"

int main()
{
    START("untuk_driver.txt");
    ADV();
    printf("GetCC: %c\n",GetCC());
    printf("IsEop: %d",IsEOP());
    return 0;
}