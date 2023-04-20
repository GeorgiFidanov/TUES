#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int age;
} cat;

void birthday(cat c){
    c.age += 1;
    printf("\n%s shte stane na %d godini", c.name, c.age);
}

int main(){
    cat s;
    printf("Vuvedi ime: ");
    scanf("%s", &s.name);
    printf("\nVuvedi godini: ");
    scanf("%d", &s.age);
    birthday(s);
    return 0;
}
