
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/errno.h>

#define MYDEV_NAME    "myprocEntry"

MODULE_AUTHOR("VAMSI TECH");
MODULE_LICENSE("GPL");


static int mydev_proc_read(char *buf, char **start, off_t offset, 
                           int count, int *eof, void *data);

/*******************************************************************************
* Name:init_module
* Description:
*******************************************************************************/
int my_init(void)
{
  printk("<1>" "Module to demo creation of proc entry\n");
  create_proc_read_entry(MYDEV_NAME,       //name
                         0,                //mode
                         0,                // parent dir
                         mydev_proc_read,  //read funnction
                         0);               //client data or private data 
  return 0;
}

/*******************************************************************************
* Name:cleanup_module
* Description:
*******************************************************************************/
void my_cleanup(void)
{
  printk("<1> Exiting proc demo module \n");
  remove_proc_entry(MYDEV_NAME,0);
}

/*******************************************************************************
* Name:mydev_proc_read
* Description:
*******************************************************************************/
static int mydev_proc_read(char *buf, char **start, off_t offset, 
                           int count, int *eof, void *data)
{
  int len;

  len = sprintf(buf,"This is message coming to you from test module\n");
  *eof = 1;
	printk("<1> mydev_proc_read A call is made from user space \n");
  return len;
}

module_init(my_init);
module_exit(my_cleanup);


