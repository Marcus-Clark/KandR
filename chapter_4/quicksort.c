#include <stdio.h>

void my_qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
int main() {


int v[] = {12, 18, 17, 56, 900, 1, 76, 53};
int left, right;
left = 0;
right = 7;
printf("unsorted array: ");
 	int i; 
 	for (i = 0; i < right+1; i++) 
 	printf(" %d ", v[i]);
 	printf("\n");

 	my_qsort(v, left, right);
 	printf("sorted array: ");
 	
 	for (i = 0; i < right+1; i++) 
 	printf(" %d ", v[i]);
 	printf("\n");
	
 	return 0; 
	
}

/* my_qsort: sort v[left]...v[right] into increasing order*/

void my_qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);
	
	if (left >= right)		/*Do nothing if array contains */
		return;				/* fewer than two elements		*/
	swap(v, left, (left + right)/2); /*move partition elem	*/
	last = left; 					/* to v[0] 			*/
	for (i = left+1; i <= right; i++)   /* partition */
		if(v[i] < v[left])
		swap(v, ++last, i);
	swap(v, left, last);
	my_qsort(v, left, last-1);
	my_qsort(v, last+1, right);
}

/*swap: interchange v[i] and v[j] */

void swap(int v[], int i, int j) {
	int temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}
