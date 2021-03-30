bool Increment(char *number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	
	for(int i = nLength - 1;i >= 0;i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
		{
			nSum++;
		}
		
		if (nSum > 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else 
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;//”¿‘∂œ»º∆À„µÕŒª
			}
		}
		else 
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	
	return isOverflow;
}


while (!Increment(number)
{
	print_number();
}
