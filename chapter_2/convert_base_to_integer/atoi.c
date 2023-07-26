#include <stdio.h>

int atoi(char s[]);

int main() {
char s[]="125";	
int n;

n = atoi(s);
printf("%s, %d", s, n );

	
return 0;

}

/* atoi: convert s to integer 
 * this atoi converts a string of digits into
 * its numeric equivalent */

int atoi(char s[]) {
	
	int i, n;

	n= 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 *  n +(s[i] - '0') ;
	return n;
}

