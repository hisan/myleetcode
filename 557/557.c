#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reversestr(char *s,int sublen)
{
    int i = 0;
    char *tmp = malloc(sublen);
	memset(tmp,0,sublen);
	
    for (i = sublen-1;i >=0;i--)
    {
        tmp[i] = s[sublen-1-i];
    }

    return tmp;
}

char * reverseWords(char * s){
    char *ps = NULL;
    char *pe = NULL;
    int sublen = 0;
    char dst[1000] = {0};
    char tmp[100] = {0};
    char *tp = NULL;
    ps = s;
    while ((pe = strchr(ps,' ')) !=NULL)
    {
        sublen = strlen(ps) - strlen(pe);
        strncpy(tmp,ps,sublen);
        tp = reversestr(tmp,sublen);
        
        if (tp != NULL)
        {
            strncpy(dst+strlen(dst),tp,sublen);
            dst[strlen(dst)] = ' ';
			free(tp);
        }

        ps = pe+1;
    }

	
	
    if (ps != NULL)
    {
		
		sublen = strlen(ps);
        strncpy(tmp,ps,sublen);
        tp = reversestr(tmp,sublen);
		
        if (tp != NULL)
        {
		    dst[strlen(dst)] = ' ';
            strncpy(dst+strlen(dst),tp,sublen);
			free(tp);
        }
    }
	
	printf("%s\n",dst);

    return dst;
}

int main()
{
	char *src = "Let's take LeetCode contest";
	
	printf("%s",reverseWords(src));
	
	return 0;
}
