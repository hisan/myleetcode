#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
    int len = strlen(s);
    if (numRows <= 1)
    {
        return s;
    }
    
    char *dst = (char *)malloc(len+1);
    memset(dst,0,len);
    dst[len] = '\0';
    int size = 2*numRows-2;
    int idx = 0;
    for (int i = 0; i < numRows;i++)
    {
        for (int j = i;j < len;j += size)
        {
            dst[idx++] = s[j];
            int pos = j+size-2*i;
            if (i != 0 && i != numRows-1)
            {
                if (pos < len)
                {
                    dst[idx++] = s[pos];
                }
            }
        }
    }
	
    return dst;
}

int main()
{
	char *src = {"PAYPALISHIRING"};
	int numRows = 4;
	char *dst = NULL;
	dst = convert(src,numRows);
	printf("%s\n",dst);
	free(dst);
	return 0;
}
