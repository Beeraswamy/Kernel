#include <fcntl.h>

int main()
{
	int fd;
	fd = open("dumpdemo.txt",O_RDWR|O_CREAT,0660);
	if(fd < 0) 
	{
		printf("Could not open file\n");
		exit(2);
	}
printf("sample sulo\n");
	//dup2(fd,1);
	dup(fd);
	printf("sample string is one\n");
	printf("sample string is two\n");
	puts("sample string is three\n");
}
	
