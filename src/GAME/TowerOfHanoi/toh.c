#include "stackhanoi.c"
#include <stdio.h>
#include <stdlib.h>

int TOWEROFHANOI(){
    boolean stategame=true;
    StackHanoi s1,s2,s3,scek;
    CreateStackhanoi(&s1);
    CreateStackhanoi(&s2);
    CreateStackhanoi(&s3);
    CreateStackhanoi(&scek);
    
    pushhanoi(&s1,9);
    pushhanoi(&s1,7);
    pushhanoi(&s1,5);
    pushhanoi(&s1,3);
    pushhanoi(&s1,1);

    pushhanoi(&scek,9);
    pushhanoi(&scek,7);
    pushhanoi(&scek,5);
    pushhanoi(&scek,3);
    pushhanoi(&scek,1);

    char tiangasal[5];
    char tiangtujuan[5];
    Typehanoi val;
    int langkah=0,skor=10;
    while (stategame){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printhanoi(s1,s2,s3);
        printf("                                                                    TIANG ASAL: ");
        char *tiangasal = stringCommand();
        printf("                                                                    TIANG TUJUAN: ");
        char *tiangtujuan = stringCommand();



        if (tiangasal[0]=='A'){
            if (isEmptyhanoi(s1)){
                printf("Input invalid\n");
                continue;
            }
            if (tiangtujuan[0]=='B'){
                if (isEmptyhanoi(s2)){
                    pophanoi(&s1,&val);
                    pushhanoi(&s2,val);
                }
                else if (TOP(s2)<TOP(s1)){
                    printf("Input invalid\n");
                }
                else{
                    pophanoi(&s1,&val);
                    pushhanoi(&s2,val);
                }
            }
            else if (tiangtujuan[0]=='C'){
                if (isEmptyhanoi(s3)){
                    pophanoi(&s1,&val);
                    pushhanoi(&s3,val);
                }
                else if (TOP(s3)<TOP(s1)){
                    printf("Input invalid\n");
                }
                else{
                    pophanoi(&s1,&val);
                    pushhanoi(&s3,val);
                }
            }
            else{
                printf("Input Invalid\n");
            }
        }        
        else if (tiangasal[0]=='B'){
            if (isEmptyhanoi(s2)){
                printf("Input invalid\n");
                continue;
            }
            if (tiangtujuan[0]=='A'){
                if (isEmptyhanoi(s1)){
                    pophanoi(&s2,&val);
                    pushhanoi(&s1,val);
                }
                else if (TOP(s1)<TOP(s2)){
                    printf("Input invalid\n");
                }
                else{
                    pophanoi(&s2,&val);
                    pushhanoi(&s1,val);
                }
            }
            else if (tiangtujuan[0]=='C'){
                if (isEmptyhanoi(s3)){
                    pophanoi(&s2,&val);
                    pushhanoi(&s3,val);
                }
                else if (TOP(s3)<TOP(s2)){
                    printf("Input invalid\n");
                }
                else{
                    pophanoi(&s2,&val);
                    pushhanoi(&s3,val);
                }
            }
            else{
                printf("Input Invalid\n");
            }

        }
        else if (tiangasal[0]=='C'){
            if (isEmptyhanoi(s3)){
                printf("Input invalid\n");
                continue;
            }
            if (tiangtujuan[0]=='A'){
                if (isEmptyhanoi(s1)){
                    pophanoi(&s3,&val);
                    pushhanoi(&s1,val);
                }
                else if (TOP(s1)<TOP(s3)){
                    printf("Input invalid\n");
                }
                else if(isEmptyhanoi(s3)){
                    printf("Input invalid\n");
                }
                else{
                    pophanoi(&s3,&val);
                    pushhanoi(&s1,val);
                }
            }
            else if (tiangtujuan[0]=='B'){
                if (isEmptyhanoi(s2)){
                    pophanoi(&s3,&val);
                    pushhanoi(&s2,val);
                }
                else if (TOP(s2)<TOP(s3)){
                    printf("Input invalid\n");
                }
                else{
                    pophanoi(&s3,&val);
                    pushhanoi(&s2,val);
                }
            }
            else{
                printf("Input Invalid\n");
            }
        }
        else{
            printf("Input invalid\n");
        }
        if (stacksamahanoi(s3,scek)){
            stategame=false;
        }
    langkah++;
    system("cls");
    }
    while (langkah>31){
        langkah-=5;
        skor--;
    }   
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                    Skor didapatkan : %d\n",skor);
    printhanoi(s1,s2,s3);
    printf("                                                                        Kamu berhasil!\n");

    return skor;
}