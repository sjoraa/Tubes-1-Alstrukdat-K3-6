#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "SoM.h"

int GetInfo(addressLDP P){
    if(P == NULL){
        return UndefLDP;
    }
    else{
        return Info(P);
    }
}
boolean SearchPoint(List L,int X,int Y){
    addressLDP S = First(L);
    boolean found = true;
    while (S != NilLDP && found){
        if (Absis(S) == X && Ordinat(S) == Y){
            found = false;
        }
        S = Next(S);
    }
    return found;
}

addressLDP SearchAP(List L,int i,int j){
    addressLDP P = First(L);
    boolean found = false;
    while(P != NilLDP && !found){
        if (Absis(P)==i && Ordinat(P)==j){
            found = true;
        }
        else{
            P = Next(P);
        }
    }
    if (found){
        return P; 
    }
    else{
        return NilLDP;
    }
}


void CreateSnake(List *L){
    CreateEmptyLDP(L);
    srand(time(NULL));
    addressLDP P1=AlokasiLDP(72); 
    addressLDP P2=AlokasiLDP(1);
    addressLDP P3=AlokasiLDP(2);

    Absis(P1)=rand()%5;
    Ordinat(P1)=rand()%5;
    
    if (Absis(P1) == 0){
        if (Ordinat(P1) == 0){
            Absis(P2) = Absis(P1);
            Absis(P3) = Absis(P1);
            Ordinat(P2) = Ordinat(P1)+1;
            Ordinat(P3) = Ordinat(P1)+2;
        }
        else{
            Absis(P2) = Absis(P1);
            Absis(P3) = Absis(P1);
            if (Ordinat(P1) == 1){
                Ordinat(P2) = Ordinat(P1)+1;
                Ordinat(P3) = Ordinat(P1)+2;
            }
            else{
                Ordinat(P2) = Ordinat(P1)-1;
                Ordinat(P3) = Ordinat(P1)-2;
            }
        }
    }
    else{
        if(Ordinat(P1) == 0){
            if(Absis(P1) == 1){
                Absis(P2) = Absis(P1)-1;
                Absis(P3) = Absis(P1)-1;
                Ordinat(P2) = Ordinat(P1);
                Ordinat(P3) = Ordinat(P1)+1;
            }
            else{
                Absis(P2) = Absis(P1)-1;
                Absis(P3) = Absis(P1)-2;
                Ordinat(P2) = Ordinat(P1);
                Ordinat(P3) = Ordinat(P1);
            }
        }
        else{
            Absis(P2) = Absis(P1)-1;
            Ordinat(P2) = Ordinat(P1);
            if (Absis(P2) == 0){
                Absis(P3) = Absis(P2);
                Ordinat(P3) = Ordinat(P2)-1;
            }
            else{
                Absis(P3) = Absis(P2)-1;
                Ordinat(P3) = Ordinat(P2);
            }
        }
    }
    InsertLastLDP(L,P1);
    InsertLastLDP(L,P2);
    InsertLastLDP(L,P3);
}

void move (List *L, char* input){
    char* atas="w";
    char* kiri="a";
    char* bawah="s";
    char* kanan="d";
    addressLDP P=Last(*L);
    POINT temp;
    if (compareSTR(input,atas)){
        temp=(*Prev(P)).coor;
        while (Prev(P)!=NilLDP){
            (*P).coor=temp;
            P=(P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).coor;
            }
        }
    }else if(compareSTR(input,bawah)){
        temp=(*Prev(P)).coor;
        while (Prev(P)!=NilLDP){
            (*P).coor=temp;
            P = (P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).coor;
            }
        }
    }else if(compareSTR(input,kanan)){
        temp=(*Prev(P)).coor;
        while (Prev(P)!=NilLDP){
            (*P).coor=temp;
            P = (P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).coor;
            }
        }
    }else if(compareSTR(input,kiri)){
        temp=(*Prev(P)).coor;
        while (Prev(P)!=NilLDP){
            (*P).coor=temp;
            P = (P)->prev;
            if (Prev(P)!=NilLDP){
                temp=(*Prev(P)).coor;
            }
        }
    }
    addressLDP a =First(*L);
    if (compareSTR(input,kiri)){
        if (Absis(a) == 0){   
            Absis(a) = 4;
        }
        else{
            Absis(a) -= 1;
        }   
    }else if(compareSTR(input,kanan)){
        if (Absis(a) == 4){   
            Absis(a) = 0;
        }
        else{
            Absis(a) += 1;
        }
    }else if(compareSTR(input,atas)){
        if (Ordinat(a) == 0){   
            Ordinat(a) = 4;
        }
        else{
            Ordinat(a) -= 1;
        } 
    }else if(compareSTR(input,bawah)){
        if (Ordinat(a)== 4){   
            Ordinat(a) = 0;
        }
        else{
            Ordinat(a) += 1;
        }
    }
}  

