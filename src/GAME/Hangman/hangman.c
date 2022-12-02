#include <stdio.h>
#include "time.h"

/*INI FINAL*/

int panjangString(char *ptr)
{
    int pjg = 0;
    while (*ptr != '\0')
    {
        pjg += 1;
        ptr += 1;
    }

    return pjg;
}

void toUpper(char *ptr)
{
    while(*ptr != '\0')
    {
        if(*ptr <= 122 && *ptr >= 97)
        {
            *ptr -= 32;
        }
        ptr += 1;
    }
}

void PrintHangman(ArrayDin array)
{
    if (array.Neff == 0)
    {
        printf("[]\n");
    }
    else
    {
        IdxType i;
        for (i = 0; i < array.Neff - 1; i++)
        {
            printf("%s ", array.A[i]);
        }
        printf("%s \n", array.A[array.Neff - 1]);
    }
}

void wordToStringHangman(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        string[i] = currentWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
}

int randomnumberHangman(int batas)
{
  int number;
  srand(time(0));
  number = (rand() % batas);
  return number;
}

char* getWord(ArrayDin listKata)
{
    int x = randomnumberHangman(listKata.Neff);
    char *kata;
    kata = (char *) malloc (sizeof(char));
    kata = listKata.A[x];

    return kata;
}

char* charToString (char x)
{
    char* y;
    y = (char *) malloc (2 * sizeof(char));
    y[0] = x;
    y[1] = '\0';
    return y;
}

boolean isAlphabet(char string)
{
    if((string < 65 || (string > 90 && string < 97) || string > 122))
    {
        return false;
    }
    return true;
}

void NEXTHANGMAN()
{
    printf("\n");
    printf("                                                                           Tekan ENTER untuk melanjutkan");
    char *bin = stringCommand();
    system("cls");
}

