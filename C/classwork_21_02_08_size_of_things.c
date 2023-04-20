#include <stdio.h>
#include <stdlib.h>

int main()
{
    char b = 'G';
    double c = 3.1428;
    long unsigned int d = -1;
    short int e = 45;
    float f = 40.04;
    printf("character: %c " "and my size is %lu byte.\n", b, sizeof(char));
    printf("long unsigned integer: %d " "and my size is %lu  bytes.\n", d, sizeof(int));
    printf("double:%lf" " and my size is %lu bytes.\n", c, sizeof(double));
    printf("short int: %hd " " and my size is %lu bytes.\n", e, sizeof(short int));
    printf("float: %f " " and my size is %lu bytes.\n", f, sizeof(float));
    return 0;
}

