typedef struct {
    int arrary[10000];
    int top;
    int tail;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *pMinStack = (MinStack *)malloc(sizeof(MinStack));
    memset(pMinStack,0,sizeof(MinStack));
    return pMinStack;
}

void minStackPush(MinStack* obj, int x) {
obj->arrary[obj->top] = x;
obj->top++;
obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->top--;
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->arrary[obj->top-1];
}

int minStackGetMin(MinStack* obj) {
    int tmp = obj->arrary[0];
    int i = 1;
    while (i < obj->size)
    {
        if (tmp > obj->arrary[i])
        {
            tmp = obj->arrary[i];
        }
        i++;
    }

    return tmp;
}

void minStackFree(MinStack* obj) {
    if (obj)
    {
        free(obj);
        obj = NULL;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
