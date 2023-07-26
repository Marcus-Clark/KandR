#include <stdio.h>
void printd(int, int);
int main()
{
	int n, base;
	n = 100;
	base = 2;
	printf("decimal %d is ",n);
	printd(n, base);
	printf(" in base %d", base); 
	
	
}

/* printd: print n in base */

void printd(int n, int base) {

	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / base)
		printd(n / base, base);
	putchar(n % base + '0');
}
