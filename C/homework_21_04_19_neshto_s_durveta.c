#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum boolean {False, True};

struct node {
    char* value;
    struct node *next;
    struct node *prev;
};

//1 ex.
char* strcopy1(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++);

    char *output = (char*)malloc((i + 1) * sizeof(char));

    for (int j = 0; j < i + 1; j++) {
        output[j] = str[j];
    }

    return output;
}

struct node* create(char* value){
    struct node *new = (struct node*)calloc(1, sizeof(struct node));
    new->next = NULL;
    new->prev = NULL;
    new->value = strcopy1(value);
    return new;
}

//2 ex.
// 3ex. Edna Funkciq
struct node* getBeginning(struct node *head) {
    if (head->prev == NULL) {
        return head;
    }

    return getBeginning(head->prev);
}

void print(struct node* head){
    struct node* cpy = getBeginning(head);
    struct node* now = cpy;
    while(now != NULL) {
        puts(now->value);

        now = now->next;
    }
}

//3 ex.
struct node* getTail(struct node *head) {
    if (head->next == NULL) {
        return head;
    }

    return getTail(head->next);
}

void add(struct node *head, char *value, int mode) {
    //mode 2 => End
    //mode 1 => Beggining
    struct node *newNode = create(value);

    if(mode == 2){
        struct node *tail = getTail(head);
        tail->next = newNode;
        newNode->prev = tail;
    }else if(mode == 1){
        struct node *tail = getBeginning(head);
        tail->prev = newNode;
        newNode->next = tail;
    }
    
}

//4 ex.
struct node* deleteElement(struct node* head, char* str){
    struct node* back = getBeginning(head);
    struct node* curr = back;

    while(strcmp(curr->value, str)){
        back = curr;
        curr = curr->next;
    }

    if (back->prev == NULL) {
        struct node *result = curr->next;

        free(curr);

        return result;
    }

    back->next = curr->next;

    free(curr);

    return head;
}

void swap(struct node *one, struct node *two){
    struct node temp = *one;
    *one = *two;
    *two = temp;
}
void sort(struct node *nodes, int size) {
    /*Code*/
}

void same(struct node* head1, struct node* head2){
    struct node* back1 = getBeginning(head1);
    struct node* now1 = back1;

    struct node* back2 = getBeginning(head2);
    struct node* now2 = back2;
    int len1 = 1;
    int len2 = 1;

    enum boolean IsItThere = False;

    while(now1 != NULL) {
        len1++;
        now1 = now1->next;
    }

    while(now2 != NULL) {
        len2++;
        now2 = now2->next;
    }

    if(len1 == len2){
        sort(head1, len1);
        sort(head2, len2);

        struct node* curr1 = getBeginning(head1);
        struct node* curr2 = getBeginning(head2);

        for(int j = 0; j < len1; j++){
            if(!strcmp(curr1->value, curr2->value)){
                IsItThere = True;
                curr1 = curr1->next;
                curr2 = curr2->next;
            } 
            
            if(IsItThere == True){
                IsItThere = False;
            }else{
                printf("They are not the same!1");
                return;
            }
        }
    }else{
        printf("They are not the same!2");
        return;
    }

    printf("They are the same!");

}

int main(){
    /*1 ex
    struct node* n = create("Pizza");*/
    /*3 ex.    
    add(n, "Sushi", 2);
    add(n, "Fish", 2);
    add(n, "Duner", 2);
    add(n, "Pepsi", 1);
    add(n, "Cola", 1);
    add(n, "Fanta", 1);
    add(n, "Cola", 2);
    add(n, "Fish", 1);*/ 
    /*2 ex.
    print(n);
    printf("===========================================================\n");*/
    /*4 ex.
    n = deleteElement(n, "Fish");
    print(n);*/
    /*5 ex.
    struct node* test1 = create("Pizza");
    add(test1, "Duner", 1);
    struct node* test2 = create("Pizza");
    add(test2, "Duner", 2);
    print(test1);
    printf("===================\n");
    print(test2);
    same(test1, test2);*/
}