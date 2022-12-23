#include <stdio.h>

int binsearch(int x, int v[], int n);

int main () {
	int x = 9;
	int v[] = { 1, 4, 6, 8, 9 };
	int n = 5;

	
	printf("%d\n", binsearch(x,v,n) );
	
	return 0;
	
}

int binsearch(int x, int v[], int n) {
	
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if ( x < v[mid])
			high = mid - 1;
		else if ( x > v[mid] )
			low = mid + 1;
		else 	/*found match */
			return mid;
		}
		return -1; /*no match */
	}
