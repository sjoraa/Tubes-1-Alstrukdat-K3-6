/** File : queue.h */
/* Driver ADT Queue*/

#include <stdio.h>
#include "queue.c"

int main()
{
    Queue Q;
    CreateQueue(&Q);
    enqueue(&Q, "1");
    enqueue(&Q, "2");
    enqueue(&Q, "3");
    ElType val;
    dequeue(&Q, &val);
    displayQueue(Q);
    printf("length: %d\n", length(Q));
    printf("isFull: %d\n", isFull(Q));
    printf("isEmpty: %d\n", isEmpty(Q));
    return 0;
}