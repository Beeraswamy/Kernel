#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_ALERT */

int module1(void)
{
  printk("<1>Hello world 1.\n");
  /* 
 * A non 0 return means init_module failed; module can't be loaded. 
   */
  return 0;
}

void cleanup(void)
{
  printk(KERN_ALERT "Goodbye world 1.\n");
}
module_init(module1);
module_exit(cleanup);

