#include <stdio.h>
#include <stdlib.h>

void pr(char toPrint, int iters);
int main()
{
   int a;
   char asterisk = '*';
   scanf("%d", &a);
   for(int i = 0; i<= a; i++){
    pr(' ', a-i);
    pr(asterisk, i);
    printf("|");
    pr(asterisk, i);
    printf("\n");
   }
    return 0;
}
void pr(char toPrint, int iters){
    for(int i =0; i < iters; i++){
        printf("%c", toPrint);
    }
}
