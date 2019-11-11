/*  
 *  Demonstrates momory allocation
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/vmalloc.h>
#define DRIVER_AUTHOR "DEPIK"
#define DRIVER_DESC   "sample memory allocation"

void   *tstmem;
void   *tstmem2;
void   *tstmem3;

static int __init init_hello(void)
{
  printk(KERN_ALERT "Memory allocation example is loaded \n");
  tstmem = kmalloc(1024, GFP_KERNEL); 
  printk(KERN_ALERT "Allocated memory with kmalloc is 0x%x\n", 
                                         (unsigned int)tstmem);
  tstmem2 = vmalloc(1024); 
  printk(KERN_ALERT "Allocated memory with vmalloc is 0x%x\n", 
                                         (unsigned int)tstmem2);
  tstmem3 = (void *)get_zeroed_page(GFP_ATOMIC); 
  printk(KERN_ALERT "Allocated memory with get_zeroed_page 0x%x\n", 
                                         (unsigned int)tstmem3);
  return 0;
}

static void __exit cleanup_hello(void)
{
  kfree(tstmem);
  vfree(tstmem2);
  free_page((unsigned long)tstmem3);
  printk(KERN_ALERT "Goodbye \n");
  
}

module_init(init_hello);
module_exit(cleanup_hello);


MODULE_LICENSE("GPL");

/*
 *  * Or with defines, like this:
 *   */
MODULE_AUTHOR(DRIVER_AUTHOR);	/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */

