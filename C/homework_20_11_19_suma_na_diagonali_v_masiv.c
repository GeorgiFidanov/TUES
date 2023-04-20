#include <stdio.h>

int sum_diagonals(int n, int arr[][n]){
    int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i][i] + arr[i][n - i - 1];
    return sum;
}

int main(){
    int n;
    printf("Enter square size of array: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    printf("The sum of the diagonals is: %d\n", sum_diagonals(n, arr));
}