void makeMeteor(POINT *meteor,POINT food){
    srand(time(NULL));

    int a = rand() % 5;
    int b = rand() % 5;
    boolean found;
    found = false;
    int idx=0;
    while (!found){
        if (a==food.x && b==food.y){
            if (idx % 3 == 1){
                a= (a-1) %5;
                b= (b+1) %5;
            }
            else if(idx % 3 == 0){
                a = (a+1) %5;
                b = (b-1) %5;
            }
            else{
                a = (a+1) %5;
                b = (b+1) %5;
            }
        }
        else{
            found=true;
            meteor->x = a;
            meteor->y = b;
        }
    
        if (a < 0 || b < 0){
            a = rand() % 5;
            b = rand() % 5;
        }
        idx++;
    }
}


void makeObstacle(List L, POINT* obstacle){
    srand(time(NULL));

    int a = rand() % 5;
    int b = rand() % 5;

    boolean found;
    found = false;

    int i = 0;

    while (!found){
        if (SearchPoint(L,a,b)){ 
            found=true;
            obstacle->x=a;
            obstacle->y=b;
        }
        else
        {
        if (i % 3 == 1){
            a= (a - 1) % 4;
            b= (b + 1 ) % 4;
        }
        else if(i % 3 == 0){
            a=(a + 1) % 4;
            b=(b - 1) % 4;
        }
        else{
            a=(a + 1) % 4;
            b=(b + 1) % 4;
        }
        if (a < 0 || b < 0){
            a = rand() % 4;
            b = rand() % 4;
        }
        i++;
        }
    }
}

void makeFood(POINT *food,List L, POINT obstacle){
    srand(time(NULL));

    int a = rand() % 5;
    int b = rand() % 5;

    boolean found;
    found = false;

    int i=0;

    while (!found){
        if (SearchPoint(L,a,b) && a != obstacle.x && b != obstacle.y){
            found = true;
            (*food).x=a;
            (*food).y=b;
        }
        else
        {
        if (i % 3 == 1){
            a= (a-1) % 5;
            b= (b+1) % 5;
        }
        else if(i % 3==0){
            a=(a+1)%5;
            b=(b-1)%5;
        }
        else{
            a=(a+1)%5;
            b=(b+1)%5;
        }
        }
        if (a < 0 || b < 0){
            a = rand() % 5;
            b = rand() % 5;
        }
        i++;
    }
}

boolean foodEaten(List *L, POINT food){
    return((*First(*L))).coor.x == food.x && ((*First(*L)).coor.y== food.y);
}
boolean stillHotAF(List L, char* input, POINT meteor){
    addressLDP P = First(L);
    char* wilujeng="w";
    char* anting="a";
    char* sayo="s";
    char* dori="d";
    int a = Absis(P);
    int b = Ordinat(P);
    boolean why = (a == meteor.x && meteor.y == (b - 1) % 5);
    boolean are = (b == meteor.y && meteor.x == (a - 1) % 5);
    boolean demn = (b == meteor.y && meteor.x == (a + 1) % 5);
    boolean sus = (a == meteor.x && meteor.y == (b + 1) % 5);
    if(compareSTR(input,wilujeng)){
        return why;
    }
    else if(compareSTR(input,anting)){
        return are;
    }
    else if(compareSTR(input,dori)){
        return demn;
    }
    else if(compareSTR(input,sayo)){
        return sus;
    }
}
void kenaMeteor(List *L,POINT food,POINT meteor){
    addressLDP a;
    a = First(*L);
    addressLDP b;
    b = Last(*L);
    boolean found;
    found = false;

    while(a != NilLDP && !found){
        if (Absis(a) == meteor.x && Ordinat(b) == meteor.y){
            found = true;    
        }
        a = Next(a);
    }

    if (found){
        if (a == NilLDP){
            DelLastLDP(L,&b);
         }
        else if(a == Next(First(*L))){
            DelLastLDP(L,&b);
            DelFirstLDP(L,&b);
        }
        else{
            while (b != Prev(a)){
                b->info= Prev(b)->info;
                b = Prev(b);
            }
            DelBeforeLDP(L,&b,a);
            printf("Anda terkena meteor!\n");
        }
    }
    else{
        printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
    }
}

