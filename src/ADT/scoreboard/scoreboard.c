#include <stdio.h>
#include "scoreboard.h"

void adddata(Scoreboard *S, char *nama, int score, char type){
    int length = nbElmt(*S);
    if (length == 0){
        (*S).d[0].score = score;
        strcpy((*S).d[0].name, nama);
        strcpy((*S).d[0].type, type);
    } else {
        int i = 0;
        while (i < length && (*S).d[i].score > score){
            i++;
        }
        if (i == length){
            (*S).d[i].score = score;
            strcpy((*S).d[i].name, nama);
            strcpy((*S).d[i].type, type);
        } else {
            int j = length;
            while (j > i){
                (*S).d[j].score = (*S).d[j-1].score;
                strcpy((*S).d[j].name, (*S).d[j-1].name);
                strcpy((*S).d[j].type, (*S).d[j-1].type);
                j--;
            }
            (*S).d[i].score = score;
            strcpy((*S).d[i].name, nama);
            strcpy((*S).d[i].type, type);
        }
    }
}

int nbElmt(Scoreboard S){
    int i = 0;
    while(S.d[i].score != 0){
        i++;
    }
    printf("%d", i);
    return i;
}

void displayscoreboard(Scoreboard S){
    int length = nbElmt(S);
    printf("Scoreboard RNG\n");
    int check = 0;
    for (int i = 0; i < length; i++){
        if (S.d[i].type == "RNG"){
            check ++;
            printf("%s %d\n", S.d[i].name, S.d[i].score);
        }
    }
    if (check == 0){
        printf("SCOREBOARD KOSONG\n");
    }

    check = 0;
    printf("Scoreboard Diner Dash\n");
    for (int i = 0; i < length; i++){
        if (S.d[i].type == "Diner Dash"){
            check ++;
            printf("%s %d\n", S.d[i].name, S.d[i].score);
        }
    }
    if (check == 0){
        printf("SCOREBOARD KOSONG\n");
    }

    check = 0;
    printf("Scoreboard Tictactoe\n");
    for (int i = 0; i < length; i++){
        if (S.d[i].type == "Tictactoe"){
            check ++;
            printf("%s %d\n", S.d[i].name, S.d[i].score);
        }
    }
    if (check == 0){
        printf("SCOREBOARD KOSONG\n");
    }

    check = 0;
    printf("Scoreboard Tower of Hanoi\n");
    for (int i = 0; i < length; i++){
        if (S.d[i].type == "Tower of Hanoi"){
            check ++;
            printf("%s %d\n", S.d[i].name, S.d[i].score);
        }
    }
    if (check == 0){
        printf("SCOREBOARD KOSONG\n");
    }

    check = 0;
    printf("Scoreboard Snake on Meteor\n");
    for (int i = 0; i < length; i++){
        if (S.d[i].type == "Snake on Meteor"){
            check ++;
            printf("%s %d\n", S.d[i].name, S.d[i].score);
        }
    }
    if (check == 0){
        printf("SCOREBOARD KOSONG\n");
    }

    check = 0;
    printf("Scoreboard HANGMAN\n");
    for (int i = 0; i < length; i++){
        if (S.d[i].type == "HANGMAN"){
            check ++;
            printf("%s %d\n", S.d[i].name, S.d[i].score);
        }
    }
    if (check == 0){
        printf("SCOREBOARD KOSONG\n");
    } 
}

void strcpy(char *dest, char *src){
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}