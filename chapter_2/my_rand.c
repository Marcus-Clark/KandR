#include <stdio.h>
#include <time.h>

int rand(void);
void srand(unsigned int seed);

int main() {
	srand(time(NULL));
	/*unsigned int r = rand();*/
	
	
	printf("%u\n", rand());
}
	
	unsigned long int next = 1;
	
	
	/* rand */
	int rand(void) {
		next = next * 1103515245 + 12345;
		return (unsigned int)(next/65536) % 7;
	}
	
	/* srand: set seed for rand() */
	
	void srand(unsigned int seed) {
		next = seed;
	}
