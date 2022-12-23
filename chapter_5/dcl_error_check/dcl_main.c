#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100
/* Author: Robert Taylor
 * Creation Date: June, 2014
 * Exercise 5-18
 * "Make dcl recover from input errors"
 * If you are doing this exercise for a course, you probably would
 * not be expected to do as much as you will find in this source file.
 *
 * You should be able to copy and paste most declarations from a
 * source file that you might find to the input to this dcl program.
 *
 * Notable limitations include: the reference operator '&' is not 
 * handled, a symbolic constant that is in an array subscript
 * will be seen as an invalid subscript, type modifiers/qualifiers such as
 * static, const, long, short, unsigned, signed etc. are not handled as they
 * will be part of the answer for Exercise 5-20.
 *
 * This dcl can handle multiple declarations on a line such as
 * char *p, line[MAXLEN];
 * dcl can also handle comments, and detects end of declaration indicators
 * such as ; or { or =
 *
 * Recovery from errors is interpreted to mean that despite missing one of
 * [ or ] or ( or ) or NAME, an error message should be displayed and some 
 * educated interpretation should be attempted. In the case of parentheses
 * it is sometimes difficult to know where they should have been so the
 * resulting interpretation will not necessarily be correct.
 *
 * In the case of a missing NAME, instead of outputting an error the name
 * is simply omitted from the output. The following for example:
 * char (*(*())[])()
 * will output:
 * :  function returning pointer to array[] of pointer to function returning char
 */

enum { NAME, PARENS, BRACKETS };

static void dcl(void);
static void dirdcl(void);

static int gettoken(void);
static int tokentype; /* type of last token */
static int oldtoken; /* previous tokentype */
static char token[MAXTOKEN]; /* last token string */
static char name[MAXTOKEN]; /* identifier name */
static char datatype[MAXTOKEN]; /* data type = char, int, etc. */
static char out[1000]; /* output string */
static int parenopen = 0; /* count of open parentheses */
static int parenclose = 0; /* count of unmatched close parentheses */
static int alphaseen = 0; /* track alpha statis for subscript */

int main(void) /* convert declaration to words */
{
	while (gettoken() != EOF) { /* 1st token on line */		
		strcpy(datatype, token); /* pull data type */
		while (tokentype != '\n'){
			out[0] = '\0';
			name[0] = '\0';
			token[0] = '\0';
			parenopen = 0;
			parenclose = 0;
			dcl(); /* parse rest of line */
			if (parenopen > 0) {
				printf("error: missing one or more )\n");
			} 
			if (parenclose > 0) {
				printf("error: missing one or more (\n");
			}
			printf("%s: %s %s\n", name, out, datatype);
		}
	}	
	return 0;
}

/* dcl: parse a declarator */
static void dcl(void)
{
	int ns;
	for (ns = 0; gettoken() == '*'; ) /* count *'s */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
static void dirdcl(void)
{
	int tempparens;
	if (tokentype == ','){ /* allow multiple declarators on a line */
		tokentype = '\n';
	}
	if (tokentype == '\n'){
		return;
	}
	if (tokentype == '('){ /* ( dcl ) */
		++parenopen;
		dcl();
		if (tokentype == ')'){
			--parenopen;
		} else { 
			if(oldtoken == '(')
				strcat(out, " function returning");
			ungetch();
		}
	} else if (tokentype == NAME){ /* variable name */
		strcpy(name, token);
	} else if (tokentype == PARENS){
		strcat(out, " function returning");
	} else if (tokentype == BRACKETS){
		strcat(out, " array");
		strcat(out, token);
		strcat(out, " of");
	} else if (oldtoken == NAME && tokentype == ')'){
		++parenclose;
		strcat(out, " function returning");
	} else {
		printf("error: expected name or (dcl)\n");
	}
	gettoken();
	while (tokentype == PARENS || tokentype == BRACKETS 
			|| tokentype == '(' || isdigit(tokentype) ||
			tokentype == NAME){
		if (tokentype == PARENS){
			strcat(out, " function returning");
		} else if (tokentype == BRACKETS) {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		} else if (tokentype == '('){
			/* process function with parameters... for now
			 * just ignoring them */
			/* prevents detection of unmatched ) in gettoken() */
			++parenopen; /* don't remove this! */
			tempparens = 1; /* track balanced parentheses */
			strcat(out, " function returning");
			do {
				gettoken();
				if (tokentype == '('){
					++tempparens;
				} else if (tokentype == ')'){
					--tempparens;
				} else if (tokentype == '\n'){
					return;
				}
			} while (tokentype != ')' || tempparens != 0);
			--parenopen;
		} else {
			/* saw NAME or digit: it could be this was part
			 * of a parameter to a function or a subscript
			 * to an array */
			do {
				gettoken();
				if (tokentype == BRACKETS){
					strcat(out, " array");
					strcat(out, token);
					strcat(out, " of");
					break; /* exit do-while */
				}
				if (tokentype == PARENS){
					strcat(out, " function returning");
					break; /* exit do-while */
				}
			} while(tokentype != '\n');
			if (tokentype == '\n')
				return;
		}
		gettoken();
	}
}

/* gettoken: return next token.
 * I have getch() and ungetch() included from the header
 * file getch.h , note that ungetch() in my implementation
 * requires no parameter.
 */
static int gettoken(void)
{
	int c;
	int i;
	char *p = token;
	oldtoken = tokentype; /* back up tokentype */
	while ((c = getch()) == ' ' || c == '\t')
		;
	/* remove comments */
	while (c == '/'){
		c = getch();
		if (c == '/'){
			while (c != '\n')
				c = getch();
		}
		if (c == '*'){ /* start of comment */
			do {
				c = getch();
				if (c == '*'){
					c = getch();
					if(c == '/'){
						c = getch();
						break;
					}
				}
			} while (c != '\n');
		}
	}
	/* Assume anything past one of these characters is something
	 * we do not care to process. */
	if (c == ';' || c == '{' || c == '='){
		while (c != '\n')
			c = getch();
	} 
	/* count unmatched closing parentheses */
	if (c == ')' && parenopen == 0){		
		++parenclose;
		return tokentype = PARENS;
	}
	if (c == '('){
		if ((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch();
			return tokentype = '(';
		}
	} else if (c == '['){ /* we sort of know what should be in here */
		alphaseen = 0;
		for (*p++ = c, i = 0; (c = getch()); ++i){
			while (c == ' ' || c == '\t') /* allow for space */
				c = getch();
			if (i == 0 && isalpha(c)){
				*p++ = c;
				alphaseen = 1;
			} else if (isdigit(c) && alphaseen == 0){
				*p++ = c;
			} else if (i > 0 && isalpha(c)){
				printf("error: invalid array subscript\n");
				while (isalnum(c = getch()))
					;
				ungetch();
			} else if (isdigit(c) && alphaseen){
				printf("error: invalid array subscript\n");
				while (isalnum(c = getch()))
					;
				ungetch();
			} else if (c == ']'){
				*p++ = c;
				break;
			} else {
				printf("error: missing ]\n");
				*p++ = ']';
				ungetch();
				break;
			}
		}
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (c == ']'){ /* unmatched closing bracket? */
		printf("error: missing [\n");
		*p++ = '[';
		*p++ = ']';
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c) || c == '_') { /* an _ is a valid char too */
		for (*p++ = c; isalnum(c = getch()) || c == '_'; )
			*p++ = c;
		*p = '\0';
		ungetch();
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}
