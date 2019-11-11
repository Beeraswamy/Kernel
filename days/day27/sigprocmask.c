#include<stdio.h>
#include<signal.h>


sighdl(int signo)
	{
	printf("recieved signal is %d",signo);
	//alarm(5);
	}


main()
		{

		sigset_t mask;
		sigset_t orgnmask;
		struct sigaction act;
		act.sa_handler=sighdl;
		act.sa_flags=NULL;
		sigemptyset(&act.sa_mask);
                sigfillset(&act.sa_mask);
	if(sigaction(SIGINT,&act,0)<0)
		{
		perror("sigaction");
		return 1;
		}

	sigemptyset(&mask);
	sigaddset(&mask,SIGILL);

	//printf("printing the value");
	//getchar();

	//sigaddset(&mask,SIGINT);

	if(sigprocmask(SIG_BLOCK,&mask,&orgnmask)<0)
	{
	printf("prashanth\n");
	perror("sigaction");
	return 1;
	}
	printf("aftre sigproc mask");

	getchar();


	if(sigprocmask(SIG_UNBLOCK,&mask,&orgnmask)<0)
	{
	printf("prashanth\n");
	perror("sigaction");
	return 1;
	}


	getchar();

	if(sigprocmask(SIG_SETMASK,&orgnmask,0)<0)
	{
	perror("sigaction");
	return 1;
	}

	getchar();

	if(sigprocmask(SIG_UNBLOCK,&orgnmask,0)<0)
	{
	printf("prashanth\n");
	perror("sigaction");
	return 1;
	}

		printf("terminating");
		getchar();
//getchar();
//if(got_signal)
//puts("got signal");
//return 0;
}
