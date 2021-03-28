typedef struct 
{
    int array[1000];
    int size;
    int top;
}stack;

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    stack g_stack;
    g_stack.size = g_stack.top = 0;
    
    int j = 0;
    for (int i = 0 ; i < pushedSize;i++)
    {
        g_stack.array[g_stack.top++] = pushed[i];
        g_stack.size++;

        while ( g_stack.size > 0 && j < poppedSize && g_stack.array[g_stack.top-1] == popped[j])
        {
            g_stack.top--;
            g_stack.size--;
            j++;
        }
    }

    if (j == poppedSize)
    {
        return true;
    }

    return false;
}

