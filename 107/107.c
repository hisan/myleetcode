#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../32_1/make_node.h"

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
	
	for (i = array_size-1; i >=0;i--)
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
		
		for (j = 0;j < colsize[i];j++)
		{
			tmp[j] = g[i][j];
		}
		new_colsize[array_size-1-i] = colsize[i];
		new_array[array_size-1-i] = tmp;
		free(g[i]);
	}
	
	free(g);
	*newcolsize = new_colsize;
	free(colsize);
	return new_array;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **level_array = NULL;
	int *array_size = NULL;
	int *new_array_size = NULL;
	int tree_dep = 0;
	
    if (root == NULL)
    {
		*returnSize = 0;
        return level_array;
    }

	tree_dep = 1000;//gettreedep(root);
	level_array = (int **)malloc(sizeof(int *)*tree_dep);
	memset(level_array,0,sizeof(int *)*tree_dep);
	
	array_size = (int *)malloc(sizeof(int)*tree_dep);
	memset(array_size,0,sizeof(int)*tree_dep);
	getlevelval(root,0,level_array,array_size);

	for (int i = 0;i < tree_dep;i++)
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


void print_arrary(int *g,int size)
{
	int i = 0;
	for ( i = 0;i < size;i++)
	{
		printf("%d\r\n",g[i]);
	}
}

int main()
{
	Node *head = NULL;
	int **ret = NULL;
	int *retcol = NULL; 
	
	int returnsize = 0;//返回树的高度
	
	int a[] = {3,9,20,NULL_NODE,NULL_NODE,15,7,NULL_NODE,NULL_NODE,NULL_NODE,NULL_NODE,123,23,12,212};
	
	int size = sizeof(a)/sizeof(a[0]);
	head = make_bitree_by_arrary(a,size);
	
	ret = levelOrderBottom(head,&returnsize,&retcol);
	
	print_arrary(ret[0],retcol[0]);
	printf("\n");
	print_arrary(ret[1],retcol[1]);
	printf("\n");
	print_arrary(ret[2],retcol[2]);
	printf("\n");
	
	free(ret);
	free(retcol);
	
	return 0;
}

