#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceSpace(char* s){
    if (strlen(s) <= 0)
    {
        return "";
    }

    int len = strlen(s);
    char *newstring = (char *)malloc(len+1);
    memset(newstring,0,len+1);
	len += 1;

    int  i = 0;
    int j = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            newstring = realloc(newstring,len+2);
            len += 2;
            newstring[j++] = '%';
            newstring[j++] = '2';
            newstring[j++] = '0';
            //strncpy(newstring+strlen(newstring),"%20",3);
        }
        else 
        {
            newstring[j++] = s[i];
            //newstring[strlen(newstring)] = s[i]; 
        }
        i++;
    }
    return newstring;
}

int main()
{
	char *src = "We are happy.";
	char *dst = replaceSpace(src);
	printf("%s\n",dst);
	free(dst);
	return 0;
}
