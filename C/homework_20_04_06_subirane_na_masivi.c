#include <stdio.h>
#include <stdlib.h>

int main()
{
     system("chcp 65001>nul");
    int b=101,a=101,c=0,i,j,k,x;
    int masiv3[100];
    while(a>100){
        printf("Въведете броя на числата в масив 1: ");
        scanf("%d",&a);
    }
       while(b>100){
        printf("Въведете броя на числата в масив 2: ");
        scanf("%d",&b);
       }
    int masiv1[a];
    for(i=0;i<a;i++){
        x=101;
        while(x>100){
            printf("Моля, въведете елемент %d в масив 1: ",i);
            scanf("%d",&x);
        }
        masiv1[i]=x;
    }
    int masiv2[b];
    for(i=0;i<b;i++){
        x=101;
        while(x>100){
            printf("Моля, въведете елемент %d в масив 2: ",i);
            scanf("%d",&x);
        }
        masiv2[i]=x;
        for(j=0;j<a;j++){
            if(masiv2[i]==masiv1[j]){
                x=0;
                for(k=0;k<c;k++){
                    if(masiv2[i]==masiv3[k]){
                        x++;
                    }
                }
                if(x==0){
                    masiv3[c]=masiv2[i];
                    c++;
                }
            }
        }
    }
    for(i=0;i<c;i++){
        printf("Maсив 3, елемент %d = %d\n",i,masiv3[i]);
    }
}
