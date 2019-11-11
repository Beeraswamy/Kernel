#include <fcntl.h>

int main()
{
	int fd,x;
	char str[20];
	printf("%d",getpid())	
	fd = open("dumpdemo.txt",O_RDONLY);
	if(fd < 0)
	{
		printf("Could not open file\n");
		exit(2);
	}
	
	printf("%d\n",fd);
	x=read(fd,str,20);
	sleep(1);
	str[x]='\0';	
	printf("%s\n",str);
	
}
