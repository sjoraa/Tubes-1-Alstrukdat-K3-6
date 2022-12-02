#include "../../console.c"
#include <stdio.h>
int main(){
    QueueDiner pesanan;
    CreateQueueDiner(&pesanan);
    ArrayDiner masak,saji;
    MakeEmptyDiner(&masak);
    MakeEmptyDiner(&saji);
    int saldo=0;
    printf("%d\n",randomnumberdinerdash(10,100));
    printf("%d\n",foodID("M123"));
    displayQueueDiner(pesanan,masak,saji,&saldo);

    return 0;
}