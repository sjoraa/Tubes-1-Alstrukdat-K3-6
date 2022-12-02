#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dinerdash.h"

int randomnumberdinerdash(int min, int max)
{
  int number;
  number = (rand() % (max-min)) + min;
  return number;
}

int foodID(char *x){
    if (x[0]=='M'){
        if (x[1]!='\0'){
        int i=1;
        int hitung = 0;
        while (x[i]!= '\0'){
            hitung *= 10;
            hitung += x[i] - '0';
            i++;
        }
        return hitung;}
    }
    return IdxUndefDiner;
}

void putaran(int *id, QueueDiner *pesanan, ArrayDiner *masak, ArrayDiner *saji){
    int durasi, ketahanan, harga;
    int lbDurasi = 1, upDurasi = 5, lbHarga = 10, upHarga = 50;
    ElTypeDiner val;
    int n;

    (*id)++;

    val.idmakanan = *id;
    val.durasi = randomnumberdinerdash(lbDurasi, upDurasi);
    val.ketahanan = randomnumberdinerdash(lbDurasi, upDurasi);
    val.harga = randomnumberdinerdash(lbHarga, upHarga) * 1000;

    enqueueDiner(pesanan, val);


    n = NbElmtDiner(*saji);
    for (int i=0; i< NbElmtDiner(*saji); i++){
        saji->TI[i].ketahanan --;
        if (saji->TI[i].ketahanan == 0) {
            DelEl(saji, &val, i);
            i--; 
            n--;
            }
    }

    n = NbElmtDiner(*masak);

    for (int i=0; i< n; i++){
        masak->TI[i].durasi --;
        if (masak->TI[i].durasi == 0) {

                DelEl(masak, &val, i);
                AddEl(saji, val);

                i--;
                n--;

                int m = val.idmakanan;
                printf("                                                                            Makanan M%d telah selesai dimasak\n\n", m);
            }
    }
}

void displayQueueDiner(QueueDiner pesanan, ArrayDiner masak, ArrayDiner saji, int* saldo) {
    int i;
    printf("                                                                    SALDO: %d\n\n                                                                                     Daftar Pesanan\n\n", *saldo);
    printf("                                                                    ------------------------------------------------\n");
    printf("                                                                    | Makanan | Durasi memasak | Ketahanan | Harga |\n");
    printf("                                                                    ------------------------------------------------\n");
    for (i = 0; i < lengthDiner(pesanan); i++) {
        int j = pesanan.idxHead+i % CAPACITY;

        printf("                                                                    |    M%d   |        %d       |     %d     | %d |\n", pesanan.buffer[j].idmakanan, pesanan.buffer[j].durasi, pesanan.buffer[j].ketahanan, pesanan.buffer[j].harga);
    }
    printf("                                                                    ------------------------------------------------\n");
    printf("\n\n");
    printf("                                                                           Daftar Makanan yang sedang dimasak\n");
    printf("                                                                           ---------------------------------\n");
    printf("                                                                           | Makanan | Sisa durasi memasak |\n");
    printf("                                                                           ---------------------------------\n");
    
    if (IsEmptyDiner(masak)){
        printf("                                                                           |         |                     |\n");
        printf("                                                                           ---------------------------------\n");
    }
    else {
        for (i = 0; i < NbElmtDiner(masak); i++) {
    
            printf("                                                                           |   M%d    |          %d          |\n", masak.TI[i].idmakanan, masak.TI[i].durasi);
        }
        printf("                                                                           ---------------------------------\n");
    }
    printf("\n\n");
    printf("                                                                           Daftar Makanan yang dapat disajikan\n");
    printf("                                                                          ------------------------------------\n");
    printf("                                                                          | Makanan | Sisa ketahanan makanan |\n");
    printf("                                                                          ------------------------------------\n");
    if (IsEmptyDiner(saji)){ 
    printf("                                                                          |         |                        |\n");
    printf("                                                                          ------------------------------------\n");
    }
    else {
        for (i = 0; i < NbElmtDiner(saji); i++) {
    
            printf("                                                                          |    M%d   |           %d            |\n", saji.TI[i].idmakanan, saji.TI[i].ketahanan);
        }
        printf("                                                                          ------------------------------------\n");
    }
}

