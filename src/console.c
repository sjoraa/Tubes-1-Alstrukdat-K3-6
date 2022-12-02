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

void pisahskor(char *key,int *value,Word currentWord){
    int i=0;
    int j;
    char temp[10];
    while (currentWord.TabWord[i]!=' '){
        key[i] = currentWord.TabWord[i];
        i++;
    }
    key[i] = '\0';
    
    i++;
    j=0;
    while (i<currentWord.Length){
        temp[j]=currentWord.TabWord[i];
        i++;
        j++;
    }
    temp[i]='\0';
    *value=atoi(temp);


}

void STARTBNMO(ArrayDin *arraygame,scoreboard *Mapgame)
{
    char *temp;
    int i=0;
    STARTWORD("../data/config.txt");
    ADVWORD();
    while (retval != MARK){
        temp = (char*) malloc (currentWord.Length *sizeof(char));
        wordToString(currentWord, temp);
        InsertLast(arraygame, temp);
        Mapgame->listmap[i].namagame=temp;
        CreateEmptyMap(&(Mapgame->listmap[i].mapscoreboard));
        Mapgame->lengthscoreboard++;
        ADVWORD();
        i++;  
    }
    temp = (char*) malloc (currentWord.Length *sizeof(char));
    wordToString(currentWord, temp);
    InsertLast(arraygame, temp);
    Mapgame->listmap[i].namagame=temp;
    CreateEmptyMap(&(Mapgame->listmap[i].mapscoreboard));
    Mapgame->lengthscoreboard++;

    printf("\n\n");
    INDENT();
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}

