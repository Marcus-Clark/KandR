#include <stdio.h>

struct point {
	int x;
	int y;
} pt1, pt2, p;
struct rect {
		struct point pt1;
		struct point pt2;
	};
int ptinrect(struct point p, struct rect r);
int main() {
	
	struct rect r;
	
	r.pt1.x = 1;
	r.pt1.y = 2;
	r.pt2.x = 3;
	r.pt2.y = 4;
	printf("co-ords of opposite corners of rectangle\n");
	printf("(%d,%d)\n", r.pt1.x, r.pt1.y);	
	printf("(%d,%d)\n", r.pt2.x, r.pt2.y);	
	
	p.x = 2;
	p.y = 2;
	
	if (ptinrect(p,r) == 0)
		printf("Point (%d,%d) is not in rectangle\n", p.x, p.y);
	else 
		printf("Point (%d,%d) is in rectangle\n\n", p.x, p.y);
		
	printf("[ptinrect func returned %d]\n", ptinrect(p,r));
	return 0;
							
}
/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r) {
	return p.x >= r.pt1.x && p.x < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y;
/* Note the >= for the left and bottom point comparison and the < for
 * the right and top point comparison. This follows the convention that a 
 * rectangle includes its left and bottom sides but not its top and right
 * sides. (see p130, above ptinrect function).							*/

}
