/* File queue_diner.c */

#include "queuedinerdash.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueueDiner(QueueDiner *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    // KAMUS LOKAL
    // ALGORITMA
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyDiner(QueueDiner q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    // KAMUS LOKAL
    // ALGORITMA
    return (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}

boolean isFullDiner(QueueDiner q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    // KAMUS LOKAL
    // ALGORITMA
    return (q.idxHead == 0 && q.idxTail == CAPACITY-1);
}

int lengthDiner(QueueDiner q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    // KAMUS LOKAL
    if (isEmptyDiner(q)) {
        return 0;
    } else if (q.idxTail >= q.idxHead) {
        return (q.idxTail - q.idxHead + 1);
    } else {
        return (CAPACITY - q.idxHead + q.idxTail + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueueDiner(QueueDiner *q, ElTypeDiner val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    // KAMUS LOKAL
    // ALGORITMA
    if (isEmptyDiner(*q)) {
        q->idxHead = 0;
        q->idxTail = 0;
    } else {
        q->idxTail = (q->idxTail + 1) % CAPACITY;
    }
    q->buffer[q->idxTail] = val;
}

void dequeueDiner(QueueDiner *q, ElTypeDiner *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    // KAMUS LOKAL
    // ALGORITMA
    *val = q->buffer[q->idxHead];
    if (q->idxHead == q->idxTail) {
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    } else {
        q->idxHead = (q->idxHead + 1) % CAPACITY;
    }
}

int SearchIdIn(QueueDiner q, int id){
    for (int i=0; i<lengthDiner(q); i++){
        if (q.buffer[(q.idxHead)+i%CAPACITY].idmakanan == id){
            return (q.idxHead)+i%CAPACITY;
        }
    }
    return IdxUndefDiner;
}