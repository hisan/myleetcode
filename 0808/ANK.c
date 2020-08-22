int g_num = 0;
int g_arr[10240];
int g_pos = 0;
bool g_visited[10240];

void dfs(int **re, int *nums, int numsSize, int start)
{
	// DFS递归的终止条件，并搜集一轮结果
    if (g_pos == numsSize) {
        re[g_num] = malloc(sizeof(int) * numsSize);
        memcpy(re[g_num], g_arr, sizeof(int) * numsSize);
        g_num++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        if (g_visited[i]) continue; // 访问过的减枝
        g_arr[g_pos++] = nums[i];
        g_visited[i] = true;
        dfs(re, nums, numsSize, 0); // 排列每次都从头访问，，略过前面访问过
        g_pos--;
        g_visited[i] = false;
    }

}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	// 初始化全局变量，C没有class，变量都通过入参传递太麻烦，适当用全局变量
	// 控制好这些全局变量的访问就好，可以加上static修饰等
    g_num = 0;
    g_pos = 0;
    
    memset(g_visited, false, sizeof(g_visited));
    int **re = malloc(sizeof(int *) * 10240);
    dfs(re, nums, numsSize, 0);
    *returnSize = g_num;
    *returnColumnSizes = malloc(sizeof(void *) * g_num);
    for (int i = 0; i < g_num; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return re;
}


