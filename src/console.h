#ifndef __CONSOLE__
#define __CONSOLE__

#define true 1
#define false 0
#define boolean unsigned char

#include "./ADT/arraydin/arraydin.c"
#include "./ADT/mesinkata/mesinkata.c"
#include "./ADT/queue/queue.c"
#include "./GAME/DinerDash/dinerdash.c"
#include "./GAME/TicTacToe/bonus.c"
#include "./ADT/map/map.c"
#include "./ADT/set/set.c"
#include "./ADT/stack/stack.c"
#include "./GAME/TowerOfHanoi/toh.c"
#include "./GAME/Hangman/hangman.c"
#include "./GAME/SnakeOnMeteor/snake.c"


int intRandoms(int lower, int upper, int count);

void concat(char *string1, char *string2, char *string3);

void wordToString(Word currentWord, char *string);

void STARTBNMO(ArrayDin *arraygame,scoreboard *Mapgame);

void CREATEGAME(ArrayDin *arraygame,scoreboard *Mapgame);

void LISTGAME(ArrayDin arraygame);

void DELETEGAME(ArrayDin *arraygame, Queue qgame,scoreboard *Mapgame);

void QUEUEGAME(ArrayDin *arraygame,Queue *qgame);

void QUIT();

void SKIPGAME(Queue *qgame, ArrayDin *arraygame, int n);

void PLAYGAME(Queue *qgame,int *skor,Stack *history,scoreboard *Mapgame);

void SAVE(ArrayDin *arraygame,char* directory,scoreboard Mapgame,Stack history);


void printhistory(Stack *historygame,int n);

void resethistory(Stack *historygame);

int randomnumber();

int RNG();

void NEXT();

void INDENT();

void SAVESCOREBOARD(char* namauser, scoreboard *Mapgame, int skor,char *game);

int TOWEROFHANOI();

#endif
