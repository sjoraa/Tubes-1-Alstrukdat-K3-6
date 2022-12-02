/* File dinerdash.h */
#include "../dinerdash/queuedinerdash.c"
#include "../dinerdash/arraydinerdash.c"

#ifndef DINER_DASH_H
#define DINER_DASH_H

int foodID(char *x);

void putaran(int *id, QueueDiner *pesanan, ArrayDiner *masak, ArrayDiner *saji);

void displayQueueDiner(QueueDiner pesanan, ArrayDiner masak, ArrayDiner saji, int* saldo);

void DinerDash();

int randomnumberdinerdash(int min, int max);

void INDENTDINERDASH();

#endif