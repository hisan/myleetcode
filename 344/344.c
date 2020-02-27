
void reverseString(char* s, int sSize)
{
    int len  = sSize-1;
    char temp;
    int i = 0;

    for(i = 0;i <= len;i++,len--)
    {//i > len时，反转完成
       temp = s[i];
       s[i] = s[len];
       s[len] = temp;
    }
}