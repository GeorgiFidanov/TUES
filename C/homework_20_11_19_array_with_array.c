#include <stdio.h>
int main(){
    int n, buffer;
    printf("Enter square size of the array: ");
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++){
            buffer = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = buffer;
        }
    printf("Rows and Columns switched:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        puts("");
    }
}
