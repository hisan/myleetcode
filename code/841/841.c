
bool dfs(int key,int *markedarray,int **rooms,int* viscounted,const int roomsSize,int *roomsColSize)
{
    markedarray[key] = 1;
    ++(*viscounted);
    
    if(*viscounted == roomsSize)
    {
        return true;
    }
    
    for(int i = 0;i < roomsColSize[key];i++)
    {//遍历该房间的每一把钥匙
        if(markedarray[rooms[key][i]] == 0)//未被访问过
        {
            if(dfs(rooms[key][i],markedarray,rooms,viscounted,roomsSize,roomsColSize))
            {//这个判断非常重要，若是[[2,3],[],[2],[1,3,1]]这种情况，则遍历到第二个数组,仿佛它去不了任何房间，但是不代表之前的房间没有去往其他房间的钥匙
                    return true;
            }
        }
    }
    return false;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){

    int marked[1001]= {0};//若房间被访问过，则标记为1
    int viscount = 0 ;//已经访问的房间数量

    return dfs(0,marked,rooms,&viscount,roomsSize,roomsColSize);
    
}
