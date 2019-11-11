/*run this program from  terminal and it block at select function call.
run devwrite program or use this command >echo vamsi > /dev/mydev*/ 
#include <stdio.h>
#include <fcntl.h>
#include <sys/select.h>



int main()
{
   char buf[100];
   int stat,len;
   fd_set fds;
   int retval;

   int fd = open("/dev/mydev", O_RDONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("fd = %d\n",fd);
   while (1)
   {
     FD_ZERO(&fds);
	printf("1\n");
     FD_SET(fd,&fds);
printf("2\n");
     FD_SET(0,&fds);
printf("3\n");
     retval = select(fd+1,&fds,0,0,0);
printf("4\n");
     if(retval)
     {
       if(FD_ISSET(fd,&fds))
       {
         len = read(fd,buf,20);
         printf("Read %d characters from DEVICE\n",len);
         buf[len] = 0;
         puts(buf);
       }
       if(FD_ISSET(0,&fds))
       {
         len = read(0,buf,20);
         printf("Read %d characters STDIN \n",len);
         buf[len] = 0;
         puts(buf);
       }

     }
     else
       printf("timeout\n");
   }
   close(fd);
}

   
