#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max # lines to be sorted */

char *lineptr[MAXLINES]; 	/*pointer to text lines	*/

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);


/* sort intput lines */

int main () {
	int nlines; 		/*number of input lines read */
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines -1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
#define MAXLEN 1000		/*max length of ant input line */
int my_getline(char *, int);
char *alloc(int);

/*readline: read input lines */
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0 )
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; 	/*delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
	int i;
	
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
	}

/* my_getline: read a line into s, return length */

int my_getline(char *s, int lim) {
	int c;
	char *t = s;
	
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}

/* qsort: sort v[left]...v[right] into increasing order*/

void qsort(char *v[], int left, int right) {
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right)		/*Do nothing if array contains */
		return;				/* fewer than two elements		*/
	swap(v, left, (left + right)/2); /*move partition elem	*/
	last = left; 					/* to v[0] 			*/
	for (i = left+1; i <= right; i++)   /* partition */
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/*swap: interchange v[i] and v[j] */

void swap(char *v[], int i, int j) {
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}
#define ALLOCSIZE 10000		/*size of available space	*/

static char allocbuf[ALLOCSIZE]; /*storage for alloc	*/
static char *allocp = allocbuf;  /*next free position 	*/

char *alloc(int n) {
 if (allocbuf + ALLOCSIZE - allocp >=n) {
	allocp += n;
	return allocp -n;
} else 
	return 0;
}
