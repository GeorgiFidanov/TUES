#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* addArr(char* ourArr, int *size1, char *addArr, int size2){
    *size1 += size2;
    ourArr = realloc(ourArr, *size1 * sizeof(char));
    for(int i = 0; i < size2; i++){
        ourArr[*size1 - size2 + i] = addArr[i];
    }
    return ourArr;
}

int main(){

    int length1 = 3;
    char *Arr1 = (char*) malloc(length1 * sizeof(char));
    Arr1[0] = 'a';
    Arr1[1] = 'b';
    Arr1[2] = 'c';
    int length2 = 3;
    char *Arr2 = (char*) malloc(length2 * sizeof(char));
    Arr2[0] = 'd';
    Arr2[1] = 'e';
    Arr2[2] = 'f';
    Arr1 = addArr(Arr1, &length1, Arr2, length2);
    for(int i = 0; i < length1; i++){
        printf("%c", Arr1[i]);
    }
    free(Arr1);
    free(Arr2);
}


