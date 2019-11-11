
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/pci.h>

#define MYDEV_NAME    "myprocpci"

MODULE_AUTHOR("VAMSI TECH");
MODULE_LICENSE("GPL");


static int my_proc_read(char *buf, char **start, off_t offset, 
                           int count, int *eof, void *data);

/*******************************************************************************
* Name:init_module
* Description:
*******************************************************************************/
int my_init(void)
{
  printk("<1>" "Module to demo creation of proc entry\n");
  create_proc_read_entry(MYDEV_NAME,0,0,my_proc_read,0);
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
static int my_proc_read(char *buf, char **start, off_t offset, 
                           int count, int *eof, void *data)
{
  int len;
  struct pci_dev *pdev = pci_get_device(0x10ec,0x8139,0);
  if(pdev)
  {
    len = sprintf(buf,"IOBASE 0x%0x 0x%0x IRQ %d\n",
                           (unsigned int )pci_resource_start(pdev, 0),
                           (unsigned int )pci_resource_end (pdev, 0),pdev->irq);
  }
  else
  {
    len = sprintf(buf,"failed to get IOBASE\n");
  }
  *eof = 1;
  return len;
}

module_init(my_init);
module_exit(my_cleanup);


