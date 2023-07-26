#include <stdio.h>

int my_strcmp(char *s, char *t);

int main() {
	char s[] = "1150";
	char t[] = "1160";
	
	
	
	printf("Contents of s is %s, contents of t is %s\n", s, t);
	printf("Result of comparison: %d\n", my_strcmp(s,t));
	if (my_strcmp(s,t) == 0 ) {printf("Therefore s = t\n");}
	else if (my_strcmp(s,t) < 0 ) {printf("Therefore s < t\n");}
	else {printf("Therefore s > t\n") ; }
	
	return 0;
	
}

/* my_strcmp: return < 0 if s < t, 0 if s = t, >0 if s > t*/

int my_strcmp(char *s, char *t) {
	int i;
	
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}
