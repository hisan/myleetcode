//2020-02-25 13:06 通过
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER 1024

void swap(int *a,int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int customsort(int a,int b)
{
    char buffer1[MAX_BUFFER] = {0};
    char buffer2[MAX_BUFFER] = {0};
	
    sprintf(buffer1,"%d%d",a,b);
    sprintf(buffer2,"%d%d",b,a);
    return strcmp(buffer1,buffer2);
}

char *largestNumber(int* nums, int numsSize)
{
    if (numsSize == 0 ) 
    {
        return NULL;
    }
	
    char *buffer = (char *)malloc(MAX_BUFFER);
    memset(buffer,0,MAX_BUFFER);
	
    for (int i = 0 ; i < numsSize;i++)
    {    
		for (int j = i+1;j<numsSize;j++)
		{
			if (customsort(nums[i],nums[j]) <0)
			{	
				swap(&nums[i],&nums[j]);
			}
		}
    }
	
	for (int i =0;i<numsSize;i++)
	{
		sprintf(buffer+strlen(buffer),"%d",nums[i]);
	}

    if (buffer[0] == '0')
    {
         return "0";
    }
	
    return buffer;
}

int main()
{
	int arrary[] = {84,142,41,17,71,170,186,183,21,76,76,10,29,81,112,39,6,43,58,41,111,33,69,97,38,82,44,7,99,135,42,150,149,21,30,164,153,92,180,61,99,81,147,109,34,98,14,178,105,5,43,46,40,37,23,16,123,53,34,192,73,94,39,96,115,88,31,96,106,131,64,189,91,34,56,22,105,104,22,31,43,90,96,65,85,184,85,90,118,152,31,161,22,104,85,160,120,31,144,115};
	char *p = largestNumber(arrary,sizeof(arrary)/sizeof(int));
	printf("%s\r\n",p);
	return 0;
}



