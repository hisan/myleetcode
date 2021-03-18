/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

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

int **rever_2arr(int **g,int *colsize,int **newcolsize,int array_size)
{
	int i = 0,j = 0;
	int *tmp = NULL;
	int *new_colsize = NULL;
	int **new_array = NULL;
	new_array = (int **)malloc(sizeof(int *)*array_size);
	memset(new_array,0,sizeof(int *)*array_size);
	
	new_colsize = (int *)malloc(sizeof(int)*array_size);
	memset(new_colsize,0,sizeof(int)*array_size);
	
	for (i = 0; i < array_size;i++)
	{
		tmp = NULL;		
		if (colsize[i]!=0)
		{
			tmp = (int *)malloc(sizeof(int)*colsize[i]);
			memset(tmp,0,sizeof(int)*colsize[i]);
		}
		else 
		{
			break;
		}
		
		if (i%2 == 0)
		{
			for (j = 0;j < colsize[i];j++)
			{
				tmp[j] = g[i][j];
			}
		}
		else 
		{
			for (j = colsize[i]-1;j >=0 ;j--)
			{
				tmp[colsize[i]-1-j] = g[i][j];
			}
		}
		
		new_colsize[i] = colsize[i];
		new_array[i] = tmp;
		free(g[i]);
	}
	
	free(g);
	*newcolsize = new_colsize;
	free(colsize);
	return new_array;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **level_array = NULL;
	int *array_size = NULL;
	int *new_array_size = NULL;
	int tree_dep = 0;
	int i = 0;

    if (root == NULL)
    {
		*returnSize = 0;
        return level_array;
    }

	tree_dep = 1000;
	level_array = (int **)malloc(sizeof(int *)*tree_dep);
	memset(level_array,0,sizeof(int *)*tree_dep);
	
	array_size = (int *)malloc(sizeof(int)*tree_dep);
	memset(array_size,0,sizeof(int)*tree_dep);
	getlevelval(root,0,level_array,array_size);

	for (i = 0;i < tree_dep;i++)
	{
		if (array_size[i] == 0)
		{
			break;
		}
	}
	
	tree_dep = i;
	
	//做一个逆序
	level_array = rever_2arr(level_array,array_size,&new_array_size,tree_dep);
	
    *returnSize = tree_dep;
    *returnColumnSizes = new_array_size;
	return level_array;
}

