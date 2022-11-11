#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void concat(char *string1, char *string2, char *string3)
{
    int i = 0;
    int j = 0;

    while (string1[i] != '\0') {
        string3[j] = string1[i];
        i++;
        j++;
    }

    i = 0;
    while (string2[i] != '\0') {
        string3[j] = string2[i];
        i++;
        j++;
    }
    string3[j] = '\0';
}

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        string[i] = currentWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
}

void STARTBNMO(ArrayDin *arraygame)
{
    char *temp;
    STARTWORD("../data/config.txt");
    ADVWORD();
    while (retval != MARK){
        temp = (char*) malloc (currentWord.Length *sizeof(char));
        wordToString(currentWord, temp);
        InsertLast(arraygame, temp);
        ADVWORD();  
    }
    temp = (char*) malloc (currentWord.Length *sizeof(char));
    wordToString(currentWord, temp);
    InsertLast(arraygame, temp);
    printf("\n\n");
    INDENT();
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void LOAD(ArrayDin *arraygame,char *filename)
{
    char *filedata = "../data/";
    char fileload[100];
    char *temp;
    concat(filedata, filename, fileload);
    STARTWORD(fileload);
    ADVWORD();
    while (retval != MARK){
        temp=(char*) malloc (currentWord.Length *sizeof(char));
        wordToString(currentWord, temp);
        InsertLast(arraygame, temp);
        ADVWORD();  
    }
    temp = (char*) malloc (currentWord.Length*sizeof(char));
    wordToString(currentWord, temp);
    InsertLast(arraygame, temp);

    printf("\n\n");
    INDENT();
    printf("    Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void CREATEGAME(ArrayDin *arraygame)
{
    INDENT();
    printf("Masukkan nama game yang akan ditambahkan : ");
    char *namagame = stringCommand();
    if (SearchArrayDin(*arraygame,namagame) == -1)
    {
        InsertLast(arraygame,namagame);
        printf("\n\n");
        INDENT();
        printf("                Game berhasil ditambahkan\n");
    }
    else
    {
        printf("\n\n");
        INDENT();
        printf("                    Game sudah tersedia.\n");
    }
}

void LISTGAME(ArrayDin arraygame)
{
    int i = 0;
    printf("\n\n");
    INDENT();
    printf("         Berikut adalah daftar game yang tersedia\n");
    for (i = 0; i < Length(arraygame); i++){
        INDENT();
        printf("        %d. %s\n", i + 1, arraygame.A[i]);
    }
}

void DELETEGAME(ArrayDin *arraygame, Queue qgame)
{
    LISTGAME(*arraygame);
    INDENT();
    printf("        Masukkan nomor game yang akan dihapus: ");
    intCommand();
    int i = ToInt(currentWord);
    if ((i > 0 && i <= 5)){
        printf("\n\n");
        INDENT();
        printf("                    Game gagal dihapus\n");
    }
    else if (isInQueue(qgame, arraygame->A[i - 1])){
        printf("\n\n");
        INDENT();
        printf("                 Game masih dalam antrean.\n");
        INDENT();
        printf("                    Game gagal dihapus.\n");
    }
    else{
        DeleteAt(arraygame, i-1);
        printf("\n\n");
        INDENT();
        printf("                  Game berhasil dihapus\n");
    }
}

void QUEUEGAME(ArrayDin *arraygame,Queue *qgame)
{
    if (isEmpty(*qgame)){
        printf("\n\n");
        INDENT();
        printf("                Antrean game masih kosong.\n");
    }
    else
    {
        INDENT();
        printf("            Berikut adalah daftar Game-mu\n");
        int i;

        displayQueue(*qgame);
    }
    LISTGAME(*arraygame);
    INDENT();
    printf("        Nomor game yang mau ditambahkan ke antrian : ");
    intCommand();
    int j = ToInt(currentWord);
    if (j > 0 && j <= Length(*arraygame)){
        enqueue(qgame, arraygame->A[j-1]);
        printf("\n\n");
        INDENT();
        printf("      Game berhasil ditambahkan kedalam daftar antrean.\n");
    }
    else{
        printf("\n\n");
        INDENT();
        printf("      Nomor permainan tidak valid, silahkan masuk nomor game pada list.\n");
    }

}

void QUIT()
{
    INDENT();
    printf("                Anda keluar dari game BNMO.\n");
    INDENT();
    printf("                      Bye bye ...\n");
    exit(0);
}


 void SKIPGAME(Queue *qgame, ArrayDin *arraygame, int n){
    if(isEmpty(*qgame))
    {
        INDENT();
        printf("\n        Tidak ada permainan dalam daftar antrian kamu.");
    } else if(n > CAPACITY || n == 0)
    {
        INDENT();
        printf("Tidak dapat melakukan skip sebanyak %d kali.\n", n);
        INDENT();
        printf("            Masukan tidak valid.\n");
    } else if(n < 0)
    {
        INDENT();
        printf("            Masukan tidak valid.\n");
    } else
    {
        ElType val;
        int i;
        for(i = 0; i < n; i++)
        {
            dequeue(qgame, &val);
        }
            printf("\n");
            INDENT();
            printf("              %d Permainan Berhasil Dilewati.\n",n);
            printf("\n");
            INDENT();
            printf("                Berikut Adalah Sisa Game-mu\n");
            displayQueue(*qgame);
            INDENT();
            printf("        ------------------------------------------\n");
    }
}
/*void SKIPGAME(Queue *qgame, int n)
{
    char *temp;
    printf("\n\n");
    INDENT();
    printf("              Berikut Adalah Daftar Game-mu :\n");
    displayQueue(*qgame);
    INDENT();
    printf("    -------------------------------------------------\n");
    while (!isEmpty(*qgame) && n > 0){
        dequeue(qgame,&temp);
        n -= 1;
    }
    if (isEmpty(*qgame)){
        INDENT();
        printf("                %d Permainan Berhasil Dilewati.\n",n);
        INDENT();
        printf("        Tidak Ada Permainan Lagi Dalam Daftar Game-mu.\n");
    }
    else if (n > CAPACITY || n == 0){
        printf("Tidak dapat melakukan skip sebanyak %d kali.\n", n);
        printf("Masukan tidak valid.\n");
    }
    else{
        printf("\n");
        INDENT();
        printf("              %d Permainan Berhasil Dilewati.\n",n);
        printf("\n");
        INDENT();
        printf("              Berikut Adalah Sisa Game-mu\n");
        displayQueue(*qgame);
        INDENT();
        printf("    -------------------------------------------------\n");
    }
}*/

void PLAYGAME(Queue *qgame,int *skor)
{
        ElType val;
        if (!isEmpty(*qgame)){
            printf("\n\n");
            INDENT();
            printf("        -----------------------------------------");
            INDENT();
            printf("              Berikut Adalah Daftar Game-mu :\n");
            int i;
    
            displayQueue(*qgame);
                INDENT();
                printf("        -----------------------------------------");
            if (compareSTR(HEAD(*qgame),"RNG")){
                dequeue(qgame, &val);
                NEXT();
                printf("\n\n");
                INDENT();
                printf("                     Game RNG dimulai!\n\n");
                RNG();
            }
            else if (compareSTR(HEAD(*qgame), "DINER DASH")){
                dequeue(qgame, &val);
                NEXT();
                printf("\n\n");
                INDENT();
                printf("                    Game DINER DASH dimulai!\n\n");
                DinerDash();
            }
            else if (compareSTR(HEAD(*qgame), "TIC TAC TOE")){
                dequeue(qgame, &val);
                NEXT();
                printf("\n\n");
                INDENT();
		char kotak[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
                printf("                    Game TIC TAC TOE dimulai!\n\n");
                TICTACTOE(kotak);
            }
            else if ((compareSTR(HEAD(*qgame), "DINOSAUR IN EARTH")) || (compareSTR(HEAD(*qgame), "RISEWOMAN")) || (compareSTR(HEAD(*qgame), "EIFFEL TOWER"))){
                printf("\n\n");
                INDENT();
                printf("      Game %s Masih Dalam Maintenance.\n", HEAD(*qgame));
                INDENT();
                printf("                Silahkan Pilih Game Lain.");
            }
            else {
                dequeue(qgame,&val);
                *skor += randomnumber(1,1000,1);
                printf("\n\n");
                INDENT();
                printf("      Selamat, Kamu Berhasil Memainkan Game %s.\n",val);
                printf("\n");
                INDENT();
                printf("              Skor Kamu Sekarang Adalah %d.\n",*skor);
            }
        }
        else{
            printf("\n\n");
            INDENT();
            printf("                    Antrean Game Kosong.\n");
        }
}

void SAVE(ArrayDin *arraygame,char* directory)
{
    char *filedata = "../data/";
    char tempatsimpen[100];
    FILE *filesave;
    int i;
    concat(filedata,directory,tempatsimpen);
    filesave = fopen(tempatsimpen, "w+");
    fprintf(filesave, "%d", Length(*arraygame));
    fprintf(filesave,"\n");
    
    for (i=0;i<Length(*arraygame);i++){
        char *p;
        p = arraygame -> A[i];
        while (*p != '\0'){
            fprintf(filesave, "%c", *p);
            p++;
        }
        if (i != Length(*arraygame) - 1){
            fprintf(filesave,"\n");
        }
    }
    fclose(filesave);
    printf("\n\n");
    INDENT();
    printf("              Save File Berhasil Disimpan.\n");
}

int randomnumber()
{
  int number;
  srand(time(0));
  number = (rand() % 100);
  return number;
}

int RNG()
{
  int number;
  number = randomnumber();
  boolean correct = false;
  int tries = 10;
  int score;
  while (correct == false && tries > 0)
  {
    INDENT();
    printf("                Tebaklah angka dari 0-100!\n");
    INDENT();
    printf("    -------------------------------------------------");
    INDENT();
    printf("    Anda mempunyai kesempatan menebak sebanyak %d kali \n", tries);
    INDENT();
    printf("    Masukkan tebakan Anda: ");
    intCommand();
	if (tries == 1){
		if (ToInt(currentWord) != number){
            INDENT();
			printf("        Maaf Anda kurang beruntung. Silakan coba lagi\n");
		}
		else{
			correct=true;
		}

	}
	else{
		if(ToInt(currentWord) > number)
    {
        printf("\n\n");
        INDENT();
        printf("    -------------------------------------------------\n");
        INDENT();
        printf("                        Lebih Kecil\n");
        INDENT();
        NEXT();
    }
    	else if (ToInt(currentWord) < number)
    {
        INDENT();
        printf("    -------------------------------------------------\n");
        INDENT();
        printf("                        Lebih Besar\n");
        INDENT();
        NEXT();
    }
    	else if (ToInt(currentWord) == number)
    {
      correct = true;
    }
	}
    
    tries--;
  }
  if (correct == true)
  {
    score = ((tries + 1) * 10);
    printf("\n\n");
    INDENT();
    printf("    -------------------------------------------------");
    INDENT();
    printf("                    Tebakan Anda benar!\n");
    INDENT();
    printf("                      Score Anda = %d", score);
    INDENT();
    printf("    -------------------------------------------------");
  }
  return score;
}


void HELP()
{
    printf("\n\n");
    printf("\n                                                ---------------------------------------------------------------------------------\n");
    printf("\n                                                | ================================== HELP ======================================|\n");
    printf("\n                                                | 1. START        - Memulai program Binomo.                                     |\n");
    printf("\n                                                | 2. LOAD         - Melanjutkan progress sebelumnya.                            |\n");
    printf("\n                                                | 3. SAVE         - Menyimpan progress.                                         |\n");
    printf("\n                                                | 4. CREATE GAME  - Menambah game baru pada daftar game.                        |\n");
    printf("\n                                                | 5. LIST GAME    - Menampilkan daftar game yang tersedia.                      |\n");
    printf("\n                                                | 6. DELETE GAME  - Menghapus game yang tersedia pada list.                     |\n");
    printf("\n                                                | 7. QUEUE GAME   - Menambah suatu game ke dalam antrean yang ingin dimainkan.  |\n");
    printf("\n                                                | 8. PLAY GAME    - Memulai permainan.                                          |\n");
    printf("\n                                                | 9. SKIPGAME <n> - Melewatkan permainan sebanyak <n>.                          |\n");            
    printf("\n                                                | 10. QUIT        - Keluar dari Binomo.                                         |\n");
    printf("\n                                                | 11. HELP        - Melihat command yang aktif.                                 |\n");
    printf("\n                                                ---------------------------------------------------------------------------------\n");
}

void NEXT()
{
    printf("\n");
    INDENT();
    printf("              Tekan ENTER untuk melanjutkan");
    char *bin = stringCommand();
    system("cls");
}

void INTERFACE()
{
printf("                                                                                                                      \n\n\n\n");
printf("                                                                                 .:::.:::::.                            \n");                
printf("                                                                       .:::.     ::::. ::::::     .::.                      \n");             
printf("                                                                .::::: :::::     ::::. ::::::     ::::.  :::.                   \n");          
printf("                                                          .:::..:::::: :::::.    ::::. ::::::.   :::::. .:::::::::..               \n");       
printf("                                                          :::::::::::: ::::::    ::::. :::::::   :::::. .:::::::::::.                 \n");    
printf("                                                          :::::  ::::: ::::::    ::::. :::::::  .:::::. .::::   :::::                    \n"); 
printf("                                                          :::::  ::::: :::::::   ::::. :::::::: ::::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: :::::::   ::::. :::::::: ::::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: :::::::   ::::. :::::::::::::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::::::  ::::. :::::::::::::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::::::  ::::. :::::::::::::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::::::. ::::. :::::.::::.::::. .::::   :::::                     \n");
printf("                                                          ::::: .::::: ::::::::: ::::. ::::: :::: ::::. .::::   :::::                     \n");
printf("                                                          :::::::::::  :::: :::: ::::. ::::: :::: ::::. .::::   :::::                     \n");
printf("                                                          ::::::::::   :::: :::::::::. ::::: .::. ::::. .::::   :::::                     \n");
printf("                                                          :::::.:::::: :::: :::::::::. :::::  ::  ::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::  ::::::::. :::::  ::  ::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::  ::::::::. :::::      ::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::  .:::::::. :::::      ::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::   :::::::. :::::      ::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::   :::::::. :::::      ::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::   .::::::. :::::      ::::. .::::   :::::                     \n");
printf("                                                          :::::  ::::: ::::    ::::::. :::::      ::::. .::::   :::::                     \n");
printf("                                                          :::::::::::: ::::    ::::::. :::::      ::::. .::::::::::::                     \n");
printf("                                                          .::::::::::: ::::     :::::. :::::      ::::. .:::::::::::.                     \n");
printf("                                                            .::::::::: ::::     :::::. :::::      ::::. .:::::::.                         \n");
printf("                                                                       ::::     :::::. :::::      ::::                                 \n");
printf("                                                                                 ::::. :::::                                             \n");
printf("\n                                                                           SELAMAT DATANG DI BINOMO!\n");
printf("                                                          ----------------------------------------------------------\n");
printf("                                                          |                      START or LOAD                     |\n");
printf("                                                          ----------------------------------------------------------\n");
}

void INDENT()
{
    printf("\n                                                          ");
}
