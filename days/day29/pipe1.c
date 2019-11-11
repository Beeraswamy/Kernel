#include <stdio.h>

int main()
{
	int fds[2],ii,n;
	char readbuf[100];
	char writebuf[100];
	
	if(pipe(fds) < 0)
	{
		perror("pipe creation failed\n");
		//exit(1);
	}
	if(fork() == 0) //child process
	{
		close(fds[1]);
		while(1)
		{	
			printf("ex\n");
			n = read(fds[0],readbuf,100);
			printf("Read from fds[0] and output to screen:\n");			
			for(ii=0;ii<n;ii++)
				readbuf[ii]=toupper(readbuf[ii]);
			puts(readbuf);
		}
	}
	//Parent process
		close(fds[0]);
	while(1)
	{
		fgets(writebuf,100,stdin);
		write(fds[1],writebuf,strlen(writebuf)+1);
		printf("Wrote to fds[1]:\n");
	}	
}
	
