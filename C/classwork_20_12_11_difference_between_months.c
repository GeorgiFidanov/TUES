#include <stdio.h>
#include <stdlib.h>
enum month {January, February, March, April, May, June, July, August, September, October, November, December};
int differenceMonths(enum month m1, enum month m2){
    int diff = m2 -m1;
    if(diff < 0){
        diff *= -1;
    }
    return diff;
}
int main()
{
    printf("The difference is: %d months", differenceMonths(March, June));
    return 0;
}
