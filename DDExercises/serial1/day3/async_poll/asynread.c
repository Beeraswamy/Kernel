#include <stdio.h>
#include <fcntl.h>
#include <signal.h>



void mysighndlr(int signo)
{
  printf("Signal %d received\n",signo);
}

int main()
{
   char buf[100];
   int stat,len,flgs;

   int fd = open("/dev/mydev", O_RDONLY);
   if(fd<0)
   {
     printf("Unable to open the device\n");
     exit(0);
   }
   printf("fd = %d\n",fd);

   signal(SIGIO, mysighndlr);
   fcntl(fd,F_SETOWN,getpid());
   flgs = fcntl(fd,F_GETFL);
   fcntl(fd,F_SETFL,flgs | FASYNC);
   while(1)
   {
     pause();
     printf("outof pause\n");
     len = read(fd,buf,20);
     printf("Read %d characters\n",len);
     buf[len] = 0;
     puts(buf);
   }
   close(fd);
}

   
