#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * reverseWords(char * s){
    char *ret = NULL;
    char *p1 = NULL;
    char *p2 = NULL;
    char *tmp = NULL;
    int len = strlen(s);
	int len2 = 0;
    int incre = 0;    
     
    ret = (char *)malloc(len+1);
    memset(ret,0,len+1);

    if (len <= 0)
    {
        return ret;
    }

    p1 = s;
    while ((p2 = strchr(p1,' ')) != NULL)
    {
        tmp = p2;
        tmp -= 1;
        while (tmp != p1)
        {
            ret[incre++] = *tmp;
            tmp -= 1;
        }

        ret[incre++] = *p1;
        ret[incre++] = ' ';
        p1 = p2+1;
        p2 = NULL;
    }

	p2 = p1+strlen(p1)-1;
	
    while (p1 != p2)
	{
		ret[incre++] = *p2;
		p2 -=1;
	}
	
	ret[incre++] = *p1;
    return ret;
}


int main()
{
	char *s = "Let's take LeetCode contest";
	char *ret = reverseWords(s);
	printf("%s\r\n",ret);	
	return 0;
}





