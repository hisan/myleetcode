
bool isValid(char* s) {
    //元素入栈，首先判断栈是否为空，若为空，则直接入栈，若不为空，则与栈顶元素比较，比较结果：若匹配，则栈顶元素退栈，若不匹配，则入栈
   
    struct stack1
    {
        char *array;
        int pos;
    };
    typedef struct stack1 stack;
    stack* s1 = malloc(sizeof(stack));
    int size = strlen(s)/sizeof(char);
    s1->array = (char*)malloc(size);
    s1->pos = 0;
    for(int i =0;i < size;i++)
    {
        
        switch(*(s+i))
        {
            case '('://左括号直接入栈
            case '[':
            case '{':
                 s1->array[s1->pos] = *(s+i);
                 s1->pos ++;
                break;
            case ')':
                if(s1->array[s1->pos-1]=='(')
                {
                    s1->pos--;
                }
                else
                {
                     return false;
                }
                break;
            case ']':
                 if(s1->array[s1->pos-1]=='[')
                {
                    s1->pos--;
                }
                else
                {
                     return false;
                }
                break;
            case '}':
                 if(s1->array[s1->pos-1]=='{')
                 {
                    s1->pos--;
                 }
                 else
                 {
                     return false;
                 }
                break;
            default:
                return false;
        }
        
    }
    if(s1->pos == 0)
    {
        return true;
    }
    return false;
}