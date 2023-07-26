#include <stdio.h>
#define NONBLANK 'a'
/* copy input to output
 * replace string of blanks with a single blank
 */

int main()
{
	int c, lastc;
	lastc = NONBLANK;
	while ( ( c = getchar() ) != EOF) {
	   if (c != ' ')	
		putchar(c);
	   if (c == ' ')  /* catches first occurence of blank and prints it*/
		if (lastc != ' ') /* but every subsequent blank
                          	* fails this test and does not get printed */
		putchar(c);
	   lastc = c;
	}
return 0;

}
