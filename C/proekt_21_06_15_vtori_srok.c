#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {miner, supervisor, manager, engineer, other}position;

typedef struct{
    char first_name[32];
    char last_name[32];
    int age;
    int height;
     position current_position;
    int salary;

}worker;

typedef struct{
    worker *arr;
    int size;
}list;

typedef struct {
    char teamName[32];
    int size;
    worker head;
    worker *members;
}team;

void add_worker(worker value, list *workers){
    workers->arr = (worker*) realloc(workers->arr,(workers->size + 1) * sizeof(worker));
    workers->arr[workers->size] = value;
    workers->size++;
}

void remove_worker(int index, list *workers){
    for(int i=0; i<workers->size; ++i){

        if(i>index){
            workers->arr[i-1] = workers->arr[i];
        }
    }

    workers->size--;
    workers->arr = realloc(workers->arr, workers->size * sizeof(workers));
}

void add_to_file(char *fileName, list *workers,worker new_worker){
    add_worker(new_worker, workers);
    FILE *f = fopen(fileName,"rb+");
    if(!f){
        printf("Problem while opening file to add\n");
        return;
    }

    int size = workers->size;
    fwrite(&size, sizeof(int),1,f);

    fseek(f,0,SEEK_END);
    fwrite(&new_worker, sizeof(worker), 1, f);
    fclose(f);
}

struct list* read_from_file(char *fileName){
    FILE *f = fopen(fileName,"rb");

    if (!f) {
        puts("Error!");
        return NULL;
    }
    int size;
    fread(&size,sizeof(int), 1, f);

    worker *workerArr = (worker*) malloc(size * sizeof(worker));
    fread(workerArr,sizeof(worker), size, f);

    fclose(f);

    list *output = (list*) malloc(sizeof(list));
    output->size = size;
    output->arr = workerArr;
    return output;
}

void edit(char *filename, list *workers, char *first_name, char *last_name, int age,
    int height, position current_position, int salary, int index){

    index --;
    worker temp = workers -> arr[index];

    strcpy(temp.first_name,first_name);
    strcpy(temp.last_name,last_name);
    temp.age = age;
    temp.height = height;
    temp.current_position = current_position;
    temp.salary = salary;

    workers -> arr[index] = temp;

    FILE *f = fopen(filename, "rb+");

    fseek(f, sizeof(int) + (index * sizeof(worker)), SEEK_SET);
    fwrite(&temp, sizeof(worker), 1, f);
    fclose(f);

}

void delete_in_file(char *fileName,list *workers, int index){
    index--;
    remove_worker(index, workers);
}

void print(list *workers){
    for (int i = 0; i < workers->size; i++) {
        printf("%d:%s %s, %d, %d-years old, %dsm tall", i+1, workers->arr[i].first_name,
        workers->arr[i].last_name, workers->arr[i].salary, workers->arr[i].age,
        workers->arr[i].height );
        switch(workers->arr[i].current_position){
        case 0:
            printf("Miner\n");
            break;
        case 1:
            printf("Supervisor\n");
            break;
        case 2:
            printf("Manager\n");
            break;
        case 3:
            printf("Engineer\n");
            break;
        case 4:
            printf("Other\n");
            break;
        default:
            printf("N/A\n");
        }
    }
}

void instructions(){
    FILE *f = fopen("instruction.txt","r");
    char buffer[255];
    while(fgets(buffer, 255, f)){
        printf("%s", buffer);
    }
    fclose(f);
}

void swap(worker *a, worker *b){
    worker temp = *a;
    *a = *b;
    *b = temp;
}

void sorted(list *workers,int sortvar){
    list *temp = workers;
    for(int i = 0; i < temp->size; i++){
        for(int j = 0; j < temp->size-i-1; j++){
            if(sortvar == 1){
                if(temp->arr[j].salary > temp->arr[j+1].salary){
                    swap(&temp->arr[j], &temp->arr[j+1]);
                }
            }
            else if(sortvar == 2){
                if(temp->arr[j].current_position < temp->arr[j+1].current_position){
                    swap(&temp->arr[j], &temp->arr[j+1]);
                }
            }
            else if(sortvar == 3){
                if(temp->arr[j].first_name[0] > temp->arr[j+1].first_name[0]){
                    swap(&temp->arr[j], &temp->arr[j+1]);
                }
            }
            else if(sortvar == 4){
                if(temp->arr[j].last_name[0] > temp->arr[j+1].last_name[0]){
                    swap(&temp->arr[j], &temp->arr[j+1]);
                }
            }
            else if(sortvar == 5){
                if(temp->arr[j].age > temp->arr[j+1].age){
                    swap(&temp->arr[j], &temp->arr[j+1]);
                }
            }
            else if(sortvar == 6){
                if(temp->arr[j].height > temp->arr[j+1].height){
                    swap(&temp->arr[j], &temp->arr[j+1]);
                }
            }
        }
    }
    print(temp);
}

