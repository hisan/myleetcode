
//2019-08-04提交通过

bool lemonadeChange(int* bills, int billsSize){
    
    int fivecount = 0;
    int tencount = 0;
    int twenty = 0;
    int i = 0;
    for(; i < billsSize;i++)
    {
        switch(bills[i])
        {
            case 5:
                fivecount++;
                break;
            case 10:
                if(fivecount > 0)
                {
                    fivecount--;
                }
                else
                {
                    return false;
                }
                tencount++;
                break;
            case 20:
                if(tencount > 0)
                {
                    if(fivecount > 0)
                    {
                        tencount--;
                        fivecount--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(fivecount >=3)
                    {
                        fivecount-=3;
                    }
                    else
                    {
                        return false;
                    }
                }
                twenty++;
                break;
            default:
                break;
        }
    }
    return true;
}
