#include <stdio.h>
#include <fcntl.h>

int main()
{
   char buf[100];
   int stat,val;

   int fd = open("/dev/mydev", O_WRONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("fd = %d\n",fd);

   printf("Enter hex number to write to LED port\n");
   scanf("%x",&val);
   stat = write(fd,&val,1);
   close(fd);
}

   
