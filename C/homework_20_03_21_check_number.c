#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    int i;
    int p;
    scanf("%d", &a);
    scanf("%d", &b);

    for( i = a; i < b; i = i + 1 ){


        if (i==1){
            printf("one\n");
        }
        if (i==2){
            printf("two\n");
        }
        if (i==3){
            printf("three\n");
        }
        if(i==4){
            printf("four\n");
        }
        if(i==5){
            printf("five\n");
        }
        if(i==6){
            printf("six\n");
        }
        if(i==7){
            printf("seven\n");
        }
        if(i==8){
            printf("eight\n");
        }
        if(i==9){
            printf("nine\n");
        }
        if(i>9){
            p=i%2;
            if(p==0){
                printf("even\n");
            }
            else{
                printf("odd\n");
            }
        }

    }
return 0;
}


