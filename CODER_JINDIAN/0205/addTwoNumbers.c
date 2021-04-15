#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    Node *p1 = l1;
    Node *p2 = l2;
    Node *ptail = NULL;

    int step = 0;
    int tmp = 0;
    while (p1 && p2)
    {
        tmp = p1->val+p2->val+step;
        step = tmp/10;
        tmp %=10;

        p1->val = tmp;
        if (!p1->next)
        {
            ptail = p1;
        }
        else if (!p2->next)
        {
            ptail = p2;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    if (!p1 && !p2)//俩链表长度相等
    {
        if (step ==1)
        {
            ptail->next = (Node *)malloc(sizeof(Node));
			memset(ptail->next,0,sizeof(Node));
			ptail->next->val = step;
        }

        return l1;
    }

    if (p2)
    {
        if(ptail)
        {
            ptail->next = p2;
        }
        else 
        {
            return l2;
        }
    }

    while (p2)
    {
        int tmp = p2->val + step;
        step = tmp/10;
        tmp %=10;
        p2->val = tmp;
        
		if (step == 1 && !p2->next)
		{
			p2->next = (Node *)malloc(sizeof(Node));
			memset(p2->next,0,sizeof(Node));
			p2->next->val = step;
			break;
		}
		
		p2 = p2->next;
    }

    while (p1)
    {
        int tmp = p1->val + step;
        step = tmp/10;
        tmp %=10;
		
		p1->val = tmp;
		
		if (step == 1 && !p1->next)
		{
			p1->next = (Node *)malloc(sizeof(Node));
			memset(p1->next,0,sizeof(Node));
			p1->next->val = step;
			break;
		}
		
        p1 = p1->next;
    }

    return l1;
}

int main()
{
	Node *array1 = (Node *)malloc(sizeof(Node)*3);
	memset(array1,0,sizeof(Node)*3);
	
	array1[0].val=2;
	array1[1].val=4;
	array1[2].val=3;
	array1[0].next = &array1[1];
	array1[1].next = &array1[2];
	
	
	Node *array2 = (Node *)malloc(sizeof(Node)*6);
	memset(array2,0,sizeof(Node)*6);
	
	array2[0].val=5;
	array2[1].val=6;
	array2[2].val=6;
	array2[3].val=9;
	array2[4].val=9;
	array2[5].val=9;
	
	array2[0].next = &array2[1];
	array2[1].next = &array2[2];
	array2[2].next = &array2[3];
	array2[3].next = &array2[4];
	array2[4].next = &array2[5];
	
	Node *list1 = &array1[0];
	Node *list2 = &array2[0];
	
	Node *res = addTwoNumbers(list1,list2);
	return 0;
}
