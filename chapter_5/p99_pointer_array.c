#include <stdio.h>

/* from page 99 K and R */


int main() {
   int a[10]={0,1,2,3};
   int i, x;
   for (i=0; i < 4; ++i) {
	   printf("contents of array: %d\n", a[i]);
   }
   int *pa;
   
   
   pa = a;
   x = *(pa+2);
   printf("x is %d\n", x);
   printf("address of array a:	 %p\n", a);
   printf("address of &a[0] is:	 %p\n", &a[0]);
	printf("address of pa is:	 %p\n", pa);
	
	printf("content of element a[0]: %d\n", a[0]);
	printf("content of element *pa: %d\n", *pa);
	printf("content of element a[1]: %d\n", a[1]);
	printf("content of element *(pa+1): %d\n", *(pa+1));
	printf("content of element a[2]: %d\n", a[2]);
	printf("content of element *(pa+2): %d\n", pa[2]);
	
   return 0;
}
