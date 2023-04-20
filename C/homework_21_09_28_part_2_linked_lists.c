#include <stdio.h>
#include <stdlib.h>

enum boolean {false, true};

typedef struct node_t {
int value;
struct node_t* next;
struct node_t* prev;
} node_t;

typedef struct linkedlist_t {
node_t* head;
node_t* tail;
int count;
} linkedlist_t;

linkedlist_t* init_linkedlist() {
linkedlist_t* result = malloc(sizeof(linkedlist_t));
result->count = 0;
result->head = NULL;
result->tail = NULL;
}

node_t* init_node(int value) {
node_t* new_node = malloc(sizeof(node_t));
new_node->value = value;
new_node->prev = NULL;
new_node->next = NULL;

return new_node;
}

void push_front(linkedlist_t* list, int value) {
node_t* new_node = init_node(value);
list->count++;

if (list->head == NULL) {
list->head = new_node;
list->tail = new_node;

return;
}

new_node->next = list->head;
list->head->prev = new_node;
list->head = new_node;
}

void push_back(linkedlist_t* list, int value) {
node_t* new_node = init_node(value);
list->count++;

if (list->head == NULL) {
list->head = new_node;
list->tail = new_node;

return;
}

new_node->prev = list->tail;;
list->tail->next = new_node;
list->tail = new_node;
}

void traverse(linkedlist_t* list) {
node_t* current = list->head;
while (current != NULL) {
printf("%d ", current->value);
current = current->next;
}
printf("\n");
}

node_t* find_first(linkedlist_t* list, int value){
    node_t* current = list->head;

    while(current != NULL){
        if(current->value == value){
            return current;
        }
        current = current->next;
    }
    return -1;
}

node_t* find_last(linkedlist_t* list, int value){
    node_t* current = list->tail;

    while(current != NULL){
        if(current->value == value){
            return current;
        }
        current = current->prev;
    }
    return -1;
}

void destroy(linkedlist_t* list){
    free(list);
}

int pop_front(linkedlist_t* list){
    int value = list->head->value;

    node_t* first = list->head;
    list->head = first->next;
    list->head->prev = NULL;
    list->head->next = first->next->next;

    list->count--;
    return value;
}

int pop_back(linkedlist_t* list){
    int value = list->tail->value;

    node_t* last = list->tail;
    list->tail = last->prev;
    list->tail->prev = last->prev->prev;
    list->tail->next = NULL;

    list->count--;
    return value;
}

int peek_front(linkedlist_t* list){
    int value = list->head->value;

    return value;
}

int peek_back(linkedlist_t* list){
    int value = list->tail->value;

    return value;
}

void insert_after(linkedlist_t* list, int index, int value){
    node_t* new_node = init_node(value);
    node_t* curr = list->head;

for(int i=1;i<list->count;i++){
        if(i == index){
            list->count++;
            node_t* temp = curr->next;
            curr->next = new_node;
            new_node->prev = curr;
            new_node->next = temp;
            return;
        }
        curr = curr->next;
}
}

void insert_before(linkedlist_t* list, int index, int value){
    node_t* new_node = init_node(value);
    node_t* curr = list->head;

for(int i=1;i<list->count;i++){
if(i == index-1){
            list->count++;
            node_t* temp = curr->next;
            curr->next = new_node;
            new_node->prev = curr;
            new_node->next = temp;
            return;
        }
        curr = curr->next;
}
}

linkedlist_t* reverse(linkedlist_t* list){
    linkedlist_t* new_list = init_linkedlist();

    node_t* last = list->tail;


    for(int i=0;i<list->count;i++){
        push_back(new_list, last->value);
        last = last->prev;
    }

    return new_list;
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int *arr, int n) {
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++) {
            if(*(arr+j) > *(arr+j+1)){
                swap((arr+j), (arr+j+1));
            }
        }
    }
}

void sort_reverse(int *arr, int n) {
    for (int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++) {
            if(*(arr+j) < *(arr+j+1)){
                swap((arr+j), (arr+j+1));
            }
        }
    }
}

linkedlist_t* sort_ascending(linkedlist_t* list){
    linkedlist_t* new_list = init_linkedlist();
    int arr[list->count];
    node_t* curr = list->head;

    for(int i=0;i<list->count;i++){
        arr[i] = curr->value;
        curr = curr->next;
    }

    sort(arr, list->count);

    for(int i=0;i<list->count;i++){
        push_back(new_list, arr[i]);
    }

    return new_list;
}

linkedlist_t* sort_descending(linkedlist_t* list){
    linkedlist_t* new_list = init_linkedlist();
    int arr[list->count];
    node_t* curr = list->head;

    for(int i=0;i<list->count;i++){
        arr[i] = curr->value;
        curr = curr->next;
    }

    sort_reverse(arr, list->count);

    for(int i=0;i<list->count;i++){
        push_back(new_list, arr[i]);
    }

    return new_list;
}

enum boolean filter_greater_than_10(int a){
    if(a > 10){
        return true;
    }
    return false;
}

linkedlist_t* filter(linkedlist_t* list){
    linkedlist_t* new_list = init_linkedlist();
    node_t* curr = list->head;

    for(int i=0;i<list->count;i++){
        if(filter_greater_than_10(curr->value) == true){
            push_back(new_list, curr->value);
        }
        curr = curr->next;
    }

    return new_list;
}

//insert_after(linkedlist_t* list, node* node) - добавя елемент след даден node в списъка
//insert_before(linkedlist_t* list, node* node) - добавя елемент преди даден node в списъка
int main() {
    linkedlist_t* list = init_linkedlist();
    push_front(list, 8);
    traverse(list);
    push_front(list, 6);
    traverse(list);
    push_front(list, 17);
    traverse(list);
    push_front(list, 4);
    traverse(list);
    push_front(list, 12);
    traverse(list);
    push_front(list, 4);
    traverse(list);
    push_back(list, 9);
    traverse(list);

    printf("\n");

    node_t* node = find_first(list, 6);
    printf("Find first: %d \n", node->value);

    node_t* node2 = find_last(list, 8);
    printf("Find last: %d \n", node2->value);

    int n = pop_front(list);
    printf("Remove first: %d \n", n);


    int n2 = pop_back(list);
    printf("Remove last: %d \n\n", n2);

    traverse(list);

    printf("List count: %d\n", list->count);

    printf("First: %d \n", peek_front(list));
    printf("Last: %d \n\n", peek_back(list));

    printf("list: ");
    traverse(list);

    linkedlist_t* reverse_list = reverse(list);
    printf("Reverse list: ");
    traverse(reverse_list);

    linkedlist_t* sort_list = sort_ascending(list);
    printf("Sort_ascending list: ");
    traverse(sort_list);

    linkedlist_t* sort_list2 = sort_descending(list);
    printf("Sort_descending list: ");
    traverse(sort_list2);

    linkedlist_t* list2 = filter(list);
    printf("Numbers greater than 10 list: ");
    traverse(list2);
    printf("\n");

    printf("List : ");
    traverse(list);
    printf("Add after index 3 number 11\n");
    insert_after(list, 3, 11);
    printf("List : ");
    traverse(list);
    printf("\n");

    printf("List : ");
    traverse(list);
    printf("Add before index 5 number 32\n");
    insert_before(list, 5, 32);
    printf("List : ");
    traverse(list);
    printf("\n");

    destroy(sort_list);
    destroy(sort_list2);
    destroy(list2);
    destroy(list);


    return 0;
}
