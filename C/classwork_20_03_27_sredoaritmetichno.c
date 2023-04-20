#include <stdio.h>
#include <stdlib.h>

int main()
{
    int broi=0;
    system("chcp 65001>nul");
    while(broi<1){
        printf("Моля, въведете общия брой числа: ");
        scanf("%d",&broi);
    }
    int numbers[broi];
    int i;
    int sum = 0;
    int a;
    float avg = 0;
    for(i=0; i<broi; i++){
        int opposite = 0;
        while(opposite==0) {
            printf("Моля, въведете число %d: ",i+1);
            scanf("%d",&a);
            if (i==0){
                if (a>0){
                    opposite = 1;
                    sum = sum + a;
                    numbers[i] = a;
                    avg = avg + abs(a);
                }
            }
            else{
                if((a>0 && numbers[i-1]<0 ) || (a<0 && numbers[i-1]>0 )) {
                    opposite = 1;
                    sum = sum + a;
                    numbers[i] = a;
                    avg = avg + abs(a);
                }
            }
        }
    }

    printf("Сумата е: %d\n",sum);
    avg = avg/broi;
    printf("Среадноаритметичното на абсолютната стойност на числата е: %f\n", avg);
    return 0;
}
