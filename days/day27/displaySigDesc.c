#include <stdio.h>
#include <signal.h>

main()
{	
	printf("%s\n",strsignal(SIGINT));
}
