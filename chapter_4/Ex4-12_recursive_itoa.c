#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
void itoa(int n, char s[]);

int main() {
	
	int n;
	char s[1000];
	n = INT_MIN + 1;

	itoa(n,s);
	printf("The int is: %d, the string is: %s\n", n, s);
	
	return 0;
	
}

/*itoa: convert n to characters in s; recursive */
 

void itoa(int n, char s[]) {
	static int i;
	
	if (n /10)
		itoa(n / 10, s);
	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
		}
		s[i++] = abs(n) % 10 + '0';
		s[i] = '\0';
	}


