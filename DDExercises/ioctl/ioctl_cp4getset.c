#include <stdio.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include "mydevioctl.h" 

int main()
{
   int stat,cp3,cp4;

   int fd = open("/dev/mydev", O_RDONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("Enter cp3 value to set \n");
   scanf("%d", &cp3);
   printf("%u %u %u %u %u \n",MYDEV_GET_CP1,MYDEV_SET_CP2,MYDEV_SET_CP3,MYDEV_GET_CP3,MYDEV_SET_GET_CP4);
   stat = ioctl(fd,MYDEV_SET_GET_CP4, &cp3);
   cp4=cp3;
   if(stat < 0)                     
   {
     printf("Error with ioctl\n");
   }
   else
   {
     printf("cparam1 = %0u\n",cp4);
   }

   close(fd);
}

   
