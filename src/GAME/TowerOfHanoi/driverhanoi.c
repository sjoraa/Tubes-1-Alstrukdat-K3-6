#include "stdio.h"
#include "stackhanoi.c"
int main(){
    StackHanoi s;
    Typehanoi val;
    CreateStackhanoi(&s);
    printf("Apakah Stack kosong: %d\n",isEmptyhanoi(s));
    pushhanoi(&s,1);
    printstackhanoi(&s);
    pophanoi(&s,&val);
    printf("Apakah Stack kosong: %d\n",isEmptyhanoi(s));


    return 0;
}