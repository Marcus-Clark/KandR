#include <stdio.h>
void printd(int);
int main()
{
	int n;
	n = 10;
	printd(n);
	
	
}

/* printd: print n in decimal */

void printd(int n) {

	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 2)
		printd(n / 2);
	putchar(n % 2 + '0');
}
