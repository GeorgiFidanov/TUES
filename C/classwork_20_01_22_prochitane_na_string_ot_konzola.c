#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char a[50];
    char b[50];
    int n,i;
    scanf("%s %s",a,b);
    if(strlen(a)>strlen(b)){
        n=strlen(b);}
    else{
        n=strlen(a);}
    for(i=0;i<=n;i++){
        if(toupper(a[i])<toupper(b[i])){
            printf("%s\n",a);
            printf("%s\n",b);
        }
        else if(toupper(b[i])<toupper(a[i])){
           printf("%s\n",b);
           printf("%s\n",a);}
        else if(toupper(a[i]) == toupper(b[i])){
            continue;}
        }

     if(i==n){
        printf("%s\n",a);
        printf("%s\n",b);
     }

    return 0;
}
