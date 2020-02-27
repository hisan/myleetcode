//20190403 
建立字符与位序的hash关系，通过查找这个hash关系进行位序转换成字符并复制到返回的字符串中


void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

char* frequencySort(char* s) {
    //第一时间想到的是hash
    int a[128]={0};
    int copy[128]={0};

    int k = 0;
    char *p = s;
    while(*p!='\0')
    {//得到一个hash映射关系
        int pos = (int)(*p);
        a[pos]++;
        p++;
    }

    memcpy(&copy,&a,sizeof(int)*128);//拷贝是为了不破坏映射关系的同时还能得到出现的字符数量关系,以便之后进行排序
    for(int i =0;i<128;i++)
    {
        for(int j = i+1;j<128;j++)
        {
            if(copy[i] < copy[j])
            {
                swap(&copy[i],&copy[j]);
            }
        }
    }
    
    for(int i = 0;i < 128;i++)
    {
        if(copy[i]>0)
        {
            for(int j = 0;j < 128;j++)
            {
                if((a[j] > 0)&&(a[j] == copy[i]))
                {//得到字符转换成的十进制位序j，再将该位序j转换成字符

                    char c = (char)(j);//字符
                    int count = 0;
                    count = copy[i];//次数

                    a[j] = 0;//置为0，避免下次循环又重复复制同一字符

                    while(count--)
                    {//字符拷贝
                       s[k++] = c;
                    }

                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    s[k]='\0';
    return s;
}


