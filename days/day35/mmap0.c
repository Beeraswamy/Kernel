/*This program demonstrates the use of mmap to create private file mapping. This prgram is a simpel version of cat(10. It maps the entire file name in its command-line argumentl and then writes the contents of the mapping to standard output*/
//./a.out s.txt

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define MEM_SIZE 10

int main(int argc, char *argv[])
{
	//char *addr;
	int *addr;	
	int fd;
	struct stat sb;
	int i;
	if(argc!=2 ||strcmp(argv[1],"--help") == 0)
		exit(1);
	
	fd=open(argv[1],O_RDONLY);
	if(fd == -1)
		exit(2);
	
	/*Obtain the size of the file and use it to specify the size of the mapping
	and the size of the buffer to be written*/
	//if(fstat(fd, &sb) == -1)
	//	exit(3);	
		
	//addr = mmap(NULL, sb.st_size, PROT_READ,MAP_PRIVATE,fd,0);
	addr = mmap(NULL, 4000, PROT_READ,MAP_PRIVATE,fd,0);	
	if(addr == MAP_FAILED)
		exit(4);
	//printf("%d %p %s\n",sizeof(*addr),addr,addr);
	for(i=0;i<=1000;i++)
		printf("%d ",addr[i]);	
	//if(write(1, addr, sb.st_size) != sb.st_size)
	//	exit(5);
	//strcpy(addr,"vamsi");
	//if(munmap(addr, sb.st_size) == -1)
	if(munmap(addr, 4000) == -1)	
	{
		printf("munmap error\n");		
		exit(6);
	}
	exit(0);
}
	
