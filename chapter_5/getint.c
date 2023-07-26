#include <stdio.h>
#include <stdlib.h>
int getint(int *pn); 

int main(void)
{
	int number;

	getint(&number);

	printf("%d\n", number);

	return EXIT_SUCCESS;
	
}

	

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */

int getint(int *pn) {
	int c, sign;
	
	while (isspace(c = getch())) /* skip whitespace*/
		;
	if ( !isdigit(c) && c != EOF && c != '+' && c != '-') {
			ungetch(c); /*it's not a number */
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

/* getch and ungetch */
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch*/
int bufp = 0; /* next free position in buf*/

int getch(void) { 
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
	}
