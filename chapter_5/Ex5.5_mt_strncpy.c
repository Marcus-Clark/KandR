#include <stdio.h>
int my_strlen(char *s);
void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);

int main() {
	int n = 5;
	char s[100];
	char t[] = "Hello world";
	
	printf("Contents of s before cat is: %s\n", s);
	printf("Contents of t is: %s\n", t);
	my_strncat(s,t, n);
	printf("Contents of s after 'cat'-ing %d chars from t is: %s\n", n, s);
	
	return 0;
}
/* my_strncat: concatenate n characters of t to the end of s */
void my_strncat(char *s, char *t, int n) {
	void my_strncpy(char *s, char *t, int n);
	int my_strlen(char *);
	my_strncpy(s+my_strlen(s), t, n);
}

/* my_strncpy: copy n characters t to s    */

void my_strncpy(char *s, char *t, int n) {
	while (*t && n-- > 0)
		*s++ = *t++;
	while (n-- > 0)
		*s++ = '\0';
	}
	
/* my_strlen: return length of string s */
int my_strlen(char *s) {
	int n;
	
	for (n = 0; *s != '\0'; s++)
			n++;
		return n;
	}
