
uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0;
    int i = 0;
    while (i < 32)
    {
        i++;
        m <<=1;
        printf("0x%x\n",m);
        m |= n&1;
        n>>=1;
    }
    
    return m;
}
