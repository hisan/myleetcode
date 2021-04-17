
//2019/03/31  分治法
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode node;
    
node *mergeTwoLists(node *list1,node* list2)
{
    
    node *list3 = (node*)malloc(sizeof(node));
    memset(list3,0,sizeof(node));
    node *temp = list3;
    
    while(list1!=NULL&&list2!=NULL)
    {
        if(list1->val < list2->val)
        {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        else  
        {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }
    
    if(list1!=NULL)
    {
        temp->next = list1;
    }
    
    if(list2!=NULL)
    {
        temp->next = list2;
    }
    
    return list3->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0)
    {
        return NULL;
    }
    
    while (listsSize > 1)
    {
        int k = (listsSize + 1) / 2;
        // k = (listsSize + 1)/2，能保证在一轮合并结束之后能够得到正确的合并后的链表个数。
        for (int i = 0; i < listsSize / 2; ++i)
        {
            lists[i] = mergeTwoLists(lists[i], lists[i + k]);
        }
        listsSize = k;
    }
    return lists[0];
}
