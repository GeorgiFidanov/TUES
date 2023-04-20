#include <stdio.h>
#include <stdlib.h>
int factorial(int chislo){
    int suma=1;
    for (int i=1; i<=chislo; i++){
            printf("%d * ", i);
            suma*=i;
    }
    return suma;
}
int main()
{
    int chislo, suma=1;
    scanf("%d", &chislo);
    suma=factorial(chislo);
    printf("I stoinostta na factoriala e: %d", suma);
}
