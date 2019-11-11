
/*Sample program that show the handling of a SIGINT (Control-C) signal.*/
#include <stdio.h>
#include <signal.h>
                                                 
void mysighandler(int signo)
{
	printf("i Caught the signal %d\n",signo);
        sleep(5);
 }
int main()
{
	signal(2,mysighandler);
	while(1)
	{
		
		printf("I slept for 15 seconds\n");
		sleep(1);
	}
}


