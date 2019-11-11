/*  
 *  Demonstrates module documentation.
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#define DRIVER_AUTHOR "VAMSI"
#define  DRIVER_DESC "Sample module"
struct timer_list timer; 
void timer_fun(unsigned long ldev)
{
  printk("hello\n");
  timer.expires = jiffies + 2000;
}

static int __init init_hello_4(void)
{
  printk(KERN_ALERT "Hello, world \n");
  init_timer(&timer);
  timer.data = 0;
  timer.function = timer_fun;
  timer.expires = jiffies + 125;
  add_timer(&timer);



  return 0;
}

static void __exit cleanup_hello_4(void)
{
  del_timer(&timer);
  printk(KERN_ALERT "Goodbye, world \n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);


/* 
 *  Get rid of taint message by declaring code as GPL. 
 */
MODULE_LICENSE("GPL");

/*
 * Or with defines, like this:
 */
MODULE_AUTHOR(DRIVER_AUTHOR);	/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */

/*  
 *  This module uses /dev/testdevice.  The MODULE_SUPPORTED_DEVICE macro might
 *  be used in the future to help automatic configuration of modules, but is 
 *  currently unused other than for documentation purposes.
 */
MODULE_SUPPORTED_DEVICE("example module");
