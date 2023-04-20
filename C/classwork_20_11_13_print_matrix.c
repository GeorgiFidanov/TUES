#include <stdio.h>
#include <stdlib.h>


void print_matrix(int rows, int columns, int matrix[][columns]){
    for (int row = 0; row < rows; row ++){
        for (int column = 0; column < columns; column++){
            printf("%d", matrix[row][column]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    print_matrix(3, 4, matrix);
    return 0;
}
