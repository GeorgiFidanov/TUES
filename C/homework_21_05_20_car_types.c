#include <stdio.h>
#include <stdlib.h>

enum type{hatchback, kombi, sedan, minivan};
enum condition {good, bad};

typedef struct{
    char name[32];
    int km;
    int power;
    enum type Type;
    enum condition Condition;
}car;

typedef struct{
    car *arr;
    int size;
}list;

void add_to_list(car value, list *cars){
    cars->arr = (car*)realloc(cars->arr, (cars->size + 1) * sizeof(car));
    cars->arr[cars->size] = value;
    cars->size++;
}

void remove_from_list(list *cars, int index){
    for(int i=0; i < cars->size; i++){
        if(i > index){
            cars->arr[i-1] = cars->arr[i];
        }
    }
    cars->size--;
    cars->arr = (car*) realloc(cars->arr, cars->size * sizeof(car));
}

void copy_list(list *old_list, list *new_list){
    new_list->arr = old_list->arr;
    new_list->size = old_list->size;
}

void write_to_file(char *fileName, list *cars){
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
    car test = {" T- Roc Cabrio", 45000, 230, kombi, good};
    car test1 = {" T- Roc rio", 65000, 270, kombi, bad};
    car test2 = {"Roc", 75000, 530, sedan, good};
    cars->arr = (car*)malloc(sizeof(car));
    cars->arr[0] = test;
    cars->size = 1;

    copy_list(cars, cars1);

    add_to_list(test, cars);
    add_to_list(test1, cars);
    add_to_list(test2, cars);

    remove_from_list(cars, 0);
    remove_from_list(cars, 2);

    write_to_file("cars.bin",cars);

    for(int i = 0; i < cars->size; i++){
        printf("%s, %d, %d, %d, %d\n", cars1->arr[i].name, cars1->arr[i].km, cars1->arr[i].power,
                cars1->arr[i].Type, cars1->arr[i].Condition);
    }
    return 0;
}
