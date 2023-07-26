#include <stdio.h>
struct point addpoint(struct point p1, struct point p2);
struct point
{
	int x;
	int y;
} ;


int main() {
	struct point p1, p2, pointsum;
	
	p1.x = 6;
	p1.y = 9;
	p2.x = 3;
	p2.y = 2;
	
	pointsum = addpoint(p1, p2);
	
	printf("%d, %d\n", pointsum.x, pointsum.y);
	 
	
	return 0;
}

/*addpoint: add two points */
struct point addpoint(struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}
