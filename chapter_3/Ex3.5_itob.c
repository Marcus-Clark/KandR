#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main () {
	int n, b;
	char s[10];
	
	
	n = 11;
	b = 2;
	
	
	itob(n,s, b);
	printf("The int is: %d, the string is: %s\n", n, s);
	
	
	return 0;
}

/*reverse: reverse string s in place */
void reverse(char s[]) {
	int c, i, j;
	
	for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itob: convert n to characters in s = base b */
void itob(int n, char s[], int b) {
	
	int i, j, sign;
	
	if ((sign = n) < 0) /* record sign */
		n = -n;			/* make n positive */
	i = 0;
	do {				/*generate digits in reverse order */
		j = n % b; /* get next digit */
		s[i++] = (j <= 9) ? j+'0' : j + 'a' - 10;
	} while ((n /= b) > 0); /*delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
