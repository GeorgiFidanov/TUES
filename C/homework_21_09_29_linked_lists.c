#include <stdlib.h>
#include <stdio.h>

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

void traverse(linkedlist_t* list) {
	node_t* current = list->head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
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
}// - добавя елемент в края
 
node_t* find_first(linkedlist_t* list, int value){
    node_t* current = list->head;

    while(current != NULL){
        if(current->value == value){
            return current;
        }
        current = current->next;
    }
    return -1;
}// - връща първия node със дадена стойност

node_t* find_last(linkedlist_t* list, int value){
    node_t* current = list->tail;

    while(current != NULL){
        if(current->value == value){
            return current;
        }
        current = current->prev;
    }
    return -1;
}//- връща последния node със дадена стойност

void destroy(linkedlist_t* list){
    free(list);
} //- освобождава паметта използвана от списъка

int pop_front(linkedlist_t* list){
    int value = list->head->value;

    node_t* first = list->head;
    list->head = first->next;
    list->head->prev = NULL;
    list->head->next = first->next->next;

    list->count--;
    return value;
}  //- премахва първия елемент и връща неговата стойност

int pop_back(linkedlist_t* list){
    int value = list->tail->value;

    node_t* last = list->tail;
    list->tail = last->prev;
    list->tail->prev = last->prev->prev;
    list->tail->next = NULL;

    list->count--;
    return value;
} //- премахва последния елемент и връща неговата стойност

int peek_front(linkedlist_t* list){
    int value = list->head->value;

    return value;
} //- връща стойността на първия елемент

int peek_back(linkedlist_t* list){
    int value = list->tail->value;

    return value;
} //- връща стойността на последния елемент

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
} //- добавя елемент след даден node в списъка

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
} //- добавя елемент преди даден node в списъка
/*
reverse() - връща нов списък, в който има същите стойности, но в обратен ред

sort_ascending() - връща нов списък, в който има същите стойности, но в сортиран ред (нарастващи)

sort_descending() - връща нов списък, в който има същите стойности, но в сортиран ред (намаляващи)

filter() - приема linkedlist и функция, която приема node и връща boolean, връща като резултат списък, съставен от всички елементи, за които функцията връща true
*/
int main() {
	linkedlist_t* list = init_linkedlist();
	push_front(list, 5);
	traverse(list);
	push_front(list, 6);
	traverse(list);
	push_front(list, 7);
	traverse(list);
	push_back(list, 8);
    traverse(list);
/*
 	node_t* node = find_first(list, 6);
    printf("Find first: %d\n", node->value);

    node_t* node = find_last(list, 9);
    printf("Find last: %d\n", node->value);

    int a = pop_front(list);
    printf("Remove first: %d\n", a);

    int new = pop_back(list);
    printf("Remove last: %d\n", new);

    printf("First: %d\n", peek_front(list));
    printf("Last: %d\n", peek_back(list));

	printf("Add after index 2 number 25\n");
    insert_after(list, 2, 25);
    traverse(list);

    traverse(list);
    printf("Add before index 3 number 99\n");
    insert_before(list, 3, 99);
    traverse(list);
*/
	return 0;
}