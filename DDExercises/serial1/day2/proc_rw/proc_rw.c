#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <asm/io.h>

MODULE_AUTHOR("DEPIK Systems");
MODULE_LICENSE("GPL");

#define HW_LEN 80
char  mydata[100];

static struct proc_dir_entry *myproc_file;

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static int myproc_read(char *page, char **start, off_t off,
                                int count, int *eof, void *data)
{
  int len;
  len = sprintf(page,"%s\n",mydata);
  return len;
}

/*******************************************************************************
* Name:proc_write_ledkey
* Description:
*******************************************************************************/
static int myproc_write(struct file *file, const char *buffer, 
                                unsigned long count, void *data)
{
  int len;  


  if(count > 100)
    len = 100;
  else
    len = count;

  if (copy_from_user(mydata, buffer,len))
  {
    return -EFAULT;
  }

  return len;
}

/*******************************************************************************
* Name:init_ledkey
* Description:
*******************************************************************************/
static int __init init_mymod(void)
{
  myproc_file = create_proc_entry("mytstproc",
                                   0666,  // mode
                                   NULL); // parent dir

  if(myproc_file == NULL)
  {
    return -ENOMEM;
  }

  myproc_file->data       = 0;
  myproc_file->read_proc  = &myproc_read;
  myproc_file->write_proc = &myproc_write;
  myproc_file->owner      = THIS_MODULE;

  printk("<1>proc demo initialized\n");
  return 0;
}

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static void __exit cleanup_mymod(void)
{
  remove_proc_entry("mytstproc",NULL);
  printk("<1>proc demo removed\n");
}

module_init(init_mymod);
module_exit(cleanup_mymod);