boolean endGame(List L,POINT meteor, POINT obstacle){
    addressLDP a;
    a = First(L);
    boolean found=false;
    a = Next(a);

    while (!found && a != NilLDP){
        if (Absis(a) == Absis(First(L)) && Ordinat(a) == Ordinat(First(L))){
            found=true;
        }
        a = Next(a);
    }
    if (!found){
        addressLDP check = First(L);
        if((check->info != 'H')){
            printf("DUAARRRRRR Kepala snake terkena meteor !\n");
            Info(First(L))+= 2;
            return true;
        }
        else if(Absis(First(L)) == obstacle.x && Ordinat(First(L)) == obstacle.y){
            printf("HAHAHA Kepala snake menabrak obstacle\n");
            return true;
        }
        else if(GetInfo(SearchAP(L,Absis(First(L))+1,Ordinat(First(L)))) < 25 && GetInfo(SearchAP(L,Absis(First(L))-1,Ordinat(First(L)))) < 25 && GetInfo(SearchAP(L,Absis(First(L)),Ordinat(First(L))-1)) < 25 && GetInfo(SearchAP(L,Absis(First(L)),Ordinat(First(L))+1)) < 25){
            printf("Anda sudah tidak bisa kemana-mana lagi wkwkwk\n");
            return true;
        }
        else{
            return false;
        }
    }
    else{
        printf("YOU LOSE....Kepala snake menabrak badannya sendiri\n");
        return found;
    }
}

void printMapSNAKE(List L,POINT food, POINT meteor,POINT obstacle){
    
    int i,j;
    for (i = 0 ; i < 11 ; i++){
        for (j = 0 ; j < 11 ;j++){
            if (i % 2 == 0 && j % 2 == 0){
                printf("%c",254);
            }
            else if (i % 2 == 0){
                printf("%c%c%c",205,205,205);
            }
            else if(j % 2 == 0){
                printf("%c",186);
            }
            else if(food.x==((j+1)/2)-1 && food.y==((i+1)/2)-1){
                printf(" o ");
            }
            else if(meteor.x==((j+1)/2)-1 && meteor.y==((i+1)/2)-1){
                printf(" M ");
            }
            else if(obstacle.x==((j+1)/2)-1 && obstacle.y==((i+1)/2)-1){
                printf(" ! ");
            }
            else if(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)){
                if (Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)) == 72){
                    printf(" %c ",Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)));
                }
                else{
                    if (Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1))<=9){
                        printf(" %d ",Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)));
                    }
                    else{
                        printf("%d ",Info(SearchAP(L,((j+1)/2)-1,((i+1)/2)-1)));
                    }
                }
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
}

