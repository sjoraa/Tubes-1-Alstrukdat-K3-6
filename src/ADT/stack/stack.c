#include "stack.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
{
    IDX_TOP(*s) = IDX_UNDEF;
}
/* ************ Prototype ************ */
boolean IsEmptyStack(Stack s)
/* Mengirim true jika s kosong: lihat definisi di atas */
{
    return IDX_TOP(s) == IDX_UNDEF;
}

boolean isFullStack(Stack s)
/* Mengirim true jika tabel penampung nilai s stack penuh */
{
    return IDX_TOP(s) == CAPACITY-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, ElTypeStack val)
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
{
    IDX_TOP(*s)++;
    TOP(*s) = val;
}


/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, ElTypeStack *val)
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
{
    *val = TOP(*s);
    TOP(*s)=0;
    IDX_TOP(*s)--;
}







// void printstack(Stack *S){
//     Stack stemp;
//     ElTypeStack val;
//     CreateStack(&stemp);
//     while (!IsEmptyStack(*S)){
//         pop(S,&val);
//         push(&stemp,val);
//         if (val==1){
//             printf("    *    \n",val);
//         }
//         else if (val==3){
//             printf("   ***   \n",val);
//         }
//         else if (val==5){
//             printf("  *****  \n",val);
//         }
//         else if (val==7){
//             printf(" ******* \n",val);
//         }        
//         else if (val==9){
//             printf("*********\n",val);
//         }
//     }
//     while(!IsEmptyStack(stemp)){
//         pop(&stemp,&val);
//         push(S,val);
//     }
//     printf(" -------\n");

// }

// void printbintang(Stack *s,int i){
//     if (s->buffer[i]==1){
//         printf("    *    ",s->buffer[i]);
//     }
//     else if (s->buffer[i]==3){
//         printf("   ***   ",s->buffer[i]);
//     }
//     else if (s->buffer[i]==5){
//         printf("  *****  ",s->buffer[i]);
//     }
//     else if (s->buffer[i]==7){
//         printf(" ******* ",s->buffer[i]);
//     }        
//     else if (s->buffer[i]==9){
//         printf("*********",s->buffer[i]);
//     }
//     else{
//         printf("    |    ");
//     }

// }
// void printhanoi(Stack s1,Stack s2,Stack s3){
//     for (int i=4;i>=0;i-=1){
//         printbintang(&s1,i);
//         printf("                ");
//         printbintang(&s2,i);
//         printf("                ");
//         printbintang(&s3,i);
//         printf("\n");

//     }
//     printf(" ------- ");
//     printf("                ");
//     printf(" ------- ");
//     printf("                ");
//     printf(" ------- ");
//     printf("                \n");
//     printf("    A    ");
//     printf("                ");
//     printf("    B    ");
//     printf("                ");
//     printf("    C    ");
//     printf("                \n\n");
    


// }



int lengthstack(Stack s){
    Stack stemp;
    ElTypeStack temp;
    int panjang=0;
    CreateStack(&stemp);
    while(!IsEmptyStack(s)){
        pop(&s,&temp);
        push(&stemp,temp);
        panjang++;
    }
    while(!IsEmptyStack(stemp)){
        pop(&stemp,&temp);
        push(&s,temp);
    }
    return panjang;
}

boolean stacksama(Stack s1,Stack s2){
    boolean sama=true;
    int i;
    if (lengthstack(s1) == lengthstack(s2)){
        for(i=0;i<IDX_TOP(s1);i++){
            if (s1.buffer[i]!=s2.buffer[i]){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return sama;
}


