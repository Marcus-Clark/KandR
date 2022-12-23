#include <stdio.h>
struct point makepoint(int, int);

struct point
{
	int x;
	int y;
} pt1, pt2, p;

struct rect {
		struct point pt1;
		struct point pt2;
	};
	
int ptinrect(struct point p, struct rect r); /*func must be declared after struct rect declared */


int main() {
	struct rect r;
	
	r.pt1 = makepoint(0, 0);
	r.pt2 = makepoint(10, 10);
	p.x = 10;
	p.y = 10;
	

	printf("%d\n", ptinrect(p,r));
	return 0;
}

/*makepoint: make a point from x and y components */
struct point makepoint(int x, int y) {
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}
/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r) {
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y;

}
