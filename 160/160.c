#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode node;

//力扣网友的解法
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

	/**
	定义两个指针, 第一轮让两个到达末尾的节点指向另一个链表的头部,
	最后如果相遇则为交点(在第一轮移动中恰好抹除了长度差)
	两个指针等于移动了相同的距离, 
	有交点就返回, 
	无交点就是各走了两条指针的长度
	**/
	
	if(headA == NULL || headB == NULL) return NULL;
	struct ListNode *pA = headA, *pB = headB;
	
	/* 
	在这里第一轮体现在pA和pB第一次到达尾部会移向另一链表的表头, 
	而第二轮体现在如果pA或pB相交就返回交点, 
	不相交最后就是null==null 
	*/
	
	while(pA != pB) {
		pA = pA == NULL ? headB : pA->next;
		pB = pB == NULL ? headA : pB->next;
	}
	return pA;
    
}

//暴力解决
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