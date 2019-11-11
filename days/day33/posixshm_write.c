/*Note use gcc -lrt posix_write.c to link with shared memory libraries
./pshm_create -c /demo_shm 0
./pshm_write /demo_shm 'hello'
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>



int main(int argc, char *argv[])
{
	int fd;
	size_t len=10;
	char *addr;
	/* Create a POSIX shared memory object */
	fd = shm_open("/demo_shm", O_RDWR|O_CREAT, 0666);
	if (fd == -1)
	{
		printf("shm_open error\n");
		return 1;
	}

	/* Setting the length object */
	if (ftruncate(fd, len) == -1)
	{
		printf("ftruncate error\n");
		return 1;
	}

	
	printf("Resized to %ld bytes\n", (long) len);
	addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED)
	{
		printf("mmap error\n");
		return 1;
	}

	/* 'fd' is no longer needed */
	if (close(fd) == -1)
	{
		printf("shm_open error\n");
		return 1;
	}
	
	printf("copying %ld bytes\n", (long) len);
	
	/* Copy string to shared memory */	
	memcpy(addr, "hello", strlen("hello"));
	
	
	
	exit(0);

}

