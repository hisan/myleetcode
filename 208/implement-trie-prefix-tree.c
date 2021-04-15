#if 0

前缀和介绍：
https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/

#endif 



typedef struct st_trie{
    bool isEnd;
    struct st_trie* pnext[26];
}Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *newtree = (Trie *)malloc(sizeof(Trie));
    memset(newtree,0,sizeof(Trie));
    newtree->isEnd = false;
    return newtree;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    if (word == NULL || !obj)
    {
        return;
    }

    Trie *ptmp = obj;
    int  i = 0;
    while (word[i] != '\0')
    {
        char ch = word[i]-'a';
        if (ptmp->pnext[ch] == NULL)
        {
            ptmp->pnext[ch] = trieCreate();
        }
        ptmp = ptmp->pnext[ch];
        i++;
    }
    ptmp->isEnd = true;
    return;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    if (word == NULL || !obj)
    {
        return false;
    }

    Trie *ptmp = obj;
    int  i = 0;
    while (word[i] != '\0')
    {
        char ch = word[i]-'a';
        if (ptmp->pnext[ch] == NULL)
        {
            return false;
        }
        ptmp = ptmp->pnext[ch];
        i++;
    }

    return ptmp->isEnd;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    if (prefix == NULL)
    {
        return false;
    }

    Trie *ptmp = obj;
    int  i = 0;
    while (prefix[i] != '\0')
    {
        char ch = prefix[i]-'a';
        if (ptmp->pnext[ch] == NULL)
        {
            return false;
        }
        ptmp = ptmp->pnext[ch];
        i++;
    }

    return true;
}

void trieFree(Trie* obj) {
    if (obj)
    {
        free(obj);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
