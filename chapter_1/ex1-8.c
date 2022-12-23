#include <stdio.h>

/* count blanks, tabs and newlines in input */

int main ()

{

	int c, nl, nb, nt;

	nl = 0;
	nb = 0;
	nt = 0;
	while (( c = getchar()) != EOF) {
		if ( c == '\n')
		++nl;

		if ( c == ' ')
		++nb;

		if ( c == '\t')
		++nt;
		}
	printf("newlines: %d, blanks: %d, tabs: %d\n", nl, nb, nt);

return 0;

}