void LOAD(ArrayDin *arraygame,char *filename,Stack *history,scoreboard *Mapgame)
{
    char *filedata = "../data/";
    char fileload[100];
    char *temp;
    char *key;
    int jumlahgame,jumlahhistory,jumlahscoreboard,value;
    concat(filedata, filename, fileload);
    FILE *cekfile=fopen(fileload,"r");
    if (cekfile==NULL){
        printf("\n\n");
        INDENT();
        printf("                    File tidak ditemukan.\n");
    }
    else{
        STARTWORD(fileload);
        temp=(char*) malloc (currentWord.Length *sizeof(char));
        wordToString(currentWord,temp);
        jumlahgame=atoi(temp);
        for (int i=0;i<jumlahgame;i++){
            ADVWORD();
            temp=(char*) malloc (currentWord.Length *sizeof(char));
            wordToString(currentWord, temp);
            InsertLast(arraygame, temp);
        }
        
        ADVWORD();
        temp=(char*) malloc (currentWord.Length *sizeof(char));
        wordToString(currentWord,temp);
        jumlahhistory=atoi(temp);
        
        for (int i=0;i<jumlahhistory;i++){
            ADVWORD();
            temp=(char*) malloc (currentWord.Length *sizeof(char));
            wordToString(currentWord, temp);
            push(history,temp);
        }

        ADVWORD();

        for(int i=0;i<jumlahgame;i++){
            temp=(char*) malloc (currentWord.Length *sizeof(char));
            wordToString(currentWord,temp);
            jumlahscoreboard=atoi(temp);
            Mapgame->listmap[i].namagame=arraygame->A[i];
            CreateEmptyMap(&(Mapgame->listmap[i].mapscoreboard));
            Mapgame->lengthscoreboard++;


            for (int j=0;j<jumlahscoreboard;j++){
                ADVWORD();
                key=(char*) malloc (currentWord.Length *sizeof(char));

                pisahskor(key,&value,currentWord);
                InsertMap(&(Mapgame->listmap[i].mapscoreboard),key,value);
            }
            ADVWORD();
        }
        printf("\n\n");
        INDENT();
        printf("    Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}

void CREATEGAME(ArrayDin *arraygame,scoreboard *Mapgame)
{
    INDENT();
    printf("Masukkan nama game yang akan ditambahkan : ");
    char *gamenama = stringCommand();
    if (SearchArrayDin(*arraygame,gamenama) == -1)
    {
        InsertLast(arraygame,gamenama);
        Mapgame->listmap[Mapgame->lengthscoreboard].namagame=gamenama;
        CreateEmptyMap(&(Mapgame->listmap[Mapgame->lengthscoreboard].mapscoreboard));
        Mapgame->lengthscoreboard++;
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

void DELETEGAME(ArrayDin *arraygame, Queue qgame,scoreboard *Mapgame)
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
        DeleteAtScoreboard(Mapgame,i-1);
        
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

void HISTORY(Stack *historygame,int n){
    int nomer=1;
    ElTypeStack val;
    Stack stemp;
    CreateStack(&stemp);
    if (IsEmptyStack(*historygame)){
        INDENT();
        printf("                     History Kosong.");
    }
    if (n>lengthstack(*historygame)){
        n=lengthstack(*historygame);
    }

    for (int i=0;i<n;i++){
        pop(historygame,&val);
        push(&stemp,val);
        printf("\n                                                                    %d. %s\n",nomer,val);
        nomer++;
    }
    while (!IsEmptyStack(stemp)){
        pop(&stemp,&val);
        push(historygame,val);
    }
}

void RESETHISTORY(Stack *historygame){
    ElTypeStack bin;
    while (!IsEmptyStack(*historygame)){
        pop(historygame,&bin);
    }
    INDENT();
    printf("                History berhasil di-reset\n");
}

void PLAYGAME(Queue *qgame,int *skor,Stack *history,scoreboard *Mapgame)
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
                char *namauser;
                dequeue(qgame, &val);
                NEXT();
                printf("\n\n");
                INDENT();
                printf("                     Game RNG dimulai!\n\n");
                *skor = RNG();
                SAVESCOREBOARD(namauser, Mapgame, *skor, val);
            }
            else if (compareSTR(HEAD(*qgame), "DINER DASH")){
                char *namauser;
                dequeue(qgame, &val);
                NEXT();
                printf("\n\n");
                INDENT();
                printf("                    Game DINER DASH dimulai!\n\n");
                DinerDash(skor);
                SAVESCOREBOARD(namauser, Mapgame, *skor, val);
            }
            else if (compareSTR(HEAD(*qgame), "TIC TAC TOE")){
                int skor1, skor2;
                char * player1, * player2;
                dequeue(qgame, &val);
                NEXT();
                printf("\n\n");
                INDENT();
		        char kotak[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
                printf("                    Game TIC TAC TOE dimulai!\n\n");
                TICTACTOE(kotak, &skor1, &skor2);
                SAVESCOREBOARD(player1, Mapgame, skor1, val);
                SAVESCOREBOARD(player2, Mapgame, skor2, val);
            }
            else if (compareSTR(HEAD(*qgame), "HANGMAN")){
                dequeue(qgame, &val);
                NEXT();
                char * namauser;
                printf("\n\n");
                *skor = HANGMAN();
                SAVESCOREBOARD(namauser, Mapgame, *skor, val);
            }
            else if (compareSTR(HEAD(*qgame), "TOWER OF HANOI")){
                dequeue(qgame, &val);
                NEXT();
                char * namauser;
                printf("\n\n");
                INDENT();
                printf("                  Game TOWER OF HANOI dimulai!\n\n");
                *skor = TOWEROFHANOI();
                char * bin = stringCommand();
                SAVESCOREBOARD(namauser, Mapgame, *skor, val);
            }
            else if (compareSTR(HEAD(*qgame), "SNAKE ON METEOR")){
                dequeue(qgame, &val);
                NEXT();
                char *namauser;
                printf("\n\n");
                INDENT();
                printf("                Game SNAKE ON METEOR dimulai!\n\n");
                SNAKEONMETEOR(skor);
                SAVESCOREBOARD(namauser, Mapgame, *skor, val);
            }
            else {
                char * namauser;
                dequeue(qgame,&val);
                *skor += randomnumber(1,1000,1);
                printf("\n\n");
                INDENT();
                printf("      Selamat, Kamu Berhasil Memainkan Game %s.\n",val);
                printf("\n");
                INDENT();
                printf("              Skor Kamu Sekarang Adalah %d.\n",*skor);
                SAVESCOREBOARD(namauser, Mapgame, *skor, val);
            }
            push(history,val);
        }
        else{
            printf("\n\n");
            INDENT();
            printf("                    Antrean Game Kosong.\n");
        }
}

void SAVE(ArrayDin *arraygame,char* directory,scoreboard Mapgame,Stack history)
{
    char *filedata = "../data/";
    char tempatsimpen[100];
    FILE *filesave;
    int i;
    ElType temp;
    Stack stemp;
    CreateStack(&stemp);

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
    fprintf(filesave,"\n%d\n",history.idxTop+1);
    while (!IsEmptyStack(history)){
        pop(&history,&temp);
        push(&stemp,temp);
        fprintf(filesave,"%s\n",temp);
    }
    while (!IsEmptyStack(stemp)){
        pop(&stemp,&temp);
        push(&history,temp);
    }
    for(i=0;i<Mapgame.lengthscoreboard;i++){
        fprintf(filesave,"%d\n",Mapgame.listmap[i].mapscoreboard.Count);
        for(int j=0;j<Mapgame.listmap[i].mapscoreboard.Count;j++){
            fprintf(filesave,"%s %d\n",Mapgame.listmap[i].mapscoreboard.Elements[j].Key,Mapgame.listmap[i].mapscoreboard.Elements[j].Value);
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
    printf("\n                                             ---------------------------------------------------------------------------------------\n");
    printf("                                             | ======================================= HELP =======================================|\n");
    printf("\n                                             | 1. START              - Memulai program Binomo.                                     |\n");
    printf("\n                                             | 2. LOAD               - Melanjutkan progress sebelumnya.                            |\n");
    printf("\n                                             | 3. SAVE               - Menyimpan progress.                                         |\n");
    printf("\n                                             | 4. CREATE GAME        - Menambah game baru pada daftar game.                        |\n");
    printf("\n                                             | 5. LIST GAME          - Menampilkan daftar game yang tersedia.                      |\n");
    printf("\n                                             | 6. DELETE GAME        - Menghapus game yang tersedia pada list.                     |\n");
    printf("\n                                             | 7. QUEUE GAME         - Menambah suatu game ke dalam antrean yang ingin dimainkan.  |\n");
    printf("\n                                             | 8. PLAY GAME          - Memulai permainan.                                          |\n");
    printf("\n                                             | 9. SKIPGAME <n>       - Melewatkan permainan sebanyak <n>.                          |\n");
    printf("\n                                             | 10. HISTORY <n>       - Menampilkan daftar game yang telah dimainkan sebanyak <n>.  |\n");   
    printf("\n                                             | 11. RESET HISTORY     - Menghapus daftar permainan yang telah dimainkan.            |\n");         
    printf("\n                                             | 12. SCOREBOARD        - Menampilkan daftar skor dari game yang telah dimainkan.     |\n");
    printf("\n                                             | 13. RESET SCOREBOARD  - Menghapus daftar skor.                                      |\n");
    printf("\n                                             | 14. QUIT              - Keluar dari Binomo.                                         |\n");
    printf("\n                                             | 15. HELP              - Melihat command yang aktif.                                 |\n");
    printf("                                             ---------------------------------------------------------------------------------------\n");
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

void SAVESCOREBOARD(char* namauser, scoreboard *Mapgame, int skor,char *game){
    boolean found=false;
    int i=0;
    while (!found){
        if (compareSTR(Mapgame->listmap[i].namagame,game)){
            found=true;
        }
        i++;
    }
    i-=1;
    INDENT();
    printf("                    Nama : ");
    namauser = stringCommand();
    while (IsMemberMap(Mapgame->listmap[i].mapscoreboard,namauser)){
        INDENT();
        printf("                    User sudah ada.\n");
        INDENT();
        printf("         Masukkan nama user yang lain: ");
        namauser = stringCommand();
    }
    InsertMap(&Mapgame->listmap[i].mapscoreboard,namauser,skor);
    INDENT();
    printf("\n                                                                         Berhasil Menyimpan Score!\n");
    /*if (!IsMemberMap(Mapgame->listmap[i].mapscoreboard,namauser)){
        InsertMap(&(Mapgame->listmap[i].mapscoreboard),namauser,skor);
        printf("\n                                                                         Berhasil Menyimpan Score!\n");
    }
    else{
        INDENT();
        printf("                        User sudah ada.\n");
    }*/
}

void PRINTSCOREBOARD(scoreboard Mapgame){
    printf("\n\n\n");
    for (int i=0;i<Mapgame.lengthscoreboard;i++){
        printf("\n\n                                                                    ----- SCOREBOARD GAME %s-----\n",Mapgame.listmap[i].namagame);
        if (IsEmptyMap(Mapgame.listmap[i].mapscoreboard)){
            printf("                                                                ---------------------------------------------");
            printf("\n                                                                |           SCOREBOARD MASIH KOSONG         |");
            printf("\n                                                                ---------------------------------------------");
        }
        else{
            printmap(Mapgame.listmap[i].mapscoreboard);
        }
    }
    NEXT();
}

void RESETSCOREBOARD(scoreboard *Mapgame){
    int nomor=0;
    INDENT();
    printf("                    DAFTAR SCOREBOARD:\n");
    INDENT();
    printf("          %d. ALL\n",nomor);
    nomor++;
    for (int i=0;i<Mapgame->lengthscoreboard;i++){
        printf("\n                                                                    %d. %s\n",nomor,Mapgame->listmap[i].namagame);
        nomor++;
    }
    INDENT();
    printf("              SCOREBOARD YANG INGIN DIHAPUS: ");
    char *hapus = stringCommand();
    int n = stringToInt(hapus);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    INDENT();
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK) ",Mapgame->listmap[n].namagame);
    char *konfirmasi = stringCommand();
    if (compareSTR(konfirmasi, "YA")){
        if (n == 0){
            for(int i=0;i<Mapgame->lengthscoreboard;i++){
                CreateEmptyMap(&(Mapgame->listmap[i].mapscoreboard));
            }
        }
        else if (n > 0 && n <= Mapgame->lengthscoreboard){
            CreateEmptyMap(&(Mapgame->listmap[n-1].mapscoreboard));
        }
        else{
            INDENT();
            printf("                    Input invalid\n");
        }
        INDENT();
        printf("                  SKOR BERHASIL DI-RESET\n");
        NEXT();
    }
    else if (compareSTR(konfirmasi, "TIDAK")){
        INDENT();
        printf("Scoreboard tidak jadi di-reset. Berikut adalah daftar Scoreboard-mu :\n");
        PRINTSCOREBOARD(*Mapgame);
    }
    else {
        INDENT();
        printf("        Command tidak dikenali. Silakan coba lagi.\n");
        NEXT();
    }
}