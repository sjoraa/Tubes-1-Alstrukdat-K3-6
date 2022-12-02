#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "boolean.h"
#include "listsnake.c"
#include "mapsnake.c"

typedef struct { 
    int x;
    int y;
} Item;
/*x = kolom, y = baris sehingga koordinat= (x,y)*/

void wipeMap (MapSNAKE *M)/*Menghapus isi map*/
{
    for (int i = 0; i < 25; i++)
    {
        M->Elements[i].Value = " ";
    }
}

void insertToMap (MapSNAKE *M, int x, int y, char *a)/*Memasukkan ke dalam map sesuai koordinat*/
{
    int i=0, k = x+y*5;
    boolean found = false;
    while (i < M->Count && found == false)
    {
        if (M->Elements[i].Key == k) 
        {
            M->Elements[i].Value = a;
            found = true;
        }
        else
        {
            i += 1;
        }
    }
}

void fillMap(MapSNAKE *M, Item H, ListSNAKE *body, int length, Item Z, Item m, Item O)
/*Mengisi map
Map pertama diisi makanan disimpan O,
kepala disimpan H, jika kepala makan yang disimpan adalah H bukan O, 
kepala disimpan Z, jika kepala menabrak obstacle yang disimpan adalah Z bukan H,
badan disimpan mulai dari 1 sampai akhir di tail,
terakhir meteor disimpan m, jika meteor mengenai kepala atau badan yang disimpan adalah m bukan H atau angka(badan)*/
{
    insertToMap(M, O.x, O.y, "O");
    insertToMap(M, H.x, H.y, "H");
    insertToMap(M, Z.x, Z.y, "Z");
    
    if (!IsEmptyListSNAKE(*body))
    {
        char *arr[24] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", 
        "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24"};
        addressSNAKE P = body->Tail;
        int i = length-2;
        while (P->next!=Nil)
        {
            insertToMap(M, P->x, P->y, arr[i]);
            P = P->next;
            i -= 1;
        }
        insertToMap(M, P->x, P->y, arr[i]);
    }

    insertToMap(M, m.x, m.y, "m");
}

void printMap (MapSNAKE *M)/*Cetak Map*/
{
    printf("                                                                      Berikut merupakan peta permainan\n");
    printf("                                                                         ==========================\n");
    printf("                                                                         | %s | %s | %s | %s | %s |\n", ValueSNAKE(*M,0), ValueSNAKE(*M,1), ValueSNAKE(*M,2), ValueSNAKE(*M,3), ValueSNAKE(*M,4));
    printf("                                                                         ==========================\n");
    printf("                                                                         | %s | %s | %s | %s | %s |\n", ValueSNAKE(*M,5), ValueSNAKE(*M,6), ValueSNAKE(*M,7), ValueSNAKE(*M,8), ValueSNAKE(*M,9));
    printf("                                                                         ==========================\n");
    printf("                                                                         | %s | %s | %s | %s | %s |\n", ValueSNAKE(*M,10), ValueSNAKE(*M,11), ValueSNAKE(*M,12), ValueSNAKE(*M,13), ValueSNAKE(*M,14));
    printf("                                                                         ==========================\n");
    printf("                                                                         | %s | %s | %s | %s | %s |\n", ValueSNAKE(*M,15), ValueSNAKE(*M,16), ValueSNAKE(*M,17), ValueSNAKE(*M,18), ValueSNAKE(*M,19));
    printf("                                                                         ==========================\n");
    printf("                                                                         | %s | %s | %s | %s | %s |\n", ValueSNAKE(*M,20), ValueSNAKE(*M,21), ValueSNAKE(*M,22), ValueSNAKE(*M,23), ValueSNAKE(*M,24));
    printf("                                                                         ==========================\n");
}

