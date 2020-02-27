//2019-1-12
//当主串与子串都很长且只有最后一个字符不等时，时间复杂度会很高，不是一个健壮的算法。
int strStr(char* haystack, char* needle) {
    char *parentstring = haystack;
    char *parenttemp = NULL;
    char *subtemp = NULL;
    int count;
    int pos = 0;
    if(strlen(haystack)<strlen(needle))
    {
        return -1;
    }
    
    if(needle[0]=='\0')
    {
        return 0;
    }
    else if(needle[0]!='\0'&&haystack[0]=='\0')
    {
        return -1;
    }
    while(*parentstring!='\0')
    {
        parenttemp = parentstring;
        subtemp = needle;
        count = 0;
        while((*parenttemp == *subtemp)&&(*parenttemp!='\0'&&*subtemp!='\0'))
        {
            parenttemp++;
            subtemp++;
            count++;
            if(count==strlen(needle))
            {
                return pos;
            }
        }
        pos++;
        parentstring++;
    }
    if(pos = strlen(haystack)-1)
        return -1;
    return 0;
}

//参考别人后的解法
int strStr(char* haystack, char* needle)
{
    int i,j;
    int flag = 1;
    int p;
    int mid;
    int sublen;
    if(needle == "")
    {
         return 0;
    }
    if(strlen(haystack) < strlen(needle))
    {
       return -1;
    }
    mid = strlen(haystack) - strlen(needle)+1;
    sublen = strlen(needle);
    for(i = 0;i<mid;i++)
    {
        p = i;
        for(j = 0;j<sublen;j++)
        {
            if(haystack[p++] != needle[j])
            {
                flag = 0;
                break;
            }
            flag = 1;
        }
        if(flag == 1)
        {
            return i;
        }
    }
    return -1;
}
/*
问题1：为什么是strlen(haystack) - strlen(needle)+1？
经调试过程得知：主串与子串的长度差为strlen(haystack) - strlen(needle)，
在迭代匹配的过程中，在主串与子串的当前比较的字符不相等的情况下，主串的比较位置就要右移一个单位，
在移动了strlen(haystack) - strlen(needle)个单位后，主串的“剩余”长度与子串的长度相等，
此时，若两者还不匹配，则主串继续偏移，导致其长度彻底小于子串长度，以后就不用匹配了，
主串小于子串的情况下按照题目要求，直接返回-1.
*/