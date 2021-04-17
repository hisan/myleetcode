int lengthOfLongestSubstring(char * s){
    int left = 0;
    int right = 1;
    int maxlen = 0;
    int hashmap[128] = {0};

    if (strlen(s) <=1)
    {
        return strlen(s);
    }
    
    hashmap[s[0]] = 1;
    while (s[right] != '\0')
    {
        if (hashmap[s[right]] > 0)
        {
            if (maxlen < right - left)
            {
                maxlen = right - left;
            }

            if (left < hashmap[s[right]])
            {
                left = hashmap[s[right]];
            }
        }

        hashmap[s[right]] = right+1;
        right++;
    }

    if (maxlen < strlen(s) - left)
    {
        maxlen = strlen(s) - left;
    }

    return maxlen;
}
