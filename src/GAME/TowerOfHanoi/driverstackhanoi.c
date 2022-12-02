#include "stackhanoi.c"
#include <stdio.h>
int main(){
    StackHanoi s;
    Typehanoi val;
    CreateStackhanoi(&s);
    pushhanoi(&s,1);
    pushhanoi(&s,2);
    pushhanoi(&s,3);
    pushhanoi(&s,4);
    pophanoi(&s,&val);
    printf("Panjang stack : %d\n",lengthstackhanoi(s));
    printf("Cek apakah stack kosong: %d\n",isEmptyhanoi(s));
    return 0;
}