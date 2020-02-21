#ifdef __LIST__H__
#define __LIST__H__

#ifdef _cplusplus
extern 'C'{
#endif 

typedef struct ListNode node;

/*************************非循环单向链表************************************/

/*
* function: CreateSingleyLinkList_FromArray
* describe: 通过整型数组,创建单链表
* param[in]:int *pArray 一维整型数组
* param[in]:int size 数组大小
* param[out]:单向链表
*/
node *CreateSingleyLinkList_FromArray(int *pArray,int size);

/*
* function: insertionSortList
* describe: 对链表进行插入排序
* param[in]:struct ListNode *head 要进行排序的链表
* param[out]:排序后的链表
*/
struct ListNode* insertionSortList(struct ListNode* head);

/*
* function: printlist
* describe: 打印单向链表的值
* param[in]:node *head 要进行打印的链表
* param[out]:
*/
void printlist(node *list);

#ifdef _cplusplus	
}
#endif
#endif 