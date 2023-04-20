#include <stdio.h>
#include <stdlib.h>

int sum(int n) {

    if (n == 0) {
        return 0;
    }

    return (n % 10) + sum(n/10);
}

int main()
{
    int num = 536719;

    printf("%d\n", sum(num));
    return 0;
}
