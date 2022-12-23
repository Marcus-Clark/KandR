#include <stdio.h>
#define MAX 1000

void squeeze(char s[], int o);


int main () {
/*char s[]="cool coke cans";*/
int o = 'o';
char s[MAX];
  
 
    printf("Enter  the string : ");
    fgets(s, MAX, stdin);
squeeze(s,o);


printf("%s\n", s );

	
return 0;	
	
}


/*squeeze: remove all o from s*/

void squeeze(char s[], int o) {
	
		int i, j;
		
		for (i = j = 0; s[i] != '\0'; i++)
			if (s[i] != o)
				s[j++] = s[i];
		s[j] = '\0';
		}
