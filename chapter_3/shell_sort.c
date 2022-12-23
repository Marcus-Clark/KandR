#include <stdio.h>

void my_shellsort(int v[], int n);
void printArray(int arr[], int n);

int main() {
	int v[]={12, 1, 3, 54, 103, 4, 17};
	int n = 7;
	
	my_shellsort(v,n);
	
	printArray(v,n);
	
	return 0;
}

/* my_shellsort: sort v[0]...v[n-1] into increasing order */
void my_shellsort(int v[], int n) {
	
		int gap, i, j, temp;
		
		for(gap = n/2; gap > 0; gap /= 2)
			for (i=gap; i < n; i++)
				for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
					temp = v[j];
					v[j] = v[j+gap];
					v[j+gap] = temp;
				}
			}
			// A utility function to print
// n array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf(" %d ", arr[i]);
}
