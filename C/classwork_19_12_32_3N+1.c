#include <stdio.h>
#include <stdlib.h>

void delene(int a){
    if(a%2==1){
        a = 3*a+1;
        printf("%d \n", a);
    }
}

int main(){
    int a = 0;
    int b = 0;
    scanf("%d", &a);

    while(a != 0){
        b=a;
        b = b%2;
        if(b==0){
            a = a/2;
            b = a;
            printf("%d \n", b);
            break;
        }
        else{
            printf("ddz oslovieto");
            break;
        }
    }
    return 0;
}
