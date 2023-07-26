#include <stdio.h>
#define MAXLINE 1000

int wordget(char word[], int maxline);
void reverse(char s[]);

int main() {

	char word[MAXLINE];

	while (wordget(word, MAXLINE) > 0 ) {
		reverse(word);
		printf("%s\n", word);
		}
return 0;
}



/*wordget*/
int wordget(char s[], int lim) {

	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) !=EOF && c != ' '; ++i)
		if (i < lim) {
			s[j] = c;
			++j;
		}
	if (c == ' ') {
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}



/* reverse char */
void reverse(char s[]) {

	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0')
		++i;
	--i;
	if (s[i] == ' ')
		--i;
	j = 0;
	while (j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}

}
