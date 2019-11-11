#include <stdio.h>
#include <fcntl.h>
#include<stdlib.h>
int main()
{
   char buf[40];
   int stat;

   int fd = open("/dev/mydev", O_RDWR);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("fd = %d\n",fd);

   printf("Success\n");
   stat = write(fd,"Hello device driver\n",21);
   printf("write stat = %d\n",stat);
   read(fd,buf,21);
   puts(buf);
   close(fd);
}

   
