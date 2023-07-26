#include <stdio.h>

int wordlength(void);


int main() {
	 int w;
	 w = wordlength();
	 printf("The wordlength on this machine is: %d bits\n", w);
	
	return 0;
}

/* wordlength: computes word length of the machine */
int wordlength(void) {
	int i;
	unsigned v = (unsigned) ~0;
	
	for (i = 1; (v = v >> 1) > 0; i++) ;
	return i;
}
