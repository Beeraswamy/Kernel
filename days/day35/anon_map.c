#include<stdio.h>
#ifdef USE_MAP_ANON
	#define _BSD_SOURCE	/*Get MAP_ANONYMOUS definition*/
#endif
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{	
	int *addr; /*pointer to shared memory region*/
	
#ifdef USE_MAP_ANON
	addr = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1,0);
	if(addr == MAP_FAILED)
		exit(1);
#else
	int fd;
	fd=open("/dev/zero",O_RDWR);	/*Map /dev/zero*/
	if(fd == -1)
		exit(2);
	
	addr = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr == MAP_FAILED)
		exit(3);
	
	if(close(fd) == -1)	/*No longer needed*/
		exit(4);

#endif

	*addr =1; 
	
	switch(fork())		/*Parent and child share mapping*/
	{
		case -1:
			exit(5);
		case 0: 	/*Child: increment shared integer and exit*/
			printf("Child started, value=%d\n",*addr);
			(*addr)++;
			if(munmap(addr, sizeof(int)) == -1)
				exit(6);
			exit(0);
		default:	/*Parent: wait for child to terminate*/
			if(wait(NULL) == -1)
				exit(7);
			printf("In parent, value = %d\n", *addr);
			if(munmap(addr, sizeof(int)) == -1)
				exit(8);
			exit(0);
	}
}
