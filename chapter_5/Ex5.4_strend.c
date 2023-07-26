#include <stdio.h>
int my_strend(char *s, char *t);

int main() {
	char s[] = "aaaaaX";
	char t[] = "aaaaX";
	printf("Value returned from strend is: %d\n", my_strend(s,t));
	
	int result = my_strend(s,t);
	
		if ( result == 1)
		{
			printf("Therefore string t occurs at end of string s\n");
		}
		else
		{
			printf("Therefore string t does NOT occur at end of string s\n");
		}
	
	return 0;
}

/* my_strend: return 1 if string t occurs at end of s */
int my_strend(char *s, char *t) {
	char *bs = s; 		/* remember beginning of str s */
	char *bt = t;
	
	for ( ; *s; s++)	/* end of the string s	*/
		;
	for ( ; *t; t++) 	/*end of string t		*/
		;
	for ( ; *s == *t; s--, t--)
		if (t == bt || s == bs)
			break; 		/* at the beginning of a str */
	if (*s == *t && t == bt && *s != '\0')
		return 1;
	else
		return 0;
	}
