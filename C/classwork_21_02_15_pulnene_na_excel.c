#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct Student {
    int number;
    char first_name[128];
    char last_name[128];
    char grades[128];
} Student;

int main() {
    Student students[] = {
        { 1,  "Алекс",     "Александров", "6526545" },
        { 2,  "Боряна",    "Борисова",    "2223422" },
        { 3,  "Васил",     "Верославов",  "4555463" },
        { 4,  "Габриел",   "Георгиев",    "2345324" },
        { 5,  "Даниел",    "Добромиров",  "2343454" },
        { 6,  "Екатерина", "Еленска",     "4566556" },
        { 7,  "Жельо",     "Желев",       "2222453" },
        { 8,  "Знайко",    "Знайков",     "6665345" },
        { 9,  "Иван",      "Иванов",      "5643254" },
        { 10, "Йоан",      "Йорданов",    "2223422" },
    };
    FILE *fp = fopen("9b_23.csv", "w");
    for (int i = 0; i < ARRAY_SIZE(students); ++i) {
        fprintf(fp, "%d,%s,%s", students[i].number, students[i].first_name, students[i].last_name);
        for (char *c = students[i].grades; *c; ++c) fprintf(fp, ",%c", *c);
        fprintf(fp, "\n");
    }
    fclose(fp);
}
