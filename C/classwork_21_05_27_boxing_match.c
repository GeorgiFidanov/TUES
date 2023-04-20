#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum boolean{false, true};

typedef struct{
    char name[32];
    int debut;
    int wins;
    int looses;
}boxer;
///създаваме стуктура за боксьор
void addToFile(char *fileName, boxer value){
    ///Записваме боксьор на края на бинарен файл
    ///Ако файла не съществува, то той се създава
    ///Първият елемент от файла е запазен за броя на боксьорите
    FILE *f = fopen(fileName, "rb+");
    enum boolean isPreEx = true;
///задаваме  емумерацията след като се е отворил файла
    if(!f){
        f = fopen(fileName, "wb");
        isPreEx = false;
///проверяваме дали  се е отворил файла и слагаме за индикация за грешка, ако навлесезем тук
        if(!f){
            puts("Error!");
            return;
        }
    }

    int size = 1;
    if(isPreEx){///докато енумерацията е вярна
        fread(&size, sizeof(int), 1, f);///проверяваме размерът на променливата size в файлът
        size++;
        fseek(f, 0, SEEK_SET);///слагамме писането във файла за началото
    }

    fwrite(&size, sizeof(int), 1, f);///записваме размерът на променливата size в файлът

    if(isPreEx){
        fseek(f, 0, SEEK_END);///слагамме писането в краят
    }

    fwrite(&value, sizeof(boxer), 1, f);///записваме структурата

    fclose(f);///затваряме файла
}

void print(char *fileName){
    ///Принтираме всички боксьори от избрания бинарен файл
    ///Първият елемент от файла е запазен за броя на боксьорите.
    FILE *f = fopen(fileName, "rb");
    if(!f){
        puts("Error!");
        return;
    }

    int size;
    fread(&size, sizeof(int), 1, f);

    boxer boxers[size];///създаваме масив от последната структура
    fread(boxers, sizeof(boxer), size, f);///запълваме масива с информация от файлът

    fclose(f);

    for(int i = 0; i < size; i++){///циклим през масивът от последната структура и принтираме
        printf("%s %d %d %d\n", boxers[i].name, boxers[i].debut, boxers[i].wins, boxers[i].looses);
    }
}

void box(char *fileName){
    ///Симулираме боксов мач
    ///Избираме двама боксьори на случаен принцип от бинарен файл
    ///Отново на случаен принцип избираме победител между двамата
    ///Принтираме победителя и обновяваме броя победи/загуби и на двамата
    ///Първият елемент от файла е запазен за броя на боксьорите.
    FILE *f = fopen(fileName, "rb+");

    if(!f){
        puts("Error!");
        return;
    }

    int size;
    fread(&size, sizeof(int), 1, f);///гледаме къде е записан size във файлът

    if(size < 2){
        puts("Error!");

    }
///ако размрът на участващите е повече от 2, вадим грешка
    int indexes[2];
    indexes[0] = rand() % size;
///салагаме първият боксьор да има случаен резултат
    do{
        indexes[1] = rand() % size;///след това повтаряме за втория
    }while(indexes[0] == indexes[1]);

    boxer boxers[2];

    fseek(f, sizeof(int) + (indexes[0] * sizeof(boxer)), SEEK_SET);
    fread(&(boxers[0]), sizeof(boxer), 1, f);

    fseek(f, sizeof(int) + (indexes[1] * sizeof(boxer)), SEEK_SET);
    fread(&(boxers[1]), sizeof(boxer), 1, f);

    int winer = rand() % 2;
///задава се случаен победител
    printf("Winner is %s\n", boxers[winer].name);

    if(winer == 0){
        boxers[0].wins++;
        boxers[1].looses++;
    }else{
        boxers[1].wins++;
        boxers[0].looses++;
    }///прибавят се текущите резултати към вече съществуващите им такива

    fseek(f, sizeof(int) + (indexes[0] * sizeof(boxer)), SEEK_SET);
    fread(&(boxers[0]), sizeof(boxer), 1, f);

    fseek(f, sizeof(int) + (indexes[1] * sizeof(boxer)), SEEK_SET);
    fread(&(boxers[1]), sizeof(boxer), 1, f);

    fclose(f);
}

int main()
{
    srand(time(NULL));
    print("boxer.bin");
///изжикжаме функциите
    box("boxer.bin");
    /*boxer b = {"Petar", 2010, 10, 2};
    boxer b1 = {"Ivan", 2015, 20, 5};
    boxer b2 = {"Georgi", 2010, 15, 1};
    boxer b3 = {"Teo", 2010, 23, 3};

    addToFile("boxer.bin", b);
    addToFile("boxer.bin", b1);
    addToFile("boxer.bin", b2);
    addToFile("boxer.bin", b3);*/
    return 0;
}
