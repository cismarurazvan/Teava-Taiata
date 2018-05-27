#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int PRET[100];
    printf("Introduceti lungimea tevii \n");
    scanf("%d",&n);

    printf("Introduceti pretul pentru teava pentru toate lungimile\n");
    for(int i=0;i<n;i++)
        scanf("%d",&PRET[i]);

    PretMaxim = TaiTeava(n,PRET);
    printf("Valoarea maxima posibila obtinuta din vanzarea tevii este %d \n", PretMaxim );
    return 0;
}


