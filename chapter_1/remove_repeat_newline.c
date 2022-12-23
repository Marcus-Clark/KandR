#include <stdio.h>

#define NONBLANK 'a'

int main() {

int c , lastc;

	lastc = NONBLANK;
	while ((c = getchar()) != EOF) {
		if (c != '\n')
			putchar(c);
		if (c == '\n')
			if (lastc != '\n')
				putchar(c);
		lastc = c;
	}

return 0;

} 
