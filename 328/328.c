
//2018-12-15   time 14：21
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head||!head->next||!head->next->next)
    {//至少保证有三个结点
        return head;
    }
    typedef struct ListNode list;
    list* p1 = head;
    list* odd_head = p1;
    list* p2 = head->next;
    list* even_list = malloc(sizeof(list));
    even_list->next = NULL;
    p1->next = p2->next;
    
    p2->next = even_list->next;
    even_list->next = p2;
    
    p1 = p1->next;
    if(p1->next)
    {
        p2->next = p1->next;
        p2 = p2->next;
    }
    else
    {
        p1->next = even_list->next;
        return odd_head;
    }
    while(p1->next&&p2->next)
    {
        p1->next = p2->next;
        p1 = p1->next;
        p2->next = p1->next;
        p2 = p2->next;
    }
    p1->next = even_list->next;
    return odd_head;
}