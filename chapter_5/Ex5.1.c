#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Used by getch/ungetch */
int buff = EOF;

int getint(int *pn);

int main(void) {
	int number;

	getint(&number);

	printf("%d\n", number);

	return EXIT_SUCCESS;

}

int getch(void) {
	int temp;

	if (buff != EOF) {
		temp = buff;
		buff = EOF;
	
	} else
		temp = getchar();

	return temp;

}

void ungetch(int c) {
	if (buff != EOF)
		fputs("ungetch: Too many characters", stderr);

	else
		buff = c;

}

int getint(int *pn) {
	int c, sign;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	
	}

	sign = (c == '-') ? -1 : 1 ;

	/**
	 * Workaround: When the user enters a number with more than one
	 * sign (+/-) causing it to be set to 0, it also happens when
	 * you enter one or more signed digits and include characters
	 * other than numbers.
	 *
	 * The following examples resulted in 0 being obtained:
	 * 1): --1: What you wanted was -1, but you got 0.
	 * 2): ++1: What you wanted was 1, but you got 0.
	 * 3): -a1: You wanted it was -1, but you got 0.
	 * 4): +a1: What you wanted was 1, but you got 0.
	 * 5): --------1: What I wanted was -1, but you got 0.
	 *
	 * Now the user can enter data like the above, and would get:
	 * -1, 1, -1, 1, -1.
	 *
	 **/

	while (!isdigit(c))
		c = getch();

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c-'0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;

}
