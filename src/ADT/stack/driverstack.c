#include "stack.c"
#include <stdio.h>
int main(){
    Stack s;
    ElTypeStack val;
    CreateStack(&s);
    push(&s,"a");
    push(&s,"2");
    push(&s,"3");
    push(&s,"4");
    pop(&s,&val);
    printf("Panjang stack : %d\n",lengthstack(s));
    printf("Cek apakah stack kosong: %d\n",IsEmptyStack(s));
    return 0;
}