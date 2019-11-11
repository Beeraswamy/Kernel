#include <stdio.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include "mydevioctl.h" 

int main()
{
   int stat;
   char cp3;	

   int fd = open("/dev/mydev", O_RDONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
printf("%x %x %x %x\n",MYDEV_GET_CP1,MYDEV_SET_CP2,MYDEV_SET_CP3,MYDEV_GET_CP3);
   stat = ioctl(fd,MYDEV_GET_CP3, &cp3);
   if(stat < 0)
   {
     printf("Error with ioctl\n");
   }
   else
   {
     printf("cparam1 = %c\n",cp3);
   }

   close(fd);
}

   
