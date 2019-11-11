#include <stdio.h>
#include <fcntl.h>

int main()
{
   unsigned char buf[100];
   int stat,len;

   int fd = open("/dev/mydev", O_RDONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("fd = %d\n",fd);

   len = read(fd,buf,20);
   printf("Read length = %d\n",len);
   printf("Key value = %02x\n",buf[0]);
   close(fd);
}

   
