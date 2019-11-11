#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd;
	struct stat sb;
	char *addr;
	/* Create a POSIX shared memory object */
	fd = shm_open("/demo_shm", O_RDONLY,0);
	if (fd == -1)
	{
		printf("shm_open error\n");
		return 1;
	}

	/* Use shared memory object size as length argument for mmap()
		and as number of bytes to write() */

	if (f
	stat(fd, &sb) == -1)
	{
		printf("fstat error\n");
		return 1;
	}
	
	addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
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
	
	/* Accessing shared memory */	
	write(STDOUT_FILENO, addr, sb.st_size);
	
	if(shm_unlink("/demo_shm") == -1)
	{
		printf("shm_unlink error\n");
		return ;
	}
	exit(0);
}
