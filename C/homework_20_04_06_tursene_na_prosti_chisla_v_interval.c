/*
zad 3.
Да се състави програма, която се прочита цяло число до 1000 и след това n цели числа.
Програмата трябва да създаде нов масив, чиито елементи са 0 и 1. 0 когато числото на
съответния индекс е просто, а 1 когато не е просто. Да се изведе новия масив на
стандартния изход .
*/

#include <stdio.h>
#include <stdlib.h>

int prost(int x) {
    int i;
    for(i=2; i<=x; i++){
        if (i==x) {
                return 0;
        }
        if (x%i==0) {
                break;
        }
    }
    return 1;
}

int main()
{
    system("chcp 65001>nul");
    int i,x,a=1001;

    while(a>1000){
        printf("Въведете броя на числата: ");
        scanf("%d",&a);
    }

    int masiv[a];
    for(i=0;i<a;i++){
        printf("Моля, въведете число %d: ",i+1);
        scanf("%d",&x);
        masiv[i]=prost(x);
    }

    for(i=0;i<a;i++){
        printf("%d: %d\n",i, masiv[i]);
    }

    return 0;
}
