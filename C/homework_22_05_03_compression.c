/// Напишете функция, която по подаден С стринг отпечатва всички възможни С стрингове и връща броя им.

/// Напишете функция, която сравянва два C стринга и връща 1, ако са еднакви
/// и 0 ако не са.

#include <stdio.h>
#include <string.h>

/*
int string_equal(char *str1, char *str2) {
	return strcmp(str1, str2) == 0;
}
void compress(char *original, char *compressed) {
	int i;
	for (i = 0; original[i] != '\0'; i++) {
		compressed[i] = original[i];
	}
	compressed[i] = '\0';
}
void decompress(char *compressed, char *decompressed) {
	int i;
	for (i = 0; compressed[i] != '\0'; i++) {
		decompressed[i] = compressed[i];
	}
	decompressed[i] = '\0';
}
*/

void compress(char *original, char *compressed, char esc_ch){
    int i;
    int count = 1;
    int pos = 0;
	for (i = 0; original[i] != '\0'; i++) {
        if(original[i] == original[i + 1]){
            count++;

        }else{
            //printf("%c - %d\n", original[i], count);
            if(count > 1){
                compressed[pos] = esc_ch;
                pos++;
                compressed[pos] = count + '0';
                pos++;
                compressed[pos] = original[i];

                pos++;
                compressed[pos] = '\0';
            }else{
                compressed[pos] = original[i];
                pos++;
                compressed[pos] = '\0';
            }
        count = 1;

        }
		compressed[i] = original[i];
	}

}
/*
void decompress(char *compressed, char *decompressed, char esc_ch){
    int i;
    int count = 1;
    int pos = 0;
	for (i = 0; compressed[i] != '\0'; i++) {
        if(compressed[i] == compressed[i + 1]){
            count++;

        }else{
            //printf("%c - %d\n", original[i], count);
            if(count > 1){
                compressed[pos] = esc_ch;
                pos++;
                compressed[pos] = count + '0';
                pos++;
                compressed[pos] = original[i];

                pos++;
                compressed[pos] = '\0';
            }else{
                compressed[pos] = original[i];
                pos++;
                compressed[pos] = '\0';
            }
        count = 1;

        }
		compressed[i] = original[i];
	}

}
*/
int main() {
	char original[] = "aaaaa1111111Aa00";
	char compressed[14];
	char decompressed[14];
	compress(original, compressed, '-');

	printf("%s", compressed);
}