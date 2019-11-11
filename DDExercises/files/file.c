#include <linux/module.h>	/* Needed by all modules */
//#include <linux/kernel.h>	/* Needed for KERN_ALERT */
#include <linux/fs.h>
#include <asm/uaccess.h>

int init_module(void)
{
  int i,j;
  struct file *myfilp;
  char buffer[20];
  mm_segment_t oldfs;
  int len=0;
  loff_t offset=0;


  printk("Accessing file module\n");

  myfilp = filp_open("/root/myfile", O_WRONLY|O_CREAT, 0);
  if (IS_ERR(myfilp)) 
  {
     printk(KERN_ERR "Fail to open file");
     return -1;
  }
  sprintf(buffer, "hellohello");
  //oldfs = get_fs(); set_fs(KERNEL_DS);
  len = myfilp->f_op->write(myfilp,buffer,10,&offset);
  //set_fs(oldfs);
  printk("offset %d len %d \n", offset, len);

  return 0;
}

void cleanup_module(void)
{
  printk(KERN_ALERT "Goodbye \n");
}
