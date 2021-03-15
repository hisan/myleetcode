#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DFS(int left,int right,const int size,char ***ret_array,int *returnSize,char *cur_array,int *cur_size)
{
    if (left == 0 && right == 0)
    {
        (*ret_array) = realloc((*ret_array),sizeof(char *)*(*returnSize+1));
        (*ret_array)[*returnSize] = (char *)malloc(size+1);
        memset((*ret_array)[*returnSize],0,size+1);
        strncpy((*ret_array)[*returnSize],cur_array,size);
        (*returnSize) += 1;
        return;
    }
    
   if (left > 0)
   {
       cur_array[*cur_size] = '(';
       (*cur_size) += 1;
       DFS(left-1,right,size,ret_array,returnSize,cur_array,cur_size);
        (*cur_size) -= 1;
   }

   if (right > left)
   {
        cur_array[*cur_size] = ')';
        (*cur_size) += 1;
        DFS(left,right-1,size,ret_array,returnSize,cur_array,cur_size);
         (*cur_size) -= 1;
   }
} 

char ** generateParenthesis(int n, int* returnSize)
{
    char **ret_array = NULL;
    char cur_array[17] = {0};
    int cur_size = 0;
    
    (*returnSize) = 0;
    DFS(n,n,2*n,&ret_array,returnSize,cur_array,&cur_size);
    
    return ret_array;
}

void print_char_1(char *ret,int size)
{
	int i = 0;
	for (i = 0;i < size-1;i++)
	{
		printf("%c ",ret[i]);
	}
	
	printf("%c\n",ret[i]);
}

void print_char(char **ret,int returnSize,int size)
{
	int i = 0;
	for (i = 0;i < returnSize;i++)
	{
		print_char_1(ret[i],size);
	}
}

int main()
{
	int n = 4;
	int returnSize = 0;
	char **ret = generateParenthesis(n,&returnSize);
	
	print_char(ret,returnSize,2*n);
	
	printf("%d\n",returnSize);
	return 0;
}












