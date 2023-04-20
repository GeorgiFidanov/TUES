#include <stdio.h>
#include <string.h>
#include<signal.h>

char text[1000]="";
int o;

void enigma(int signun) {
    int i=0;
    char encrypted[1000];
    for (i=0;i<1000; i++){
            if (text[i] =='\0') {
                break;
            }
        if ((text[i] > 96)&&(text[i] < 123)) {
            encrypted[i]=( text[i]+o - 97)%26 +97; //malki angl  bukvi
            }
        else if ((text[i] > 64) && (text[i] < 91)){
            encrypted[i]=( text[i]+o - 65)%26 +65; //golemi anglijiski bukvi
            }
        else if ((text[i] > 47) && (text[i] < 58)){
            encrypted[i]=( text[i]+o - 48)%10 +48; //chisla
            }
        else {
            encrypted[i] = text[i];
        }
    }
    printf("\nEncrypted text:\n%s\n", encrypted);
}

int main()
{
    signal(SIGINT, enigma);
    int i=0;
    printf("choose a number to crypt with: ");
    scanf("%d", &o);
    printf("Enter text \n");
    while (1){
        i++;
        char line[100]="";
        fgets(line, 100, stdin);
        strcat(text, line);
    }
    return 0;
}
