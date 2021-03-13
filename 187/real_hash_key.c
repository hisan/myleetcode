#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
char ** findRepeatedDnaSequences(char *s, int* returnSize)
{
	int map[85] = {0};
	char **res = NULL;
	int mask = 0x3ffff;
	int cur = 0;
	int i = 0;
    int len = strlen(s);
    char buffer[11] = {0};
	int *hash_table = NULL;
    int num = pow(2,20);
	
	(*returnSize) = 0;

	if (len <=10)
	{  
		return res;
	}
	
	hash_table = (int *)malloc(sizeof(int)*num);
	memset(hash_table,0,sizeof(int)*num);
	
	
	map[(int)'A'] = 0;//00...00
	map[(int)'C'] = 1;//00...01
	map[(int)'G'] = 2;//00...10
	map[(int)'T'] = 3;//00...11
	
	for (i = 0; i < 9; ++i) {
		cur = (cur << 2) | (map[(int)s[i]]);
	}
	
	//printf("%x\n\n",cur);
	
	for (i = 9; i < len; i++) 
	{
		cur = ((cur & mask) << 2)|(map[(int)s[i]]);
		if (hash_table[cur] == 1)
		{
			res = realloc(res,sizeof(char *)*(*returnSize+1));
			res[*returnSize] = (char *)malloc(11);
			memset(res[*returnSize],0,11);
			strncpy(res[*returnSize],&s[i-9],10);
			(*returnSize) += 1;
		}
		
		hash_table[cur]++;
	}
	free(hash_table);
	return res;
}

int main()
{
	char *s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	int returnSize = 0;
	char **res = findRepeatedDnaSequences(s,&returnSize);
	int i = 0;
	
	for (i = 0; i < returnSize;i++)
	{
		printf("%s\n",res[i]);
	}
	
	return 0;
}