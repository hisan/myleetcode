//双指针移动步长差异即可(其中一者一定为1)，如果有环，最终两者会指向同一个结点，为了在最小时间内得到结果，两者的步长分别为1与2
bool hasCycle(struct ListNode *head) {
    if(head==NULL)
    {
        return false;
    }
    typedef struct ListNode list;
    list *pslow=head;
    list *pFast=head;
    while(pslow)
    {
        pslow = pslow->next;
        if(pFast->next&&pFast->next->next)//一定要注意边界条件
        {
            pFast = pFast->next->next;
        }
        else
        {
            break;
        }
        if(pslow==pFast)
        {
            return true;
        }
    }
    return false;
}