#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a)>(b)?(a):(b)

int maxProduct(char ** words, int wordsSize){
    int i,j;
    int max_size = 0;
    int num_arrary[10000] = {0};
    
    for (i = 0; i < wordsSize; i++)
    {
        for (j = 0;j < strlen(words[i]); j++)
        {
            num_arrary[i] |= 1 << (words[i][j] - 'a'); 
        }
    }

    for (i = 0; i < wordsSize; i++)
    {
        for (j = i+1; j < wordsSize; j++)
        {
            if ((num_arrary[i] & num_arrary[j]) == 0)
            {
                max_size = max(max_size,strlen(words[i])*strlen(words[j]));
            }
        }
    }

    return max_size;
}


int main()
{
	int i = 0 ;
	int wordsSize = 6;
	int max_size = 0;
	char **words = (char **)malloc(sizeof(char *)*wordsSize);
	for (;i < wordsSize;i++)
	{
		words[i] = (char *)malloc(25);
		memset(words[i],0,25);
		scanf("%s",words[i]);
	}
	
	max_size = maxProduct(words,wordsSize);
	printf("%d\n",max_size);
	
	return 0;
}




















