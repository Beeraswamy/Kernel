       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 
int main()
{
  int fd = open("/dev/sbd", O_RDONLY);
  char buff[100];
  if(fd < 0) 
  {
    printf("Failed to open \n");
    return 1;
  }
  printf("bytes read %d\n", read(fd, buff, 100));
  printf("data %s\n", buff);
  printf("bytes read %d\n", read(fd, buff, 100));
  printf("data %s\n", buff);
  close(fd);
}
