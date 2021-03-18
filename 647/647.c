int searchstring(char *s,int left,int right)
{
	int cnt = 0;
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right])
    {
		//扩散
        --left;
		right++;
		
		cnt += 1;
    }
	
	return cnt;
}

int countSubstrings(char * s){
	int len = strlen(s);
	int i = 0;
	int cnt = 0;
	
	for (i = 0;i < len;i++)
	{
		cnt += searchstring(s,i,i);
		cnt += searchstring(s,i,i+1);
	}
	
	return cnt;
}
