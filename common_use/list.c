#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


struct ListNode 
{	
	int val;
	struct ListNode *next;	
};

typedef struct ListNode node;

node *CreateSingleyLinkList_FromArray(int *pArray,int size)
{
	int i = 0;
	if (pArray == NULL || size == 0)
	{
		return NULL;
	}
	
	node *phead = (node *)malloc(sizeof(node));
	memset(phead,0,sizeof(node));
	phead->val = pArray[0];
	
	node *ptail = phead;
	
	for ( i = 1;i < size;i++)
	{
		node *tmpnode = (node *)malloc(sizeof(node));
		memset(tmpnode,0,sizeof(node));
		tmpnode->val = pArray[i];
		tmpnode->next = ptail->next;
		ptail->next = tmpnode;
		ptail = tmpnode;
	}
	
	return phead;
}

void printlist(node *list)
{
	node *p = list;
	while (p)
	{
		printf("%d\n",p->val);
		p = p->next;
	}
}

struct ListNode* insertionSortList(struct ListNode* head){
   
    if (head == NULL || head->next == NULL)
	{
		return head;
	}

	node *tmphead = head;
	node *ptail = head;
	node *pCur = head->next;
	while (pCur != NULL)
	{
		if (pCur->val <= tmphead->val)//将当前要进行排序的节点和有序序列中的头节点比较，若小于头节点，则直接头插
		{
			ptail->next = pCur->next;
			pCur->next = tmphead;
			tmphead = head = pCur;
			pCur = ptail->next;
		}
		else if (pCur->val >= ptail->val)//将当前要进行排序的节点和有序列表中的最后一个元素比较，若大于，则直接尾插
		{
			tmphead = head;
			ptail = pCur;
			pCur = pCur->next;
		}
		else//进入这里，可以确定当前节点在有序序列的插入范围即不在头也不在尾，只能在有序序列中间查找到它的插入位置
		{
			while (tmphead->next != pCur)//确保是在有序序列的范围内查找
			{
				if (pCur->val > tmphead->next->val)
				{
					tmphead = tmphead->next;
				}
				else //得到插入位置，插入
				{
					ptail->next = pCur->next;
					pCur->next = tmphead->next;
					tmphead->next = pCur;
					pCur = ptail->next;
					tmphead = head;
					break;
				}
			}
		}
	}
	return head;
}

void Freelist(struct ListNode *list)
{
	if (list == NULL)
	{
		return;
	}
	struct ListNode *tmp = NULL;
	while (tmp)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
