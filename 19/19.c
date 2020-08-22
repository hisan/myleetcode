/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode list;
    list *p1 = head;
    int size = 0;
    while(p1!=NULL)
    {
        size++;
        p1 = p1->next;
    }
    if( size == 1)//只有一个结点的情况直接返回null
    {   
        return NULL;
    }
    
    size = size - n;//倒变正,也即是所要删除的节点前面有几个节点
    
    if(size == 0)//链表节点数>1,且为删除链表的第一个节点的情况下
    {
        return head->next;
    }
    
    p1 = head;
    for(int i = 0;i<size-1;i++)//注意i是从0到size-2的，因为从0到size-1为size个位移量，但是我们是从第一个开始偏移，只需要偏移size-1个位移量，所以边界值为size -1
    {
        p1 = p1->next;
    }
    p1->next = p1->next->next;
    return head;
}