给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
说明:
    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


//2018-11-19-18：12
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* swapPairs(struct ListNode* head) {
    typedef struct ListNode list;
    list *p1;
    list *p2;
    list *l1;
    int size = 0;
    int temp = 0;
    int num = 0;
    p1 = head;
    if(head==NULL)//链表为空直接返回
    {
        return NULL;
    }
    while(p1!=NULL)//求得非空链表的大小
    {
        size++;
        p1 = p1->next;
    }
    if(size==1)//若链表长度为1,直接返回当前链表
    {
        return head;
    }
    temp = size%2;
   
    if(temp>0)//为奇数,则最后一个结点不用操作
    {
        size-=1;
    }
    p1 = head;
    p2 = head->next;
    l1 = p2;//l1唯一的做用就是只想未进行变换之前的第二个接电脑，依题意，ta一定是我们返回的链表的头节点
    num = size/2;//注意顺序，这里的size一定为偶数
    list *p4 = p1;//每一行代码都具有重大的意义，是我在每一次试错中不断理解而不断修正后得到的最好结果，所以，绝大部分行代码，它们出现在程序中的位置并不具有随机性
    int i;
    for(i=0;i<num;i++)//每次操作2个结点，故，只需要操作size/2次
    {
        p1->next = p2->next;//交换
        p2->next = p1;
        if(i>0)//第一次交换，由于第一个结点为首结点，所以它的交换是最简单的，而从第二对结点开始，每一次交换除了考虑指向后面的元素，还得考虑它前面的元素的指向的变化，这非常重要
        {
           p4->next = p2;//p4每一次都指向一对未交换元素的第一个元素，当发生交换后，它就指向了交换后的元素的第二个元素，用于我们在改变第三对元素的后指向后，来改变第一队元素的后指向，依次类推
           p4 = p1;
        }
        if(p1->next!=NULL&&p1->next->next!=NULL)//两者不为空时才能后移
        {//移动，后移很简单
           p1 = p1->next;
           p2 = p1->next;
        }
        else
        {
            return l1;
        }
    }
    return l1;
}
    return head;
}