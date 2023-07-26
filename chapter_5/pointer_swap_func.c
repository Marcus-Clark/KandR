#include <stdio.h>
void swap(int *px, int *py);
int main() {
	
	int x, y;
	x = 10;
	y = 1;
	printf("BEFORE swap: x equals %d and y equals %d\n", x, y);
	
	swap(&x, &y);
	printf("AFTER swap: x equals %d and y equals %d\n", x, y);
	
	
	return 0;	
}	
void swap(int *px, int *py) {
	int temp;
	
	temp = *px;
	*px = *py;
	*py = temp;
	
}
