#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getmaxsub(char *str1,char *str2)
{
    int i = 0;
    int len = 0;
    if (str1[0] == '\0') 
    {
        return 0;
    }

    if (str2[0] == '\0')
    {
        return 0;
    }

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            break;
        }
        len++;
        i++;
    }

    return len;
}

int min(int a,int b)
{
    return a<b?a:b;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int max_len = 201;
    char *tmpbuffer = (char *)malloc(200);
    memset(tmpbuffer,0,200);
    strcpy(tmpbuffer,strs[0]);
    for (int i = 1; i < strsSize;i++)
    {
        int tmplen = getmaxsub(tmpbuffer,strs[i]);
        if (tmplen == 0)
        {
            return NULL;
        }
        tmpbuffer[tmplen] = '\0';
        max_len = min(max_len,tmplen);
    }

    return tmpbuffer;
}

int main()
{

	while (1)
	{
		int strsSize = 0;
		scanf("%d",&strsSize);

		char **src = (char **)malloc(sizeof(char *)*strsSize);
		for (int i = 0;i < strsSize;i++)
		{
			src[i] = (char *)malloc(200);
			scanf("%s",src[i]);
		}

		char *res = longestCommonPrefix(src,strsSize);
		printf("\n\n%s\n",res);
		
		for (int i = 0;i < strsSize;i++)
		{
			free(src[i]);
		}
		free(src);
	}

	return 0;
}
