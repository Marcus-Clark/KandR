#include <stdio.h>
unsigned rightrot(unsigned x, int n);
int wordlength(void);


int main() {
	unsigned int u;
	u = rightrot(1,28 );
	printf("%u\n", u);
	
	return 0;
	
}
/* rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n) {
	int wordlength(void);
	int rbit;				/*rightmost bit */
	
	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() -1);
		x = x >> 1;			/* shift x 1 position right */
		x = x | rbit;		/* complete one rotation */
	}
	return x;
}
/* wordlength: computes word length of the machine */
int wordlength(void) {
	int i;
	unsigned v = (unsigned) ~0;
	
	for (i = 1; (v = v >> 1) > 0; i++) ;
	return i;
}
