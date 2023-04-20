#include <stdio.h>

void crypt(FILE *in, FILE *out){
    fscanf(in,"..");

    fprintf(out, ",,");
    }

int main()
{
    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "a");
    crypt(input, output);
    fclose(input);
    fclose(output);

}
