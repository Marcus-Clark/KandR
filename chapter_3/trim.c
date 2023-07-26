#include <stdio.h>
#include <string.h>
int trim(char s[]);

int main(void) {
	
	char s[]="hello,world		\t\t\t\t\t\t\t\t\t\n";
	
	printf("%d\n", trim(s) );
	return 0;
}
	
	
	/*trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) {
	int n;
	
	for(n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n+1] = '\0';
	return n;
		
	}
	
	
