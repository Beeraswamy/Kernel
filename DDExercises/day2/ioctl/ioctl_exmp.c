#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/ioport.h>
#include <linux/errno.h>
#include <linux/ioctl.h>
#include <asm/io.h>
#include <linux/cdev.h>
#include "mydevioctl.h" 

MODULE_AUTHOR("VAMSI TECH");
MODULE_LICENSE("GPL");

static int mydev_open(struct inode *inode, struct file *file);
static int mydev_close(struct inode *inode, struct file *file);
static ssize_t mydev_read(struct file *file, char *buf, size_t count,
                          loff_t *offset);
static ssize_t mydev_write(struct file *file, const char *buf, size_t count,
                           loff_t *offset);

static int mydev_ioctl(struct inode* inode, struct file *file, 
                       unsigned int cmd, unsigned long arg);

static int cparam1,cparam2,cparam3;

#define MYDEV_MAJOR_NUM   42
#define MYDEV_MINOR_NUM   0
#define MYDEV_NO_DEVS     10
#define MYDEV_NAME        "mytstdev"

struct cdev mycdev;

static struct file_operations mydev_ops =
{
  .read    = mydev_read,
  .write   = mydev_write,
  .ioctl   = mydev_ioctl,
  .open    = mydev_open,
  .release = mydev_close,
};

/*******************************************************************************
* Name:init_module
* Description:
*******************************************************************************/
int mydev_init(void)
{
  int res=0;
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
void mydev_cleanup(void)
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
  return (ssize_t)1;
}

/*******************************************************************************
* Name:mydev_write
* Description:
*******************************************************************************/
static int mydev_write(struct file * file, const char * buf,
                       size_t count,loff_t * offset)
{
  return 1;
}

/*******************************************************************************
* Name: mydev_ioctl
* Description:
*******************************************************************************/
static int mydev_ioctl(struct inode* inode, struct file *file, 
                       unsigned int cmd, unsigned long arg)
{
  int ret;

  switch(cmd)
  {
    case MYDEV_GET_CP1: 
      ret = __put_user(cparam1, (unsigned char*) arg);
      break;

    case MYDEV_SET_CP2: 
      ret = __get_user(cparam2, (unsigned char*) arg);
      break;

    case MYDEV_SET_CP3: 
      ret = __get_user(cparam3, (unsigned char*) arg);
      break;

    case MYDEV_GET_CP3: 
      ret = __put_user(cparam3, (unsigned char*) arg);
      break;
    default:
      return -1;
  }

  return ret;
}
 

module_init(mydev_init);
module_exit(mydev_cleanup);

