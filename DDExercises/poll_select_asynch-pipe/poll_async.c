#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/ioport.h>
#include <linux/errno.h>
#include <linux/semaphore.h>
#include <linux/sched.h>
MODULE_AUTHOR("VAMSI");
MODULE_LICENSE("GPL");

static int mydev_proc_read(char *buf, char **start, off_t offset, int count, int *eof, void *data);
static int mydev_open(struct inode *inode, struct file *file);
static int mydev_close(struct inode *inode, struct file *file);
static ssize_t mydev_read(struct file *file, char *buf, size_t count, loff_t *offset);
//static ssize_t mydev_write(struct file *file,const char *buf, size_t count, loff_t *offset);
static int mydev_write(struct file *file,const char *buf, size_t count, loff_t *offset);
static unsigned int mydev_poll(struct file *file, poll_table *wait);
static int mydev_fasync(int fd, struct file *fp, int mode);


#define MAX_BUF_SIZE 0x1000
#define MAX_Q_SIZE 100



typedef struct
{
	unsigned char q[MAX_Q_SIZE];
	unsigned int ri;
	unsigned int wi;
	unsigned int cnt;
}cq_t;

typedef struct 
{
	cq_t cq;
	struct semaphore sem;
	wait_queue_head_t rwq;
	wait_queue_head_t wwq;
	struct fasync_struct *async_queue;
}mypipe_t;

mypipe_t mypipe;

#define MYDEV_MAJOR_NUM 42
#define MYDEV_NAME "mypipe"

static struct file_operations mydev_ops =
{
	read:mydev_read,
	write:mydev_write,
	open:mydev_open,
	poll:mydev_poll,
	release:mydev_close,
	fasync:mydev_fasync,
};

/*****************************************************************************
*	Name: init_module
*****************************************************************************/
int mypipe_init(void)
{
	int res;
	sema_init(&mypipe.sem,1);
	init_waitqueue_head(&mypipe.wwq);
	init_waitqueue_head(&mypipe.rwq);
	
	res = register_chrdev(MYDEV_MAJOR_NUM, MYDEV_NAME, &mydev_ops);
	if(res < 0)
	{
		printk("<1>" "Registration error %d\n", res);
		return res;
	}
	else
	{
		printk("<1>" "Registration success %d\n", res);
	}
	create_proc_read_entry(MYDEV_NAME, 0, 0, mydev_proc_read,0);
	return 0;
}

/*****************************************************************************
*	Name: mypipe_cleanup
*****************************************************************************/
void mypipe_cleanup(void)
{
	unregister_chrdev(MYDEV_MAJOR_NUM, MYDEV_NAME);
	remove_proc_entry(MYDEV_NAME,0);
	printk(KERN_ALERT "good bye\n");
}

/*****************************************************************************
* Name: mydev_open
*****************************************************************************/
static int mydev_open(struct inode *inode, struct file *file)
{
	try_module_get(THIS_MODULE);
	if(file->f_mode & FMODE_READ)
		printk("<1>" "open for read\n");
	if(file->f_mode & FMODE_WRITE)
		printk("<1>" "opened for write\n");
	return 0;
}

/*****************************************************************************
*Name: mydev_close
*****************************************************************************/
static int mydev_close(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);
	printk("<1>" "device close");
	return 0;
}

/*****************************************************************************
*NameL: mydev_read
******************************************************************************/
static ssize_t mydev_read(struct file *file, char *buf, size_t count, loff_t *offset)
{
	int copylen, partlen;
	wait_event_interruptible(mypipe.rwq, mypipe.cq.cnt > 0);
	down_interruptible(&mypipe.sem);
	copylen = (count < mypipe.cq.cnt) ? count : mypipe.cq.cnt;
	
	if((mypipe.cq.ri + copylen) <= MAX_Q_SIZE)
	{
		copy_to_user(buf,mypipe.cq.q + mypipe.cq.ri, copylen);
	}
	else
	{
		partlen = MAX_Q_SIZE - mypipe.cq.ri;
		copy_to_user(buf,mypipe.cq.q + mypipe.cq.ri, partlen);
		copy_to_user(buf+partlen, mypipe.cq.q, copylen-partlen);
	}
	
	mypipe.cq.ri = (mypipe.cq.ri + copylen) % MAX_Q_SIZE;
	mypipe.cq.cnt -= copylen;
	up(&mypipe.sem);
	wake_up_interruptible(&mypipe.wwq);
	
	printk("<1>" "read called\n");
	return (ssize_t)copylen;
}

/*****************************************************************************
* Name mydev_write
*****************************************************************************/

//static int mydev_write(struct file *file, const char *buf, size_t count, loff_t offset)
static int mydev_write(struct file *file,const char *buf, size_t count, loff_t *offset)
{
	int avllen, copylen, partlen;
	int culen = count;
	
	while(culen)
	{
		wait_event_interruptible(mypipe.wwq, mypipe.cq.cnt < MAX_Q_SIZE);
		if(down_interruptible(&mypipe.sem))
			return -ERESTARTSYS;
		avllen = MAX_Q_SIZE - mypipe.cq.cnt;
		copylen = (culen <avllen) ? culen : avllen;
		if((mypipe.cq.wi + copylen) <= MAX_Q_SIZE)
		{
			copy_from_user(mypipe.cq.q+mypipe.cq.wi, buf, copylen);
		}
		else
		{
			partlen = MAX_Q_SIZE - mypipe.cq.wi;
			copy_from_user(mypipe.cq.q + mypipe.cq.wi, buf, partlen);
			copy_from_user(mypipe.cq.q,buf+partlen, copylen - partlen);
		}
		mypipe.cq.wi = (mypipe.cq.wi + copylen) % MAX_Q_SIZE;
		mypipe.cq.cnt += copylen;
		wake_up_interruptible(&mypipe.rwq);
		if(mypipe.async_queue)
			kill_fasync(&mypipe.async_queue,SIGIO,POLL_IN);
		
		culen = culen -copylen;
		printk("<1>" "write called\n");
	}
	up(&mypipe.sem);
	return count;
}

static unsigned int mydev_poll(struct file *file, poll_table *wait)
{
	unsigned int mask = 0;
	printk("<1>" "poll called\n");
	poll_wait(file, &mypipe.wwq, wait);
	printk("<1>" "poll 1\n");
	poll_wait(file, &mypipe.rwq, wait);
	printk("<1>" "poll 2\n");	
	if(mypipe.cq.cnt)
		mask = mask | POLLIN | POLLRDNORM;
	if(mypipe.cq.cnt < MAX_Q_SIZE)
		mask = mask | POLLOUT | POLLWRNORM;
	printk("<1>" "poll 3\n");	
	return mask;
}

static int mydev_fasync(int fd, struct file *fp, int mode)
{
	printk("<1>" "Async called\n");
	return fasync_helper(fd, fp, mode, &mypipe.async_queue);
}


/*****************************************************************************
*Name: mydev_proc_read
****************************************************************************/
static int mydev_proc_read(char *buf, char **start, off_t offset, int count, int *eof, void *data)
{
	int len;
	len = sprintf(buf, " ri = %d, wi = %d, cnt %d\n", mypipe.cq.ri, mypipe.cq.wi, mypipe.cq.cnt);
	*eof = 1;
	return len;
}

module_init(mypipe_init);
module_exit(mypipe_cleanup);
	
