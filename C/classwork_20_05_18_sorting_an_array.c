#include <stdio.h>
#include <stdlib.h>

int main()
{
    int kolonite[] = {2, 34, 67, 30, 5, 90};
    int n=6;
    int i,j;
    int razmqna =0;
    for(i=0; i<n-1; i++){
        razmqna=0;
        for(j=0; j<n-1; j++){
            if(kolonite[j] > kolonite[j+1]){
                int sravnqemo = kolonite[j];
                kolonite[j] = kolonite[j+1];
                kolonite[j+1] = sravnqemo;
                razmqna=1;
            }
        }
        if(razmqna==0){
            break;
        }
    }
    printf("Podredenqt red izglejda taka:\n");
    for(i=0; i<n; i++){
        printf("%d", kolonite[i]);
    }
    return 0;
}
