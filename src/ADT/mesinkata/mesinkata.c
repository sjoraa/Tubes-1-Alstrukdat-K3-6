#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"
#include "../mesinkarakter/mesinkarakter.c"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == ' ')
    {
        ADV();
    }
}

void STARTWORD(char *directory)
{
    START(directory);
    IgnoreBlanks();
    if (currentChar == '\n' || retval == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    // IgnoreBlanks();
    ADV();
    if (currentChar == '\n' || retval == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        // IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;
    // while ((currentChar != '.') && (currentChar != BLANK))
    while (retval != MARK && currentChar != '\n')
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.TabWord[i] = '\n';

    if (i > NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }
}

boolean isEndWord()
{
    return EndWord;
}


int ToInt(Word word)
/* Mengubah Kata berupa angka ke dalam bentuk integer */
{
    /*Kamus Lokal*/
    int result = 0;

    /*Algoritma*/
    if(word.Length == 1){
        result = (int)(word.TabWord[0]) - 48;
    } else {
        int pengali = 1;
        for(int i = (word.Length-1); i>=0; i--){
            result += ((int)(word.TabWord[i]) - 48) * pengali;
            pengali *= 10;
        }
    }
    return result;
}

void intCommand()
/* Membaca command dari terminal
I.S. : CC adalah karakter pertama kata yang akan diakuisisi dari terminal
F.S. : currentWord adalah hasil akuisisi command;
CC = ENTER; CC adalah karakter sesudah karakter terakhir yang diakuisisi*/
{
    /*Kamus Lokal*/
	int i = 0;

    /*Algoritma*/
	do {
		ADVCmd();
		currentWord.TabWord[i] = currentChar;
		i++;
	} while((currentChar != ENTER) && (i < NMax));
	currentWord.Length = i-1;
}

char* stringCommand(){
   pita = stdin;
   char* string;
   int a;
   int i = 0;
   string = (char*) malloc(101 * sizeof(char));

   while (a = fgetc(pita))
   {
      if (a == '\n')
      {
         break;
      }
      *(string + i) = (char)a;
      i++;
   }
   *(string + i) = '\0';
   return string;
}

void ADVCmd()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != ENTER
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK.
Jika  CC = MARK maka EOP akan menyala (true) */
{
    /* Algoritma */
    retval = scanf("%c",&currentChar);
}

boolean compareSTR(char input_command[], char command_comp[])
{
    int i = 0;
    while(input_command[i] == command_comp[i])
    {
        if(input_command[i] == '\0' || command_comp[i] == '\0')
        {
            break;
        }
        i++;
    }
    if(input_command[i] == '\0' && command_comp[i] == '\0')
    {
        return true;
    } else
    {
        return false;
    }
}

int countSpace(char *str){
    int i = 0;
    int count = 0;
    while(str[i] != '\0'){
        if(str[i] == ' '){
            count++;
        }
        i++;
    }
    return count;
}

char *firstString(char *command){
    char *first;
    int i = 0;
    int j = 0;
    first = (char*) malloc(101 * sizeof(char));
    while(command[i] != ' ' && command[i] != '\0'){
        first[j] = command[i];
        i++;
        j++;
    }
    first[j] = '\0';
    return first;
}

char *secondString(char *command){
    char *second;
    int i = 0;
    int j = 0;
    second = (char*) malloc(101 * sizeof(char));
    while(command[i] != ' '){
        i++;
    }
    i++;
    while(command[i] != '\0'){
        second[j] = command[i];
        i++;
        j++;
    }
    second[j] = '\0';
    return second;
}

boolean isNumber(char *str_int)
{
    if(countSpace(str_int) == 0)
    {
        return true;
    } else
    {
        false;
    }
}

int stringToInt(char *str){
    int i = 0;
    int result = 0;
     if(isNumber(str))
    {
        while(str[i] != '\0')
        {
            result = result * 10 + str[i] - '0';
            i++;
        }
        return result;
    }
    else
    {
        result = -9999;
        return result;
    }
}

int ToStr(){
    int i = 0;
    int result = 0;
    while(currentWord.TabWord[i] != '\0'){
        result = result * 10 + currentWord.TabWord[i] - '0';
        i++;
    }
    return result;
}