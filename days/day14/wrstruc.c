#include <stdio.h>

main(int argc,char *argv[])
{
	FILE *fp;
	int num;
	
	if(argc<2)
	{
		printf("FIle name is missing\n");
		exit(1);
	}
	
	fp=fopen(argv[1],"w");
	if(fp==0)
	{
		printf("Could not open a file\n");
		exit(2);
	}
	printf("Info rollno name city is stored in file\n");
	fprintf(fp,"%s %s %s\n",argv[2],argv[3],argv[4]);
	fclose(fp);
}
