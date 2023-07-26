#include <stdio.h>
#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /*storage for alloc */
static char *allocp = allocbuf; /*next free position */
char *alloc(int n);
void afree(char *p);


int main() {
	
	char *p1, *p2, *p3;
	
	p1 = alloc(1);
	p2 = alloc(1);
	p3 = alloc(1);
	printf("p1 is at %p\n", p1);
	printf("p2 is at %p\n", p2);
	printf("p3 is at %p\n", p3);
	
	afree(p3); p3=0;
        printf("allocp is at %p\n", allocp);
	afree(p2); p2=0;
        printf("allocp is at %p\n", allocp);
	afree(p1); p1=0;
        printf("allocp is at %p\n", allocp);

	return 0;
	
}

char *alloc(int n) {  /*return pointer to n characters */
		if (allocbuf + ALLOCSIZE - allocp >= n) { /*it fits*/
			allocp += n;
			return allocp - n;/*old p */
		} else /* not enough room*/
			return 0;
		
}
void afree(char *p) {
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
	}
	
