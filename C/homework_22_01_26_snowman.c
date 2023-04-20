#include <stdio.h>
#include <stdlib.h>

struct ball{
    int weight;
    struct ball *prev;
};

struct snowman{
    int weight;
    int ball_count;
    struct snowman *next;
    struct snowman *prev;
    int current_position;
    struct ball *ball;
};

struct snowman *init_snowman(int p, int m){
    struct snowman *head = malloc(sizeof(struct snowman));
    head -> current_position = p;
    head -> weight = m;
    head -> ball_count = 1;
    head -> next = NULL;
    head -> prev = NULL;
    head -> ball = malloc(sizeof(struct ball));
    head -> ball -> weight = m;
    head -> ball -> prev = NULL;

    return head;
}


struct snowman *create_snowman(int p, int m, struct snowman *head){
    struct snowman *temp = malloc(sizeof(struct snowman));
    temp -> ball = malloc(sizeof(struct ball));

    if (head == NULL && m != 0){
        return init_snowman(p, m);
    }

    if (head -> current_position == p){
        temp = head;
        temp -> ball = head -> ball;
        temp -> next = NULL;
        temp -> ball_count++;
        temp -> weight = temp -> weight + m;
        temp -> ball -> prev = temp -> ball;
        temp -> ball -> weight = m;

        head -> next = temp;
        head -> next -> prev = head;
        head -> next -> current_position = head -> current_position + 1;
        head -> next -> next = NULL;

        return head;
    }

    if (m > 0){
        while (head -> next != NULL){
            head = head -> next;
            if(head -> current_position == p){
                temp = head;
                temp -> ball = head -> ball;
                temp -> next = NULL;
                temp -> ball_count++;
                temp -> weight = temp -> weight + m;
                temp -> ball -> prev = temp -> ball;
                temp -> ball -> weight = m;
               // printf("%d\n",ball->weight);
            }
        }
        head -> next = temp;
        head -> next -> prev = head;
        head -> next -> current_position = head -> current_position + 1;
        head -> next -> next = NULL;
        //printf("%d\n",weight);
    }
    else if (m == 0){
            while (head -> next != NULL){
            head = head -> next;
            if(head -> current_position == p){
                temp = head;
                temp -> next = NULL;
                temp -> ball_count++;
                temp -> weight = temp -> weight - temp -> ball -> weight;
                temp -> ball = temp -> ball -> prev;
                printf("%d\n",temp ->weight);
            }
        }
        head -> next = temp;
        head -> next -> prev = head;
        head -> next -> current_position = head -> current_position + 1;
        head -> next -> next = NULL;
        printf("%d\n",head->weight);
    }

    return head;
}

int sum_ballz(struct snowman *head){
    int sum = 0;
    while(head -> next != NULL){
        printf("%d\n", head -> weight);
        sum = sum + head -> weight;
        head = head -> next;
    }
    return sum;
}

int main()
{
    int n;
    printf("number of operations:\n");
    scanf("%d", &n);
    struct snowman *nulev = NULL;
    for(int i=1; i<=n; ++i){
        int m,p;
        //printf("number of snowman:\n");
        scanf("%d", &p);
        //printf("weight of his ballz:\n");
        scanf("%d", &m);
        nulev = create_snowman(p, m, nulev);
        }

    printf("the sum of the snowmen is: %d \n", sum_ballz(nulev));



    return 0;
}

/*void create_snowman(int p, int m, struct snowman *head){

    if (head == NULL)head = init_snowman(p, m);
    else if (m > 0){
        while (head->current_possion != p){
            head = head->next;
        }
        struct snowman *temp = head;
        temp -> next = NULL;
        temp -> ball_count++;
        temp -> weight = temp -> weight + m;
        while(head -> next != NULL){
            head = head -> next;
        }
        head -> next = temp;
    }
}*/
