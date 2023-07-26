#include <stdio.h>
#include <string.h>

# define abs(x) ((x) < 0 ? -(x) : (x))


void itoa(int n, char s[], int w);

int main () {
	int n, w;
	char s[20];
	
	
	n = 12;
;
	w = 7;
	
	
	itoa(n,s,w);
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

/* itoa: convert n to characters in s, w characters wide */
void itoa(int n, char s[], int w) {
	
	int i, sign;
	void reverse(char s[]);
	sign = n; /* record sign */
		
	i = 0;
	do {				/*generate digits in reverse order */
		s[i++] = abs(n % 10) + '0'; /* get next digit */
	} while ((n /= 10) > 0); /*delete it */
	if (sign < 0)
		s[i++] = '-';
	while (i < w) 			/*pad with blanks */
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}
