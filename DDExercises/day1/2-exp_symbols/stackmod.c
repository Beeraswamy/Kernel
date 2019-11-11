/*******************************************************************************
* 
* 
*******************************************************************************/

#include <linux/module.h>
#include <linux/init.h>


MODULE_AUTHOR("VAMSI TECH");
MODULE_LICENSE("GPL");
void myexportfun(void);
/*******************************************************************************
* Name:init_module
* Description:
*******************************************************************************/
int my_init(void)
{
  printk("<1>" "Module to demo export of symbols\n");
  myexportfun();
  return 0;
}

/*******************************************************************************
* Name:cleanup_module
* Description:
*******************************************************************************/
void my_cleanup(void)
{
  printk("<1> exiting symbol export demo module \n");
}


module_init(my_init);
module_exit(my_cleanup);

