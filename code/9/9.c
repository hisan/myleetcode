void searchstring(char *s,int left,int right,int *start,int *max)
{
    int len = strlen(s)-1;
    while (left >= 0 && right <=len && s[left] == s[right])
    {
        left--;
        right++;
    }

    if (*max < right - left -1)
    {
        *max =  right - left -1;
        *start = left+1;
    }
}

bool judgePalindrome(char *s)
{
    int start1 = 0,start2 = 0;
    int max1 = 0,max2 = 0;
    int len = strlen(s);

    for (int i = 0 ; i < len-1;i++)
    {
        searchstring(s,i,i,&start1,&max1);
        searchstring(s,i,i+1,&start2,&max2);
    }

    if (max1 == len || max2 == len)
    {
        return true;
    }

    return false;
}

bool isPalindrome(int x){
    char buffer[11] = {0};
    if (x < 0)
    {
        return false;
    }

    if (x < 10)
    {
        return true;
    }

    sprintf(buffer,"%d",x);
    return judgePalindrome(buffer);
}
