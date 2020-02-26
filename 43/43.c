//2020-02-26 23:48 通过

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//大数时行不通
char * multiply1(char * num1, char * num2){
    
    int len = 0;
    int tmp = 0;
    int m = 0;
    char *p = num1;
    int value1 = 0;
    int value2 = 0;

    char *buffer = (char *)malloc(1024);
    memset(buffer,0,1024);

    len = strlen(num1);
    while (*p != '\0')
    {
        tmp = *p - 48;
        tmp *= pow(10,len-m-1);//当时大数的时候，此处会一处，行不通啊
        value1 += tmp;
        m++;
        p++;
    }
    printf("%d\r\n",value1);
    p = num2;
    tmp = 0;
    m = 0;
    len = strlen(num2);
    while (*p != '\0')
    {
        tmp = *p - 48;
        tmp *= pow(10,len-m-1);
        value2 += tmp;
        m++;
        p++;
    }
    printf("%d\r\n",value2);
    value1 *= value2;

    sprintf(buffer,"%d",value1);

    return buffer;
}

char *multiply(char *num1,char *num2)
{
	int len1 = strlen(num1); 
	int len2 = strlen(num2);
	int len = len1 + len2;//两数相乘，得到的乘积的位数 <= strlen(num1) + strlen(num2)
	int i = 0,j = 0;
	int tmp = 0;
    char *ret = NULL;
    int buffer[220] = {0};
    ret = (char *)malloc(220);
	memset(ret,0,220);
	
    if ((len1 ==1 && num1[0] == '0')||(len2 ==1 && num2[0] == '0'))
	{
		sprintf(ret+strlen(ret),"%c",'0');
		return ret;
	}

	for(i = len1-1;i >= 0;i--)//一开始我是使用for(i = 0;i < len1 ;i++),得到错误的结果
	{
		for (j = len2-1;j >= 0;j--)//...
		{
			tmp = (buffer[i+j+1] + ((num1[i] - 48) * (num2[j] - 48)));
			buffer[i+j+1] = tmp %10;
			buffer[i+j] += tmp/10;
		}
	}

	for (i = 0;i < len;i++)
	{
		printf("%d\r\n",buffer[i]);
		if (i == 0 && buffer[i] == 0 )
		{
			continue;
		}

		sprintf(ret+strlen(ret),"%c",buffer[i]+48);
	}
	
	return ret;
}

int main()
{
	//char p[10]={'0','1','2','3','4','5','6','7','8','9'}; 一种计算时的hash思想
	char *p1 = "2";
	char *p2 = "3";
	char *ret = multiply(p1,p2);
	printf("%s\r\n",ret);
}

