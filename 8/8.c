#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define INT_MAX (pow(2,32) - 1)
#define INT_MIN	(pow(-2,31))

int myAtoi1(char * str){

    if (str == NULL)
    {
        return 0;
    }

    
    if ((str[0] > '9' || str[0] <'0') && str[0] != '-' && str[0] != '+')
    {
        return 0;
    }

    int oddflag = 0;
    char buffer[1024] = {0};

    int len = 0;
    char *p = str;
	
    while ( *p != '\0')
    {
        if (*p == ' ')
        {
            p++;
            continue;
        }
        else if(*p == '-')
        {
            oddflag = 1;
             p++;
            continue;
        }
        else if(*p >='0' && *p <= '9')
        {
            sprintf(buffer+strlen(buffer),"%c",*p);
            len += 1; 
            p++;
            continue;
        }
        p++;
    }
    

    double ret = 0;
    double a = 0;
	char c = '0';

    for (int i = 0 ;i < len;i++)
    {
        a = (buffer[i] - 48);
        a *= pow(10,len-i-1);
        printf("a: %f\r\n",a);
        ret += a;
		printf("ret: %f\r\n",ret);
    }

    if (oddflag == 1)
    {
        ret = 0 - ret;
    }

    if (oddflag == 0 && ret > INT_MAX)
    {
        return INT_MAX;
    }
    else if (oddflag == 1 && ret < INT_MIN)
    {
        return INT_MIN;
    }
	
    return ret;
}


//力扣网友的解法
int myAtoi(char * str){

    long result = 0;
    sscanf(str, "%ld", &result);
    if (result < INT_MIN)
    {
        return INT_MIN;
    }
    else if (result > INT_MAX)
    {
        return INT_MAX;
    }
	
    return result;
}


int main()
{
	int ret = myAtoi("words and 987");
	printf("%d\r\n",ret);
}


/*
ASCII码中，字符0~9的的对应十进制值，在字符串转换（特别是字符转数字)中很有用,
可以记住'0'==48,以后使用的时候就不用查了。
48	0
49	1
50	2
51	3
52	4
53	5
54	6
55	7
56	8
57	9
 */