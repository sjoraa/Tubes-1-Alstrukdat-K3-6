#include "map.h"

void CreateEmptyMap(Map *M){
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
    return(M.Count == Nil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M){
    return(M.Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k){
    if(IsMemberMap(M,k)){
        int i = 0;
        while(!compareSTR(M.Elements[i].Key,k)){
            i++;
        }
        return(M.Elements[i].Value);
    }
    else{
        return(Undefined);
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v){
    if(IsEmptyMap(*M)){
        (*M).Elements[0].Key = k;
        (*M).Elements[0].Value = v;
        (*M).Count = 1;
    }
    else{
        if(!IsMemberMap((*M),k)){
            int i = 0;
            while(i != ((*M).Count)){
                i++;
            }
            (*M).Elements[i].Key = k;
            (*M).Elements[i].Value = v;
            (*M).Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k){
    if(IsMemberMap((*M),k)){
        int i = 0;
        while(i != ((*M).Count-1) && (*M).Elements[i].Key != k){
            i++;
        }
        int idxtemp;
        idxtemp = i;
        for(idxtemp ; idxtemp <= (*M).Count-1 ; idxtemp++){
            (*M).Elements[idxtemp] = (*M).Elements[idxtemp+1];
        }
        (*M).Elements[(*M).Count-1].Key = '\0';
        (*M).Elements[(*M).Count-1].Value = Undefined;
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k){
	int i;
	i = 0;
	boolean found;
	found = false;
	while (i < M.Count && found == false)
	{
		if (compareSTR(M.Elements[i].Key,k))
		{
			found = true;
		}
		i++;
	}
	return found;
}
/* Mengembalikan true jika k adalah member dari M */

int IMAX (Map *map){
    int imax;
    imax = 0;
    for (int i = 1 ; i<map->Count ; i++){
        if (map->Elements[i].Value > map->Elements[imax].Value){
            imax = i;
        }
    }
    return imax;
}

Map CopyMap (Map *map){
    Map temp;
    CreateEmptyMap(&temp);
    for (int i = 0;i<map->Count;i++){
        InsertMap(&temp,map->Elements[i].Key,map->Elements[i].Value);
    }
    return temp;
}

void printmap(Map M){
        printf("                                                                ---------------------------------------------");
        printf("\n                                                                |          NAMA          |       SKOR       |");
        printf("\n                                                                ---------------------------------------------");
        for (int i=0;i<M.Count;i++){
            printf("\n                                                                |          %s          |        %d        |",M.Elements[i].Key,M.Elements[i].Value);
        }
            printf("\n                                                                ---------------------------------------------\n");
}

void DeleteAtScoreboard(scoreboard *Mapgame, int i)
{
    int temp = i;
    while (temp < Mapgame->lengthscoreboard - 1)
    {
        Mapgame->listmap[temp] = Mapgame->listmap[temp + 1];
        temp++;
    }

    if (Mapgame->lengthscoreboard > 1)
    {
        Mapgame->lengthscoreboard--;
    }
    else
    {
        Mapgame->lengthscoreboard = 0;
    }
}