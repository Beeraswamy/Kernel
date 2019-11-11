#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/ioport.h>

MODULE_AUTHOR("VAMSI TECH");
MODULE_LICENSE("GPL");

#define MOD_VERSION "1.0"
#define MODULE_NAME "Accessing I/O Port"

#define HW_LEN 80

#define SPP_IOBASE        0x378
#define SPP_NR_PORTS      0x8
#define SPP_INT_ENABLE    0x10 
#define SPP_DATA_PORT     SPP_IOBASE + 0 
#define SPP_CONTROL_PORT  SPP_IOBASE + 2 



static struct proc_dir_entry *ledkey_file;

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static int hextobin(char ch, unsigned char *pval)
{
  if( (ch >= '0') && (ch <= '9'))
  {
    *pval = (ch - '0');
    return 1;
  }
  if( (ch >= 'A') && (ch <= 'F'))
  {
    *pval = (10 + ch - 'A');
    return 1;
  }
  if( (ch >= 'a') && (ch <= 'f'))
  {
    *pval = (10 + ch - 'a');
    return 1;
  }
  return 0;
}

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static int proc_read_ledkey(char *page, char **start, off_t off,
                                int count, int *eof, void *data)
{
  int len;
  len = sprintf(page,"status = %x\n",inb(0x379));
  return len;
}

/*******************************************************************************
* Name:proc_write_ledkey
* Description:
*******************************************************************************/
static int proc_write_ledkey(struct file *file, const char *buffer, 
                                unsigned long count, void *data)
{
  int len;  
  unsigned char byteVal, nibLo, nibHi;

  char value[HW_LEN];

  if(count > HW_LEN)
    len = HW_LEN;
  else
    len = count;

  if (copy_from_user(value, buffer,len))
  {
    return -EFAULT;
  }

  if(hextobin(value[0],&nibHi))
  {
    if(hextobin(value[1],&nibLo))
    {
       byteVal = (nibHi << 4) | nibLo;
       outb(byteVal,0x378);
    }
  }
  return len;
}

/*******************************************************************************
* Name:init_ledkey
* Description:
*******************************************************************************/
static int __init init_ledkey(void)
{

  if(!request_region(SPP_IOBASE, SPP_NR_PORTS, "my_SPP"))
  {
    printk(KERN_INFO "can't get I/O port address 0x%x\n",SPP_IOBASE);
    return -1;
  }


  ledkey_file = create_proc_entry("ledkey",0666, NULL);

  if(ledkey_file == NULL)
  {
    return -ENOMEM;
  }

  ledkey_file->data       = 0;
  ledkey_file->read_proc  = &proc_read_ledkey;
  ledkey_file->write_proc = &proc_write_ledkey;
  ledkey_file->owner      = THIS_MODULE;

  printk("<1>%s %s initialized\n",MODULE_NAME, MOD_VERSION);
  return 0;
}

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static void __exit cleanup_ledkey(void)
{
  release_region(SPP_IOBASE,SPP_NR_PORTS);
  remove_proc_entry("ledkey",NULL);
  printk("<1>%s %s removed\n",MODULE_NAME, MOD_VERSION);
}

module_init(init_ledkey);
module_exit(cleanup_ledkey);


