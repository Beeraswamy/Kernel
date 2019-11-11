#include <stdio.h>

int main(int argc,char *argv[])
{
	FILE *fp;
	int num;
	
	/*if(argc<2)
	{
		printf("Filename is missing");
	}*/
	
	fp = fopen("file1.txt","w");
	if(fp == 0)
	{
		printf("Could not open file\n");
		exit(2);
	}
	
	printf("Enter integers to store in file\n");
	printf("Enter zeros to exit\n");
	while(1)
	{
		scanf("%d",&num);
		if(num==0)
			break;
		fwrite(&num,sizeof(int),1,fp);	
	}
	fclose(fp);
}
	
