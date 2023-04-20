#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bsize 255

enum type{weapon,armour,ring,cloack};

typedef struct{
    double weight;
    enum type type;
    char name[bsize];
    char desc[bsize];
}item;

void Swap(item *one, item *two){
    item three = *one;
    *one = *two;
    *two = three;
}

void sortFile(item *buffer,int size){
    for (int i = 0; i <= size; i++) {
        for (int j = i; j < size; j++) {
            if (buffer[i].type > buffer[j].type) {
                Swap(&buffer[i], &buffer[j]);
            }
        }
    }
}

void printSorted(char *fileName,item buffer[bsize],int size){
    FILE *f = fopen(fileName,"rb");
    for(int i = 0; i < size; i++){
        fread(&buffer[i], sizeof(item), 1, f);
    }
    sortFile(buffer,size);
    for (int i = 0; i < size; i++) {
            printf("%.1f, ", buffer[i].weight);

            switch(buffer[i].type){
                case 0:
                printf("weapon");
                break;
                case 1:
                printf("armour");
                break;
                case 2:
                printf("ring");
                break;
                case 3:
                printf("cloack");
                break;
                default:
                printf("non-existent type");

            }
            printf(", %s, %s\n", buffer[i].name, buffer[i].desc);
    }
    fclose(f);
}

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
    //printSorted("example.bin",buffer,size);
    //addItem("example.bin",buffer,size);
    //copyFile("example.bin","new.bin",&buffer);
    //printSorted("new.bin",buffer,size);
    return 0;
}
