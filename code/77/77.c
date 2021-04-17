#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DFS(int n,int k,int **ret,int *traverpos,int start,int *tmparray,int* returnSize)
{
    if (*traverpos == k)
    {
        ret[*returnSize] = malloc(sizeof(int)*k);
        memcpy(ret[*returnSize],tmparray,sizeof(int)*k);
        //printf("%d %d %d %d %d %d\r\n",tmparray[0],tmparray[1],tmparray[2],tmparray[3],tmparray[4],tmparray[5]);
        *returnSize += 1;
        return;
    }

    for (int i = start; i <= n;i++)
    {
        tmparray[*traverpos] = i;
        *traverpos += 1;
        DFS(n,k,ret,traverpos,i+1,tmparray,returnSize);
        *traverpos -= 1;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int **ret = malloc(sizeof(int* )*10000);
    memset(ret,0,sizeof(int* )*10000);
    int traverpos = 0;
   
    *returnSize = 0;
    
    int *tmparray = malloc(sizeof(int)*k);
    memset(tmparray,0,sizeof(int)*k);
    *returnColumnSizes = malloc(sizeof(int)*(*returnSize));
    DFS(n,k,ret,&traverpos,1,tmparray,returnSize);
    for (int i = 0;i < (*returnSize);i++)
    {
	(*returnColumnSizes)[i] = k;
    }
    return ret;
}

int main()
{
	int n = 3;
	int k = 3;
	int returnSize = 0;
	int *retcol = malloc(sizeof(int)*10000);
	memset(retcol,0,sizeof(int)*10000);
	int** ret = combine(n,k,&returnSize,&retcol);
	printf("retnum:%d\r\n",returnSize);
	return 0;
}

/*
这个穷举是如何实现的？

1.因为之前我一直在想，从(1,2)...(1,16)之后，for循环结束，那(2,3)这些组合是如何产生的呢？于是我加以调试，直至结束1，16的DFS,
结果i在这次循环的起点变为了2，此时，我方才恍然大悟，这个for也是递归的一部分，(1,2)...(1,16)都只是第一个DFS的调用的结束，他们
的i都在>n后跳出他们的DFS,从而for循环的第一次调用结束。

所以，这个穷举就是深度优先搜索的表达。这个代码是我参考别人写的，我也知道是用来解决DFS问题，但是我在经历以上后，才深刻体会到何为
深度优先遍历。


深度优先遍历：
先从第一层节点的第一个节点开始，探寻下一层的节点,所以，第一次调用DFS中的for就是从第一层的所有节点中的第一个节点开始。
现在看来，这代码非常的形象地表达了深度优先遍历！！！


*/


