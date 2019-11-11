#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/ioport.h>
#include <linux/errno.h>
#include <linux/cdev.h>
#include <linux/sched.h>

static int mydev_open(struct inode *inode, struct file *file);
static int mydev_close(struct inode *inode, struct file *file);
static ssize_t mydev_read(struct file *file, char *buf, size_t count,
                          loff_t *offset);
static ssize_t mydev_write(struct file *file, const char *buf, size_t count,
                           loff_t *offset);

static unsigned int mydev_poll(struct file *file, poll_table *wait);
static int mydev_fasync(int fd, struct file *fp, int mode);

MODULE_AUTHOR("VAMSI TECH");
MODULE_LICENSE("GPL");

#define MAX_BUF_SIZE    0x1000

struct cdev mycdev;
static unsigned char mydevbuf[MAX_BUF_SIZE];
static int writeCnt = 0;

struct fasync_struct *async_queue;
DECLARE_WAIT_QUEUE_HEAD(wq);

#define MYDEV_MAJOR_NUM   42
#define MYDEV_MINOR_NUM   0
#define MYDEV_NO_DEVS     10
#define MYDEV_NAME        "mytstdev"


static struct file_operations mydev_ops =
{
  .read    =mydev_read,
  .write   =mydev_write,
  .open    =mydev_open,
  .release =mydev_close,
  .poll    =mydev_poll,
  .fasync  =mydev_fasync,
};

/*******************************************************************************
* Name:init_module
* Description:
*******************************************************************************/
int init_module(void)
{
  int res;
  dev_t devno = 0;

  devno = MKDEV(MYDEV_MAJOR_NUM, MYDEV_MINOR_NUM);
  res = register_chrdev_region(devno, MYDEV_NO_DEVS, MYDEV_NAME);
  if(res<0)
  {
    printk("<1>" "Registration Error %d\n",res);
    return res;
  }
  else
  {
    printk("<1>" "Registration success %d\n",res);
  }

  cdev_init(&mycdev, &mydev_ops);
  mycdev.owner = THIS_MODULE;
  res = cdev_add(&mycdev, devno, 1);
  if(res)
    goto fail_exit;
  printk("cdev added successully %d\n",res);
  return 0;

fail_exit:
  unregister_chrdev_region(devno, MYDEV_NO_DEVS);
  return res;


}

/*******************************************************************************
* Name:cleanup_module
* Description:
*******************************************************************************/
void cleanup_module(void)
{

  dev_t devno = MKDEV(MYDEV_MAJOR_NUM, MYDEV_MINOR_NUM);

  cdev_del(&mycdev);

  unregister_chrdev_region(devno, MYDEV_NO_DEVS);

  printk(KERN_ALERT "char dev unloaded successfully \n");

}

/*******************************************************************************
* Name:mydev_open
* Description:
*******************************************************************************/
static int mydev_open(struct inode *inode, struct file * file)
{
  try_module_get(THIS_MODULE);
  if (file->f_mode & FMODE_READ)
    printk("<1>" "open for read\n");
  if (file->f_mode & FMODE_WRITE)
    printk("<1>" "opened for write\n");
  
  return 0;	
}


/*******************************************************************************
* Name:mydev_close
* Description:
*******************************************************************************/
static int mydev_close(struct inode *inode, struct file * file)
{
  module_put(THIS_MODULE);
  printk("<1>" "device closed\n");
  return 0;
}


/*******************************************************************************
* Name:mydev_read
* Description:
*******************************************************************************/
static ssize_t mydev_read(struct file *file, char * buf,
                          size_t count,  loff_t * offset)
{
  wait_event_interruptible(wq, writeCnt > 0);
  if (count>writeCnt) 
    count=writeCnt;
  copy_to_user(buf,mydevbuf,count);
  writeCnt = 0;
	
  printk("<1>" "read called \n");
  return (ssize_t)count;
}

/*******************************************************************************
* Name:mydev_write
* Description:
*******************************************************************************/
static ssize_t mydev_write(struct file * file, const char * buf,
                       size_t count,loff_t * offset)
{
  if (count > MAX_BUF_SIZE) 
    count = MAX_BUF_SIZE;
  copy_from_user(mydevbuf,buf,count);
  printk("<1>" "write called \n");
  writeCnt =count;
  wake_up_interruptible(&wq);
  if(async_queue)
    kill_fasync(&async_queue,SIGIO,POLL_IN);
  return count;
}

static unsigned int mydev_poll(struct file *file, poll_table *wait)
{
  unsigned int mask = 0;

  printk("<1>" "poll called \n");
  poll_wait(file, &wq, wait);
  printk("<1>" "poll 1 \n");
if(writeCnt)
    mask = mask | POLLIN | POLLRDNORM;
  //if(writeCnt < MAX_BUF_SIZE)
  //  mask = mask | POLLOUT | POLLWRNORM;
printk("<1>" "poll 2 \n");
  return mask;
}

static int mydev_fasync(int fd, struct file *fp, int mode)
{
  printk("<1>" "Async called \n");
  return fasync_helper(fd,fp,mode,&async_queue);
}


