#include <stdio.h>
#include <stdlib.h>

struct snowman{
   int weight;
   int *balls;
   int size;

};

int main()
{
    int n, p, m;
    int sum = 0;
//    printf("\nnumber of operations:");
    scanf("%d", &n);

    struct snowman *clones = (malloc(sizeof(struct snowman) * n));
    for(int i=0; i<n; i++){
        clones[i].balls = malloc(sizeof(int) * n);
        clones[i].weight = 0;
        clones[i].size = 0;
    }


    for(int i=0; i<n; i++){
//        printf("\nclone snowman number:");
        scanf("%d", &p);
//        if(p>i){printf("wrong input");}

//        printf("\nball mass:");
        scanf("%d", &m);

        if(p != 0)clones[i]= clones[p-1];

        if(m>0){
            clones[i].weight += m;
            clones[i].balls[clones[i].size] = m;
            clones[i].size++;
        }
        else{
            clones[i].weight -= clones[i].balls[clones[i].size-1];
            clones[i].balls[clones[i].size-1]=0;
            clones[i].size--;
         };
        sum += clones[i].weight;
    }
    printf("%d", sum);
    return 0;
}
/*8
0 1
1 5
2 4
3 2
4 3
5 0
6 6
1 0
*/
