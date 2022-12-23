#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 1000000

struct tnode {		/*the tree node	*/
	char *word;		/*points to the text */
	int count;		/*number of occurences	*/
	struct tnode *left; /*left child */
	struct tnode *right; /*right child */
} ;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int getch(void);
void ungetch(int c);
/* word count: count word frequency*/
int main() {
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}
struct tnode *talloc(void);
char *my_strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
	int cond;
	
	if (p == NULL) { 				/* a new word has arrived */
		p = talloc();				/* make a new node		*/
		p->word = my_strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++ ;				/*repeated word  */
	else if (cond < 0)				/* less than into left subtree */
		p->left = addtree(p->left, w);
	else 							/*greater than into right subtree*/
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
#include <stdlib.h>

/*talloc: make a tnode */
struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}
/* my_strdup: make a duplicate of s */
char *my_strdup(char *s) {
	char *p;
	
	p = (char *) malloc(strlen(s)+1);	/* +1 for '\0' */
	if (p != NULL)
			strcpy(p, s);
	return p;
}
		

/*getword: get next word or character from input*/
int getword(char *word, int lim) {
	int c, d, comment(void), getch(void);
	
	char *w = word;
	
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (isalpha(c) || c == '_' || c == '#') {
		for ( ; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') {
				ungetch(*w);
				break;
			}
	} else if (c  == '\'' || c == '"') {
		for ( ; --lim > 0; w++)
			if ((*w = getch()) == '\\')
				*++w = getch();
			else if (*w == c) {
				w++;
				break;
			} else if (*w == EOF)
				break;
				} else if (c == '/')
				if ((d = getch()) == '*')
					c = comment();
				else
					ungetch(d);
				*w = '\0';
				return c;
			}
/*comment: skip over comment and return a character */
int comment(void) {
	int c;
	while (( c = getch()) != EOF)
			if (c == '*')
				if ((c = getch()) == '/')
					break; 
				else
					ungetch(c); 
		return c; 
		}

/* getch and ungetch */
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch*/
int bufp = 0; /* next free position in buf*/

int getch(void) { 
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
	}
