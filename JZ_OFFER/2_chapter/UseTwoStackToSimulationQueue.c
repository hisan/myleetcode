typedef struct st_stack{
    int arrary[10000];
    int top;
    int tail;
    int size;
}stack;

stack *create_stack()
{
    stack *pstack = (stack *)malloc(sizeof(stack));
    memset(pstack,0,sizeof(stack));
    return pstack;
}

bool empty_stack(stack *pstack)
{
    if (pstack->size > 0)
    {
        return false;
    }

    return true;
}

bool full_stack(stack *pstack)
{
    if (pstack->size < 10000)
    {
        return false;
    }

    return true;
}

void push_stack(stack *pstack,int val)
{
    if (full_stack(pstack) == true)
    {
        return;
    }

    pstack->arrary[pstack->top] = val;
    pstack->top++;
    pstack->size++;
}

int pop_stack(stack *pstack)
{
    if (true == empty_stack(pstack))
    {
        return -1;
    }

    int tmp = pstack->arrary[pstack->top-1];
    pstack->top--;
    pstack->size--;
    return tmp;
}

typedef struct {
    stack *dataA;
    stack *dataB;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *pQueue = (CQueue *)malloc(sizeof(CQueue));
    memset(pQueue,0,sizeof(CQueue));
    pQueue->dataA = create_stack();
    pQueue->dataB = create_stack();

    return pQueue;
}

//元素入队
void cQueueAppendTail(CQueue* obj, int value) 
{    
    if (full_stack(obj->dataA) == false)
    {
        push_stack(obj->dataA,value);
    }
}

int cQueueDeleteHead(CQueue* obj) {
    while (false == empty_stack(obj->dataA))
    {
        int tmp1 = pop_stack(obj->dataA);
        if (false == full_stack(obj->dataB))
        {
            push_stack(obj->dataB,tmp1);
        }
    }

    int tmp = pop_stack(obj->dataB);

    while (false == empty_stack(obj->dataB))
    {
        int tmp2 = pop_stack(obj->dataB);
        if (false == full_stack(obj->dataA))
        {
            push_stack(obj->dataA,tmp2);
        }
    }

    return tmp;
}

void cQueueFree(CQueue* obj) {
    if (obj)
    {
        if (obj->dataA)
        {
            free(obj->dataA);
        }

        if (obj->dataB)
        {
            free(obj->dataB);
        }

        free(obj);
    }
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
