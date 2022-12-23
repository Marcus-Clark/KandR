#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = my_getline(line, MAXLINE)) > 0)
		if (len > max) {
		max = len;
		copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

/* my_getline */
int my_getline(char s[], int lim)
{
	int c, i;
	enum loop {NO, YES};
	enum loop okloop = YES;
	
	i=0;
	while (okloop == YES)
		if (i >= lim-1)
			okloop = NO;
		else if ((c = getchar() ) == '\n')
			okloop = NO;
		else if (c == EOF)
			okloop = NO;
		else {
				s[i] = c;
				++i;
			}
if (c == '\n') {
                s[i] = c;
                ++i;
        }
	s[i] = '\0';
	return i;
}

/* copy */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
