bool isPowerOfTwo(int n){
    int num_1 = 0;
    while (n > 0)
    {
        num_1 += (n&1);
        n >>= 1;
    }

    return num_1 == 1;
}
