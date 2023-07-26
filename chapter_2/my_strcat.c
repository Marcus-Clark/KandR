#include <stdio.h>

void my_strcat(char s[], char t[]);
int main() {
	char s[]="Bredgar";
	char t[]="Village";
	
	my_strcat(s,t);
	printf("%s\n", s);
	return 0;
	
}
/*my_strcat: concatenate t to end of s; s must be big enough */

void my_strcat(char s[], char t[]) {
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0'); /* copy t */
}
