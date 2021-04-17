#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dfs(int size,int *visited,char **ret_array,char *cur_array,int *cur_size,int *cnt,int k,int *go_flag)
{
    int i = 0;
    char *ret = NULL;
	
	if (*go_flag == 1)
	{
		return;
	}
	
    if (*cur_size == size)
    {
        *cnt += 1;
        if (*cnt == k)
        {
			#if 0
            ret = (char *)malloc(size+1);
            memset(ret,0,size+1);
            strncpy(ret,cur_array,size);
            *ret_array = ret;
			#endif
			
			*ret_array = (char *)malloc(size+1);
			memset(*ret_array,0,size+1);
			strncpy(*ret_array,cur_array,size);
        }
		
        return;
    }

    for (i = 1; i <= size;i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }

        cur_array[*cur_size] = (char)48+i;

        visited[i] = 1;
        (*cur_size) += 1;
        
        dfs(size,visited,ret_array,cur_array,cur_size,cnt,k,go_flag);

        visited[i] = 0;
        (*cur_size) -= 1;
    }
}

char * getPermutation(int n, int k){
    int visited[10] = {0};
    int count = 0;
    char *ret_array = NULL;
    char cur_array[10] = {0};
    int cur_size = 0;
	int go_flag = 0;

    dfs(n,visited,&ret_array,cur_array,&cur_size,&count,k,&go_flag);

    return ret_array;
}

int main()
{
	char *ret = NULL;
	
	int n = 0;
	int k = 0;
	
	scanf("%d",&n);
	scanf("%d",&k);
	
	ret = getPermutation(n,k);
	printf("%s\n",ret);	
	return 0;
}


