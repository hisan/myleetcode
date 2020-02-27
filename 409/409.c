//最长回文串：（从前至后或者从后至前遍历都是一样的字符串 ）
//2019-04-27
int longestPalindrome(char * s){
////若生成的字符串为回文字符串，需要除了中心字符，其余字符只要头部出现，尾部就要对应出现。
    int len = 0;
    int centerlag = 0;
    int hash_map[128] = {0};
    for(int i =0;s[i]!='\0';i++)
    {
        hash_map[s[i]]++;
    }
    for(int i =0;i<128;i++)
    {
        if(hash_map[i]%2==0)
        {
            len += hash_map[i];
        }
        else
        {
            len += hash_map[i]-1;
            centerlag = 1;
        }
    }
    
    if(centerlag)
    {
        return len+=1;  
    }
    else
    {
        return len;
    }
}


//思路：将字符串的出现的次数与字符串建立映射关系，由回文串的特点知道，相同字符出现的次数为偶数，则一定可以参与构成回文串，为奇数则表明该回文串可以有一个中心字符串。






