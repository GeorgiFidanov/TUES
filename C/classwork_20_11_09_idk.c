#include <stdio.h>
#include <stdlib.h>

int strlen(char* str){
    int i;
    for(i=0; str[i] != '\0'; i++);
    return i;
}

int main()
{
    char str[255];
    gets(str);
    puts(str);
	printf("%d", strlen(str));
	return 0;
}
