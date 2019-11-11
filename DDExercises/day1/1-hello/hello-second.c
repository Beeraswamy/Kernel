#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_ALERT */
#include <linux/init.h>		/* Needed for the macros */


static void __exit hello_2_exit(void)
{
  printk(KERN_ALERT "Goodbye, world 5\n");
}

module_exit(hello_2_exit);
