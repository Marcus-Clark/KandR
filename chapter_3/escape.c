#include <stdio.h>
void escape(char s[], char t[]);
int main () {
	/*char t[]="Bredgar 		Village	Here is a tab\n";*/
	char t[50];
	fgets(t, 50, stdin);
	
	char s[50];
	escape(s, t);
	printf("%s\n", s);
	
	return 0;
	
}
void escape(char s[], char t[]) {
	int i, j;
	
	for (i = j = 0; t[i] != '\0'; i++)
		switch (t[i]) {
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	s[j] = '\0';
}
			
