/*******************************************************************************
* 
* 
*******************************************************************************/

#include <linux/module.h>
#include <linux/init.h>


MODULE_AUTHOR("DEPIK Systems");
MODULE_LICENSE("GPL");


void myexportfun();

/*******************************************************************************
* Name:init_module
* Description:
*******************************************************************************/
int my_init(void)
{
  printk("<1>" "Module to demo export of symbols\n");
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

void myexportfun()
{
  printk("<1>" "I am exported function\n");
}


//EXPORT_SYMBOL (myexportfun);
module_init(my_init);
module_exit(my_cleanup);

