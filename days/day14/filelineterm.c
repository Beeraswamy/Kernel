#include <stdio.h>

main(int argc,char *argv[])
{
	FILE *fp;
	char buf[128];
	/*if(argc<2)
	{
		printf("File name is missing\n");
		exit(1);	
	}
	fp=fopen(argv[1],"r");*/
	fp=fopen("ara.txt","r");	
	if(fp == 0)
	{
		printf("Could not open file\n");
		exit(2);	
	}
	fseek(fp,4,0);
	while(fgets(buf,128,fp))
	{
		printf("%s",buf);
	}
	fclose(fp);
}
	
	
