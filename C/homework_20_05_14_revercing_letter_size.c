#include <stdio.h>
#include <stdlib.h>

void obrushtane(char ch){
    if(ch >= 'a' && ch <= 'z'){
        ch-=32;
    }else if(ch >= 'A' && ch <= 'Z'){
        ch+=32;
    }else{
    printf("\nError. Enter a valid symbol.\n");
    return 0;
    }
    printf("%c", ch);
}
int main()
{
    char ch;
    scanf("%c", &ch);
    obrushtane(ch);
    return 0;
}
