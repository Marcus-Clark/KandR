#include <stdio.h>

void my_strcat(char *s, char *t);

int main() {
	
	char s[100] = "hello ";
	char t[] = "Hello world";
	
	printf("Contents of s before copying is: %s\n", s);
	printf("Contents of t is: %s\n", t);
	my_strcat(s,t);
	printf("Contents of s after copying  from t is: %s\n",  s);
	
	return 0;
}

/* my_strcat: concatenates t to the end od s; pointer version */
void my_strcat(char *s, char *t) {
	while (*s)
		s++;
	while (*s++ = *t++)
		;
	}
