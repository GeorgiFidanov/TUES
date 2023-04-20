#include <stdio.h>
#include <stdlib.h>

enum mythology{Greek, Scandinavian, Christian, Slavic, other};
enum behaviour {good, bad};

typedef struct{
    char name[32];
    enum mythology Mythology;
    int legs;
    enum behaviour Behaviour;
}creature;

typedef struct{
    creature *arr;
    int size;
}list;

void add_to_list(creature value, list *creatures){
    creatures->arr = (creature*)realloc(creatures->arr, (creatures->size + 1) * sizeof(creature));
    creatures->arr[creatures->size] = value;
    creatures->size++;
}

void write_to_file(char *fileName, list *creatures){
    FILE *f = fopen(fileName,"wb");
    int size = creatures->size;
    fwrite(&size, sizeof(int), 1, f);
    fwrite(creatures->arr, sizeof(creature), size, f);

    fclose(f);
}

list read_from_file(char *fileName){
    list creatures;
    FILE *f = fopen(fileName, "rb");
     if (!f) {
        printf("Error!");
        return;
    }
    fread(&creatures.size, sizeof(int), 1, f);
    creatures.arr = malloc(creatures.size * sizeof(creature));
    fread(creatures.arr, sizeof(creature), creatures.size, f);
    fclose(f);
    return creatures;
}


int main()
{
    list *creatures = malloc(sizeof(list));
    list creatures1 = read_from_file("creatures.bin");
    creature test = {"Zevs", Greek, 2, good};
    creature test1 = {"Tangra", Slavic, 2, bad};
    creature test2 = {"Torro", other, 5, good};
    creatures->arr = (creature*)NULL;
    creatures->size = 0;

    add_to_list(test, creatures);
    add_to_list(test1, creatures);
    add_to_list(test2, creatures);

    write_to_file("creatures.bin",creatures);

    for(int i = 0; i < creatures->size; i++){
        printf("%s, %d, %d, %d\n", creatures->arr[i].name, creatures->arr[i].Mythology, creatures->arr[i].legs,
                creatures->arr[i].Behaviour);
    }
    return 0;
}
