#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>

int kpid=-1;
static struct completion thr_exited;

int mythread (void *arg)
{
  wait_queue_head_t dummy_wq;
  daemonize ("tst_kthread");

  sigemptyset(&current->blocked);
  recalc_sigpending();
  init_waitqueue_head (&dummy_wq);
  while(1)
  {
    wait_event_interruptible_timeout(dummy_wq, 0, 5*HZ);
    printk("kernel thread....Hello\n");
    if (signal_pending (current))
       break;
  }
  complete_and_exit (&thr_exited, 0);
}

static int hello_init(void)
{
  printk(KERN_ALERT "Simple kernel thread module\n");
  init_completion (&thr_exited);
  kpid = kernel_thread (mythread, 0, CLONE_FS | CLONE_FILES | CLONE_SIGHAND);
  printk("Kernel thread created pid %d\n", kpid);
  return 0;
}

static void hello_exit(void)
{
  int ret;
  printk("killing kernel thread \n");
  ret = kill_proc (kpid, SIGTERM, 1);
  printk("return value %d\n", ret);
  wait_for_completion (&thr_exited);
		
  printk(KERN_ALERT "Simple kernel thread module unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR ("Anjaneyulu Jagarlamudi<anji@depik.com>");
MODULE_DESCRIPTION ("kernel thread module");
MODULE_LICENSE ("GPL");
