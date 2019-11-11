/*******************************************************************************
* Following is the example usage insertion to set module parameters.
* $ insmod parmod.o myival=20 mysval="hello"
*******************************************************************************/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/moduleparam.h>


MODULE_AUTHOR("VAMSI TECH");
MODULE_LICENSE("GPL");

static int myival = 0;
//MODULE_PARM(myival, "i");
module_param(myival,int,0);
static char *mysval = "default string";
//MODULE_PARM(mysval, "s");
module_param(mysval,charp,0);

/*******************************************************************************
* Name:init_module
* Description:
*******************************************************************************/
int my_init(void)
{
  printk("<1>" "Module to demo module parameters\n");
  printk("Module parameters : ival = %d, sval = %s\n",myival,mysval);
  return 0;
}

/*******************************************************************************
* Name:cleanup_module
* Description:
*******************************************************************************/
void my_cleanup(void)
{
  printk("<1> exiting parameter demo module \n");
}

module_init(my_init);
module_exit(my_cleanup);

