#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceSpaces(char* S, int length){
    char *str = S;
    char *space_idx = NULL;
    int index = 0;
    int i = 0;
    int len = 0;
    char *ret = NULL;

    while ((space_idx = strchr(str,' ')) != NULL)
    {
        index = length - strlen(space_idx);
        for (i=length-1;i > index ;i-=2)
        {
            S[i] = S[i-2];
            S[i-1] = S[i-3];
        }

        snprintf(S+index,3,"%s","%20");
        str = space_idx+1;
    }

    ret = (char *)malloc(strlen(S)+1);
    strncpy(ret,S,strlen(S));
    ret[strlen(ret)] = '\0';

    return ret;
}

int main()
{
	char g[] = "Mr John Smith    ";
	int len = strlen(g);
	printf("%s",replaceSpaces(g,len));
	return 0;
}
