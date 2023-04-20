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
    int b=0;
    int a=0;
    for(i=0; i<broi; i++){
        printf("\n Моля въведете число: %d", numbers[i]);
        scanf("%d", &numbers[i]);
        if (numbers[i]%2==1){
            a++;
            break;
        }
        else {
            b++;
            break;
        }
        i++;
    }
    printf("Четните са: %d/n",b);
    printf("Нечетните са: %d/n",a);
    return 0;
    //Трябва да прочетете цяло число n след това се прочитат n цели числа и да се запишат в масив след това се извеждат, броя на четните и нечетните цели числа и тяхните проценти от общия брой
}
