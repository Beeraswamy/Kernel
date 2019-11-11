#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/net.h>
#include <linux/types.h>
#include <linux/socket.h>
#include <net/tcp.h>
#include <net/ip.h>
#include <linux/inet.h>
#include <net/protocol.h>
#include <net/sock.h>

#define PORT 7

int recv_buffer (struct socket *sock, char *buf, size_t size);
int send_buffer (struct socket *sock, const char *buf, const size_t len_in);
int kpid=-1;
static struct completion thr_exited;

int mythread (void *arg)
{
  struct socket *srvSock;
  struct socket *cliSock=0;
  struct sockaddr_in srvAddr;
  int n, error;
  char buf[1500];
	  

  wait_queue_head_t dummy_wq;
  daemonize ("tcp_echo");

  sigemptyset(&current->blocked);
  recalc_sigpending();
  init_waitqueue_head (&dummy_wq);

  if (0 > sock_create (PF_INET, SOCK_STREAM, IPPROTO_TCP, &srvSock, 0 ))
  {
    printk ("Error during creation of socket; terminating\n");
    goto exit;
  }

  srvAddr.sin_family      = AF_INET;
  srvAddr.sin_addr.s_addr = INADDR_ANY;
  srvAddr.sin_port        = htons (PORT);
  
  srvSock->sk->sk_reuse   = 1;

  if (0 > srvSock->ops->bind (srvSock, (struct sockaddr *) &srvAddr,
				  sizeof (srvAddr)))
  {
    printk ("ERROR BINDING SOCKET!!!!!!!\n");
    goto exit;
  }

  if (srvSock->ops->listen (srvSock, 1))
  {
    printk ("Error listening on socket\n");
    goto exit;
  }

accept:
  cliSock = sock_alloc ();
  if (cliSock == NULL)
  {
    printk ("Erro during creation cliSock\n");
    goto exit;
  }

  cliSock->type = srvSock->type;
  cliSock->ops  = srvSock->ops;

  printk("before accept \n");
  error = srvSock->ops->accept (srvSock, cliSock, O_RDWR);
  printk("after accept \n");

  if (signal_pending (current))
     goto exit;

  if (error < 0)
  {
    printk ("accept error  (%d)  accept\n", error);
    sock_release (cliSock);
    goto exit;
  }

  if (srvSock->sk->sk_state != TCP_LISTEN)
  {
    printk ("TCP DON´T LISTEN!!!\n");
    sock_release (cliSock);
    goto accept;
  }


  while(1)
  {
    n = recv_buffer (cliSock, buf, 1500);
    if(n <= 0)
    {
      printk("socket closed\n");
      sock_release (cliSock);
      cliSock = NULL;
      goto accept;
    }
    send_buffer(cliSock, buf, n);
    if (signal_pending (current))
      goto exit;
  }

exit:
  if(cliSock)
  {
    printk("releasing cliSock\n");
    sock_release(cliSock);
  }
  if(srvSock)
  {
    printk("releasing srvSock\n");
    sock_release(srvSock);
  }

  complete_and_exit (&thr_exited, 0);
}
/******************************************************************************
 *
 *****************************************************************************/
int send_buffer (struct socket *sock, const char *buf, const size_t len_in)
{
  struct msghdr msg;
  mm_segment_t oldfs;
  struct iovec iov;
  int len;

  if (!sock->sk)
  {
    printk ("send_buffer: invalid socket\n");
    return -ECONNRESET;
  }

  msg.msg_name = 0;
  msg.msg_namelen = 0;
  msg.msg_iov = &iov;
  msg.msg_iovlen = 1;
  msg.msg_control = NULL;
  msg.msg_controllen = 0;
  msg.msg_flags = MSG_DONTWAIT | MSG_NOSIGNAL;
  msg.msg_iov->iov_base = (char *) buf;
  msg.msg_iov->iov_len = (__kernel_size_t) len_in;

  oldfs = get_fs ();
  set_fs (KERNEL_DS);
  len = sock_sendmsg (sock, &msg, (size_t) (len_in));
  set_fs (oldfs);

  return len;
}

/******************************************************************************
 *
 *****************************************************************************/
int recv_buffer (struct socket *sock, char *buf, size_t size)
{
  struct msghdr msg;
  mm_segment_t oldfs;
  struct iovec iov;
  int len;


  if (!sock->sk)
  {
    printk ("recv_buffer: invalid socket\n");
    return -ECONNRESET;
  }

  msg.msg_name = 0;
  msg.msg_namelen = 0;
  msg.msg_iov = &iov;
  msg.msg_iovlen = 1;
  msg.msg_control = NULL;
  msg.msg_controllen = 0;
  msg.msg_flags = 0;
  msg.msg_iov->iov_base = (char *) buf;
  msg.msg_iov->iov_len = (__kernel_size_t) size;

  oldfs = get_fs ();
  set_fs (KERNEL_DS);
  //len = sock_recvmsg (sock, &msg, size, MSG_PEEK);
  len = sock_recvmsg (sock, &msg, size, 0);
  set_fs (oldfs);
  printk("len %d\n", len);

  return len;
}

static int hello_init(void)
{
  printk(KERN_ALERT "tcp echo server in kernel\n");
  init_completion (&thr_exited);
  kpid = kernel_thread (mythread, 0, CLONE_FS | CLONE_FILES | CLONE_SIGHAND);
  printk("Kernel thread created pid %d\n", kpid);
  return 0;
}

static void hello_exit(void)
{
  int ret;
  printk("killing kernel thread \n");
  ret = kill_proc (kpid, SIGTERM, 1);
  printk("return value %d\n", ret);
  wait_for_completion (&thr_exited);
		
  printk(KERN_ALERT "Simple kernel thread module unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR ("Vamsi Rajulapudi<vamsi.rajulapudi@gmail.com>");
MODULE_DESCRIPTION ("tcp echo server in kernel");
MODULE_LICENSE ("GPL");
