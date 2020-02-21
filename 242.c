/*
*  2020-01-18 16:58 - 17:00 提交通过
*  张云波
*  浙江-杭州
*/

//字母异位词指字母相同，但排列不同的字符
#include <stdio.h>
#include <string.h>


#define bool int
#define false  0
#define true   1

bool isAnagram(char * s, char * t){
    if(s == NULL || t == NULL)
    {
        return false;
    }

    if (strlen(t) != strlen(s))
    {
        return false;
    }
    int tmp1[128] ={0};
    int tmp2[128] = {0};

    for (int i = 0 ; i < strlen(s);i++)
    {
        tmp1[(int)s[i]]++;
        tmp2[(int)t[i]]++;
    }

    for (int i = 0 ; i < 128;i++)
    {
        if (tmp1[i] != tmp2[i])
        {
            return false;
        }    
    }

    return true;

}

int main()
{
	char *s = "aaaaaabbbbbb";
	char *t = "aabb";
	bool ret = isAnagram(s,t);
	printf("%s\n",(ret == 1)?"yes":"no");
	return 0;
}