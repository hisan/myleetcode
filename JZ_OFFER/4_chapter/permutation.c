#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void DFS(const char *str,const int len,char ***res,int *returnSize,char *cur_str,int cur_size)
{
    if (cur_size == len)
    {
        (*res) = realloc((*res),sizeof(char *)*(*returnSize + 1));
        (*res)[*returnSize] = (char *)malloc(len+1);
        strncpy((*res)[*returnSize],cur_str,len);
        (*res)[*returnSize][len] = '\0';
        (*returnSize) += 1;
        return;
    }

    int str_len = strlen(str);
    char newstr[20] = {0};
    int newsize = 0;
    int visited[128] = {0};
    for (int i = 0; i < str_len;i++)
    {
        if (visited[(int)str[i]] == 1)//¿¿¿¿¿¿¿¿¿¿¿
        {
            continue;
        }
        
        visited[(int)str[i]] = 1;
        cur_str[cur_size] = str[i];
		newsize = 0;
		
        for (int j = 0;j < str_len;j++)
        {
            if (j != i)
            {
                newstr[newsize++] = str[j];
            }
        }
        DFS(newstr,len,res,returnSize,cur_str,cur_size+1);
    }
}

char** permutation(char* s, int* returnSize){
    char **res = NULL;
    char cur_str[20] = {0};
    int cur_size = 0;
    int len = strlen(s);

    (*returnSize) = 0;
    DFS(s,len,&res,returnSize,cur_str,cur_size);
    return res;
}

int main()
{
	
	struct timeval StartTime;
	struct timeval EndTime;
	double TimeUse=0;
	
	gettimeofday(&StartTime, NULL);  //²âÁ¿¿ªÊ¼
	 
	
	
	//Òª²âÁ¿µÄ³ÌÐò´úÂë
	char *s = "dkjphedy";
	int returnSize = 0;
	char** res = permutation(s,&returnSize);
	printf("%d\n",returnSize);
	
	gettimeofday(&EndTime, NULL);   //²âÁ¿½áÊø

	TimeUse = 1000000*(EndTime.tv_sec-StartTime.tv_sec)+EndTime.tv_usec-StartTime.tv_usec;
	TimeUse/=1000;  //²âÁ¿½á¹û£¬ºÁÃë¼¶±ð


	
	// for (int i = 0; i < returnSize;i++)
	// {
		// printf("%s\n",res[i]);
	// }
	
	
	printf("cost: %f ms\n",TimeUse);
	
	return 0;
}






