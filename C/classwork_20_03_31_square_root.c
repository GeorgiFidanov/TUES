#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//sqrt c e funkciq za korenkvadrad
int main()
{
int n;
scanf("%d", &n);
int k[n];
for(int i=0; i<n; i++){
    scanf("%d", &k[i]);
    k[i]=pow(k[i],k[i]);
    }
    //ako vmesto vtoroto k[i] napishem 2 stava kvadrad
for (int j=0; j<n; j++){
    printf("%d\n", k[j]);
    }
}
