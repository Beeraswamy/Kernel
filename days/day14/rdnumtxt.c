#include <stdio.h>

main(int argc, char *argv[])
{
	FILE *fp;
	int num;
	
	/*if(argc<2)
	{
		printf("Filename is missing\n");
		exit(1);
	}
	fp = fopen(argv[1],"r");*/
	fp = fopen("ara.txt","r");
	if(fp == 0)
	{
		printf("could not open file\n");
		exit(2);
	}
	printf("Following are the numbers stored in file in txt form\n");
	while(fscanf(fp,"%d",&num)==1)
	{
		printf("%d\n",num);
	}
	printf("\n");
	fclose(fp);
}
