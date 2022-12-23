#include <stdio.h>

void expand(const char s1[], char s2[]);

int main() {
	int n = 63;
	char s1[]="A-z";
	char s2[n];
	int i;
	
	
	expand(s1,s2);
	
	printf("The expanded array: \n");
	for (i = 0; i < n; i++)
	printf("%c", s2[i]);
	
	
	return 0;
}
/* expand: expand shorthand notation in s1 into string s2 */
 void expand(const char s1[], char s2[]) {
	 char c;
	 int i, j;
	 
	 i = j = 0;
	 while ((c = s1[i++]) != '\0') /* fetch a char from s1[] */
		if (s1[i] == '-' && s1[i+1] >= c) {
			i++;
			while (c < s1[i]) /*expand shorthand*/
				s2[j++] = c++;
		} else
			s2[j++] = c; /* copy the character */
	s2[j] = '\0';
}
