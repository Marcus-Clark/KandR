#include <stdio.h>
#include <ctype.h>
int my_atoi(char *s);

int main () {
	char *s = "0";
	printf("s is %s, after func: %d\n", s, my_atoi(s));

return 0;
}

/* mt_atoi: convert s to integer: pointer version*/
int my_atoi(char *s) {
	int n, sign;
	
	for ( ; isspace(*s); s++) 		/*skip white sapce */
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')		/*skip sign */
		s++;
	for (n = 0; isdigit(*s); s++)
		n = 10 * n + *s - '0';
	return sign * n;
}
