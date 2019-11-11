#include <stdio.h>
#include <fcntl.h>
#include <sys/select.h>

int main()
{
   char buf[100];
   int stat,len;

   int fd = open("/dev/mydev", O_RDONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("fd = %d\n",fd);

   len = read(fd,buf,20);
   printf("Read %d characters\n",len);
   buf[len] = 0;
   puts(buf);
   close(fd);
}

   
