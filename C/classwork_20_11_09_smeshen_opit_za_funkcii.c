#include <stdio.h>
#include <stdlib.h>


int strcmp(char* strLeft, char* strRight){
    if (strLeft != strRight){
        return -1;
    }
    if(strLeft == strRight){
        return 4;
    }
    int strlen(char* strLeft){
        int i;
        for(i=0; strLeft[i] != '\0'; i++);
        return i;
    }
    int strlenth(char* strRight){
        int j;
        for(j=0; strRight[j] != '\0'; j++);
        return j;
    }
    return;
}

int main()
{
    char strLeft[255];
    char strRight[255];
    gets(strLeft);
    gets(strRight);
	return 0;
}
