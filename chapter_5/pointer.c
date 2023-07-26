#include <stdio.h>

int main() {
	
	int x = 10;
	int y = 0;
	int i, j;
	
	int *px;
	int *py;
	
	px = &x;
	py = &y;
	
	for (i = 0; i < 5; i++)
	 {
		 printf("px is %d is %p\n", i, px);
		 px++; 
	 }
	for (j = 0; j < 5 ; ++j)
	{
		printf("py is %d %p\n", j, py);
		 py++;
	}
	return 0;
}
