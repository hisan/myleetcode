#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>

//#define INT_MIN pow(-2,31)

typedef struct st_node
{
	int key;
	int value;
	struct st_node *next;
}Node;

typedef struct st_hashmap
{
	int size;
	Node *data;
}HashMap;

HashMap *hashCreate(int capability)
{
	HashMap *Hash_Manage = (HashMap *)malloc(sizeof(HashMap));
    Hash_Manage->size = capability;
    Hash_Manage->data = (Node *)malloc(sizeof(Node)*capability);
	
	for (int i = 0 ; i < Hash_Manage->size;i++)
	{
		Hash_Manage->data[i].key = INT_MIN;
		Hash_Manage->data[i].value = 0;
		Hash_Manage->data[i].next = NULL;
	}
	
	return Hash_Manage;
}

void put(int key,HashMap *hashMapInfo)
{
	int pos  = abs(key) % hashMapInfo->size;
	Node *pNewNode = NULL;
	
	Node *ptmpNode = &hashMapInfo->data[pos];
	
	if (ptmpNode->key == INT_MIN)
	{
		ptmpNode->key = key;
		ptmpNode->value = 1;
		return;
	}
	
	while (ptmpNode)
	{
		if (ptmpNode->key == key)
		{
			ptmpNode->value++;
			return;
		}
		
		if (ptmpNode->next == NULL)
		{
			break;
		}
		
		ptmpNode = ptmpNode->next;	
	}
	
	pNewNode = (Node *)malloc(sizeof(Node));
	pNewNode->key = key;
	pNewNode->value = 1;
	pNewNode->next = NULL;
	
	ptmpNode->next = pNewNode;
	
	return;
}

int get(int key,HashMap *hashMapInfo)
{
	int count = 0;
	int pos = abs(key) % hashMapInfo->size;
	Node *pnode = &hashMapInfo->data[pos];
	
	while (pnode)
	{
		if (pnode->key == key)
		{
			count = pnode->value;
			break;
		}
		
		pnode = pnode->next;
	}
	
	return count;
}

int subarraySum(int* nums, int numsSize, int k)
{
	int sum = 0;
	int size = 0;
	HashMap *pHashMap = NULL;
	
	pHashMap = hashCreate(numsSize);
	put(0,pHashMap);
	
	for (int i = 0 ; i < numsSize;i++)
	{
		sum += nums[i];
		size += get(sum - k,pHashMap);
		put(sum,pHashMap);
	}
	
	return size;
}

int main()
{
	int nums[] = {-1,-1,1};
	int k = 0;
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	
	printf("1.start %d\n",(int)time(NULL));
	int ret = subarraySum(nums,numsSize,k);
	printf("1.end %d\n\n",(int)time(NULL));
	printf("%d\n",ret);

	return 0;
}


