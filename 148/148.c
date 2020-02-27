
typedef struct ListNode node;
struct ListNode* sortList(struct ListNode* head){
    if (head == NULL || head->next == NULL) 
	{
		return head;
	}
	node *tmphead = head;
	node *ptail = head;
	node *pCur = head->next;
	while (pCur != NULL)
	{
		if (pCur->val <= tmphead->val)//将当前要进行排序的节点和有序序列中的头节点比较，若小于头节点，则直接头插
		{
			ptail->next = pCur->next;
			pCur->next = tmphead;
			tmphead = head = pCur;
			pCur = ptail->next;
		}
		else
		{
			if (pCur->val >= ptail->val)//将当前要进行排序的节点和有序列表中的最后一个元素比较，若大于，则直接尾插
			{
				tmphead = head;
				ptail = pCur;
				pCur = pCur->next;
			}
			else//进入这里，可以确定当前节点在有序序列的插入范围即不在头也不在尾，只能在有序序列中间查找到它的插入位置
			{
				while (tmphead->next != pCur)//确保是在有序序列的范围内查找
				{
					if (pCur->val > tmphead->next->val)
					{
						tmphead = tmphead->next;
					}
					else //得到插入位置，插入
					{
						ptail->next = pCur->next;
						pCur->next = tmphead->next;
						tmphead->next = pCur;
						pCur = ptail->next;
						tmphead = head;
						break;
					}
				}
			}
		}
	}
	return head;
}



