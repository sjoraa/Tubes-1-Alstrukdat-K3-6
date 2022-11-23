#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "../../console.h"
#include "../dinerdash/dinerdash.h"

typedef struct
{
    char type[10];
    int score;
    char name[50];
} Datascore;

typedef struct
{
    Datascore d[100];
} Scoreboard;


#endif