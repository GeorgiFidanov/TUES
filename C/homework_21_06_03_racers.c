#include <stdio.h>
#include <stdlib.h>

typedef enum{ferari, mercedes, redbull, mclaren}team;
typedef enum{false, true}boolean;
typedef struct{
    char name[50];
    team Team;
    int first_places;
}racer;

typedef struct{
    racer *arr;
    int size;
}list;

void addToEnd(char *fileName, racer r){
    FILE *f = fopen(fileName, "rb+");
    boolean existing = true;
    if(!f){
        f = fopen(fileName, "wb+");
        if(!f){
            puts("Error");
            return;
        }
    }
    int size = 1;
    if(existing){
        fread(&size, sizeof(int), 1, f);
        size++;
        fseek(f, 0, SEEK_SET);
    }
    fwrite(&size, sizeof(int), 1, f);
    if(existing){
        fseek(f, 0, SEEK_END);
    }
    fwrite(&r, sizeof(racer), 1, f);

    fclose(f);
}

void printFile(char *fileName){
    FILE *f = fopen(fileName, "rb");
    if(!f){
        printf("Error");
        return;
    }

    int size;
    fread(&size, sizeof(int), 1, f);
    racer racers[size];
    fread(racers, sizeof(racer), size, f);

    fclose(f);

    for(int i = 0; i < size-1; i++){
        printf("%s, %d, %d\n", racers[i].name, racers[i].Team, racers[i].first_places);
    }

}



int main()
{
    racer r1 = {"Milano", redbull, 7};
    racer r2 = {"Yohan", mercedes, 10};
    racer r3 = {"Bjorn", ferari, 14};

    addToEnd("test.bin", r1);
    addToEnd("test.bin", r2);
    addToEnd("test.bin", r3);

    printFile("test.bin");



    return 0;
}
