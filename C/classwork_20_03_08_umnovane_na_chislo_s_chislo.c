#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i=1;
    while(i<11){
        printf("n=%d, i=%d, n*i=%d  \n", n, i, n * i  );
        i++;
    }
    return 0;
}
