#include <stdio.h>

int upper(int c);

int main() {
int c;
c = 'z';

printf("%c", upper(c) );
	
return 0;

}

/* upper: convert c to upper case; ASCII only*/

int upper(int c) {
	if (c >= 'a' && c <= 'z')
		return c + 'A' - 'a';
	else
		return c;
	}

