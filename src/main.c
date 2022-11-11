#include "console.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ArrayDin arraygame = MakeArrayDin();
    ArrayDin historygame = MakeArrayDin();
    ArrayDin queuegame;
    Queue qgame;
    CreateQueue(&qgame);

    boolean loadstatus = false;
    boolean endProgram = false;
    int skor = 0;

    while (!loadstatus && !endProgram)
    {
        INTERFACE();
        printf("\n                                                          ENTER COMMAND : ");
        char *command = stringCommand();
        if (countSpace(command) == 0){
            if(compareSTR(command,"START"))
            {
                STARTBNMO(&arraygame);
                NEXT();
                loadstatus = true;
            }
            else if (compareSTR(command, "QUIT")){
                QUIT();
                endProgram = true;
            }
            else{
                INDENT();
                printf("        Command tidak dikenali. Silakan coba lagi.");
                NEXT();
            }
        }
        else if (countSpace(command) == 1)
        {
            char *first = firstString(command);
            char *second = secondString(command);
            if (compareSTR(first, "LOAD"))
            {
                LOAD(&arraygame, second);
                NEXT();
                loadstatus = true;
            }
            else{
            INDENT();
            printf("        Command tidak dikenali. Silakan coba lagi.");
            NEXT();
            }
        }
        else
        {
            INDENT();
            printf("        Command tidak dikenali. Silakan coba lagi.");
            NEXT();
        }
    }
    while (loadstatus && !endProgram)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        INDENT();
        printf("        -----------------------------------------\n");
        INDENT();
        printf("        | KETIK HELP UNTUK MELIHAT LIST COMMAND |\n");
        INDENT();
        printf("        -----------------------------------------\n");
        INDENT();
        printf("\n                                                                   ENTER COMMAND : ");
        char *command = stringCommand();
        if (compareSTR(command,"CREATE GAME"))
        {
            CREATEGAME(&arraygame);
            NEXT();
        }
        else if (compareSTR(command,"LIST GAME"))
        {
            LISTGAME(arraygame);
            NEXT();
        }
        else if (compareSTR(command,"DELETE GAME"))
        {
            DELETEGAME(&arraygame);
            NEXT();
        }
        else if (compareSTR(command,"QUEUE GAME"))
        {
            QUEUEGAME(&arraygame, &qgame);
            NEXT();
        }
        else if (compareSTR(command,"PLAY GAME"))
        {

            PLAYGAME(&qgame, &skor);
            NEXT();
        
        }
        else if (countSpace(command) == 1){
            char *first = firstString(command);
            char *second = secondString(command);
            if (compareSTR(first,"SKIPGAME"))
            {
                int n = stringToInt(second);
                SKIPGAME(&qgame,&arraygame, n);
                NEXT();
            }
            else if (compareSTR(first, "SAVE")){
                SAVE(&arraygame, second);
                NEXT();
            }
            else{
                INDENT();
                printf("        Command tidak dikenali. Silakan coba lagi.\n");
                NEXT();
            }
        } 
        else if (compareSTR(command,"HELP"))
        {
            system("cls");
            HELP();
            NEXT();
        }
        else if (compareSTR(command,"QUIT"))
        {
            QUIT();
            endProgram = true;
        }
        else
        {
            INDENT();
            printf("        Command tidak dikenali. Silakan coba lagi.\n");
            NEXT();
        }
    }
    return 0;
}