#include <stdio.h>

struct point {
	int x;
	int y;
};
struct point makepoint(int x, int y);
int main() {
	struct point origin, *pp;
	/*origin.x = 1;
	origin.y = 1; */
	origin = makepoint(10, 0);
	pp = &origin;
	printf("origin is (%d, %d)\n", pp->x, (*pp).y);
	
	return 0;
}
struct point makepoint(int x, int y) {
	struct point suki;
	
	suki.x = x;
	suki.y = y;
	return suki;
}
