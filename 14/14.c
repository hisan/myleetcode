/*
	2020-08-04 23:36 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//寻找两个字符串之间的公共长缀,找到后并在原来的基础上修改为当前最短前缀
void comparetwostring(char *minstr1,char *str2)
{
    int len = strlen(minstr1);
    for (int i = 0;i < len;i++)
    {
        if(minstr1[i] == str2[i])
        {
            if (minstr1[i] == '\0')
            {
                return;
            }

            if (minstr1[i+1] == '\0')
            {
                return;
            }
        }
        else 
        {
            minstr1[i] = '\0';
            return;
        }
    }

    return ;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    
    if (strsSize == 0)
    {
        return "";
    }

    if (strsSize == 1)
    {
        return strs[0];
    }

    for (int i = 0;i < strsSize;i++)
    {
        if (i != 0)
        {
            comparetwostring(strs[0],strs[i]); 
        }
    }

    return strs[0];
}

int main()
{
	int strnum = 3;
	int tmplen = 100;
	char **p = (char **)malloc(sizeof(char *)*strnum);
	for (int i = 0; i < strnum;i++)
	{
		p[i] = malloc(sizeof(char)*tmplen);
	}
	
	strcpy(p[0],"flower");
	strcpy(p[1],"flow");
	strcpy(p[2],"flight");
	
	printf("%s\r\n",longestCommonPrefix(p,strnum));
	
	return 0;
}
