#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>

#define TEST_DEV "myIntDev"
#define MODULE_NAME "MyIntDev module"
#define MY_MODULE_VERSION "1.0"

#define HW_LEN 80
#define IRQ_7 7

#define SPP_IOBASE        0x378
#define SPP_NR_PORTS      0x8
#define SPP_INT_ENABLE    0x10 
#define SPP_DATA_PORT     SPP_IOBASE + 0 
#define SPP_CONTROL_PORT  SPP_IOBASE + 2 

MODULE_LICENSE("GPL");

static struct proc_dir_entry *ledkey_file;
static int isrCnt = 0; 
static unsigned char ledVal = 1;

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static int proc_read_ledkey(char *page, char **start, off_t off,
                                int count, int *eof, void *data)
{
  int len;
  len = sprintf(page,"Interrupts count = %x\n",isrCnt);
  return len;
}


/*******************************************************************************
* Name:myIntHandler
* Description:
*******************************************************************************/
static irqreturn_t myIntHandler(int irq, void *dev_id, struct pt_regs *regs)
{
  ledVal = ledVal << 1;

  if(ledVal == 0)
    ledVal = 1;

  outb(ledVal, 0x378);
  isrCnt++;
  return IRQ_HANDLED;
}
/*******************************************************************************
* Name:init_ledkey
* Description:
*******************************************************************************/
static int __init init_ledkey(void)
{
  int rv;

  if(!request_region(SPP_IOBASE, SPP_NR_PORTS, TEST_DEV))
  {
    printk(KERN_INFO "can't get I/O port address 0x%x\n",SPP_IOBASE);
    return -1;
  }

  ledkey_file = create_proc_entry(TEST_DEV,0666, NULL);

  if(ledkey_file == NULL)
  {
    return -ENOMEM;
  }

  ledkey_file->data       = 0;
  ledkey_file->read_proc  = &proc_read_ledkey;
  ledkey_file->write_proc = NULL; 
  ledkey_file->owner      = THIS_MODULE;

  /*** Register interrupt handler ***/
  rv = request_irq(IRQ_7, myIntHandler, SA_INTERRUPT, TEST_DEV,NULL);
  if(rv)
  {
    printk("<1>Can't get interrupt %d\n",IRQ_7);
  }
  /*** Enable parallel port interrupt reporting ***/
  outb(SPP_INT_ENABLE, SPP_CONTROL_PORT);

  outb(ledVal, SPP_DATA_PORT);

  printk("<1>%s %s initialized\n",MODULE_NAME, MY_MODULE_VERSION);
  return 0;
}

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static void __exit cleanup_ledkey(void)
{
  /*** disable parallel port interrupt reporting ***/
  outb(0x00, SPP_CONTROL_PORT);

  /*** Free the ioports ***/
  release_region(SPP_IOBASE,SPP_NR_PORTS);
  /*** Free the interrupt ***/
  free_irq(IRQ_7,NULL);

  /*** Remov /proc filesystem entries ***/
  remove_proc_entry(TEST_DEV,NULL);
  printk("<1>%s %s removed\n",MODULE_NAME, MY_MODULE_VERSION);
}

module_init(init_ledkey);
module_exit(cleanup_ledkey);


