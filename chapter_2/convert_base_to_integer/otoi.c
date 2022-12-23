#include <stdio.h>
#define YES 	1
#define NO 		0

int otoi(char s[]);

int main() {
char s[] = "0377";
printf("%u" , otoi(s) );

	return 0;
}
/* otoi: convert octal string s to integer */

int otoi(char s[]) {
	int octdigit, i, inoct, n;
	i = 0;
	if (s[i] == '0') {
		++i;
	}
	n = 0;
	inoct = YES;
	for ( ; inoct == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '7')
			octdigit = s[i] - '0';
		else
			inoct = NO;
		if (inoct == YES)
			n = 8 * n + octdigit;
		}
		return n;
	}