void filtered(list *workers, int value, int ans){
    list *temp = workers;
    for(int i = 0; i < temp->size; i++){
        for(int j = 0; j < temp->size-i-1; j++){
            if(temp->arr[j].salary > temp->arr[j+1].salary){
                    swap(&temp->arr[j], &temp->arr[j+1]);
                }
        }
    }

    for(int i = 0; i < temp->size; i++){
        if(ans == 1){
            if(temp->arr[i].salary < value){
               printf("%d:%s %s, %d, %d-years old, %dsm tall", i+1, temp->arr[i].first_name,
        temp->arr[i].last_name, temp->arr[i].salary, temp->arr[i].age,
        temp->arr[i].height );
                switch(temp->arr[i].current_position){
                case 0:
                    printf("Miner\n");
                    break;
                case 1:
                    printf("Supervisor\n");
                    break;
                case 2:
                    printf("Manager\n");
                    break;
                case 3:
                    printf("Engineer\n");
                    break;
                case 4:
                    printf("Other\n");
                    break;
                default:
                    printf("N/A\n");
                }
            }
        }
        else{
            if(temp->arr[i].salary > value){
            printf("%d:%s %s, %d, %d-years old, %dsm tall", i+1, temp->arr[i].first_name,
        temp->arr[i].last_name, temp->arr[i].salary, temp->arr[i].age,
        temp->arr[i].height );
                switch(temp->arr[i].current_position){
                case 0:
                    printf("Miner\n");
                    break;
                case 1:
                    printf("Supervisor\n");
                    break;
                case 2:
                    printf("Manager\n");
                    break;
                case 3:
                    printf("Engineer\n");
                    break;
                case 4:
                    printf("Other\n");
                    break;
                default:
                    printf("N/A\n");
                }
            }
        }
    }
}

void worker_details(list *workers, int i){
    if(i > workers->size || i < 1){
        printf("Error! Non-existent person!");
        return ;
    }
    i--;
    printf("=========================================\n");
    printf("    Worker number: %d\n     First name: %s\n    Last name: %s\n    Age:%d\n    Height:%dsm- tall\n      Salary: %d lv.\n",
    i+1, workers->arr[i].first_name,
        workers->arr[i].last_name, workers->arr[i].age,
        workers->arr[i].height, workers->arr[i].salary);

        switch(workers->arr[i].current_position){
    case 0:
        printf("    Profession: Miner\n");
        break;
    case 1:
        printf("    Profession: Supervisor\n");
        break;
    case 2:
        printf("    Profession: Manager\n");
        break;
    case 3:
        printf("    Profession: Engineer\n");
        break;
    case 4:
        printf("    Other\n");
        break;
    default:
        printf("N/A\n");
    };
    printf("============================================");
}

