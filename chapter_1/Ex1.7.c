#include <stdio.h>

/* copy input to output and verify expression getchar() != EOF is 0 or 1 */

int main()
{
	int c;

		while (c = getchar() != EOF) /* set c to 0 or 1 */
			printf("%d\n", c);
		printf("%d - at EOF\n", c);
printf("EOF is %d\n", EOF);
return 0;

}


