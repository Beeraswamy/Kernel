#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>

#define TEST_DEV "myIntDev"
#define MY_MODULE_VERSION "1.0"
#define MODULE_NAME "MyIntDev module"

#define HW_LEN 80
#define IRQ_7 7

#define SPP_IOBASE        0x378
#define SPP_NR_PORTS      0x8
#define SPP_INT_ENABLE    0x10 
#define SPP_DATA_PORT     SPP_IOBASE + 0 
#define SPP_STATUS_PORT   SPP_IOBASE + 1 
#define SPP_CONTROL_PORT  SPP_IOBASE + 2 

MODULE_LICENSE("GPL");

#define MYDEV_MAJOR_NUM   42
#define MYDEV_NAME        "mykeys"


void do_mytasklet (unsigned long);
DECLARE_TASKLET (my_tasklet, do_mytasklet, 0);

static int isrCnt = 0; 

/*******************************************************************************
* Name:do_mytasklet
* Description:
*******************************************************************************/
void do_mytasklet (unsigned long unused)
{
  printk("This message from tasklet\n");
}
/*******************************************************************************
* Name:myIntHandler
* Description:
*******************************************************************************/
static irqreturn_t myIntHandler(int irq, void *dev_id, struct pt_regs *regs)
{
  tasklet_schedule(&my_tasklet);
  isrCnt++;
  return IRQ_HANDLED;
}
/*******************************************************************************
* Name:init_ledkey
* Description:
*******************************************************************************/
static int __init init_myKeyDev(void)
{
  int rv;

  if (!request_region(SPP_IOBASE, SPP_NR_PORTS, TEST_DEV))
  {
    printk(KERN_INFO "can't get I/O port address 0x%x\n",SPP_IOBASE);
    return -1;
  }



  /*** Register interrupt handler ***/
  rv = request_irq(IRQ_7, myIntHandler, SA_INTERRUPT, TEST_DEV,NULL);
  if(rv)
  {
    printk("<1>Can't get interrupt %d\n",IRQ_7);
  }
  /*** Enable parallel port interrupt reporting ***/
  outb(SPP_INT_ENABLE, SPP_CONTROL_PORT);

  printk("<1>%s %s initialized\n",MODULE_NAME, MY_MODULE_VERSION);
  return 0;
}

/*******************************************************************************
* Name:
* Description:
*******************************************************************************/
static void __exit cleanup_myKeyDev(void)
{
  /*** disable parallel port interrupt reporting ***/
  outb(0x00, SPP_CONTROL_PORT);

  /*** Free the ioports ***/
  release_region(SPP_IOBASE,SPP_NR_PORTS);

  /*** Free the interrupt ***/
  free_irq(IRQ_7,NULL);

  printk("<1>%s %s removed\n",MODULE_NAME, MY_MODULE_VERSION);
}

module_init(init_myKeyDev);
module_exit(cleanup_myKeyDev);


