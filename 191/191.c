int hammingWeight(uint32_t n) {
    int num = 0;
    while (n)
    {
        num += (n & 1);
        n>>=1;
    }

    return num;
}
