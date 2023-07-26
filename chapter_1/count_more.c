#include <stdio.h>

int main() {

	int c, nl, nt, nb;

	nl = 0, nt = 0, nb = 0;
	while ((c= getchar() ) != EOF) {
		if (c == '\n')
			++nl;
		if (c == '\t')
			++nt;
		if (c == ' ')
			++nb;
		}
		printf("%d %d %d\n", nl, nt, nb);
return 0;

}
