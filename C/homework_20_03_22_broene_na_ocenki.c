#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    int dvoiki=0;
    int troiki=0;
    int chetvorki=0;
    int petici=0;
    int sheshtci=0;
    int i;
    system("chcp 65001>nul");
    printf("Моля, въведете брой ученици: ");
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        float ocenka=0;
        while((ocenka<2) || (ocenka>6)){
            printf("Моля, въведете оценка %d: ",i);
            scanf("%f",&ocenka);

        }
        if(ocenka<3){
            ocenka=2;
        }
        //printf("debug %.2f\n",ocenka);
        ocenka=round(ocenka);
        switch((int)ocenka){
            case 2:
                //printf("Двойкаджия");
                dvoiki++;
                break;
            case 3:
                troiki++;
                break;
            case 4:
                chetvorki++;
                break;
            case 5:
                petici++;
                break;
            case 6:
                sheshtci++;
                break;
        }
    }
    float procent=(float)dvoiki/n*100;
    printf("2 -  %d - %.2f %%\n",dvoiki, procent);
    procent=(float)troiki/n*100;
    printf("3 -  %d - %.2f %%\n",troiki, procent);
    procent=(float)chetvorki/n*100;
    printf("4 -  %d - %.2f %%\n",chetvorki, procent);
    procent=(float)petici/n*100;
    printf("5 -  %d - %.2f %%\n",petici, procent);
    procent=(float)sheshtci/n*100;
    printf("6 -  %d - %.2f %%\n",sheshtci, procent);

    return 0;
}
