#define K 0xFFFFFFFF /* -1 in 32 bit, 2's complement */
#include <stdio.h>

int main()
{
	char c = '\141';
	printf("c is %d\n", c);
	if (0 < K) printf("K is unsigned (Standard C)\n");
	else printf("K is signed (traditional C)\n");
	printf("K is : %u\n", K);
	return 0;
}
