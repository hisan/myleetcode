#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_hashnode
{
    char str[11];
    int cnt;
    struct st_hashnode *next;
}Node;

Node *g_HashList = NULL;

Node* findnode_bykey(char* str)
{
    Node *p = NULL;
    p = g_HashList;
	
    while (p)
    {
        if (!strncmp(p->str,str,10))
        {
            return p;
        }
		
        p = p->next;
    }

    return p;
}

void insert_node(char *str)
{
    Node *pNode = NULL;
    pNode = findnode_bykey(str);
    if (pNode != NULL)
    {
        pNode->cnt++;
        return;
    }

    pNode = (Node *)malloc(sizeof(Node));
    memset(pNode,0,sizeof(Node));
    strncpy(pNode->str,str,strlen(str));
    pNode->cnt++;

    if (g_HashList == NULL)
    {
        pNode->next = NULL;
        g_HashList = pNode;
    }
    else 
    {
        pNode->next = g_HashList->next;
        g_HashList->next = pNode;
    }

    return;
}

void delete_list()
{
    Node *p = g_HashList;
    Node *tmp = NULL;
    while (p)
    {
		//printf("cnt:%d\n",p->cnt);
        if (p->next)
        {
            tmp = p->next;
        }
        
        if (p != NULL)
        {
            free(p);
            p = tmp;
		    tmp = NULL;
        }
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
char ** findRepeatedDnaSequences(char *s, int* returnSize){
	char **res = NULL;
	int mask = 0x7ffffff;
	int cur = 0;
	int i = 0;
    Node *tmp = NULL;
    int len = strlen(s);
    char buffer[11] = {0};

     (*returnSize) = 0;

	if (len <=10)
	{  
		return res;
	}

	for (i = 9; i < len; i++) 
	{
		memset(buffer,0,11);
        strncpy(buffer,&s[i-9],10);
        tmp = findnode_bykey(buffer);
        
        if (tmp != NULL)
        {
            if (tmp->cnt == 1)//如果是第二次发现
            {
                res = realloc(res,sizeof(char *)*(*returnSize+1));
                res[*returnSize] = (char *)malloc(11);
                memset(res[*returnSize],0,11);
                strncpy(res[*returnSize],buffer,10);
                (*returnSize) += 1;
            }

            tmp->cnt++;
        }
        else
        {
            //拷贝字符串
            insert_node(buffer);
        }
	}
    
    delete_list();
	return res;
}

int main()
{
	char *s = "AAAAAAAAAAAAA";
	int returnSize = 0;
	char **res = findRepeatedDnaSequences(s,&returnSize);
	int i = 0;
	
	for (i = 0; i < returnSize;i++)
	{
		printf("%s\n",res[i]);
	}
	
	return 0;
}





