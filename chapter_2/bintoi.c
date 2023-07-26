#include <stdio.h>
#define YES 	1
#define NO 		0

int bintoi(char s[]);

int main() {
char s[] = "1010101";
printf("%u" , bintoi(s) );

	return 0;
}
/* bintoi: convert binary string s to integer */

int bintoi(char s[]) {
	int bindigit, i, inbin, n;
	i = 0;
	if (s[i] == '0') {
		++i;
	}
	n = 0;
	inbin = YES;
	for ( ; inbin == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '1')
			bindigit = s[i] - '0';
		else
			inbin = NO;
		if (inbin == YES)
			n = 2 * n + bindigit;
		}
		return n;
	}
