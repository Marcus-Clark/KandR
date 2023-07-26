#include <stdio.h>

void my_strcpy(char *s, char *t);

int main() {
	char s[100];
	char t[] = "world";
	
	printf("Contents of s before copying is: %s\n", s);
	my_strcpy(s,t);
	printf("Contents of s after copying is: %s\n", s);
	
	return 0;
}

/* my_strcpy: copy t to s; array subscript version */

void my_strcpy(char *s, char *t) {
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
	}
