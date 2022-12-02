#include "stackhanoi.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateStackhanoi(StackHanoi *s)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
{
    IDX_TOP(*s) = IDX_UNDEF;
    for (int i=0;i<10;i++){
        s->buffer[i]=-999;
    }
}
/* ************ Prototype ************ */
boolean isEmptyhanoi(StackHanoi s)
/* Mengirim true jika s kosong: lihat definisi di atas */
{
    return IDX_TOP(s) == IDX_UNDEF;
}

boolean isFullhanoi(StackHanoi s)
/* Mengirim true jika tabel penampung nilai s stackHanoi penuh */
{
    return IDX_TOP(s) == CAPACITY-1;
}

/* ************ Menambahkan sebuah elemen ke StackHanoi ************ */
void pushhanoi(StackHanoi *s, Typehanoi val)
/* Menambahkan val sebagai elemen StackHanoi s */
/* I.S. s mungkin kosong, tabel penampung elemen stackHanoi TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
{
    IDX_TOP(*s)++;
    TOP(*s) = val;
}


/* ************ Menghapus sebuah elemen StackHanoi ************ */
void pophanoi(StackHanoi *s, Typehanoi *val)
/* Menghapus val dari StackHanoi s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
{
    *val = TOP(*s);
    TOP(*s)=0;
    IDX_TOP(*s)--;
}





void printstackhanoi(StackHanoi *S){
    StackHanoi stemp;
    Typehanoi val;
    CreateStackhanoi(&stemp);
    while (!isEmptyhanoi(*S)){
        
        pophanoi(S,&val);
        pushhanoi(&stemp,val);
        if (val==1){
            printf("                        *    \n",val);
        }
        else if (val==3){
            printf("                       ***   \n",val);
        }
        else if (val==5){
            printf("                      *****  \n",val);
        }
        else if (val==7){
            printf("                     ******* \n",val);
        }        
        else if (val==9){
            printf("                    *********\n",val);
        }
    }
    while(!isEmptyhanoi(stemp)){
        pophanoi(&stemp,&val);
        pushhanoi(S,val);
    }
    printf("                     -------\n");

}

void printbintang(StackHanoi *s,int i){
    if (s->buffer[i]==1){
        printf("                        *    ",s->buffer[i]);
    }
    else if (s->buffer[i]==3){
        printf("                       ***   ",s->buffer[i]);
    }
    else if (s->buffer[i]==5){
        printf("                      *****  ",s->buffer[i]);
    }
    else if (s->buffer[i]==7){
        printf("                     ******* ",s->buffer[i]);
    }        
    else if (s->buffer[i]==9){
        printf("                    *********",s->buffer[i]);
    }
    else{
        printf("                        |    ");
    }

}
void printhanoi(StackHanoi s1,StackHanoi s2,StackHanoi s3){
    for (int i=4;i>=0;i-=1){
        printbintang(&s1,i);
        printf("                                    ");
        printbintang(&s2,i);
        printf("                                    ");
        printbintang(&s3,i);
        printf("\n");

    }
    printf("                     ------- ");
    printf("                                    ");
    printf("                     ------- ");
    printf("                                    ");
    printf("                     ------- ");
    printf("                                    \n");
    printf("                        A    ");
    printf("                                    ");
    printf("                        B    ");
    printf("                                    ");
    printf("                        C    ");
    printf("                                    \n\n");
    


}



int lengthstackhanoi(StackHanoi s){
    StackHanoi stemp;
    Typehanoi temp;
    int panjang=0;
    CreateStackhanoi(&stemp);
    while(!isEmptyhanoi(s)){
        pophanoi(&s,&temp);
        pushhanoi(&stemp,temp);
        panjang++;
    }
    while(!isEmptyhanoi(stemp)){
        pophanoi(&stemp,&temp);
        pushhanoi(&s,temp);
    }
    return panjang;
}

boolean stacksamahanoi(StackHanoi s1,StackHanoi s2){
    boolean sama=true;
    int i;
    if (lengthstackhanoi(s1) == lengthstackhanoi(s2)){
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