int HANGMAN()
{
    /*MEMINDAHKAN DARI .TXT KE ARRAY*/
    ArrayDin listKata;
    listKata = MakeArrayDin();
    char directory[] = "./GAME/Hangman/hangman.txt";
    STARTWORD(directory);
    ADVWORD();
    while(retval != MARK)
    {
        char *Temp = (char *) malloc (15*sizeof(char));
        wordToStringHangman(currentWord, Temp);
        InsertLast(&listKata, Temp);
        ADVWORD();
    }
    char *Temp = (char *) malloc (15*sizeof(char));
    wordToStringHangman(currentWord, Temp);
    InsertLast(&listKata, Temp);

    /*MEMINTA INPUTAN AWAL GAME (START/ADD)*/ /*cat: belom dibuat validasi input*/
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                               WELCOME TO HANGMAN!\n");
    printf("                                                                                       MENU:\n");
    printf("                                                                    -----------------------------------------");
    printf("\n                                                                    |    1. START: Langsung bermain         |\n");
    printf("                                                                    |    2. ADD: Menambahkan kata sendiri   |\n");
    printf("                                                                    -----------------------------------------");
    printf("\n                                                                          MASUKKAN MENU : ");

    char *startHangman = (char *) malloc (15*sizeof(char));
    startHangman = stringCommand();
    toUpper(startHangman); /*MENGUBAH MENJADI HURUF KAPITAL*/

    while(compareSTR(startHangman, "START") == 0)
    {
        if (compareSTR(startHangman, "ADD"))
        {
            char* inputKata = (char *) malloc (15*sizeof(char));
            printf("\n                                                                    MASUKKAN KATA YANG INGIN DITAMBAH : ");
            inputKata = stringCommand();
            toUpper(inputKata); /*MENGUBAH MENJADI HURUF KAPITAL*/

            while (SearchArrayDin(listKata, inputKata) != -1)
            {
                printf("\n                                                  Kata tersebut sudah terdapat di dictionary. Silahkan masukkan kata lain.\n");
                printf("\n                                                                    MASUKKAN KATA YANG INGIN DITAMBAH : ");
                inputKata = stringCommand();
                toUpper(inputKata);
            }
            InsertLast(&listKata, inputKata);

            FILE* hangman;
            hangman = fopen(directory, "w+");
            fprintf(hangman, "%d", Length(listKata));
            fprintf(hangman,"\n");

            for (int i=0;i<Length(listKata);i++){
                char *p;
                p = listKata.A[i];
                while (*p != '\0'){
                    fprintf(hangman, "%c", *p);
                    p++;
                }
                if (i != Length(listKata) - 1){
                    fprintf(hangman,"\n");
                }
            }
            fclose(hangman);
                printf("\n                                                                            KATA BERHASIL DITAMBAHKAN!\n");
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                                       MENU:\n");
            printf("                                                                    -----------------------------------------");
            printf("\n                                                                    |    1. START: Langsung bermain         |\n");
            printf("                                                                    |    2. ADD: Menambahkan kata sendiri   |\n");
            printf("                                                                    -----------------------------------------");
            printf("\n                                                                          MASUKKAN MENU : ");
            startHangman = stringCommand();
            toUpper(startHangman); /*MENGUBAH MENJADI HURUF KAPITAL*/
        }
        else
        {
            printf("                                                                        MOHON MEMASUKKAN COMMAND YANG SESUAI\n\n");
            printf("                                                                                       MENU:\n");
            printf("                                                                    -----------------------------------------");
            printf("\n                                                                    |    1. START: Langsung bermain         |\n");
            printf("                                                                    |    2. ADD: Menambahkan kata sendiri   |\n");
            printf("                                                                    -----------------------------------------");
            printf("\n                                                                          MASUKKAN MENU : ");
            startHangman = stringCommand();
            toUpper(startHangman); /*MENGUBAH MENJADI HURUF KAPITAL*/
        }
    }

    /*INISIALISASI*/
    ArrayDin tebakan, temp;
    tebakan = MakeArrayDin();
    temp = MakeArrayDin();

    char *input;
    int score = 0;
    int kesempatan = 10;
    while (kesempatan > 0)
    {
        /*MEMULAI PERMAINAN*/
        char* kata = getWord(listKata);
        int length = panjangString(kata);

        for (int i = 0; i < length; i++)
        {
            InsertLast(&temp, "_");
        }
        system("cls");

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                                Tebakan sebelumnya: -\n\n");
        printf("                                                                                Kata : ");
        PrintHangman(temp);
        printf("\n\n                                                                                Kesempatan = %d\n", kesempatan);

        char *input;

        /*SELAMA BELUM KETEBAK*/
        int guessed = 0;
        while (guessed != length && kesempatan > 0)
        {
            input = (char *) malloc (sizeof(char));
            printf("\n                                                                              Masukkan tebakan: ");
            input = stringCommand();

            int test = 0; /*UNTUK MEMERIKSA APAKAH TEBAKAN BENAR*/

            /*MEMERIKSA APAKAH HURUF UPPER/LOWER-CASE SUDAH PERNAH DITEBAK SEBELUMNYA*/
            if(SearchArrayDin(tebakan, charToString(input[0])) == -1 && SearchArrayDin(tebakan, charToString(input[0] + 32)) == -1 && SearchArrayDin(tebakan, charToString(input[0] - 32)) == -1)
            {
                InsertLast(&tebakan, input);
                for(int j = 0; j < length; j++)
                {
                    if (panjangString(input) == 1)
                    {
                        if(kata[j] == input[0] || (kata[j] + 32) == input[0])
                        {
                            DeleteAt(&temp, j);
                            InsertAt(&temp, charToString(kata[j]), j);
                            guessed++;
                            test = 1;
                        }
                    }
                }

                /*JIKA HURUF YANG DIINPUT SALAH*/
                if (test != 1)
                {
                    kesempatan--;
                }
                
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                            Tebakan sebelumnya : ");
                PrintHangman(tebakan);
                printf("\n                                                                                Kata : ");
                PrintHangman(temp);
                printf("\n                                                                                 Kesempatan = %d\n", kesempatan);
            }
            else /*SUDAH DITEBAK SEBELUMNYA*/
            {
                printf("\n                                                            Kamu sudah pernah menebak huruf %s. Silahkan tebak huruf lain.\n", input);
            }
            if (guessed==length){
                score += length;
                printf("\n                                                            Berhasil menebak kata %s! Kamu mendapatkan %d poin!\n", kata, length);
                NEXTHANGMAN();
            }
        }

        //reset
        while (IsEmpty(temp) == 0)
        {
            DeleteLast(&temp);
        }

        while (IsEmpty(tebakan) == 0)
        {
            DeleteLast(&tebakan);
        }
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                                 GAME OVER\n");
    printf("\n                                                                             Tekan ENTER untuk melanjutkan...");
    char *bin=stringCommand();
    printf("                                                                              Final Score : %d\n", score);
    return score;
}