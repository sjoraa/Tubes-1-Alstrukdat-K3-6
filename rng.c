#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"boolean.h"

int randomnumber()
{
  int number;
  srand(time(0));
  number = (rand() % 100);
  return number;
}

int main()
{
  int number;
  number = randomnumber();
  int guess;
  boolean correct = false;
  int tries = 10;
  int score;
  printf("Tebaklah angka dari 0-100!\n");
  while (correct == false && tries > 0)
  {
    printf("Anda mempunyai kesempatan menebak sebanyak %d kali \n", tries);
    printf("Masukkan tebakan anda: ");
    scanf("%d", &guess);
	if (tries==1){
		if (guess!=number){
			printf("Maaf anda kurang beruntung. Silakan coba lagi\n");
		}
		else{
			correct=true;
		}

	}
	else{
		if(guess > number)
    {
      printf("Lebih kecil\n");
    }
    	else if (guess < number)
    {
      printf("Lebih besar\n");
    }
    	else if (guess == number)
    {
      correct = true;
    }
	}
    
    tries--;
  }
  if (correct == true)
  {
    score = ((tries + 1) * 10);
    printf("Tebakkan anda benar!\n");
    printf("Score anda = %d", score);
  }
}