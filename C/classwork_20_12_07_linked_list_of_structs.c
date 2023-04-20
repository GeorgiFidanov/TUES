#include <stdio.h>
#include <stdlib.h>

struct definition{
    char *key;
    char *value;
    struct definition *next;
};

void addToNext(struct definition *prev, struct definition *current){
    current->next = prev->next;
    prev->next = current;
}

char *getDefinition(struct definition *head, char *key){
    if(head==NULL){
        return NULL;
    }
    if (strcmp(head->key, key) ==0){
        return head->value;
    }
    return getDefinition(head->next, key);
}
void swap ( struct definition *d1, struct definition *d2){
    struct definition temp = {d1->key, d1->value, NULL};
    d1->key = d2->key;
    d1->value = d2->value;
    d2->key = temp.key;
    d2->value = temp.value;
}
void sort(struct definition *d){
    for (struct definition *i = d; i->next != NULL; i = i->next){
        for(struct definition *j = d; j !=NULL; j= j->next){
            if(strcmp(j->key, (j->next)->key)<0){
                swap(j, j->next);
            }
        }
    }
}

int main()
{
    struct definition d0 = {"riba", "fish", NULL};
    struct definition d = {"kuche", "dog", &d0};
    struct definition d2 = {"kotka", "cat", NULL};
//    printf("%s\n", (d.next)->key);
    addToNext(&d, &d2);
    printf("%s\n",(d.next)->key);
    printf("%s\n",((d.next)->next)->key);
    printf("The definition of %s is %s.", "kotka", getDefinition(&d, "kotka"));
    return 0;
}
