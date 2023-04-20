#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    int b=0;
    int i, j;
    system("chcp 65001>nul");
    printf("Моля, въведете 1 число: ");
    scanf("%d",&a);
    while(a>=b){
        printf("Моля, въведете 2ro число: ");
        scanf("%d",&b);
    }
    for(i=a; i<=b; i++){
        printf("debug: chislo: %d\n",i);
        for(j=2; j<=i; j++){
            if (i==j) {
                    printf("%d e prosto\n", i,j);
            }
            if (i%j==0) {
                    break;
            }
        }


    }

    return 0;
}
