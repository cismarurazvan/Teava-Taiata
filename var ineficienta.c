#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif



int n, i, j,x;
int PretMaxim;

int cutRod(int price[], int n){
        if (n <= 0)
            return 0;
   int max_val = 0;
        for (int i = 0; i<n; i++){
                max_val = max(max_val, price[i] + cutRod(price, n-i-1));
                                }
   return max_val;
}


int main()
{    int PRETPRE;
    int PRET[100];

       srand(time(NULL));
    n = (rand() % 30) +1;
    printf("Lungimea tevii este de %d metri  \n", n);


    printf("Pretul pentru teava pentru 1m ,2m ,3m ... Nm este \n");
    PRETPRE=0;
    for(int i=0;i<n;i++){
        PRET[i]= PRETPRE + (rand()%5) +1;
        printf("%d m liniari costa %d euro \n", i+1, PRET[i]);
        PRETPRE= PRET[i];
    }




    x=cutRod(PRET, n);
    printf("Maximum Obtainable Value is %d \n", x);

    return 0;
}


