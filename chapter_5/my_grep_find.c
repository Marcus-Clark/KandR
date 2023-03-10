#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char *line, int max);

/*find: print lines that match pattern from 1st arg */
/*example usage:									*/
/* bash-5.1$ cat tyger.txt | ./my_grep_find -n burning */

int main (int argc, char *argv[]) {
	
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	
	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			switch (c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (my_getline(line, MAXLINE) > 0) {
			lineno++;
		if((strstr(line, *argv) != NULL) != except) {
			if (number)
				printf("%ld:", lineno);
					printf("%s", line);
					found++;
			}
		}
	return found;
}
	
	


/* getline: read a line into line, return length */

int my_getline(char *line, int max) {
	int c;
	char *t = line;
	
	while (--max > 0 && (c=getchar()) != EOF && c != '\n')
		*line++ = c;
	if (c == '\n')
		*line++ = c;
	*line = '\0';
	return line - t;
}
