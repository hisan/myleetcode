/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){

    typedef struct ListNode Node;
    Node *pre_left = NULL;
    Node *pleft = head;

    Node *pright = head;
    Node *pnext_right = NULL;
    
    if (!head || !head->next || right == left)
    {
        return head;
    }

    int cnt = 1;
    while (cnt < left)//得到要逆转的子链表的头元素指针和其头结点的前驱
    {
        pre_left = pleft;
        pleft = pleft->next;
        cnt++;
    }
    
    cnt = 1;
    pnext_right = pright->next;
    while (cnt < right)//得到要逆转的子链表的尾结点指针和其后继
    {
        pright = pright->next;

        if (pright)
        {
            pnext_right = pright->next;
        }

        cnt++;
    }

    pright->next = NULL;//断开:子链表后尾元素指向NULL

    Node *ptmp = NULL;
    Node *pnewsublist = NULL;
    Node *psubtail = NULL;
    
    while(pleft)//逆转子链表
    {
        if (pnewsublist)
        {
            ptmp = pleft;
            pleft = pleft->next;
            ptmp->next = pnewsublist;
            pnewsublist = ptmp;
        }
        else
        {
            psubtail = pnewsublist = pleft;
            pleft = pleft->next;
        }
    }

    if (pre_left == NULL)//left=1
    {
        psubtail->next = pnext_right;
        return pnewsublist;
    }
  
    pre_left->next = pnewsublist;//子链表左边接入

    if (psubtail)//子链表右边接入
    {
        psubtail->next = pnext_right;
    }

    return head;
}
