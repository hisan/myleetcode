/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define max(a,b) ((a)>(b)?(a):(b))
 
int gettreedep(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + max(gettreedep(root->left),gettreedep(root->right));
}

int getlevelval(struct TreeNode* root,int cur_level,int **level_array,int *array_size)
{
	if (root)
	{
		level_array[cur_level] = realloc(level_array[cur_level],sizeof(int)*(array_size[cur_level]+1));
		level_array[cur_level][array_size[cur_level]] = root->val;
		array_size[cur_level] += 1;
		
		if (root->left)
		{
			getlevelval(root->left,cur_level+1,level_array,array_size);
		}
		
		if (root->right)
		{
			getlevelval(root->right,cur_level+1,level_array,array_size);
		}
	}
	
	return 0;
}
 
int* levelOrder(struct TreeNode* root, int* returnSize){
    int **level_array = NULL;
	int *array_size = NULL;
	int *ret_array = NULL;
	int node_cnt = 0;
	int tree_dep = 0;
	int i = 0,j = 0;
	int tmp = 0;
	
    if (root == NULL)
    {
		*returnSize = 0;
        return ret_array;
    }
	
	tree_dep = 1000;//gettreedep(root);题目已告知节点数最大为1000，则假设最大深度为1000,避免获取树深度而消耗时间
	level_array = (int **)malloc(sizeof(int *)*tree_dep);
	memset(level_array,0,sizeof(int *)*tree_dep);

	array_size = (int *)malloc(sizeof(int)*tree_dep);
	memset(array_size,0,sizeof(int)*tree_dep);
	
	getlevelval(root,0,level_array,array_size);
	
	for (i = 0;i < tree_dep;i++)
	{
		node_cnt += array_size[i];
	}

	ret_array = (int *)malloc(sizeof(int)*node_cnt);
	memset(ret_array,0,sizeof(int)*node_cnt);

	for (i=0;i < tree_dep;i++)
	{
		for (j = 0;j < array_size[i];j++)
		{
			ret_array[tmp++] = level_array[i][j];
		}
	}
	
	for (i=0;i < tree_dep;i++)
	{
		free(level_array[i]);
	}

    free(level_array);    
    free(array_size);

    *returnSize = node_cnt;
	return ret_array;
}


