/*USER Application using select()
 The following example shows the usage of select system call to test the poll/select implementation of our device driver*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/select.h>

int main()
{
	char buf[100];
	int stat, len;
	fd_set fds;
	struct timeval tv;
	int retval;
	
	int fd= open("/dev/mydev", O_RDONLY);
	if(fd<0)
	{
		printf("Unable to open the device\n");	
		exit(0);
	}
	printf("fd = %d\n",fd);
	FD_ZERO(&fds);
	FD_SET(fd, &fds);
	tv.tv_sec = 60;
	tv.tv_usec = 0;
	retval = select(fd+1, &fds, 0, 0, &tv);
	if(retval)
	{
		if(FD_ISSET(fd, &fds))
		{
			len = read(fd, buf, 20);
			printf("Read %d characteristics\n",len);
			buf[len] = 0;
			puts(buf);
		}
	}	
	else
		printf("timeout\n");
	close(fd);
}


