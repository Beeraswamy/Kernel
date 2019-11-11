#include <stdio.h>

main()
{
	int id;
	int cnt=0;
	printf("I am going to create a new processs\n");
	id = fork();
	if(id)
	{
		while(cnt < 5)
		{
			cnt++;
			printf("I am parent, my child process is %d\n",id);
			sleep(10);
		}
	}
	
	//printf("yahoo");
	
	else
	{
		while(cnt <5)
		{
			cnt++;
			printf("I am child process I got id value as %d\n",id);
			sleep(10);
		}
 	}
 	
 	printf("yepee");
}


