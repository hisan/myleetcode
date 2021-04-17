#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

void free_2_arrary(int **g,int size)
{
    int  i = 0;
    for (i = 0;i < size;i++)
    {
        if (g[i])
        {
            free(g[i]);
            g[i] = NULL;    
        }
    }

    if (g)
    {
        free(g);
        g = NULL;
    }
}

bool completepath(char** board,int **matrix,int n,int m,int x,int y,char *cur_str,int cursize,const char *words,const int str_len,int index)
{
    //上下左右四个方向都进行探测
    int tmp_idx = 0;
    int tmp_cursize = 0;
   
    int **new_matrix = (int **)malloc(sizeof(int *)*n);//先复制二维矩阵
    for (int i = 0 ; i < n;i++)
    {
        new_matrix[i] = (int *)malloc(sizeof(int)*m);
        memcpy(new_matrix[i],matrix[i],sizeof(int)*m);
    }

    tmp_idx = index;
    tmp_cursize = cursize;

    //x+1,y
    if (x+1 < n && matrix[x+1][y] != 1 &&  board[x+1][y] == words[tmp_idx])
    {
        cur_str[cursize] = words[tmp_idx];
        tmp_idx += 1;

        if (tmp_idx == str_len && strncmp(cur_str, words,str_len) == 0)
        {
            free_2_arrary(new_matrix,n);
            return true;
        }

        tmp_cursize += 1;
        new_matrix[x+1][y] = 1;

        if (true == completepath(board,new_matrix,n,m,x+1,y,cur_str,tmp_cursize,words,str_len,tmp_idx))
        {
            free_2_arrary(new_matrix,n);
            return true;
        }

        new_matrix[x+1][y] = 0;
    }

    tmp_idx = index;
    tmp_cursize = cursize;

    //x-1,y
    if (x-1>=0 && matrix[x-1][y] != 1 && board[x-1][y] == words[tmp_idx])
    {
        cur_str[tmp_cursize] = words[tmp_idx];
        tmp_idx += 1;

        if (tmp_idx == str_len && strncmp(cur_str, words,str_len) == 0)
        {
            free_2_arrary(new_matrix,n);
            return true;
        }
        
        tmp_cursize += 1;
        new_matrix[x-1][y] = 1;

        if (true == completepath(board,new_matrix,n,m,x-1,y,cur_str,tmp_cursize,words,str_len,tmp_idx))
        {
            free_2_arrary(new_matrix,n);
            return true;
        }

        new_matrix[x-1][y] = 0;
    }

    tmp_idx = index;
    tmp_cursize = cursize;

    //x,y+1
    if (y+1 < m && matrix[x][y+1] != 1 && board[x][y+1] == words[tmp_idx])
    {
        cur_str[tmp_cursize] = words[tmp_idx];
        tmp_idx++;

        if (tmp_idx == str_len && strncmp(cur_str, words,str_len) == 0)
        {
            return true;
        }

        tmp_cursize += 1;
        new_matrix[x][y+1] = 1;

        if (true == completepath(board,new_matrix,n,m,x,y+1,cur_str,tmp_cursize,words,str_len,tmp_idx))
        {
            free(new_matrix);
            return true;
        }

        new_matrix[x][y+1] = 0;
    }

    tmp_idx = index;
    tmp_cursize = cursize;

    //x,y-1
    if (y-1>=0 && matrix[x][y-1] != 1 && board[x][y-1] == words[tmp_idx])
    {
        cur_str[tmp_cursize] = words[tmp_idx];
        tmp_idx++;

        if (tmp_idx == str_len && strncmp(cur_str, words,str_len) == 0)
        {
            return true;
        }

        tmp_cursize += 1;
        new_matrix[x][y-1] = 1;

        if (true == completepath(board,new_matrix,n,m,x,y-1,cur_str,tmp_cursize,words,str_len,tmp_idx))
        {
            free(new_matrix);
            return true;
        }

        new_matrix[x][y-1] = 0;
    }

    free_2_arrary(new_matrix,n);
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
	if (board == NULL || boardSize <= 0 || boardColSize == NULL || *boardColSize <= 0 || word == NULL)
    {
        return false;
    }

    int n = boardSize;
    int m = *boardColSize;
    int **matrix= NULL;
    int point_array[40000][2] = {0};
    int size = 0;

    for (int i = 0 ; i < n;i++)
    {
        for (int j = 0 ; j < m;j++)
        {
            if (board[i][j] == word[0])
            {
                point_array[size][0] = i;
                point_array[size][1] = j;
                size++;
            }
        }
    }
    
    if (size == 0)
    {
        return false;
    }

    matrix = (int **)malloc(sizeof(int *)*n);

    for (int i = 0 ; i < n;i++)
    {
        matrix[i] = (int *)malloc(sizeof(int)*m);
        memset(matrix[i],0,sizeof(int)*m);
    }

    char cur_str[4000] = {0};
    int cursize = 0;

    for (int i = 0;i < size;i++)
    {
        matrix[point_array[i][0]][point_array[i][1]] = 1;
		cur_str[0] = board[point_array[i][0]][point_array[i][1]];
		cursize = 1;

        if (cursize == strlen(word) && strncmp(cur_str, word,strlen(word)) == 0)
        {
            free_2_arrary(matrix,n);
            return true;
        }
		
        if (true == completepath(board,matrix,n,m,point_array[i][0],point_array[i][1],cur_str,cursize,word,strlen(word),1))
        {
            free_2_arrary(matrix,n);
            return true;
        }
		
        matrix[point_array[i][0]][point_array[i][1]] = 0;
    }
    
    free_2_arrary(matrix,n);
    return false;
}

int main()
{
	char word[1000] = {0};
	int boardColSize = 0;
	int boardSize = 0;
	char **board = NULL;
	bool ret = false;
	int i = 0;
	
	printf("please input the matrix high and width:\n\n");
	
	while ((EOF != scanf("%d",&boardSize)) && (EOF != scanf("%d",&boardColSize)))
	{
		if (board == NULL)
		{
			board = (char **)malloc(sizeof(char *)*boardSize);
			for (i = 0; i < boardSize;i++)
			{
				board[i] = (char *)malloc(boardColSize+1);
			}
		}
		
		printf("please input the matrix content:\n\n");
		for (i = 0; i < boardSize;i++)
		{
			memset(board[i],0,boardColSize+1);
			scanf("%s",board[i]);
		}
		
		printf("please input the path string:\n\n");
		scanf("%s",word);
		
		ret = exist(board,boardSize,&boardColSize,word);
		printf("the result is: %s\n",ret == 1?"true":"false");
	}
	
	//free_2_arrary(board,boardSize);
	
	return 0;
}







