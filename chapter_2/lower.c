#include <stdio.h>

int lower(int c);

int main() {
int c;
c = 'H';

printf("%c", lower(c) );
	
return 0;

}

/* lower: convert c to lower case; ASCII only*/

int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
	}

