//2018-11-17-20:22
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//方法一：直接将两个链表连接起来，再用冒泡排序就可以了
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
   typedef struct ListNode list;
    list *p1 = l1;
    list *p2 = l2;
    int size = 0;
    if(p1==NULL)//要考虑到p1、p2为null的情况
    {
        return p2;
    }
    if(p2==NULL)
    {
        return p1;
    }
    
    while(p1->next!=NULL)
    {
        p1 = p1->next;
    }//现在p1处于l1的最后一个结点上
    
    p1->next = p2;//顺利将两个链表串联在一块
    p1 = l1;//p1回到起始之处
    while(p1!=NULL)
    {
        size++;
        p1 = p1->next;
    }
    
    p1 = l1;
    int *arrary = malloc(sizeof(int)*size);
    memset(arrary,0,sizeof(int)*size);
    for(int i = 0;i<size;i++)
    {
        arrary[i] = p1->val;
        p1 = p1->next;
    }//得到包含这条链表的所有数的数组
    
    //开始冒泡排序
    for(int i = 0;i<size;i++)
    {
        for(int j = i +1;j<size;j++)
        {
            if(arrary[i]>arrary[j])
            {
                int temp = arrary[i];
                arrary[i] = arrary[j];
                arrary[j] = temp;
                
            }
        }
    }
    
    p1 = l1;
    int i = 0;
    while(p1!=NULL&&i<size)
    {
        p1->val = arrary[i++];
        p1 = p1->next;
    }
    return l1;
    
}