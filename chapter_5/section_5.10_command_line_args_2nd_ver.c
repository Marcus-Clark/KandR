#include <stdio.h>

/* echo command-line arguments: second version */

int main(int argc, char *argv[]) {
	
	
	while (--argc > 0)
		printf("%s%s", *++argv, (argc-1 > 1) ? " " : "");
	printf("\n");
	return 0;
}
