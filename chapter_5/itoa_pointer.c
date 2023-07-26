#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void reverse(char *s);
void my_itoa(int n, char *s);
int main() {
	int n = 11;
	
	char* s = malloc( 1000 * sizeof(char));				/* is a very contrived way of declaring 'char s[1000]'*/
	printf("size is: %ld\n", malloc_usable_size(s));
	my_itoa(n,s);
	printf("The int is: %d, the string is: %s\n", n, s);
	free(s);
	
}
// chapter 3 reverse, page 62: reverse string s in place
void reverse(char *s)
{
    for (char *i = s, *j = s + (strlen(s) - 1); j - i > 0; i++, j--) // note char *i = s, *j = ... in for loop is same as declaring them like char *i, *j; above the for loop
    {
        int c = *i;
        *i = *j;
        *j = c;
    }
}
/* my_itoa: convert n to characters in s; pointer version */
void my_itoa(int n, char *s) {
	int sign;
	char *t = s;				/* save pointer to s		*/
	
	if ((sign = n) < 0)			/* record sign				*/
		n = -n;					/* make n positive			*/
	do {			/*generate digits in reverse order		*/
		*s++ = n % 2 + '0';	/* get next digit			*/
	} while ((n /= 2) > 0);	/* delete it 				*/
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(t);
}
