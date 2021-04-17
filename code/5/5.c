void searchstring(char *str,int left,int right,int *start,int *maxlen)
{
    int len = strlen(str);
    while (left >=0 && right <=len-1 && str[left] == str[right])
    {
        left--;
        right++;
    }

    if (*maxlen < right-left-1)
    {
        *start = left+1;
        *maxlen = right-left-1;
    }
}

char * longestPalindrome(char * s){
    char *ret = NULL;
    int len = strlen(s);
    int i = 0;
    int max1_len = 0;
    int max2_len = 0;

    int start1 = 0;
    int start2 = 0;

    if (len < 2)
    {
        return s;
    }
    
    for (i = 0;i < len-1;i++)
    {
        searchstring(s,i,i,&start1,&max1_len);
        searchstring(s,i,i+1,&start2,&max2_len);
    }

    if (max1_len > max2_len)
    {
        ret = (char *)malloc(max1_len+1);
		memset(ret,0,max1_len+1);
        strncpy(ret,s+start1,max1_len);
    }
    else 
    {
         ret = (char *)malloc(max2_len+1);
		 memset(ret,0,max2_len+1);
         strncpy(ret,s+start2,max2_len);
    }

    return ret;
}
