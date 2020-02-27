
int lengthOfLongestSubstring(char* s) {

    int maxlen = 0,currlen = 0;
    int table[128], i, j, start = 0;
    memset(table, 0, sizeof(table));
    for (i = 0; s[i] != '\0'; ++i)
    {//这里是取每个字符出现的次数，但是这个次数并不是一开始就设定好的，而是在遍历的过程中逐渐累加的
        int num =  ++table[s[i]];//这里应该分两步写
        if( num == 2 )//先判断再累加,避免多+1个长度
        {//num是每个字符出现的次数，
    //这个逻辑就是，当我们扫描到的当前的这个字符是第二次出现，我们就去判断我们当前的子串是从哪里开始出现重复字符的
            if (currlen > maxlen)
            {
                maxlen = currlen;
            }
            for(j = start; j < i; ++j)
            {//从头遍历扫描到的子串
                if (s[j] == s[i])
                {
                    table[s[j]] = 1;//复位，逻辑等同于字符串右移一位
                    start = j+1;//下次查找的起始位置
                    break;
                }
                else
                {
                    --currlen;//currlen在遍历的过程中永远变化，当当前子串开始出现重复元素时，
                    table[s[j]] = 0;
                }
            }
        }
        else
        {
            ++currlen;
        }
        
    }
    
    if (currlen > maxlen)
    {
        maxlen = currlen;
    }

    return maxlen;
}
