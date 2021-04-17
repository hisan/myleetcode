#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc,char **argv)
{
	int len1,len2,len3 = 0;
	char *parg = NULL;
	if (argc < 3)
	{
		printf("Usage:\r\n	mygcc file.c out\r\n");
		printf("		-l	link your library\r\n");
		exit(0);
	}
	
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	if (argc > 3)
	{
		len3  = strlen(argv[3]);
	}
	
	parg = (char*)malloc(sizeof(char)*(len1+len2+20 + len3));
	
	if (argc > 3)
	{
		sprintf(parg,"gcc -g %s -o %s %s",argv[1],argv[2],argv[3]);	
	}
	else 
	{
		sprintf(parg,"gcc -g %s -o %s",argv[1],argv[2]);
	}
	
	parg[strlen(parg)] = '\0';
	system(parg);
	free(parg);
	exit(0);
}
