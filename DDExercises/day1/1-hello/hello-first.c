#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_ALERT */
#include <linux/init.h>		/* Needed for the macros */

MODULE_LICENSE("GPL");
static int __init hello_2_init(void)
{
  printk(KERN_ALERT "Hello, world 5\n");
  return 0;
}

module_init(hello_2_init);
