#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100
int my_getline(char line[], int max);
/* rudimentary calculator */

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


	

