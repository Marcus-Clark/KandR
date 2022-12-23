#include <stdio.h>

int power(int m, int n);

int main()
{

	int i;
	
	for ( i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
	return 0;
}

/* power: raise base to the n-th power; n>= 0 */

int power(int base, int k)
{
	int i, foo;

	foo = 1;	/* ensures base^0 = 1, by definition */
	for (i = 1; i <= k; ++i)
		foo = foo * base;  /* remember single equals assigns a value */
	return foo;
}

