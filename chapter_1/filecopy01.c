#include <stdio.h>
#define NONBLANK 'a'
/* copy input to output */

int main()
{
	int c, lastc;
	lastc = NONBLANK;
	while ( ( c = getchar() ) != EOF) {
	   if (c != 'k' )	
		putchar(c);
	   if (c == 'k' )
		if (lastc != 'k' )
		putchar(c);
	   lastc = c;
	}
return 0;

}
