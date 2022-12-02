/* File array.h */
#include "../../boolean.h"

#ifndef ARRAY_DINER_H
#define ARRAY_DINER_H

/* Kamus Umum */

#define IdxMaxDiner 100
#define IdxMinDiner 0
#define IdxUndefDiner -1 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;

typedef struct {
    int idmakanan;
	int durasi;
	int ketahanan;
	int harga;
} ElTypeDiner;

typedef struct {
    ElTypeDiner TI [IdxMaxDiner-IdxMinDiner+1]; /* memori tempat penyimpan elemen (container) */
    int Neff; /* banyaknya elemen efektif */
} ArrayDiner;

/* Indeks yang digunakan [IdxMinDiner..IdxMaxDiner] */
/* Jika T adalah Array, cara deklarasi dan akses: */
/* Deklarasi : T : Array */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyDiner (ArrayDiner *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxDiner-IdxMinDiner+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtDiner (ArrayDiner T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElDiner (ArrayDiner T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdxDiner (ArrayDiner T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdxDiner (ArrayDiner T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
void SetNeffDiner (ArrayDiner *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidDiner (ArrayDiner T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEffDiner (ArrayDiner T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyDiner (ArrayDiner T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullDiner (ArrayDiner T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void AddEl(ArrayDiner *T, ElTypeDiner val);
// Menambahkan elemen baru dengan value val

void DelEl(ArrayDiner *T, ElTypeDiner *val, int x);
//Menghapus suatu elemen dalam array

int SearchIdArray(ArrayDiner T, int id);
//Mengembalikan indeks pada array T dengan id_makanan idx

#endif