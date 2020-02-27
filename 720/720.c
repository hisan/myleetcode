//cpp版本
class Solution {
public:
    string longestWord(vector<string>& words) {
        string best, temp;
        sort(words.begin(), words.end());//单词排序，
        for (int i = 0; i < words.size(); i++) {
            int len = words[i].length();
            if (temp.substr(0, len - 1) == words[i].substr(0, len - 1)) {
                temp = words[i];        //由单词数组的特征可知，第一个单词一定为一个字母
                if (len > best.length())
                    best = words[i];
            }
        }
        return best;
    }
};

//C语言版本
int CalcSeqVal(char *string)
{
    int ret = 0;
    for(int i =0 ;i<strlen(string);i++)
    {
        ret += (int)string[i];
    }
    return ret;
}

char * longestWord(char **words, int wordsSize)
{
    char *p = NULL;
    char *temp = NULL;
    char *best = NULL;
    
    int seqcount = 0;
    int seqarray[1001] = {0};

    for(int i =0 ; i< wordsSize;i++)
    {
        if(strlen(words[i]) == 1)
        {
            seqarray[seqcount++] = i;
        }
    }
    seqarray[seqcount++] = wordsSize;
#if 1
    if(seqcount >=2)
    {
        for(int k = 0;k<seqcount;k++)
        {
            for(int i = seqarray[k] ;(i < seqarray[k+1])||(i < wordsSize);i++)
            {//冒泡排序得到字典序
                for(int j = i+1 ;j<seqarray[k+1];j++)
                {
                    int len1 = strlen(words[i]);
                    int len2 = strlen(words[j]);
                    int seqval1 = CalcSeqVal(words[i]);
                    int seqval2 = CalcSeqVal(words[j]);
                    if(len1 >= len2 )
                    {
                        if((len1 == len2)&&(seqval1 > seqval2))
                        {//长度相等，但是字典序前面的较大，则进行交换
                            char temp1[35]={0};
                            strcpy(temp1,words[i]);

                            words[i] = NULL;
                            words[i] = (char*)realloc(words[i],sizeof(char)*35);
                            strcpy(words[i],words[j]);

                            words[j] = NULL;
                            words[j] = (char*)realloc(words[j],sizeof(char)*35);
                            strcpy(words[j],temp1);

                            continue;
                        }
                        else if(len1 == len2)
                        {
                            continue;
                        }
                
                        char temp[35]={0};
                        strcpy(temp,words[i]);

                        words[i] = NULL;
                        words[i] = (char*)realloc(words[i],sizeof(char)*35);
                        strcpy(words[i],words[j]);
                
                        words[j] = NULL;
                        words[j] = (char*)realloc(words[j],sizeof(char)*35);
                        strcpy(words[j],temp);
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0 ;i<wordsSize;i++)
        {//冒泡排序得到字典序
            for(int j = i+1 ;j<wordsSize;j++)
            {
                int len1 = strlen(words[i]);
                int len2 = strlen(words[j]);
                int seqval1 = CalcSeqVal(words[i]);
                int seqval2 = CalcSeqVal(words[j]);

                if(len1 >= len2 )
                {
                    if((len1 == len2)&&(seqval1 > seqval2))
                    {//长度相等，但是字典序前面的较大，则进行交换
                        char temp1[35]={0};
                        strcpy(temp1,words[i]);

                        words[i] = NULL;
                        words[i] = (char*)realloc(words[i],sizeof(char)*35);
                        strcpy(words[i],words[j]);

                        words[j] = NULL;
                        words[j] = (char*)realloc(words[j],sizeof(char)*35);
                        strcpy(words[j],temp1);

                        continue;
                    }
                    else if(len1 == len2)
                    {
                        continue;
                    }
                
                    char temp[35]={0};
                    strcpy(temp,words[i]);

                    words[i] = NULL;
                    words[i] = (char*)realloc(words[i],sizeof(char)*35);
                    strcpy(words[i],words[j]);
                
                    words[j] = NULL;
                    words[j] = (char*)realloc(words[j],sizeof(char)*35);
                    strcpy(words[j],temp);
                }
            }
        }
    }
#endif
    
    p = words[0];
    best = words[0];

    if(seqcount >= 2 )
    {
        for(int k = 0;k<seqcount;k++)
        {
            p = words[seqarray[k]];
            for(int i = seqarray[k] ; i<seqarray[k+1];i++)
            {
                if(!strncmp(words[i],p,strlen(p)))
                {
                     p = words[i];
                }
            }

            if(strlen(p)>=strlen(best))
            {
                if( strlen(p) == strlen(best) )
                {
                    if( (int)p[0] < (int)best[0] )
                    {
                        best = p;
                        continue;
                    }
                }
                best = p;
            }
        }
        return best;
    }
    else
    {
        for(int i = 0 ; i < wordsSize;i++)
        {
            if(!strncmp(words[i],p,strlen(p)))
            {
                    p = words[i];
            }
        }
        return p;
    }

    return NULL;
}

