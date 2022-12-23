#include <stdio.h>
int my_getline(char *s, int lim);
int main () {
	char str[1000];
    printf("%d\n", my_getline(str, 1000));
    printf("%s", str);
	return 0;
	
}

/* getline: read a line into s, return length */

int my_getline(char *s, int lim) {
	int c;
	char *t = s;
	
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}
