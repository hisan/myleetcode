#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode node;

//�������ѵĽⷨ
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

	/**
	��������ָ��, ��һ������������ĩβ�Ľڵ�ָ����һ�������ͷ��,
	������������Ϊ����(�ڵ�һ���ƶ���ǡ��Ĩ���˳��Ȳ�)
	����ָ������ƶ�����ͬ�ľ���, 
	�н���ͷ���, 
	�޽�����Ǹ���������ָ��ĳ���
	**/
	
	if(headA == NULL || headB == NULL) return NULL;
	struct ListNode *pA = headA, *pB = headB;
	
	/* 
	�������һ��������pA��pB��һ�ε���β����������һ����ı�ͷ, 
	���ڶ������������pA��pB�ཻ�ͷ��ؽ���, 
	���ཻ������null==null 
	*/
	
	while(pA != pB) {
		pA = pA == NULL ? headB : pA->next;
		pB = pB == NULL ? headA : pB->next;
	}
	return pA;
    
}

//�������
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode *ptmp = headB;
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    while (headA != NULL)
    {
        while (headB != NULL)
        {
            if (headA == headB)
            {
                return headA;
            }

            headB = headB->next;
        }
        
        headB = ptmp;
        headA = headA->next;
    }

    return NULL;
    
}

int main()
{
	node n1,n2,n3,n4,n5;
	n3.val = 10010;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;
	
	node n6,n7,n8;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n3;
	
	node *p = NULL;
	p = getIntersectionNode(&n1,&n2);
	
	printf("%d  %d\r\n",p->val,n3.val);
	
}