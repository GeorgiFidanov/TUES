#include <stdio.h>
#include <stdlib.h>

enum Type{hatchback, station_wagon, sedan, minivan};
enum Condition {good, bad};

typedef struct{
    char name[32];
    int km;
    int power;
    enum Type type;
    enum Condition condition;
}car;

typedef struct{
    car *arr;
    int size;
}list;

void add(car value, list *cars){
    cars->arr = (car*)realloc(cars->arr, (cars->size + 1) * sizeof(car));
    cars->arr[cars->size] = value;
    cars->size++;
}

void removeFromList(list *cars, int index){
    for(int i=0; i < cars->size; i++){
        if(i > index){
            cars->arr[i-1] = cars->arr[i];
        }
    }
    cars->size--;
    cars->arr = (car*) realloc(cars->arr, cars->size * sizeof(car));
}

void makeCopy(list *oldList, list *newList){
    newList->arr = oldList->arr;
    newList->size = oldList->size;
}

void write(char *fileName, list *cars){
    FILE *f = fopen(fileName,"wb");
    int size = cars->size;
    fwrite(&size, sizeof(int), 1, f);
    fwrite(cars->arr, sizeof(car), size, f);

    fclose(f);
}

int main()
{
    list *cars = malloc(sizeof(list));
    list *cars1 = malloc(sizeof(list));
    car test = {"Dodge Charger Scat Pack", 20000, 470, sedan, good};

    cars->arr = (car*)malloc(sizeof(car));
    cars->arr[0] = test;
    cars->size = 1;

    makeCopy(cars, cars1);

    test.km = 25000;
    add(test, cars);

    removeFromList(cars, 0);

    write("cars.bin",cars);

    for(int i = 0; i < cars->size; i++){
        printf("%s, %d\n", cars1->arr[i].name, cars1->arr[i].km);
    }
    return 0;
}
