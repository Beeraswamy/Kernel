#include <stdio.h>

main(int argc,char *argv[])
{
	FILE *fp;
	int num,iu;
	/*
	if(argc<2)
	{
		printf("FIle name is missing\n");
		exit(1);
	}

	fp=fopen(argv[1],"w");*/
//printf("\nfd %d %ld \n",fp,*fp);
	fp=fopen("psr2.txt","w");
printf("\nui %d %d \n",fp,*fp);
	if(fp==0)
	{
		printf("Could not open a file\n");
		exit(2);
	}
	printf("enter intetgers to store in file\n");
	printf("enter 0 to exit\n");	
	while(1)
	{
		scanf("%d",&num);
		if(num==0)
			break;
		fprintf(fp,"%d\n",num);
	}
	fclose(fp);
}
