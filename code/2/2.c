//2018-11-8未解决，明日继续


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp;
  
    int i=0,j=0;
    int ay1[100]={0};
    int ay2[100]={0};
    
    //第一步，求单链表长度
    temp = l1;
    while(temp->next!=NULL)
    {
        i++;
        temp = temp->next;
    }
    
    temp = l2;
    while(temp->next!=NULL)
    {
        j++;
        temp = temp->next;
    }
    
    //第二步：遍历链表得到其每个节点的数值域的值
    temp = l1;
    while(temp->next!=NULL)
    {
        int k = 0;
        ay1[k++] = temp->val;
        temp = temp->next;
    }
    
    temp = l2;
    while(temp->next!=NULL)
    {
        int l = 0;
        ay2[l++] = temp->val;
        temp = temp->next;
    }
    
    //第三步：根据两个链表的长短，决定谁加谁
    if(i>=j)
    {
        temp=l1;
        for(int k = 0 ; k < i ;k++)//边界条件非常重要，因为若某一方的个数小于另一方，则只能执行最少的次数
        {
            ay1[k] += ay2[k];
            if(ay1[k] > 9)//进位判断
            {
                ay1[k+1]+=1;
                ay1[k]%=10;
            }
            temp->val = ay1[k];
            temp = temp->next;
        }
        return l1;
    }
    else
    {
        temp=l2;
        for(int k = 0 ; k < j ;k++)
        {
            ay2[k] += ay1[k];
             if(ay2[k] > 9)
            {
                ay2[k+1]+=1;
                ay2[k]%=10;
            }
            temp->val = ay2[k];
            temp = temp->next;
        }           
        return l2;
    }
    return NULL;
    
}







// 问题一：如果是相加后超出链表最长的长度怎么处理？


/*******************************************************************************************************************************************************************

//2018-11-12 终于解决了这题，但是用的是边加边生成结点的方式，而不是我一开始的使用辅助数组的方式
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    
    struct ListNode *l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p3 = l3;
    
    int carry = 0;
    int sum = 0;
    
    while( p1 != NULL&&p2 != NULL)
    {//之前的问题是，我将sum赋值在了l3链的第一个结点之处，导致我最终返回的链表多出一个空结点，现在我将创建头节点为空的链表，但是我返回的开始结点是头结点的下一个结点
        sum = p1->val + p2->val + carry;
        if(sum>9)//第一个条件
        {
           sum%=10;//啊啊啊啊！！！
           carry = 1;
        }
        else
        {
            carry = 0;
        }
        struct ListNode *p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
        p4->val = sum;
        p4->next = NULL;
        p3->next = p4;
        p3 = p4;
        p1 = p1->next;
        p2 = p2->next;
    }
    while(p1!=NULL)//p1较长
    {
        sum = p1->val + carry;
        if(sum>9)//第一个条件
        {
           sum%=10;//啊啊啊啊！！！
           carry = 1;
        }
        else
        {
            carry = 0;
        }
        struct ListNode *p5 = (struct ListNode*)malloc(sizeof(struct ListNode));
        p5->val = sum;
        p5->next = NULL;
        p3->next = p5;
        p3 = p5;
        p1 = p1->next;
    }
    while(p2!=NULL)//p2较长
    {
        sum = p2->val + carry;
        if(sum>9)//第一个条件
        {
           sum%=10;//啊啊啊啊！！！
           carry = 1;
        }
        else
        {
            carry = 0;
        }
        struct ListNode *p6 = (struct ListNode*)malloc(sizeof(struct ListNode));
        p6->val = sum;
        p6->next = NULL;
        p3->next = p6;
        p3 = p6;
        p2 = p2->next;
    }
    if(carry == 1)//完成两条链表的值合并，但是最大值位发生进位的处理
    {//我之前出错，将if写成while，造成时间超时
        sum = carry;
        struct ListNode *p7 = (struct ListNode*)malloc(sizeof(struct ListNode));
        p7->val = sum;
        p7->next = NULL;
        p3->next = p7;
    }
    
    return l3->next;//舍弃了l3的头节点（因为它为空，我们生成它只是为了索引作用
}
//关键点：我们一开始就生成了L3链表（长度为1),和辅助索引p3,在真正的边计算边生成结点的过程中，最重要的是我们将值赋值在了循环中生成的结点中，而不是从l3的头节点开始赋值，因为，我们的链表是单向链表，如果我们从l3的头部开始赋值，最终我们要在循环中经历一次malloc生成结点但是却没有值可以赋给它，这就造成我们最终生成的链表尾部多出了一个空结点，而我们的单向链表只能向'后'不能向前，我们并不能找到很好的方法处理这个最后的结点，因此，我们选择将值从while循环中生成的结点开始赋值，这样我们返回链表时，只需从l3->next开始返回就可以了。















