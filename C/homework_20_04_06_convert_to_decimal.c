/*
zad2
Да се състави програма, която се прочита цяло число до 1000 в двоична бройна система и
записва цифрите в масив. Броя на битовете на числото се въвеждат предварително.
Програмата трябва да изведе числото в десетична бройна система.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 65001>nul");
    int n,a,b,i,count,chislo = 0;
    printf("Въведете броя на битовете: ");
    scanf("%d",&n);
    while(n>10){
        printf("Въведете броя на битовете: ");
        scanf("%d",&n);
    }
    int masiv[n];
    while((count!=n)||(chislo>1000)){
        count=0;
        chislo = 0;
        printf("Въведете число в двоична бройна система: ");
        scanf("%d",&a);
        b=a;
        int ost=0;
        while(b!=0){
            ost = b % 10;
            b=b/10;
            masiv[count]= ost;
            count++;
        }

        for(i=0;i<n;i++) {
            chislo += masiv[i]* pow(2,i);
        }
    }
    printf("Вашето число в десетична бройна система е: %d", chislo);
    return 0;
}
