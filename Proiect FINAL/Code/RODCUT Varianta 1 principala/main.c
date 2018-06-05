#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif



int n, i, j;
int PretMaxim;

int TaiTeava(int n, int PRET[]){
    int i,j;
    int result[30];
    result[0]=0;

    for(i=1;i<=n;i++){
        result[i]=0;
            for(j=0;j<i;j++){
                    int k=PRET[j]+result[i-(j+1)];
            result[i]=max(result[i],k);
            }
    }


    return result[n];
}



int main(){
    int PRETPRE;
    int PRET[100];


    //generator valori;
    srand(time(NULL));
    n = (rand() % 30) +1;
    printf("Lungimea tevii este de %d metri  \n", n); //generam valoarea tevii


    printf("Pretul pentru teava pentru 1m ,2m ,3m ... Nm este \n");
    PRETPRE=0;
    for(int i=0;i<n;i++){
        PRET[i]= PRETPRE + (rand()%5) +1; //generam valoarea fiecarui pret , considerand ca pretul evolueaza de la o marime la urmatoarea cu o marja intre 1 si 5 eur
        printf("%d m liniari costa %d euro \n", i+1, PRET[i]);
        PRETPRE= PRET[i];
    }


    PretMaxim = TaiTeava(n,PRET);
    printf("Valoarea maxima posibila obtinuta din vanzarea tevii este %d euro \n", PretMaxim );

    if(PretMaxim == n*PRET[0])
        printf("Cea mai eficienta varianta de a vinde teava este in bucati de 1 metru \n");
    if(PretMaxim == PRET[n-1])
        printf("Putem obtine cei mai multi bani vanzand teava intreaga, fara a taia din ea! \n");

    return 0;
}


