#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100
int my_getline(char line[], int max);
/* rudimentary calculator
 * This one handles scientific notation of the
 * form 123.45e-6 */

int main() {

	double sum; 
	double atof(char []);
	char line[MAXLINE];
	int my_getline(char line[], int max);
	
	sum = 0;
	while (my_getline(line, MAXLINE) > 0)
		printf("\t%g\n",sum = sum + atof(line));
	return 0;
	}

/* atof: convert string s to double; can handle scientific 
 * notation of the form 123.45e-6*/

double atof(char s[]) {
	double val, power;
	int exp, i, sign;
	
	for (i = 0; isspace(s[i]); i++) /*skip white space */
	;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]) ; i++) {
		val = 10.0 * val + (s[i] - '0') ;
		power *= 10.0;
	}
	val = sign * val /power;
	
	if (s[i] == 'e' || s[i] == 'E') {
			sign = (s[++i] == '-') ? -1 : 1;
			if (s[i] == '+' || s[i] == '-')
				i++;
			for (exp = 0; isdigit(s[i]); i++)
				exp = 10 * exp + (s[i] - '0');
			if (sign == 1)
				while (exp-- > 0) /*positive exponent */
					val *= 10;
			else
				while (exp-- > 0) /*negative exponent */
					val /= 10;
				}
			return val;
		}
			
					
		
		/* my_getline: get line into s, return length */
int my_getline(char s[], int lim) {
	int c , i;
	
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

