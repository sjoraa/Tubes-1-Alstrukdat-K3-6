#include <stdio.h>
#include "../mesinkata/mesinkata.h"

char kotak[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int checkwin();
void board();

void TICTACTOE()
{
    int menang = 100, kalah = 0, seri = 50;
    int pemain = 1, i;

    char mark;
    do
    {
        board();
        pemain = (pemain % 2) ? 1 : 2;
        printf("\n\n");
        printf("                                                                                      PEMAIN %d \n", pemain);
        printf("                                                                                MASUKKAN NOMOR :  ");
        char *command = stringCommand();
        int opsi = stringToInt(command);

        mark = (pemain == 1) ? 'X' : 'O';

        if (opsi == 1 && kotak[1] == '1')
            kotak[1] = mark;
            
        else if (opsi == 2 && kotak[2] == '2')
            kotak[2] = mark;
            
        else if (opsi == 3 && kotak[3] == '3')
            kotak[3] = mark;
            
        else if (opsi == 4 && kotak[4] == '4')
            kotak[4] = mark;
            
        else if (opsi == 5 && kotak[5] == '5')
            kotak[5] = mark;
            
        else if (opsi == 6 && kotak[6] == '6')
            kotak[6] = mark;
            
        else if (opsi == 7 && kotak[7] == '7')
            kotak[7] = mark;
            
        else if (opsi == 8 && kotak[8] == '8')
            kotak[8] = mark;
            
        else if (opsi == 9 && kotak[9] == '9')
            kotak[9] = mark;
            
        else
        {
            printf("                                                                                INVALID MOVE! SILAKAN COBA LAGI!");

            pemain--;

        }
        i = checkwin();

        pemain++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1){
        printf("\n                                                                                  PEMAIN %d MENANG!!! \n\n\n", --pemain);
        printf("                                                                           ---------- SCOREBOARD ----------\n\n");
        if (pemain == 1){
            printf("                                                                                   PEMAIN 1 : %d\n\n", menang);
            printf("                                                                                   PEMAIN 2 : %d\n", kalah);
        }
        else{
            printf("                                                                                   PEMAIN 1 : %d\n\n", kalah);
            printf("                                                                                   PEMAIN 2 : %d\n", menang);
        }
    }
    else
    {
            printf("                                                                                 PERMAINAN SERI!!!\n\n\n");
            printf("                                                                          ---------- SCOREBOARD ---------\n\n");
            printf("                                                                                   PEMAIN 1 : %d\n\n", seri);
            printf("                                                                                   PEMAIN 2 : %d\n", seri);
    }
}

int checkwin()
{
    if (kotak[1] == kotak[2] && kotak[2] == kotak[3])
        return 1;
        
    else if (kotak[4] == kotak[5] && kotak[5] == kotak[6])
        return 1;
        
    else if (kotak[7] == kotak[8] && kotak[8] == kotak[9])
        return 1;
        
    else if (kotak[1] == kotak[4] && kotak[4] == kotak[7])
        return 1;
        
    else if (kotak[2] == kotak[5] && kotak[5] == kotak[8])
        return 1;
        
    else if (kotak[3] == kotak[6] && kotak[6] == kotak[9])
        return 1;
        
    else if (kotak[1] == kotak[5] && kotak[5] == kotak[9])
        return 1;
        
    else if (kotak[3] == kotak[5] && kotak[5] == kotak[7])
        return 1;
        
    else if (kotak[1] != '1' && kotak[2] != '2' && kotak[3] != '3' &&
        kotak[4] != '4' && kotak[5] != '5' && kotak[6] != '6' && kotak[7] 
        != '7' && kotak[8] != '8' && kotak[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH pemainS MARK
 ********************************************************************/


void board()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                                     Tic Tac Toe\n\n");

    printf("                                                                            PEMAIN 1 (X)  -  PEMAIN 2 (O)\n\n\n");


    printf("                                                                                       |     |     \n");
    printf("                                                                                    %c  |  %c  |  %c \n", kotak[1], kotak[2], kotak[3]);

    printf("                                                                                  _____|_____|_____\n");
    printf("                                                                                       |     |     \n");

    printf("                                                                                    %c  |  %c  |  %c \n", kotak[4], kotak[5], kotak[6]);

    printf("                                                                                  _____|_____|_____\n");
    printf("                                                                                       |     |     \n");

    printf("                                                                                    %c  |  %c  |  %c \n", kotak[7], kotak[8], kotak[9]);

    printf("                                                                                       |     |     \n\n");
}

/*******************************************************************
END OF PROJECT
 ********************************************************************/