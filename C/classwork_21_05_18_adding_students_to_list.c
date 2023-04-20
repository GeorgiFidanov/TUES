#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char firstName[32];
    char lastName[32];
    int grade;
    char className;
    int number;
}student;
 ///struktura za uchenik
typedef struct{
    student *arr;
    int size;
}list;
///vuvejdame list
void add(student value, list *students){
    students->arr = (student*) realloc(students->arr,(students->size + 1) * sizeof(student)); /// relokirame pametta, za da ima mqsto za dobavqne na uchenik
    students->arr[students->size] = value; /// dobavqme uchenika kum lista
    students->size++; ///uvelichavame razmera
}

void removeS(int index,list *students){
    for(int i=0; i<students->size; ++i){

        if(i>index){
            students->arr[i-1] = students->arr[i]; ///premestvame s edno napred uchenicite ot students, ako i e po-golqmo ot uchenika, koito iskame da mahnem
        }
    }

    students->size--; ///namalqme razmera
    students->arr = realloc(students->arr, students->size * sizeof(students)); ///relokirame pametta s promeneniqt razmer
}

void addToFile(list *students,char *fileName){
    FILE *f = fopen(fileName,"wb"); ///otvarqme/suzdavame faila

    int size = students->size; ///suzdavame promenliva za razmer
    fwrite(&size,sizeof(int),1,f); ///zapazvame razmera na lista
    fwrite(students->arr,sizeof(student),size,f); /// zapisvame uchenicite v faila

    fclose(f); ///zatvarqme faila
}

struct list *readF(char *fileName){
    FILE *f = fopen(fileName,"rb"); ///otvarqme faila

    if(!f)printf("Error");return NULL; ///proverqva dali faila sushtestvuva

    int size;
    fread(&size,sizeof(int),1,f); ///prochitame razmera na masiva

    student *studentArr = (student*) malloc(size * sizeof(student)); /// zadavame dinamichno pametta na masiva s prochetiq razmer
    fread(studentArr,sizeof(student),size,f); ///prochitame uchenicite

    fclose(f);

    list *output = (list*) malloc(sizeof(list)); ///dinamichno zadelqme pamet
    output->size = size;  ///zapisvame prochetenoto v nov list
    output->arr = studentArr;
    return output; ///vrushtame procheteno
}

int main()
{
    list *students = malloc(sizeof(list));

    student test = {"Georgi","Fidanov", 9, 'B', 4};

    students->arr = (student*) malloc(sizeof(student));
    students->arr[0] = test;
    students->size = 1;

    test.grade = 12;
    add(test,students);

    test.grade = 11;
    add(test,students);

    addToFile(students,"test.bin");

    //removeS(0,students);

    for(int i = 0; i< students->size; i++){
        printf("%s %s No:%d\n", students->arr[i].firstName, students->arr[i].lastName, students->arr[i].grade);
    }
    return 0;
}
