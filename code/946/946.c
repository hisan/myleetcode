//2019-1-2
 //2019-1-4
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    /*
    思路：
        当前push[]元素入B栈，每个元素入栈后再进行判断，假设该元素在push【】中对应位置i，若push[i] != pop[j],则i++,并继续执行上述过程。若push[i] == pop[j]，则将push[i]出栈并插入到输出数组array中，同时i++,j++,并继续执行上述过程.
        当push【】中的所有元素都完成上述过程后，若B不空，将B中的元素逐一出栈并插入array,将array与pop[]数组相比，
        相等则说明栈序列正确。否则返回false.
    */
    typedef struct
    {
        int top;
        int *array;
    }stack;
    int i = 0;
    int cur = 0;
    int *result = (int*)malloc(sizeof(int)*poppedSize);
    stack* s1 = (stack*)malloc(sizeof(stack));
    memset(s1,0,sizeof(stack));
    s1->array = (int*)malloc(sizeof(int)*pushedSize);
    int j =0;
    for(i =0;i < pushedSize;i++)
    {
        s1->array[s1->top++] = pushed[i];
        if(s1->array[s1->top-1] == popped[j])
        {//比较两个栈同一位置的两个元素是否相等
           result[cur++] = s1->array[s1->top-1];//代表当前元素出栈的意思啊
           s1->top--;
           j++;
           while((s1->top>0)&&(s1->array[s1->top-1]==popped[j]))
           {
                result[cur++] = s1->array[s1->top-1];//代表当前元素出栈的意思啊
                s1->top--;
                j++;
           }
        }
    }
    if(s1->top>0)
    {
        while(s1->top>0)
        {//若栈s1中有元素，将其逐一出栈并增加到数组result中
             result[cur++] = s1->array[s1->top-1];
             s1->top--;
        }
    }
    for(i = 0 ;i<pushedSize;i++)
    {
        if(result[i] == popped[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}