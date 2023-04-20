#include <stdio.h>
#include <stdlib.h>
void swap(int*a, int *b, int c = 0){
 c = *a;
 *a = *b;
 *b = c;
}
void sort(int *arr, int n){
    for(i nt i =0; i<n; i++){
        for (int j = 0; j < n-i-1; j++){
            if(*(arr + j))>*(arr + j +1){
                swap((arr +j), (arr + j + 1));
            }
        }
    }
}
void print(int *arr, int n){
    for (int *i = arr; i < arr + n; i++){
        printf("%d", *i);
    }
    printf("\n");
}
void sort_2d(int *arr, int n, int m){
    for (int i=0; i < n *m; i++){
        for (int j =0; j< n * m - 1; j++){
            if (*(arr + j)) > *(arr + j + 1){
                swap((arr +j), (arr + j + 1));
            }
        }
    }

}
int main()
{
    int a, b;
    a = 5;
    b = 10;
    swap(&a, &b);
    printf("a is: %d, and n is: %d", a, b);
    int arr[] = {4, 3, 12, 5, 1, 2, 9, 0, 15};
    sort(arr, 9);
    print(arr, 9);
    int n= 3;
    int m = 4;
    int arr2d[]
    return 0;
}