void som(int *skor){
    List L;
    ElmtList ekorbaru;
    char* input;
    POINT obstacle,food,meteor;
    boolean kena = false;
    int turn = 1;
    int score;
    char*jwbn;

    food.x = UndefLDP;
    food.y = UndefLDP;
    meteor.x = UndefLDP;
    meteor.y = UndefLDP;

    char* we = "w";
    char* ah = "a";
    char* es = "s";
    char* de = "d";
    char* satu = "1";
    char* dua = "2";

    printf(".........................................................................\n");
    printf("...................                       ...............................\n");
    printf(".................. JPPPPPPPPPPPPPPPPPPPPP^ ..............................\n");
    printf("..............     G@@@@@@@@@@@@@@@@@@@@@~    ....................@@@@...\n");
    printf("............. :55555555555555555555555555555P? ..................@@@@@@..\n");
    printf("............. ^@@@@Y!!!!!!!!!!!!!!!!!!!!!#@@@5    ................@@@@...\n");
    printf("............. ^@@@@Y!77777777777777777777Y5555555Y. .........@@@.........\n");
    printf("..........    ^@@@@J!!!77777777777777!!!!!!!!5@@@&: ........@@@@@........\n");
    printf("......... !5YYY5555PPPG5777777777777?PPPP?77!5@@@&: .........@@@.........\n");
    printf("......... Y@@@&7!!!B@@@B!77777777777J@@@@J77!5@@@&.    ..................\n");
    printf("......... J@@@#7777B@@@B!77777777777J@@@@J777JGGGPYJJY~ .....@...........\n");
    printf("......... J@@@#7777#@@@B!77777777777J@@@@J7777???J@@@@? ....@@@..........\n");
    printf("......... J@@@#7!7!5PPPY777777777777?PPPP?!7!7JJJJ&@@@? .....@...........\n");
    printf("......... Y@@@&!!!!!!!!!7777777777777!!!!!!!!7???J@@@@? .................\n");
    printf("......... !5YYY5555?7????????????????????7777JPPPP5YY5~ .................\n");
    printf("..........    ^@@@@5?????????????????????????P@@@&.    ..................\n");
    printf("............. :5555PPPPPPPPPPPPPPPPPPPPPPPPPPB@@@&: .....................\n");
    printf("..........         G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&.    ..................\n");
    printf("......... ^77777777PBGGGGGGB@@@@#GGGGGGGGBBBB#@@@&?777^ .................\n");
    printf("......    Y@@@@@@@@Y!!!!!!!7&@@@5!!!!!!!!????P@@@@@@@@?    ..............\n");
    printf(".    .#@@@P!7777777!!!!77777&@@@5!7777777????P@@@@J???B@@@B     .........\n");
    printf(" :!!!!GBB#Y!7777777JYYYJ777?B###577777777Y555PBBBBJJJ?P###G!!!!. ........\n");
    printf(" !@@@@?!77777777777#@@@B?????????????????#@@@G!777?JJJ????Y@@@@^    .....\n");
    printf(" !@@@@J777777777777P###G55555555555555555B###P7777?JJJY555P####7~~~^ ....\n");
    printf(" !@@@@Y?JJ?77777777777!Y@@@@@@@@@@@@@@@@@J!7777777?JJ?B@@@#???J&@@@Y ....\n");
    printf(" !@@@@Y?JJ?77777777777!Y#################J77777777?JJ?B@@@#JJJJ#@@@Y ....\n");
    printf(" !@@@@Y??J?777777777777777777777777777777777777777????B@@@#JJJJ#@@@Y ....\n");
    printf("......#@@@G??????????????????????????????????????J&@@@@@@@#???J&@@@Y ....\n");
    printf("......... Y@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&:.......!@@@@~.........\n");
    printf("......    J&#####################################B:       ~####^   ......\n");
    printf(".........................................................................\n");
    printf(".........................................................................\n");
    printf("\n");
    printf("\n");
    printf(" #####                                                  #     #                                    \n");
    printf("#     # #    #   ##   #    # ######     ####  #    #    ##   ## ###### ##### ######  ####  #####   \n");
    printf("#       ##   #  #  #  #   #  #         #    # ##   #    # # # # #        #   #      #    # #    #  \n");
    printf(" #####  # #  # #    # ####   #####     #    # # #  #    #  #  # #####    #   #####  #    # #    #  \n");
    printf("      # #  # # ###### #  #   #         #    # #  # #    #     # #        #   #      #    # #####   \n");
    printf("#     # #   ## #    # #   #  #         #    # #   ##    #     # #        #   #      #    # #   #   \n");
    printf(" #####  #    # #    # #    # ######     ####  #    #    #     # ######   #   ######  ####  #    #  \n");
    printf("\n");
    printf("\n");
    printf("===========MAIN MENU===========\n");
    printf("1. PLAY GAME \n");
    printf("2. EXIT \n");
    printf("PRESS 1 OR 2\n");
    printf("ENTER CHOICE : ");
    jwbn = stringCommand();

    while(!compareSTR(jwbn,satu) && !compareSTR(jwbn,dua)){
        printf("Masukkan input yang benar!\n");
        printf("PRESS 1 OR 2\n");
        printf("ENTER CHOICE : ");
        jwbn = stringCommand();
    }

    while (compareSTR(jwbn,dua)){
        break;
    }
    if(compareSTR(jwbn,satu)){
        srand(time(NULL));
        CreateSnake(&L);
        printf("Selamat datang di snake on meteor!\n");
        printf("\n");
        printf("Mengenerate peta,snake dan makanan...\n");
        printf("\n");
        printf("Berhasil digenerate!\n");
        printf("\n");
        printf("__________________________________________\n");
        printf("\n");
        printf("Berikut merupakan peta permainan!\n");
        
        makeObstacle(L,&obstacle);
        makeFood(&food,L,obstacle);
        printMapSNAKE(L,food,meteor,obstacle);

        while(!kena){
            printf("Turn %d:\n",turn);
            printf("Silahkan masukkan command anda: ");
            input = stringCommand();
            if (compareSTR(input,we) || compareSTR(input,ah) || compareSTR(input,es) || compareSTR(input,de)){
                addressLDP cek = First(L);
                if(compareSTR(input,de) && GetInfo(SearchAP(L,Absis(cek)+1,Ordinat(cek))) < 25){
                    printf("Ada badan snake, Input ulang\n");
                }            
                else if(compareSTR(input,ah) && GetInfo(SearchAP(L,Absis(cek)-1,Ordinat(cek))) < 25){
                    printf("Ada badan snake, Input ulang\n");
                }
                else if(compareSTR(input,we) && GetInfo(SearchAP(L,Absis(cek),Ordinat(cek)-1)) < 25){
                    printf("Ada badan snake, Input ulang\n");
                }
                else if(compareSTR(input,es) && GetInfo(SearchAP(L,Absis(cek),Ordinat(cek)+1)) < 25){
                    printf("Ada badan snake, Input ulang\n");
                }                        
                else if(!stillHotAF(L,input,meteor)){
                    move(&L,input);
                    if (foodEaten(&L,food)){
                        addressLDP ekortemp = Last(L);
                        if(GetInfo(SearchAP(L,Absis(ekortemp)+1,Ordinat(ekortemp))) < 25 && GetInfo(SearchAP(L,Absis(ekortemp)-1,Ordinat(ekortemp))) < 25 && GetInfo(SearchAP(L,Absis(ekortemp),Ordinat(ekortemp)-1)) < 25 && GetInfo(SearchAP(L,Absis(ekortemp),Ordinat(ekortemp)+1)) < 25){
                            printf("Ekor sudah tidak bisa spawn wkwkwk \n");
                            score = Info(Last(L)) * 2;
                            printf("Score : %d\n",score);
                            kena = true;
                        }
                        else{
                            ekorbaru=*(Last(L));
                            addressLDP alamatekor= AlokasiLDP(((int)Info(Last(L))) + 1);
                            Absis(alamatekor)= ekorbaru.coor.x;
                            Ordinat(alamatekor)= ekorbaru.coor.y;
                            InsertLastLDP(&L,alamatekor);
                            makeFood(&food,L,obstacle);
                        }     
                    }
                    makeMeteor(&meteor,food);
                    printMapSNAKE(L,food,meteor,obstacle);
                    kenaMeteor(&L,food,meteor);

                    if(!endGame(L,meteor,obstacle)){
                        turn++;
                    }
                    else if(Info(Last(L)) == 23){
                        int sekor = 46;
                        printf("Score : %d\n",score);
                        kena = true;
                    }
                    else{
                        score = Info(Last(L)) * 2;
                        printf("Score : %d\n",score);
                        kena = true;
                    }                
                }
                else if(stillHotAF(L,input,meteor)){
                    printf("AWWWW!!! Meteornya masih panas.... Input ulang command dong, jangan kesini...\n");
                }
            } 
            else{
                printf("Silahkan memasukkan command yang valid!\n");
            }   
        }
    }
}