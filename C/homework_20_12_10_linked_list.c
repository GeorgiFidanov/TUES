#include <stdio.h>
struct human {
    int age;
    int height;
    double weight;
    char *name;
};
struct node{
    struct node *prev;
    struct node *next;
    int value;
};
void printForward(struct node *current){
    if (current != NULL){
    printf("The current value is %d\n", current->value);
    printForward(current->next);
    }
}
void printBackwards(struct node *current){
     if (current == NULL){
        return;
     }
     printf("The current value is %d\n", current->value);
     printBackwards(current->prev);
}
struct node *findFirst(struct node *current){
    if(current->prev==NULL){
        return current;
    }
    return findFirst(current->prev);
};
void addNote_(struct node *n,int index){
    if (index == 0){
        newNode->next=current;
        newNode->prev = current->prev;
        current->prev= newNode;
        return;
    }
    addNode_(head, index);
}
void addNode(struct node *n,int index){
    struct node *head = findFirst(n);
    addNode_(head, index);
}
int main()
{
    struct node tail ={NULL, NULL, 15};
    struct node middle ={NULL, &tail, 10};
    struct node head ={NULL, &middle, 5};
    tail.prev = &middle;
    middle.prev = &head;
    printf("The value of the first element is &d.", findFirst(&tail)->value);
   /* printBackwards(&tail);
    printForward(&head);
    printf("%d\n", (head.next)->value);
    printf("%d\n", (middle.next)->value);
    printf("%d\n", ((head.next)->next)->value);
    struct human h1 = {16, 186, 75.3, "Atanas"};
    struct human *ptr = &h1;
    printf("This is %s. He is %d years old, %d cm of height and weights about %0.2f kg.",
       (*ptr).name, ptr->age, ptr->height, (*ptr).weight);*/
    return 0;
}
