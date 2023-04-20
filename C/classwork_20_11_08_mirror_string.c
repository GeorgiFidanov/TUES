#include <stdio.h>

void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void mirror(char *str, int k)
{
	static int i = 0;
	if (*(str + k) == '\0')
		return;
	mirror(str, k + 1);
	if (i <= k)
		swap(&str[i++], &str[k]);
}

int main()
{
	char str[] = "debel lebed";
	mirror(str, 0);
	printf("%s", str);
	return 0;
}
