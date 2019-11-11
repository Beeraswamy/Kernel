

#ifndef __KERNEL__
#define __KERNEL__
#endif
#ifndef MODULE
#define MODULE
#endif

#include <linux/fs.h>
#include <linux/wait.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>



#define PATH "/root/task"


int mykthread(void *);


int myvar = 50;
wait_queue_head_t my_queue;
int myevnt=0;
int mykthread(void *arg)
{

	char *argv[] ={"/root/task",NULL};
	init_waitqueue_head(&my_queue);	
	
		
	/* Run the kernel thread as a daemon */
	
	daemonize("mykthread");
	
	/* Request the delivery of SIGKILL */
	allow_signal(SIGKILL);
	printk("\n mykthread\n");
	myevnt=0;
	wait_event_interruptible(my_queue,myevnt!=0);
	printk("\n wait_event_interruptible after\n");
	// Now when myvar is altered we are notifying a user program using
	// call_usermodhelper [ defined in kernel/kmod.c ]
	

	call_usermodehelper(PATH,argv,NULL,1);
	return 0;
}

int init_module()
{
printk("\n init_module\n");
kernel_thread(mykthread,NULL,CLONE_FILES | CLONE_SIGHAND | CLONE_FS | SIGCHLD);
	return 0;
}

void cleanup_module()
{
printk("\n Module Removed\n");
}
EXPORT_SYMBOL(myevnt);
EXPORT_SYMBOL(myvar);
EXPORT_SYMBOL(my_queue);
