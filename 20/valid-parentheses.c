#include <stdio.h>
#include <string.h>

#define bool int
#define false 0
#define true  1

typedef struct st_stack
{
	char array[10000];
	int top;	
	int tail;
	int size;
}stack;

void init_stack(stack *pstack)
{
	memset(pstack,0,sizeof(stack));
}

void en_stack(stack *pstack,char c)
{
	pstack->array[pstack->top] = c;
	pstack->top++;
	pstack->size++;
}

void pop_stack(stack *pstack)
{
	pstack->top--;
	pstack->size--;
}

char top_stack(stack *pstack)
{
	return pstack->array[pstack->top-1];
}

int size_stack(stack *pstack)
{
	return pstack->size;
}

stack g_stack;

bool isValid(char* s) 
{
	int i = 0;     
	//元素入栈，首先判断栈是否为空，若为空，则直接入栈，若不为空，则与栈顶元素比较，比较结果：若匹配，则栈顶元素退栈，若不匹配，则入栈
	init_stack(&g_stack);
	
    for(i =0;i < strlen(s);i++)
    { 
        switch (s[i])
        {
            case '('://左括号直接入栈
            case '[':
            case '{':
                 en_stack(&g_stack,s[i]);
                break;
				
            case ')':
                if (size_stack(&g_stack) == 0)
                {
                    return false;
                }
				
                if(top_stack(&g_stack) =='(')
                {
                   pop_stack(&g_stack);
                }
                else
                {
                    return false;
                }
                break;
				
            case ']':
                if (size_stack(&g_stack) == 0)
                {
                   return false;
                }
                
				if(top_stack(&g_stack) =='[')
                {
                   pop_stack(&g_stack);
                }
                else
                {
                    return false;
                }
                break;
				
            case '}':
                if (size_stack(&g_stack) == 0)
                {
                   return false;
                }
				
                if(top_stack(&g_stack) == '{')
                {
                   pop_stack(&g_stack);
                }
				else
                {
                    return false;
                }
                break;
        }
        
    }
	
	if (size_stack(&g_stack) == 0)
	{
		return true;
	}
	
    return false;
}

int main()
{
	char *g = "()[]{}";
	bool flag = isValid(g);
	printf("%s\n",flag==1?"yes":"no");
	return 0;
}
