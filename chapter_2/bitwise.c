#include <stdio.h>
int main () {
	
	int x =10; /* 1010*/
	int y = 5; /*  101*/
	printf("\nx = %d, y = %d\n", x, y);
	
	x = x ^ y;
	y = x ^ y;
	printf("\nx = %d, y = %d\n", x, y);
	
	int p;
	p = 255;
	printf("\np = %d", p);
	p = 255 &  ~077;
	printf("\np = %d", p);
	
	
	return 0;
}
	
	
