#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int old_max = max(arr, n-1);
    if (arr[n-1] > old_max){
        return arr[n-1];
    }
    return old_max;
}

int main()
{
    int arr[] = {15, 92, 123, 23, 74, 100, 625, 24, 532};

    printf("%d\n", max(arr, 9));
    return 0;
}