int main()
{
    struct list *workers = read_from_file("list.bin");
    int ans, ans1, index, salary, id = 1;
    char answer[32];
    char first_name[32];
    char last_name[32];
    int age, height;
    position current_position;

    menu:
    instructions();

    printf("Please select an answer: (answer must be chosen between 0 and 7)");
    scanf("%d", &ans);

    if(ans == 0){
        printf("Goodbye!");
        return 0;
    }
    else if(ans == 1){ //read and print
        system("cls"); //clearing screen
        printf("The workers of WE\n-----------------------------------\n");
        print(workers);
        printf("-----------------------------------");

        printf("\nGo back to main menu? ");
        scanf("%s", answer);
        if(!strcmp(answer,"yes") || !strcmp(answer,"Yes")){
            system("cls");
            goto menu;
        }else{printf("Goodbye!");}
    }
    else if(ans == 2){ //edit
        system("cls");
        printf("You have selected the edit option.\nPlease select the person you want to edit by his index: ");
        scanf("%d",&index);
        printf("Excellent! Please change your selected worker(%d)(first_name, last_name, position, age, height, salary):\n",index);
        scanf("%s %s %d %d %d %d",first_name, last_name, &age, &height, &current_position, &salary);
        edit("list.bin", workers, first_name, last_name, age, height, current_position, salary, index);
        printf("Success!");

        printf("\nGo back to main menu? ");
        scanf("%s", answer);
        if(!strcmp(answer,"yes") || !strcmp(answer,"Yes")){
            system("cls");
            goto menu;
        }else{
            printf("Goodbye!");}
    }
    else if(ans == 3){ //add
        system("cls");
        printf("You have selected the add option.\nPlease describe the person you want to add.(first_name, last_name, age, height, position, salary):\n");
        scanf("%s %s %d %d %d %d", &first_name, &last_name, &age, &height, &current_position, &salary);

        worker temp;
        strcpy(temp.first_name, first_name);
        strcpy(temp.last_name, last_name);
        temp.age = age;
        temp.height = height;
        temp.current_position = current_position;
        temp.salary = salary;

        add_to_file("list.bin", workers, temp);
        printf("Success!");

        printf("\nGo back to main menu? ");
        scanf("%s", answer);
        if(!strcmp(answer,"yes") || !strcmp(answer,"Yes")){
            system("cls");
            goto menu;
        }else{
            printf("Goodbye!");}
    }
    else if(ans == 4){ //remove
        system("cls");
        printf("You have selected the delete option.\nPlease select the person you want to remove by his index: ");
        scanf("%d", &index);
        delete_in_file("list.bin", workers, index);
        printf("Success!");

        printf("\nGo back to main menu? ");
        scanf("%s", answer);
        if(!strcmp(answer,"yes") || !strcmp(answer,"Yes")){
            system("cls");
            goto menu;
        }else{
            printf("Goodbye!");}
    }
    else if(ans == 5){
        system("cls");
        printf("You have chosen to view a sorted list of the employees.\nPlease choose the order: salary (1), working position (2),");
        printf("first name (3), last name (4), age(5), height(6):");
        scanf("%d",&ans1);

        printf("\nThe workers of WE\n-------------------------------------\n");
        sorted(workers, ans1);
        printf("--------------------------------------");

        printf("\nGo back to main menu? ");
        scanf("%s", answer);
        if(!strcmp(answer,"yes") || !strcmp(answer,"Yes")){
            system("cls");
            goto menu;
        }else{
            printf("Goodbye!");}
    }
    else if(ans == 6){
        system("cls");
        printf("You have chosen to view a filtered list of the employees.\n");
        printf("Please choose the value of the salary: ");
        scanf("%d",&ans);
        printf("Great, now decide if you want to view the employees with lower(1) or higher(2) wage: ");
        scanf("%d",&ans1);

        printf("\nThe workers of WE\n-----------------------------------\n");
        filtered(workers, ans, ans1);
        printf("-----------------------------------");

        printf("\nGo back to main menu? ");
        scanf("%s", answer);
        if(!strcmp(answer,"yes") || !strcmp(answer,"Yes")){
            system("cls");
            goto menu;
        }else{
            printf("Goodbye!");}
    }
    else if(ans == 7){
        system("cls");
        worker_details(workers, id);
        next_person:
        printf("\nPlease enter (N) to see the next, (P) the previous or (E) to edit the current person and");
        printf("(B) to go back to main menu: ");
        scanf("%s", answer);
        if(!strcmp(answer,"n") || !strcmp(answer,"N")){
            system("cls");
            id++;
            worker_details(workers, id);
            goto next_person;
        }
        else if(!strcmp(answer,"p") || !strcmp(answer,"P")){
            system("cls");
            id--;
            worker_details(workers, id);
            goto next_person;
        }
        else if(!strcmp(answer,"b") || !strcmp(answer,"B")){
            system("cls");
            goto menu;
        }
        else if(!strcmp(answer,"e") || !strcmp(answer,"E")){
            system("cls");
            printf("You have selected the edit option.");
            printf("Excellent! Please change your selected worker(%d)(fName, lName, salary, position, age, height):\n",index);
        scanf("%s %s %d %d %d %d",&first_name, &last_name, &age, &height, &current_position, &salary);
        edit("list.bin", workers, first_name, last_name, age, height, current_position, salary, ans);
        printf("Success!");

                printf("\nGo back to main menu? ");
            scanf("%s", answer);
            if(!strcmp(answer,"yes") || !strcmp(answer,"Yes")){
                system("cls");
                goto menu;
            }else{
                printf("Goodbye!");}
        }
        else{printf("Goodbye!");}
    }
    return 0;
}
