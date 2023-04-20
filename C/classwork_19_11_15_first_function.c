#include <stdio.h>
#include <stdlib.h>

int powfunc(int x,int y){
    int a = pow(x,y);
    return a;
}

int main(){
    int x,y;
    printf("Vuvedi x - \n");
    scanf("%d", &x);
    printf("Vuvedi y - \n");
    scanf("%d", &y);
    printf("%d na stepen %d e - %d\n",x,y,powfunc(x,y));
    return 0;
}
