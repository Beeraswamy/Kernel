/*Used to create shared file mapping*/

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
//#include "tlpi_hdr.h"
#include <strings.h>
#define MEM_SIZE 20

#define FILESIZE 4000
int main(int argc, char *argv[])
{
	//char *addr;
	int *addr;
	int fd;
	struct stat sb;
	int i;
	if(argc < 2 ||strcmp(argv[1],"--help") == 0)
		exit(1);
	
	fd=open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd == -1)
	{
		printf("open fail\n");		
		exit(2);
	}	
	printf("open success\n");
	lseek(fd, FILESIZE-1,SEEK_SET);
	write(fd,"",1);
	//addr = mmap(NULL, MEM_SIZE, PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	addr = mmap(NULL, FILESIZE, PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);	
	if(addr == MAP_FAILED)
		exit(3);
	//ftruncate(fd,20);	
	printf("mmap success\n");
	//if(close(fd) == -1)
	//	exit(4);
	printf("close success\n");
	//printf("Current string  =%.*s\n",MEM_SIZE,addr);
	
		/*Secure practice: output at most MEM_SIZE bytes*/

	if(argc > 2)
	{
		if(strlen(argv[2]) >= MEM_SIZE)
			exit(5);
		
		//memset(addr,0,MEM_SIZE);
	printf("%s %d\n",argv[2],strlen(argv[2]));
		//strncpy(addr,argv[2],strlen(argv[2]));
		
	printf("strlen success\n");
		if(msync(addr,MEM_SIZE,MS_SYNC) == -1)
			exit(6);
for(i=0;i<=1000;i++)
	addr[i]=2*i;
#if 0
		addr[0]='h';
		addr[1]='a';
		addr[3]='i';
		addr[4]='z';
		addr[5]='z';
		addr[6]='z';
#if 0		
		if(msync(addr,MEM_SIZE,MS_SYNC) == -1)
			exit(6);
#endif
#endif	
		printf("copied \"%s\" to shared memory\n",argv[2]);
	//if(munmap(addr, MEM_SIZE) == -1)
	if(munmap(addr, FILESIZE) == -1)
		exit(8);
	close(fd);
	}
	exit(0);
}
	
