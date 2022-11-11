#ifndef __CONSOLE__
#define __CONSOLE__

#define true 1
#define false 0
#define boolean unsigned char

#include "./ADT/arraydin/arraydin.c"
#include "./ADT/mesinkata/mesinkata.c"
#include "./ADT/queue/queue.c"
#include "./ADT/dinerdash/dinerdash.c"
#include "./ADT/Bonus/bonus.c"


int intRandoms(int lower, int upper, int count);

void concat(char *string1, char *string2, char *string3);

void wordToString(Word currentWord, char *string);

void STARTBNMO(ArrayDin *arraygame);

void CREATEGAME(ArrayDin *arraygame);

void LISTGAME(ArrayDin arraygame);

void DELETEGAME(ArrayDin *arraygame);

void QUEUEGAME(ArrayDin *arraygame,Queue *qgame);

void QUIT();

void SKIPGAME(Queue *qgame, ArrayDin *arraygame, int n);

void PLAYGAME(Queue *qgame,int *skor);

void SAVE(ArrayDin *arraygame,char* directory);

int randomnumber();

int RNG();

void NEXT();

void INDENT();

void TicTacToe();

#endif
