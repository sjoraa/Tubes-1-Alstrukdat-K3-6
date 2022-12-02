#ifndef mapsnake_H
#define mapsnake_H
#include <stdio.h>
#include "boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define MaxElSNAKE 25

// typedef int bool;
typedef int keytypeSNAKE;
typedef char* valuetypeSNAKE;

typedef struct
{
	keytypeSNAKE Key;
	valuetypeSNAKE Value;
} infotypeSNAKE;

typedef struct
{
	infotypeSNAKE Elements[MaxElSNAKE];
	int Count;
} MapSNAKE;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMapSNAKE(MapSNAKE *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElSNAKE */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMapSNAKE(MapSNAKE M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullSNAKE(MapSNAKE M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElSNAKE */

/* ********** Operator Dasar Map ********* */
valuetypeSNAKE ValueSNAKE(MapSNAKE M, keytypeSNAKE k);
/* Mengembalikan nilai value dengan key k dari M */

void InsertSNAKE(MapSNAKE *M, keytypeSNAKE k, valuetypeSNAKE v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteSNAKE(MapSNAKE *M, keytypeSNAKE k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberSNAKE(MapSNAKE M, keytypeSNAKE k);
/* Mengembalikan true jika k adalah member dari M */

#endif