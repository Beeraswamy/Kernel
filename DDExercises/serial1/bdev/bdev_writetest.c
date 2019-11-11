       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 
int main()
{
  int fd = open("/dev/sbd", O_RDWR);
  char buff[100];
  if(fd < 0) 
  {
    printf("Failed to open \n");
    return 1;
  }
  gets(buff);
  printf("bytes writen %d\n", write(fd, buff, strlen(buff)));
  close(fd);
}