int posisikepala (char *c, Item H)/*Posisi kepala setelah input command*/
{
    int pos;
    if (compareSTR(c,"w"))
    {
        pos = (H.x+((H.y+4)%5)*5);
    }
    else if (compareSTR(c,"a"))
    {
        pos = (((H.x+4)%5)+H.y*5);
    }
    else if (compareSTR(c,"s"))
    {
        pos = (H.x+((H.y+1)%5)*5);
    }
    else if (compareSTR(c,"d"))
    {
        pos = (((H.x+1)%5)+H.y*5);
    }
    else{
        pos = -999;
    }
    return pos;
}

boolean meteorpanas (int poskepala, Item m)/*Kepala bergerak ke arah meteor*/
{
    boolean panas = false;
    if (m.x==-1 || m.y==-1){}
    else
    {
        if (poskepala == (m.x+m.y*5))
            {
                panas = true;
            }
    }
    return panas;
}

boolean tabrakbadan (int poskepala, ListSNAKE *body)/*Kepala bergerak ke tubuh sendiri*/
{
    boolean tabrak = false;
    addressSNAKE P = body->Tail;
    while (P->next!=Nil && tabrak == false)
    {
        if (poskepala == P->x+P->y*5)
        {
            tabrak = true;
        }
        else
        {
            P = P->next;
        }
    }
    if (poskepala == P->x+P->y*5)
    {
        tabrak = true;
    }
    return tabrak;
}

void snakegerak (ListSNAKE *body, Item H, int length)/*Badan snake bergerak*/
{
    if (IsEmptyListSNAKE(*body)){}
    else if (length == 2)
    {
        body->Tail->x = H.x;
        body->Tail->y = H.y;
    }
    else
    {
        body->Tail->x = body->Tail->next->x;
        body->Tail->y = body->Tail->next->y;
        addressSNAKE Prec = body->Tail;
        addressSNAKE P = Prec->next;
        while (P->next!=Nil)
        {
            Prec->next->x = P->next->x;
            Prec->next->y = P->next->y;
            Prec = Prec->next;
            P = P->next;
        }
        Prec->next->x = H.x;
        Prec->next->y = H.y;
    }
}

boolean sentuhan (int poskepala, Item T)/*Snake bergerak*/
{
    boolean tersentuh = false;
    if (poskepala == T.x+T.y*5)
    {
        tersentuh = true;
    }
    return tersentuh;
}

int kenameteor (ListSNAKE *body, Item H, Item m)/*Snake kena meteor*/
{
    int kena = 0;
    int posmeteor = (m.x+m.y*5);
    if (posmeteor == (H.x+H.y*5))
    {
        kena = 2;
    }
    else
    {
        addressSNAKE P = body->Tail;
        while (P->next!=Nil && kena == 0)
        {
            if (posmeteor == P->x+P->y*5)
            {
                kena = 1;
            }
            else
            {
                P = P->next;
            }
        }   
        if (posmeteor == P->x+P->y*5)
        {
            kena = 1;
        } 
    }
    return kena;
}

