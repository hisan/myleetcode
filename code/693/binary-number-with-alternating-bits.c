bool hasAlternatingBits(int n){
    int p1_bit = 0;
    int p2_bit = 0;
    int mask = 0x1;
    while (n)
    {
        p1_bit = n&mask;
        p2_bit = (n>>1)&mask;
        
        printf("p1_bit :%d p2_bit: %d\n",p1_bit,p2_bit);

        if (p1_bit - p2_bit == 0)
        {
            return false;
        }

        n>>=1;

        printf("%d\n",n);
    }
    return true;
}

#if 0
从低位开始，取最低位和次低位，判断两者是否都为1,是的话直接返回
#endif
