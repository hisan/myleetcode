//2019-1-4
int minAddToMakeValid(char* S)
{
    typedef struct st_stack
    {
        char array[1000];
        int top;
    }stack;
    stack* s1 = (stack*)malloc(sizeof(stack));
    int curleftnum = 0;
    int hasleft = 0;
    char *p = S;
    int i =0;
    int len = strlen(p);
    memset(s1,0,sizeof(stack));
    while(len--)
    {
        switch(*(p+i))
        {
            case '(':
                if(hasleft==0)
                {
                    hasleft = 1;
                }
                curleftnum++;
                s1->array[s1->top++] = *(p+i);
                break;
            case ')':
                if(hasleft==0)
                {
                    s1->array[s1->top++] = *(p+i);
                }
                else
                {//退栈到最近的一个'('
                    while((s1->top>0)&&(s1->array[s1->top-1] !='('))
                    {//靠近最后一个'('
                        s1->top--;
                    }
                    s1->top--;//s杀掉最近一个'('
                    curleftnum--;
                    if(curleftnum == 0)
                    {
                        hasleft = 0;
                    }
                }
                break;
            default:
                break;
        }
        i++;
    }
    if(s1->top>0)
    {    
        return  s1->top;
    }
    return 0;
}