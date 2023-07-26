#include <stdio.h>

int bitcount(unsigned x);

int main() {
	
	unsigned int x, y;
	x = 1987;
	y = bitcount(x);
	printf("%d\n", y);
	return 0;
	
}

/*bitcount: count 1 bits in x - faster version */
int bitcount(unsigned x) {
	int b;
	
	for (b = 0; x != 0; x &= x-1)
		++b;
	return b;
	}
