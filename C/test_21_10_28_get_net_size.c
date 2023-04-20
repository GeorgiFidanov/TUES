#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 8

unsigned int get_net_size(int mask[4]){
    unsigned int available;
    unsigned int count = 0;
    count = count_zeros(mask);
    available = pow(2, count)-2;
    return available;
}

int count_zeros(int data[4]){
    unsigned int cache[MAX_SIZE];
    unsigned int zeros = 0;
    for(int j = 0; j<4; j++){
        for(int i = 0; i<MAX_SIZE; i++){
        cache[i] = data[j] & 1;
        data[j] >>= 1;
        if (!cache[i]){
            zeros++;
        }
    }
    }
    return zeros++;
}

int main()
{
    int mask[4] = {255, 255, 255, 0};
    printf("%d", get_net_size(mask));
    return 0;
}
//съжалявам, че е само тази ;(