#include <stdio.h>

int find_row_max_one(int n, int m, int arr[][m]){
    int max = 0, max_row, sum_of_ones = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            if (arr[i][j]) sum_of_ones++;
        if (sum_of_ones > max){
            max = sum_of_ones;
            max_row = i + 1;
            sum_of_ones = 0;
        }
    }
    return max_row;
}

int main(){
    printf("Enter number of rows and columns: ");
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    printf("Now enter the numbers\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0 && arr[i][j] != 1){
                printf("Please enter a valid number (0 or 1)\n");
                j--;
                continue;
            }
        }
    printf("The row with most ones is: %d\n", find_row_max_one(n, m, arr));

}
