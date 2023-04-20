#include <stdio.h>
#include <stdlib.h>

void drawer(int n){
    int c=n+2;
    for(int i=0; i<c; i++){
        printf(".");
    }
    for(int y=0; y<n; y++){
        printf("\n");
        printf("-");
        for(int z=0; z<n; z++){
            printf("v");
        }
        printf("-");
    }
    printf("\n");
    for(int x=0; x<c; x++){
        printf(".");
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    drawer(a);
    return 0;
}
