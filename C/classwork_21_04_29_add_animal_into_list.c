#include <stdio.h>
#include <stdlib.h>

enum boolean1{false,true};
enum boolean2{none, shortt, medium, longg};

struct animal{
    int number_of_legs;
    char colour[20];
    enum boolean2 hair;
    char name[20];
};

void save_to_list(char *fileName, struct animal *cat){
    FILE *f = fopen(fileName, "rb+");
    enum boolean1 is_new_file = false;

    if(!f){
        f = fopen(fileName, "wb");
        is_new_file = true;
    }

    int size = 1;

    if(!is_new_file){
        fread(&size, sizeof(int), 1, f);
        size++;
        fseek(f, 0, SEEK_SET);
    }

    fwrite(&size, sizeof(int), 1, f);

    if(!is_new_file){
        fseek(f, 0, SEEK_END);
    }

    fwrite(cat, sizeof(struct animal), 1, f);

    fclose(f);
}

void readList(char *fileName){

}

int main()
{
    struct animal British_long = {4, "grey", longg, "Lagerta"};
    save_to_list("animalList.bin", &British_long);
}
