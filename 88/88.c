#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
	
    if (nums1 == NULL || nums2 == NULL || nums1Size < (m+n))
    {
        return ;
    }

	if (m == 0)
    {
        for (i = 0;i < n && i < nums1Size;i++)
        {
            nums1[i] = nums2[i]; 
            m += 1;
        }

        return;
    }

    for (i = 0;i < n;i++)
    {
        if (nums2[i] >= nums1[m-1])//==================================================>
        {                                                                              |
            nums1[m] = nums2[i];                                                       |
			m+=1;                                                                      |
        }                                                                              |
        else if (nums2[i] < nums1[0])                                                  |
        {                                                                              |保持一致
            for (j = m-1; j >= 0;j--)                                                  |
            {                                                                          |
                nums1[j+1] = nums1[j];                                                 |
            }                                                                          |
                                                                                       |
            nums1[0] = nums2[i];                                                       |
			m+=1;                                                                      |
        }                                                                              |
        else                                                                           |
        {                                                                              |
            for(j = 0;j < m;j++)                                                       |
            {                                                                          |
                if (nums2[i] >= nums1[j])//<<<========================================\|/
                {
                    continue;
                }

                for(k = m-1;k >= j;k--)
                {
                    nums1[k+1] = nums1[k];
                }
                
                nums1[j] = nums2[i];
                m += 1;
                break;
            }
        }
    }
}

int main()
{
	int nums1[] = {1,2,3,0,0,0};
	int nums1Size = 6;
	int m = 3;
	
	int nums2[] = {2,5,6};
	int nums2Size = 3;
	int n = 3;
	
	merge(nums1,nums1Size,m,nums2,nums2Size,n);
	
	return 0;
}