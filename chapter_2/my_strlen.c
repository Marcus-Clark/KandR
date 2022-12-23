#include <stdio.h>

/* my_strlen : return length of s */
int my_strlen(char s[]);

int main(void)
{
    char s[] = "University";
    printf("%d\n", my_strlen(s));
    
    return 0;
}
/* my_strlen : return length of s */
int my_strlen(char s[]) {
	int i;
	
	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
	}
