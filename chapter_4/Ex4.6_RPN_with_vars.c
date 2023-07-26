#include <stdio.h>
#include <stdlib.h> /* for atof */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n'  /* signal that a name was found */



int getop(char []);
void push(double);
double pop(void);
void mathfnc(char []);

/* reverse polish calculator */

int main () {
	int i, type, var = 0;
	double op2, v;
	char s[MAXOP];
	double variable[26];
	
	for (i = 0; i < 26; i++)
		variable[i] = 0.0;
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case NAME:
			mathfnc(s);
			break;
		case '+':
			push(pop() + pop());
			break ;
		case '*':
			push(pop() * pop());
			break ;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '=':
			pop();
			if (var >= 'A' && var <= 'Z')
				variable[var - 'A'] = pop();
			else
				printf("error: no variable name\n");
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if (type >= 'A' && type <= 'Z')
				push(variable[type - 'A']);
			else if (type == 'v')
				push(v);
			else
				printf("error: unknown command %s\n", s);
			break;
		}
		var = type;
	}
	return 0;
		
}
		
/* functions */

#define MAXVAL 100 		/* maximum depth of val stack */

int sp = 0; 			/*next free stack position */
double val[MAXVAL];		/*value stack */

/* push: push f onto value stack */

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
	}
	
/* pop: pop and return top value from stack */
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0' /*signal that a number was found */
#define NAME 'n'   /* signal that a name was found */

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand, or mat fnc */
int getop(char s[]) {
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t');
		;
	s[1] = '\0';
	i = 0;
	if (islower(c)) { /* command or NAME */
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c); /* went one char to far */
		if (strlen(s) > 1)
			return NAME; /* > 1 char; it is name */
		else
			return c; /* it may be a command */
		}
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	if (c == '-') 
		{ if (isdigit(c = getch()) || c == '.')
			s[++i] = c; /* negative number */
		else {
				if (c != EOF)
					ungetch(c);
				return '-'; /*minus sign*/
			}
		}
	if (isdigit(c)) /*collect integer part*/
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /*collect fraction part*/
			while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

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
	/* mathfnc: check string s for supported math functions */
	void mathfnc(char s[]) {
		double op2;
		
		if (strcmp(s, "sin") == 0)
			push(sin(pop()));
		else if (strcmp(s, "cos") == 0)
			push(cos(pop())); 
		else if (strcmp(s, "exp") == 0)
			push(exp(pop())); 
		else if (strcmp(s, "pow") == 0) {
			op2 = pop();
			push(pow(pop(), op2));
		} else
			printf("error: %s not supported\n", s);
		}
			
