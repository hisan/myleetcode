//总结：二维数组和二维指针模型我没有搞清楚，没有清晰明了的掌握，所以写代码涉及到相关部分就会纰漏百出，因此，此难点应该进行专项突破
//2018-12-16
#define MAXNUM 3000
struct stack1
{
    int array[MAXNUM];//栈空间大小最大值
    int pos;//栈顶指针
};
int calPoints(char** ops, int opsSize) {
    int num = 0;
    int i =0;
    typedef struct stack1 stack;
    //数组栈初始化
    stack* stack_1 = (stack*)malloc(sizeof(stack));
    memset(stack_1->array,0,MAXNUM);//第三个参数不要想当然写成sizeof(MAXNUM)
    stack_1->pos = 0;
    while(i<opsSize)
    {
        switch(*(*(ops+i)))//ops为数组的地址，*(pos)为数组中第一个元素的地址，*(*(pos))为第一个元素的值
        {
            case '+':
                stack_1->array[stack_1->pos]= stack_1->array[stack_1->pos-1]+stack_1->array[stack_1->pos-2];
                stack_1->pos++;
                i++;
                break;
            case 'D':
                stack_1->array[stack_1->pos] = 2*stack_1->array[stack_1->pos-1];//前一轮得分的两倍
                stack_1->pos++;
                i++;
                break;
            case 'C'://退栈
                stack_1->pos--;
                stack_1->array[stack_1->pos]=0;//当前回合的前一轮得分无效;
                i++;
                break;
            default://数字
                stack_1->array[stack_1->pos] =atoi(*(ops+i));//字符ASCLL值转化为数字，atoi（const char*）的参数为地址
                stack_1->pos++;
                i++;
                break;
        }
    }
    for(i = 1;i<stack_1->pos;i++)
    {
        stack_1->array[0]+=stack_1->array[i];
    }
    return stack_1->array[0];
}