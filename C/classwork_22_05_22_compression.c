#include <stdio.h>
#include <stdlib.h>

char compress(char *str){
    char compressed = str[0];
    return compressed;
}


void decompress(char compressed){
    int size = 50;
    char original[size];

    for(int i = 0; i < size; i++){
        if(i % 5 == 0){
            original[i] = ' ';
            continue;
        }
        original[i] = compressed;
    }
    original[size] = '\0';

    printf("\nORIGINAL: %s", original);
}


int main()
{
    /*
    printf("num_str:");
    int num_str = 0;
    scanf("%d", &num_str);
    char *str;
    for(int i =0; num_str < i; i++){
        printf("enter str");
        scanf("%s", &str);
        compress(str);
    }
    */
    char num_of_str = 0;
    printf("enter number of strings");
    scanf("%c", &num_of_str);
    char compressed = 0;
    char *str;
    for(char i= 0; i<num_of_str; i++){

        printf("enter str: ");
        scanf("%s", &str);

        compressed = compress(str);

        printf("COMPRESSED: %c", compressed);

        decompress(compressed);

    }
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

char compress(char *str){
    char compressed = str[0];
    return compressed;
}


void decompress(char compressed){
    int size = 50;
    char original[size];

    for(int i = 0; i < size; i++){
        if(i % 5 == 0){
            original[i] = ' ';
            continue;
        }
        original[i] = compressed;
    }
    original[size] = '\0';

    printf("\nORIGINAL: %s", original);
}


int main()
{

    printf("num_str:");
    int num_str = 0;
    scanf("%d", &num_str);
    char *str;
    for(int i =0; num_str < i; i++){
        printf("enter str");
        scanf("%s", &str);
        compress(str);
    }


    char compressed = compress("aaaa aaaa aaaa aaaa aaaa aaaa aaaa aaaa aaaa aaaa");

    printf("COMPRESSED: %c", compressed);

    decompress(compressed);


    return 0;
*/
