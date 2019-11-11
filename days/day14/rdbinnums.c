#include <stdio.h>

main(int argc,char *argv[])
{
	FILE *fp;
	int num;
	if(argc<2)
	{
		printf("File name is missing\n");
		//exit(1);
	}
	fp = fopen("file1.txt","r");
	if(fp == 0)
	{
		printf("could not open file\n");
		exit(2);
	}
	printf("\n Following are the numbers stored in the file in the binary form\n");
	while(fread(&num,sizeof(int),1,fp)==1)
//while(1)
	{
		printf("%d\n",num);
	}
	printf("\n");
	fclose(fp);
}
