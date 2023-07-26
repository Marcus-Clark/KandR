#include <stdio.h>
 int main() {
	 int i;
	 int nums[10]={1,2,3,4,5,6,7,8,9,10};
	 
	 int *ptr = nums;
	 
	 for (i = 0; i < 10; i++)
	 {
		 printf("Element %d contains value %d\n", i, *ptr);
		 ptr++;
	 }
	 
	 return 0;
 }
