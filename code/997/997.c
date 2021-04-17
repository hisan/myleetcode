//根据题意，可先获取每个人的出入度，最终出度为0，入度为n-1的即为法官

int findJudge(int N, int** trust, int trustSize, int* trustColSize){
//找到一个节点，这个节点被所有其他节点指向
    int people[1001][2] = {0};
   
    for(int i = 0 ; i < trustSize;i++)
    {
        people[trust[i][0]][0]++;//出度
        people[trust[i][1]][1]++;//入度       
    }
    
    for(int j = 1 ;j<=N;j++)
    {
        if((people[j][0] == 0)&&(people[j][1] == N-1))
        {
           return j;
        }
    }
    return -1;
}
