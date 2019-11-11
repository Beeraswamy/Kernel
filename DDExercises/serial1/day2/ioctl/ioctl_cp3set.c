#include <stdio.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include "mydevioctl.h" 

int main()
{
   int stat,cp3;

   int fd = open("/dev/mydev", O_RDONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("Enter cp3 value to set \n");
   scanf("%d", &cp3);

   stat = ioctl(fd,MYDEV_SET_CP3, &cp3);
   if(stat < 0)
   {
     printf("Error with ioctl\n");
   }
   else
   {
     printf("cparam1 = %0d\n",cp3);
   }

   close(fd);
}

   
