#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bsize 255
enum type{weapon,armour,ring,chakra};

struct object{
    float weight;
    enum type type;
    char name[bsize];
    char description[bsize];
}item;

void swap(struct object item *obj1, struct object item *obj2){
    item temp = *obj1;
    *obj1 = *obj2;
    *obj2 = temp;
}
void sortFile(struct object item *buffer, int size){
    for (int i = 0; i <= size; i++) {
        for (int j = i; j < size; j++) {
            if (buffer[i].type > buffer[j].type) {
                Swap(&buffer[i], &buffer[j]);
            }
        }
    }
}
void printSorted(char *fileName,struct object item buffer[bsize],int size){
    FILE *f = fopen(fileName,"rb");
    for(int i = 0; i < size; i++){
        fread(&buffer[i], sizeof(item), 1, f);
    }
    sortFile(buffer,size);
    void addItem(char *fileName, item *buffer,int size){
    FILE *f = fopen(fileName,"ab");
    item add;
    printf("Enter the weight(kg),type(0-3),name and description of your item:");
    scanf("%f %d %s %s",&add.weight,&add.type,add.name,add.desc);
    size++;
    fwrite(&add,sizeof(item),1,f);
    fclose(f);
    printSorted(fileName,&buffer,size);
}

void add(char *fileName, struct object *objects, int){
    FILE *f= fopen(fileName, "");
    if (!f){
        printf("File error!");
    }
    fwrite(objects, sizeof(struct object), ,f);
    fclose(f);
}

void copyFile(char *oldFile,char *newFile,item *buffer){
    FILE *of = fopen(oldFile,"rb");
    FILE *nf = fopen(newFile,"wb");

    int size = bsize;

    while (size == bsize) {
        size = fread(buffer, sizeof(item), bsize, of);

        for (int i = 0; i < size; i++) {
            fwrite(&buffer[i], sizeof(item), 1, nf);
        }
    }

    fclose(of);
    fclose(nf);
}

int main()
{
    item buffer[bsize];
    int size = 12;
    return 0;
}
