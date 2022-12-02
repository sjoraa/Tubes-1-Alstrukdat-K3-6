#include "arraydin.c"
#include <stdio.h>
int main(){
    ArrayDin driver;
    driver=MakeArrayDin();
    printf("Cek kosong apa tidak : %d\n",IsEmpty(driver));
    InsertLast(&driver,"tes");
    printf("Panjang arraydin: %d\n",Length(driver));
    PrintArrayDin(driver);
    printf("Indeks string \"tes\": %d",SearchArrayDin(driver,"tes"));
    return 0;
}