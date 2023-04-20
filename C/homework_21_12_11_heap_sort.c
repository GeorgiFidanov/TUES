#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], unsigned int size, int root){
    int max_root = root;
    int left_child = root * 2 + 1;
    int right_child = root * 2 + 2;

    if (left_child < size && array[left_child] > array[max_root])
      max_root = left_child;

    if (right_child < size && array[right_child] > array[max_root])
      max_root = right_child;

    if (max_root != root) {
      swap(&array[root], &array[max_root]);
      heapify(array, size, max_root);
    }
}

void heap_build(int *array, unsigned int size){
    for (int non_leaf = size / 2 - 1; non_leaf >= 0; non_leaf--){
        heapify(array, size, non_leaf);
    }
}

void heapsort(int *array, unsigned int size){
    heap_build(array, size);
    for (int i = size - 1; i >= 0; i--){
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

int main() {

    int array[] = {69, 57, 7, 420, 35, 68};
    unsigned int size = sizeof(array) / sizeof(int);

    heapsort(array, size);

    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
///аз от тук учих за сорта - https://www.programiz.com/dsa/heap-sort
