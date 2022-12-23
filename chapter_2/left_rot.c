#include <stdio.h>
unsigned leftrot(unsigned x, int n);
int wordlength(void);


int main() {
	unsigned int u;
	u = leftrot(1,4 );
	printf("%u\n", u);
	
	return 0;
	
}

unsigned leftrot(unsigned x, int n) {
	int wordlength(void);
	int lbit;
	
	while (n-- > 0) {
		lbit = (x & 1) >> (wordlength() -1);
		x = x << 1;
		x = x | lbit;
	}
	return x;
}

int wordlength(void) {
	int i;
	unsigned v = (unsigned) ~0;
	
	for (i = 1; (v = v >> 1) > 0; i++) ;
	return i;
}