void SNAKEONMETEOR(int *skor)/*Program utama*/
{
    srand(time(NULL));
    boolean gameover = false;
    int turn = 1;
    int currentHead, currentTail;
    int length = 3; /*Snake length (tail + body + head)*/

    Item H; /*Snake head*/
    H.x = rand() % 5;
    H.y = rand() % 5;

    ListSNAKE body; /*Snake body and tail*/
    CreateEmptyListSNAKE(&body);
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            if (H.x-1 < 0)
            {
                if (H.y-1 < 0)
                {
                    InsVTailSNAKE(&body, H.x, H.y+1);
                }
                else
                {
                    InsVTailSNAKE(&body, H.x, H.y-1);
                }
            }
            else
            {
                InsVTailSNAKE(&body, H.x-1, H.y);
            }
        }
        else
        {
            addressSNAKE P = body.Tail;
            if (P->x-1 < 0)
            {
                if (P->y-1 < 0)
                {
                    InsVTailSNAKE(&body, P->x, P->y+1);
                }
                else
                {
                    InsVTailSNAKE(&body, P->x, P->y-1);
                }
            }
            else
            {
                InsVTailSNAKE(&body, P->x-1, P->y);
            }

        }
        
    }

    Item Z; /*Obstacle*/
    Z.x = rand() % 5;
    Z.y = rand() % 5;
    while (((Z.x+Z.y*5) == (H.x+H.y*5)) || ((Z.x+Z.y*5) == (body.Tail->x+body.Tail->y*5)) || ((Z.x+Z.y*5) == (body.Tail->next->x+body.Tail->next->y*5)))
    {
        Z.x = rand() % 5;
        Z.y = rand() % 5;
    }

    Item O; /*Makanan*/
    O.x = rand() % 5;
    O.y = rand() % 5;
    while (((O.x+O.y*5) == (H.x+H.y*5)) || ((O.x+O.y*5) == (body.Tail->x+body.Tail->y*5)) || ((O.x+O.y*5) == (body.Tail->next->x+body.Tail->next->y*5)) || ((O.x+O.y*5) == (Z.x+Z.y*5)))
    {
        O.x = rand() % 5;
        O.y = rand() % 5;
    }

    MapSNAKE M;/*Map*/
    CreateEmptyMapSNAKE(&M);
    for (int i = 0; i < 25; i++)
    {
        InsertSNAKE(&M, i, " ");
    }

    /*Masukan map inisial*/
    insertToMap(&M, O.x, O.y, "O");
    insertToMap(&M, H.x, H.y, "H");
    insertToMap(&M, Z.x, Z.y, "Z");
    if (!IsEmptyListSNAKE(body))
    {
        char *arr[24] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", 
        "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24"};
        addressSNAKE P = body.Tail;
        int i = length-2;
        while (P->next!=Nil)
        {
            insertToMap(&M, P->x, P->y, arr[i]);
            P = P->next;
            i -= 1;
        }
        insertToMap(&M, P->x, P->y, arr[i]);
    }    

    printf("                                                                      Selamat datang di snake on meteor!\n\n");
    printf("                                                                      Mengenerate peta, snake dan makanan . . .\n\n");
    printf("                                                                      Berhasil digenerate!\n\n");
    printf("                                                                      ---------------------------------------------\n\n");
    printMap(&M);
    printf("\n");

    Item m; /*Meteor*/
    m.x = -1; 
    m.y = -1;
    /*Turn 1 belum ada meteor*/
    
    /*Game mulai*/
    while (gameover == false)
    {
        /*Masukkan Command*/
        printf("                                                                      Turn %d\n\n", turn);
        printf("                                                                      Silahkan masukkan command anda: ");
        char *command = stringCommand();
        currentHead = posisikepala(command, H);
        while (currentHead==-999 || meteorpanas(currentHead, m) || tabrakbadan(currentHead, &body)){
            printf("                                                                      Input invalid\n");
            printf("                                                               Silahkan masukkan command anda: ");
            char *command = stringCommand();

            currentHead = posisikepala(command, H);
        }

        /*Menyimpan tail sekarang*/
        if(!IsEmptyListSNAKE(body))
        {
            currentTail = (body.Tail->x+(body.Tail->y*5));
        }
        else
        {
            currentTail=-1;
        }
        /*Masukan di cek*/

        /*Masukan berhasil*/
        printf("                                                                      Berhasil bergerak!\n");
        turn += 1;
        
        /*Map dihapus*/
        wipeMap (&M);

        /*Posisi tubuh baru*/
        snakegerak(&body, H, length);

        /*Posisi kepala baru*/
        H.x = currentHead%5;
        H.y = currentHead/5;

        /*Snake memakan makanan*/
        if (sentuhan(currentHead, O))
        {
            /*Tail tumbuh di tail sebelumnya*/
            if(!IsEmptyListSNAKE(body))
            {
                InsVTailSNAKE(&body, (currentTail%5), (currentTail/5));
                length += 1;
            }
            else
            {
                if (H.x-1 >= 0 && (((H.x-1)+H.y*5) == (Z.x+Z.y*5)) && (((H.x-1)+H.y*5) == (O.x+O.y*5)) && (((H.x-1)+H.y*5) == (m.x+m.y*5)))
                {
                    InsVTailSNAKE(&body, (H.x-1), H.y);
                    length += 1;
                }
                else if (H.y-1 >= 0 && ((H.x+(H.y-1)*5) == (Z.x+Z.y*5)) && ((H.x+(H.y-1)*5) == (O.x+O.y*5)) && ((H.x+(H.y-1)*5) == (m.x+m.y*5)))
                {
                    InsVTailSNAKE(&body, H.x, (H.y-1));
                    length += 1;
                }
                else if (H.y+1 >= 0 && ((H.x+(H.y+1)*5) == (Z.x+Z.y*5)) && ((H.x+(H.y+1)*5) == (O.x+O.y*5)) && ((H.x+(H.y+1)*5) == (m.x+m.y*5)))
                {
                    InsVTailSNAKE(&body, H.x, (H.y+1));
                    length += 1;
                }
                else if (H.x+1 >= 0 && (((H.x+1)+H.y*5) == (Z.x+Z.y*5)) && (((H.x+1)+H.y*5) == (O.x+O.y*5)) && (((H.x+1)+H.y*5) == (m.x+m.y*5)))
                {
                    InsVTailSNAKE(&body, (H.x+1), H.y);
                    length += 1;
                }
                else
                {
                    printf("                                                                      Ekor snake tidak dapat tumbuh!\n");
                    gameover = true;
                }
            }
            
            /*Dibuat makanan baru*/
            O.x = rand() % 5;
            O.y = rand() % 5;
            while (((O.x+O.y*5) == (H.x+H.y*5)) || SearchSNAKE(body, O.x, O.y) != Nil || ((O.x+O.y*5) == (Z.x+Z.y*5)) || ((O.x+O.y*5) == (m.x+m.y*5)))
            {
                O.x = rand() % 5;
                O.y = rand() % 5;
            }
        }
        
        /*Dibuat meteor baru*/
        m.x = rand() % 5;
        m.y = rand() % 5;
        while (((m.x+m.y*5) == (H.x+H.y*5)) || SearchSNAKE(body, m.x, m.y)!=Nil || ((m.x+m.y*5) == (Z.x+Z.y*5)) || ((m.x+m.y*5) == (O.x+O.y*5)))
        {
            m.x = rand() % 5;
            m.y = rand() % 5;
        }

        /*Dicetak map hasil turn barusan*/
        fillMap(&M, H, &body, length, Z, m, O);
        printMap (&M);

        if (sentuhan(currentHead, Z))/*Kepala snake menabrak obstacle*/
        {
            gameover = true;
            printf("                                                                      Kepala snake menabrak obstacle!\n");
        }
        else 
        {
            if (kenameteor(&body, H, m) == 0)/*Meteor meleset*/
            {
                printf("                                                                  Anda beruntung tidak terkena meteor! \n"); 
                if (gameover==false)
                {
                    printf("                                                                      Silahkan lanjutkan permainan\n\n");
                }
            }
            else if (kenameteor(&body, H, m) == 1)/*Meteor kena badan*/
            {
                DelPSNAKE(&body, m.x, m.y);
                length -= 1;
                printf("\n\n\n");
                printf("                                                                      Anda terkena meteor!\n");
                wipeMap (&M);
                fillMap(&M, H, &body, length, Z, m, O);
                printMap (&M);
                if (gameover==false)
                {
                    printf("                                                                      Silahkan lanjutkan permainan\n\n");
                }
                
            }
            else if (kenameteor(&body, H, m) == 2)/*Meteor kena kepala*/
            {
                length -= 1;
                gameover = true;
                printf("                                                                  Kepala snake terkena meteor!\n");
            }
        }
    }
    printf("\n\n                                                                      Game berakhir. Skor: %d\n", length*2);
    *skor = length*2;
}