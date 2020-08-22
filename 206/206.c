//2018-12-10
struct ListNode* reverseList(struct ListNode* head) {
    if(!head||!head->next)
    {
        return head;
    }
    typedef struct ListNode list;
    list* new_head = malloc(sizeof(list));
    new_head->next=NULL;
    list* p = head;
    list* pnext = p->next;
    while(p&&pnext)
    {
        p->next = new_head->next;
        new_head->next = p;
        p = pnext;
        pnext = pnext->next;
    }
    p->next = new_head->next;
    return  p;
}

//一个刷题以来一直碰到的问题：
// 就是很容易complier就会报错：“member access within null pointer of type 'struct list'”
// 说白了就是，我们知道这个结点为null,我们的目的是故意将这个结点置为null，
// 然后以此判断跳出循环条件为真，但是这是我们的思维方式，
