#include <stdio.h>
#include <stdlib.h>
int deliteli(int n){
    int delise=0;
    for (int i=1; i<=n; i++){
        if(n%i==0){
            delise++;
        }
    }
    return delise;
}
int main()
{
    int chislo;
    scanf("%d", &chislo);
    printf("deliteli:%d", deliteli(chislo));
}
