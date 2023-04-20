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
///��������� �������� �� �������
void addToFile(char *fileName, boxer value){
    ///��������� ������� �� ���� �� ������� ����
    ///��� ����� �� ����������, �� ��� �� �������
    ///������� ������� �� ����� � ������� �� ���� �� ����������
    FILE *f = fopen(fileName, "rb+");
    enum boolean isPreEx = true;
///��������  ������������ ���� ���� �� � ������� �����
    if(!f){
        f = fopen(fileName, "wb");
        isPreEx = false;
///����������� ����  �� � ������� ����� � ������� �� ��������� �� ������, ��� ���������� ���
        if(!f){
            puts("Error!");
            return;
        }
    }

    int size = 1;
    if(isPreEx){///������ ������������ � �����
        fread(&size, sizeof(int), 1, f);///����������� �������� �� ������������ size � ������
        size++;
        fseek(f, 0, SEEK_SET);///�������� �������� ��� ����� �� ��������
    }

    fwrite(&size, sizeof(int), 1, f);///��������� �������� �� ������������ size � ������

    if(isPreEx){
        fseek(f, 0, SEEK_END);///�������� �������� � �����
    }

    fwrite(&value, sizeof(boxer), 1, f);///��������� �����������

    fclose(f);///��������� �����
}

void print(char *fileName){
    ///���������� ������ �������� �� �������� ������� ����
    ///������� ������� �� ����� � ������� �� ���� �� ����������.
    FILE *f = fopen(fileName, "rb");
    if(!f){
        puts("Error!");
        return;
    }

    int size;
    fread(&size, sizeof(int), 1, f);

    boxer boxers[size];///��������� ����� �� ���������� ���������
    fread(boxers, sizeof(boxer), size, f);///��������� ������ � ���������� �� ������

    fclose(f);

    for(int i = 0; i < size; i++){///������ ���� ������� �� ���������� ��������� � ����������
        printf("%s %d %d %d\n", boxers[i].name, boxers[i].debut, boxers[i].wins, boxers[i].looses);
    }
}

void box(char *fileName){
    ///���������� ������ ���
    ///�������� ����� �������� �� ������� ������� �� ������� ����
    ///������ �� ������� ������� �������� ��������� ����� �������
    ///���������� ���������� � ���������� ���� ������/������ � �� �������
    ///������� ������� �� ����� � ������� �� ���� �� ����������.
    FILE *f = fopen(fileName, "rb+");

    if(!f){
        puts("Error!");
        return;
    }

    int size;
    fread(&size, sizeof(int), 1, f);///������� ���� � ������� size ��� ������

    if(size < 2){
        puts("Error!");

    }
///��� ������� �� ����������� � ������ �� 2, ����� ������
    int indexes[2];
    indexes[0] = rand() % size;
///�������� ������� ������� �� ��� ������� ��������
    do{
        indexes[1] = rand() % size;///���� ���� ��������� �� ������
    }while(indexes[0] == indexes[1]);

    boxer boxers[2];

    fseek(f, sizeof(int) + (indexes[0] * sizeof(boxer)), SEEK_SET);
    fread(&(boxers[0]), sizeof(boxer), 1, f);

    fseek(f, sizeof(int) + (indexes[1] * sizeof(boxer)), SEEK_SET);
    fread(&(boxers[1]), sizeof(boxer), 1, f);

    int winer = rand() % 2;
///������ �� ������� ���������
    printf("Winner is %s\n", boxers[winer].name);

    if(winer == 0){
        boxers[0].wins++;
        boxers[1].looses++;
    }else{
        boxers[1].wins++;
        boxers[0].looses++;
    }///�������� �� �������� ��������� ��� ���� �������������� �� ������

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
///��������� ���������
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
