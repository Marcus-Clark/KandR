#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main () {
	int n;
	char s[10];
	
	
	n = -2147483648;
	int k = n % 10 + '0';
	
	itoa(n,s);
	printf("The int is: %d, the string is: %s\n", n, s);
	printf("k is %d\n", k);
	
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

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
	
	int i, sign;
	
	if ((sign = n) < 0) /* record sign */
		n = -n;			/* make n positive */
	i = 0;
	do {				/*generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /*delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
