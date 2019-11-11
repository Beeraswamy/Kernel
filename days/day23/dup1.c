#include<fcntl.h>
void main()
{
     int fd = dup2(fd,0);
     char *buf1 = "This appears on terminal\n";
     char *buf2 = "This also appears on terminal\n";
     printf("New fd %d\n",fd);
     write(1,buf1,strlen(buf1));
     write(fd,buf2,strlen(buf2));
}
