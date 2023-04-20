#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 65001>nul");
    int x,y,sum=0;
    printf("Колко реда искаш?");
    scanf("%d",&y);
    printf("\n Колко колони искаш?");
    scanf("%d",&x);
    int arr[y][x];
    for(int i = 0; i<y; i++){
        for(int j = 0; j<x; j++){
            printf("\n Въведи стоиност за %d ред, %d колона.", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            printf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<y; i++){
        sum=0;
        for(int j=0; j<x; j++){
            sum+= arr[i][j];
        }
        printf("Сумата на ред %d е: %d\n",i+1,sum);
    }

    for(int i=0; i<y; i++){
        sum=0;
        for(int j=0; j<x; j++){
            sum+= arr[j][i];
        }
        printf("Сумата на колона %d е: %d\n",i+1,sum);
    }
    return 0;
}
