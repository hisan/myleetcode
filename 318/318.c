#define max(a,b) (a)>(b)?(a):(b)
int maxProduct(char ** words, int wordsSize){
    int i,j;
    int max_size = 0;
    int num_array[10000] = {0};

    for (i=0;i<wordsSize;i++)
    {
        for (j=0;j<strlen(words[i]);j++)
        {
            num_array[i] |= 1<<(words[i][j] - 'a');
        }
    }

    for (i=0;i<wordsSize;i++)
    {
        for (j=i+1;j<wordsSize;j++)
        {
            if ((num_array[i] & num_array[j]) == 0)
            {
                max_size = max(max_size,strlen(words[i])*strlen(words[j]));
            }
        }
    }

    return max_size;
}

