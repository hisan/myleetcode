#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void DFS(const char *str,const int len,char ***res,int *returnSize,char *cur_str,int cur_size,int *num_visited)
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

    int visited[128] = {0};
    for (int i = 0; i < len;i++)
    {
		if (num_visited[i] == 1)//深度优先遍历的保证
		{
			continue;
		}
		
        if (visited[(int)str[i]] == 1)//同层次重复元素剪枝去重
        {
            continue;
        }
		
		num_visited[i] = 1;
        visited[(int)str[i]] = 1;
        cur_str[cur_size] = str[i];

        DFS(str,len,res,returnSize,cur_str,cur_size+1,num_visited);
		num_visited[i] = 0;
    }
}

char** permutation(char* s, int* returnSize){
    char **res = NULL;
    char cur_str[20] = {0};
    int cur_size = 0;
    int len = strlen(s);

    (*returnSize) = 0;
	
	int *num_visited = (int *)malloc(sizeof(int)*len);
	
	memset(num_visited,0,sizeof(int)*len);
	
    DFS(s,len,&res,returnSize,cur_str,cur_size,num_visited);
    return res;
}

int main()
{
	
	struct timeval StartTime;
	struct timeval EndTime;
	double TimeUse=0;
	
	gettimeofday(&StartTime, NULL);  //测量开始
	 
	
	
	//要测量的程序代码
	char *s = "dkjphedy";
	int returnSize = 0;
	char** res = permutation(s,&returnSize);
	printf("%d\n",returnSize);
	
	gettimeofday(&EndTime, NULL);   //测量结束

	TimeUse = 1000000*(EndTime.tv_sec-StartTime.tv_sec)+EndTime.tv_usec-StartTime.tv_usec;
	TimeUse/=1000;  //测量结果，毫秒级别


	
	// for (int i = 0; i < returnSize;i++)
	// {
		// printf("%s\n",res[i]);
	// }
	
	
	printf("cost: %f ms\n",TimeUse);
	
	return 0;
}

class Solution {
public:
	void dfs(const string &s,vector<string> &res,string &cur_str,map<int,int> &numvisited)
	{
		if (cur_str.size() == s.size())
		{
			res.push_back(cur_str);
			return0;
		}
		
		bool visited[128] = {0};
		for (size_t i = 0 ; i < s.size();++i)
		{
			if (num_visited[i] == 1)
			{
				continue;
			}
			
			if (visited[(int)str[i]] == 1)
			{
				continue;
			}
			
			visited[(int)str[i]] = 1;
			num_visited[i] = 1;
			
			cur_str.push_back(str[i]);
			
			dfs(s,res,cur_str,numvisited);
			
			cur_str.pop_back();
			num_visited[i] = 0;
		}
	}
	
    vector<string> permutation(string s) {
		vector<string> res;
		string cur_str;
		map<int,int> numvisited;
		dfs(s,res,cur_str,numvisited);
		return res;
    }
};



