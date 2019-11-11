#include <fcntl.h>

int main()
{
	int fd;
	char str[20];
	//fd = open("dumpdemo.txt",O_RDWR|O_CREAT|O_TRUNC,0660);
	fd = open("dumpdemo.txt",O_WRONLY|O_CREAT);
	if(fd < 0)
	{
		printf("Could not open file\n");
		exit(2);
	}
	dup2(fd,1);
	scanf("%s",str);
	
	write(fd,str,strlen(str));
	
}

