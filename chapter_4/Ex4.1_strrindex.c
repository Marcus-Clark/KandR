/*************************************************************
strrindex will return the rightmost starting position of t in s.
I thought this was neat as it's simply the original strindex 
function from K&R page 69 with the smallest of changes.  I
interpreted the exercise as asking for the index of s at which
the final occurence of t begins e.g. for "aaZ" in "aaZZaaaZZaaZa"
the answer would be 9.
*************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main()
{
        int i;
	char parent[] = "123456789in";
	char child[] = "in";
        i = strrindex(parent,child);
        printf("%d\n",i); /* strrindex: returns rightmost --> index of t in s, -1 if none */
        return 0;
}
/* strrindex: returns rightmost --> index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k, pos = -1;
        for (i = 0; s[i] != '\0'; i++)
	{
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
        return pos;
}
