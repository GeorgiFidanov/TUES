#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x)/ sizeof((x)[0]))

typedef struct student{
    int number;
    char name[128];
    char lastname[128];
    char grades[128];
}student;

int main()
{
    student people[] = {
        {1, "Алеко", "Александров", "6526545" },
        {2, "Васил", "Любенов", "2223422" },
        {3, "Васил", "Мирославов", "4555463" },
        {4, "Георги", "Добрев", "2345324" },
        {5, "Даниел", "Томов", "2343454" },
        {6, "Елена", "Вутева", "4566556" },
        {7, "Жельо", "Желев", "2222453" },
        {8, "Знайко", "Знайков", "6665345" },
        {9, "Ивайло", "Пеев", "5643254" },
        {10, "Йордан", "Якимов", "2223422" },
    };
    FILE *fp = fopen("9b_4.csv","w");
    for(int i=0;i<ARRAY_SIZE(people);i++){
        fprintf(fp,"%d,%s,%s",people[i].number,people[i].name,people[i].lastname);
        for (char *c = people[i].grades; *c; c++) fprintf(fp, ",%c", *c);
        fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}