void DinerDash(int *skor) {
    /* KAMUS LOKAL */
    QueueDiner pesanan;
    ArrayDiner masak, saji;
    int saldo = 0, serve = 0, idpesanan = 0;
    ElTypeDiner val;
    int i, j, idx;
    int lbDurasi = 1, upDurasi = 5, lbHarga = 10, upHarga = 50;
    int durasi, ketahanan, harga;
    char* perintah, *makanan, *command;

    boolean cook;
    /* ALGORITMA */
    CreateQueueDiner(&pesanan);
    MakeEmptyDiner(&masak);
    MakeEmptyDiner(&saji);

    INDENTDINERDASH();
    printf("                  Selamat Datang di Diner Dash!\n\n");
    
    for (i = 0; i < 3; i++) {
        idpesanan = i;
        val.idmakanan = idpesanan;
        val.durasi = randomnumberdinerdash(lbDurasi, upDurasi);
        val.ketahanan = randomnumberdinerdash(lbDurasi, upDurasi);
        val.harga = randomnumberdinerdash(lbHarga, upHarga) * 1000;

        enqueueDiner(&pesanan, val);
    }

    while (lengthDiner(pesanan) <= 7 && serve < 15) {
        displayQueueDiner(pesanan, masak, saji, &saldo);
        INDENTDINERDASH();     
        printf("          ENTER COMMAND: ");

        command = stringCommand();
        perintah = firstString(command);
        makanan = secondString(command);
        idx = foodID(makanan);
        
        while ((!compareSTR(perintah, "COOK") || SearchIdIn(pesanan, idx)==IdxUndefDiner) && (!compareSTR(perintah, "SERVE") || SearchIdArray(saji, idx)==IdxUndefDiner || idx!=pesanan.buffer[pesanan.idxHead].idmakanan) && (!compareSTR(perintah, "SKIP"))){
            if (compareSTR(perintah, "SERVE") && idx!=pesanan.buffer[pesanan.idxHead].idmakanan){
                INDENTDINERDASH();
                printf("        %s belum dapat disajikan karena M%d belum selesai\n\n", makanan, pesanan.buffer[pesanan.idxHead].idmakanan);}
            else{
                INDENTDINERDASH();
                printf("                Masukan tidak valid. Silahkan coba lagi.\n\n");}
                INDENTDINERDASH();
                printf("          ENTER COMMAND: ");

                command = stringCommand();
                perintah = firstString(command);
                makanan = secondString(command);
                idx = foodID(makanan);
        }
        system("cls");

        if (compareSTR(perintah, "COOK")) {
                AddEl(&masak, pesanan.buffer[SearchIdIn(pesanan, idx)]); 
                masak.TI[SearchIdArray(masak, idx)].durasi ++;  
                printf("\n\n");
                INDENTDINERDASH();   
                printf("                    Berhasil memasak %s\n\n", makanan);                         
        }


        else if (compareSTR(perintah, "SERVE")) {
            DelEl(&saji, &val, SearchIdArray(saji, idx));
            printf("\n\n");
            INDENTDINERDASH();
            printf("                    Berhasil mengantar %s\n\n", makanan);
            serve++;
            saldo += val.harga;
            dequeueDiner(&pesanan, &val);            
        }

        else if (compareSTR(perintah, "SKIP")){
            printf("\n\n");
            INDENTDINERDASH();
            printf("                        Skip berhasil\n");
        }
        putaran(&idpesanan, &pesanan, &masak, &saji);
        INDENTDINERDASH();
        printf("          ================================================\n\n");
    }
    INDENTDINERDASH();
    printf("                        GAME OVER!!!\n\n                                                            Skor akhir: %d\n\n", saldo);
    *skor = saldo;
}

void INDENTDINERDASH()
{
    printf("\n                                                          ");
}