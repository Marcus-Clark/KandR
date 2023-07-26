#include <stdio.h>
struct point makepoint(int, int);
struct point
{
	int x;
	int y;
} pt1, pt2;

struct rect {
		struct point pt1;
		struct point pt2;
	};
int main() {
	
	struct rect screen;
	struct point middle;
	
	
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(10, 10);
	middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
					   (screen.pt1.y + screen.pt2.y)/2);

	printf("%d, %d\n", screen.pt1.x, screen.pt1.y);
	printf("%d, %d\n", screen.pt2.x, screen.pt2.y); 
	printf("%d, %d\n", middle.x, middle.y);  
	
	return 0;
}

/*makepoint: make a point from x and y components */
struct point makepoint(int x, int y) {
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}
