

//2018-12-30
//原理就是，使用两个栈实现队列，prestack作为第一个栈，afterstack作为第二个栈

//单个元素x入队：
        // 若prestack不空，先将prestack中的元素全部入afterstack栈中，将元素x入prestack栈中，再将afterstack栈中的元素从栈头至栈尾移到prestack中。
        // 若prestack空，则元素x直接入prestack栈中

//出队：prestack中的栈头（队头）元素直接出栈

//判空，若queuea->prestack->top>0;则非空

struct stack
{
    int *array;
    int top;
};
typedef struct stack stack;

struct MyQueue{
    stack* prestack;
    stack* afterstack;
};
typedef struct MyQueue  MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue* queue  = (MyQueue*)malloc(sizeof(MyQueue));
    stack* s1 = (stack*)malloc(sizeof(stack));
    stack* s2 = (stack*)malloc(sizeof(stack));
    s1->array = (int*)malloc(sizeof(int)*maxSize);
    s2->array = (int*)malloc(sizeof(int)*maxSize);
    s1->top = 0;
    s2->top = 0;
    queue->prestack = s1;
    queue->afterstack = s2;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(obj->prestack->top>0)
    {
        while(obj->prestack->top>0)
        {
            obj->afterstack->array[obj->afterstack->top] = obj->prestack->array[obj->prestack->top-1];
            obj->afterstack->top++;
            obj->prestack->top--;
        }
    }
    obj->prestack->array[obj->prestack->top] = x;
    obj->prestack->top++;
    if(obj->afterstack->top>0)
    {
        while(obj->afterstack->top>0)
        {
            obj->prestack->array[obj->prestack->top] = obj->afterstack->array[obj->afterstack->top-1];
            obj->prestack->top++;
            obj->afterstack->top--;
        }
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    obj->prestack->top--;
    return obj->prestack->array[obj->prestack->top];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->prestack->array[obj->prestack->top-1];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->prestack->top>0)
    {
        return false;
    }
    return true;
}

void myQueueFree(MyQueue* obj) {
    free(obj->prestack->array);
    obj->prestack->array = NULL;
    free(obj->afterstack->array);
    obj->afterstack->array = NULL;
    free(obj);
    obj = NULL;
}
