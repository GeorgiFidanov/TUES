/*
Да се състави програма, която се прочита цяло число до 1000 и след това n цели числа.
Програмата трябва да създаде нов масив, чиито елементи са 0 и 1. 0 когато числото на
съответния индекс е просто, а 1 когато не е просто. Ново полученият масив образува
двоично число. Да се превърне това число в десетично и да се изведе на конзолата.
*/

#include <stdio.h>
#include <stdlib.h>

int prost(int x) {
    int i;
    for(i=2; i<=x; i++){
        if (i==x) {
                return 0; // prosto
        }
        if (x%i==0) {
                break;
        }
    }
    return 1; // ne e prosto
}

int main()
{
    system("chcp 65001>nul");
    int i,a=1001,b=0,x;

    while(a>1000){
        printf("Въведете броя на числата: ");
        scanf("%d",&a);
    }

    char masiv[a];
    for(i=0;i<a;i++){
        printf("Моля, въведете число %d: ",i+1);
        scanf("%d",&x);
        masiv[i]=prost(x);
    }

    printf("binary: ");
    for(i=0;i<a;i++){
        //printf("DEBUG: %d: %d\n",i, masiv[i]);
        printf("%d", masiv[i]);
    }
    printf("\n");

    int chislo=0;
    int k;
    //for(i=a-1;i>=0;i--) {
    for(i=0;i<a;i++){
        k=a-i-1;
        chislo += masiv[i]* pow(2,k);
    }
    printf("decimnal: %d\n",chislo);

    return 0;
}
