#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define bool int 
#define false -1
#define true 1

//是1~N之间的数，所以没有考虑0
void print_right_number(char *number)
{
	int len = strlen(number);
	int begin0 = true;
	
	for(int i = 0;i < len;++i)
	{
		if (begin0 == true && number[i] != '0')
		{
			begin0 = false;
		}
		
		if (false == begin0)
		{
			printf("%c",number[i]);
		}
	}
	
	printf("\n");
}

bool increnumber(char *number)
{
	int num = 0;
	int len = strlen(number);
	int ntakeover = 0;
	
	for(int i = len-1;i>=0;i--)
	{
		num = number[i] - '0' + ntakeover;
		
		if (i == len-1)
		{
			num+=1;
		}
		
		if (num == 10)
		{
			if (i == 0)
			{
				return true;
			}
			else
			{
				number[i] = '0';
				num = 0;
				ntakeover = 1;
			}
		}
		else 
		{
			number[i] = '0' + num;
			break;
		}
	}
	
	return false;
}

void Print1ToMaxOfNDigits_1(int n)
{	
	char *number = NULL;
	if (n <= 0)
	{
		return;
	}
	number = realloc(number,n+1);
	memset(number,'0',n);
	number[n] = '\0';
	
	while (false == increnumber(number))
	{
		print_right_number(number);
	}
	
	free(number);
	return;
}

void dfs(char *number,int size,const int n)
{
	if (size == n)
	{
		print_right_number(number);
		return;
	}
	
	for (int i = 0;i < 10;i++)
	{
		number[size] = i + '0';
		size++;
		dfs(number,size,n);
		size--;
	}
}

//全排列的方法
void Print1ToMaxOfNDigits_dfs(int n)
{
	char *number = realloc(number,n+1);
	memset(number,'0',n);
	number[n] = '\0';
	
	dfs(number,0,n);
}

int main()
{
	int n = 0;
	while (EOF != scanf("%d",&n))
	{
		//Print1ToMaxOfNDigits_1(n);
		Print1ToMaxOfNDigits_2(n);
	}
	return 0;
}