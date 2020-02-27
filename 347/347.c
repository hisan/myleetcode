
（1）//2019/04/20 使?1用??链???表???建??立???hash链???表???
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//使?1用??链???表???动??态??实???现?hash表???
typedef struct hashnode2
{
    int value;//出?现?的??值??
    int count;//出?现?的??次??数?y
    struct hashnode2 *pnext;
}node;
node *findhashnode(node* listhead,int value)
{
    node *ptemp = listhead;
   
    while(ptemp != NULL)
    {
        if(ptemp->value == value)
        {
            return ptemp;
        }
       
        ptemp = ptemp->pnext;
    }
   
    return NULL;
}
void CreatehashList(node **pplisthead,int value)
{
     node *listhead = *pplisthead;
    node *temp = NULL;
    if(listhead != NULL)
    {
        temp = findhashnode(*pplisthead,value);
        if(temp!=NULL)
        {
            temp->count++;
        }
        else 
        {
            temp = (node*)malloc(sizeof(node));
                memset(temp,0,sizeof(node));
            temp->value = value;
            temp->count++;
            temp->pnext = listhead;
            listhead = temp;
                *pplisthead = listhead;
        }
    }
    else 
    {
        listhead = (node*)malloc(sizeof(node));
           memset(listhead,0,sizeof(node));
        listhead->value = value;
        listhead->count++;
        listhead->pnext = NULL;
           *pplisthead = listhead;
    }
}
//对?链???表???进?行D冒??泡Y排?序??
node *bubblesortlist(node* listhead)
{
     node *pNode1 = listhead;
     node *pNode2 = listhead;
     if(listhead == NULL)
     {
           return listhead;     
     }
     for(;pNode1->pnext!=NULL;pNode1=pNode1->pnext)
    {//外?a层?循-环??只?是??起e到??计?数?y作???用??,对?于???冒??泡Y排?序??，??每?次??得??到??一??个?确???定??的??位?序??，??进?行Dn次??排?序??得??到??完???整?序??列?D
        for(pNode2=listhead;pNode2->pnext!=NULL;pNode2=pNode2->pnext)
        {
            if(pNode2->count < pNode2->pnext->count)
            {
                int tempvalue = pNode2->value;
                     int tempcount = pNode2->count;
                pNode2->value = pNode2->pnext->value;
                     pNode2->count = pNode2->pnext->count;
                pNode2->pnext->value = tempvalue;
                     pNode2->pnext->count = tempcount;
            }
        }
    }
    return listhead;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    node *hashhead = NULL;
    for(int i =0 ;i < numsSize;i++)
    {
        CreatehashList(&hashhead,nums[i]);//建??立???hash链???
    }
    //对?链???表???排?序??
    hashhead = bubblesortlist(hashhead);
    int *retarray = (int*)malloc(sizeof(int)*k);
    *returnSize = 0;
    int j = 0;
    while((hashhead!=NULL)&&(j < k))
    {
        retarray[(*returnSize)++] = hashhead->value;
        hashhead = hashhead->pnext;
        j++;
    }
   
    return retarray;
}



//其实我使用冒泡排序，时间复杂度已经是O(n^2)了，不符合题目的O(nlogn)，我可以使用堆排序来进行排序

