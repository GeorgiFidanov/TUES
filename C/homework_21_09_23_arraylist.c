


///обърках и къде/кое да ви пратя




#include <stdio.h>
/*
int* get_triangle(int nums[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				if (...) {
					// razlika mejdu int* int[]
					int* result = (int*) malloc(3*sizeof(int));
					
					return result;
				}
				result[0];
			}
		}
	}
}	
*/
typedef struct arraylist_t {
	int count;
	int capacity;
	int* array;
} arraylist_t;

arraylist_t* init() {
	arraylist_t* list = malloc(sizeof(arraylist_t));
	
	list->capacity = 16;
	list->count = 0;	
	list->array = malloc(sizeof(int)*list->capacity);
	
	return list;
}

int add(arraylist_t* arraylist, int value) {
	if (list->count == list->capacity) {
		// if realloc neshto ne e srabotilo
		// return -1;
		list->array = realloc(list->array, list->capacity * 2);
		list->capacity = list->capacity * 2;
	}
	
	list->array[list->count] = value;
	list->count++;
	
	return 0;
}

void remove(arraylist_t arraylist, int value){
    for(int i=0; i<arraylist->count; ++i){

        if(i>value){
            arraylist->arr[i-1] = arraylist->arr[i];
        }
    }

    arraylist->count--;
    arraylist->arr = realloc(arraylist->arr, arraylist->count * sizeof(arraylist));
    
}
int get_at(arraylist_t arraylist, int index);

void arraylist_destroy(arraylist_t *arraylist){
    free(arraylist);
    arraylist->count = 0;
    arraylist->capacity = 0;
}

int arraylist_size(arraylist_t *arraylist){
     return arraylist->count;
}

int arraylist_at(arraylist_t *arraylist, int index){
    return arraylist->array[index];
}

int main(){
	int input[] = {1, 6, 8, 2 ,3 ,56,87};
	//int* first_triangle = get_triangle(input, 7);
	////
	free(first_triangle);
	
	arraylist* list = init();
	add(list*, 6);
	
	return 0;
}
//съжалявам за това ^^, нямах време и само намятах идеи, не го донаправих, извинявам се



