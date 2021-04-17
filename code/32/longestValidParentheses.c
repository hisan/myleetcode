typedef struct 
{
    int array[30000];
    int top;
    int size;
}STACK;

int compare(void const *a, void const *b)
{
    return *(int*)a - *(int *)b;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int longestValidParentheses(char * s){

    int str_len = strlen(s);//此错误别再犯
    if (str_len <= 1)
    {
        return 0;
    }

    STACK g_stack;
    g_stack.top = g_stack.size = 0;

    int i = 0;
    int max_len = 0;

    int *array = NULL;
    int arr_size = 0;

    while (i < str_len)
    {
        if (s[i] == '(')
        {
            g_stack.array[g_stack.top++] = i;
            g_stack.size++;
        }
        else if (s[i] == ')')
        {
            if (g_stack.size == 0)
            {
                i++;
                continue;
            }
            else 
            {
                array = realloc(array,sizeof(int)*(arr_size+2));
                array[arr_size] = g_stack.array[g_stack.top-1];
                array[arr_size+1] = i;
                arr_size += 2;
                g_stack.top--;
                g_stack.size--;
            }
        }
        i++;
    }

    if (array == NULL)//若没有配对的括号，则后续的步骤也不用进行了
    {
        return 0;
    }

    qsort((void *)&array[0],arr_size, sizeof(int),compare);
    int start = 0;
    int end = 0;
    for (int i = 1;i < arr_size;i++)//求经过排序的int数组中最长的连续子数组
    {
        if (array[i-1] + 1 == array[i])
        {
            end++;
            max_len = max(max_len,end - start + 1);
        }
        else 
        {
            start=0;
            end = 0;
        }
    }
    
    free(array);
    return max_len;
}
