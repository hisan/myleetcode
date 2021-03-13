char * toHex(int num){
    int tmp1 = 0;
    char buffer[9] = {0};
    char *ret = NULL;
    int i = 0;
    char hashtable[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    ret = (char *)malloc(9);
    memset(ret,0,9);
    
    do 
    {
        tmp1 = num & 0xf;
        sprintf(buffer+strlen(buffer),"%c",hashtable[tmp1]);
        i++;
        num >>= 4;
    }while (i < 8 &&num);

    #if 0
    if (num == 0)
    {
        sprintf(ret+strlen(ret),"%c",hashtable[num]);
        return ret;
    }

    for (int i = 0; num && i < 8; ++i) 
    {
            tmp1 = num & 0xf;
            sprintf(buffer+strlen(buffer),"%c",hashtable[tmp1]);
            num >>= 4;
    }
    #endif

    for (int i = 0;i < strlen(buffer);i++)
    {
        ret[i] = buffer[strlen(buffer)-1-i];
    }

    return ret;
}


