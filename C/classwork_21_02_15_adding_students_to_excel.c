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
        {1, "�����", "�����������", "6526545" },
        {2, "�����", "�������", "2223422" },
        {3, "�����", "����������", "4555463" },
        {4, "������", "������", "2345324" },
        {5, "������", "�����", "2343454" },
        {6, "�����", "������", "4566556" },
        {7, "�����", "�����", "2222453" },
        {8, "������", "�������", "6665345" },
        {9, "������", "����", "5643254" },
        {10, "������", "������", "2223422" },
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
