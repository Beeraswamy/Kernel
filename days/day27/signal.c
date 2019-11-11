#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
	printf("OUCH! - I got a signal %d\n", sig);
	//(void) signal(sig, SIG_DFL);
}


int main()
{
	(void) signal(SIGINT, ouch);

	while(1) {
		printf("hello world\n");
		printf("pid id  <%d\n>",getpid());
		sleep(2);
	}
}
