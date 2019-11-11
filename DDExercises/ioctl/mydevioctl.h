#define MYDEV_MAGIC  0xd0

#define  MYDEV_GET_CP1     	_IOR(MYDEV_MAGIC,1,int )//1st argument is magic no,2nd is cmd no, 3rd is size of command);
#define  MYDEV_SET_CP2     	_IOW(MYDEV_MAGIC,2,int)
#define  MYDEV_SET_CP3     	_IOW(MYDEV_MAGIC,3,char)
#define  MYDEV_GET_CP3     	_IOR(MYDEV_MAGIC,4,int)
#define  MYDEV_SET_GET_CP4      _IOWR(MYDEV_MAGIC,5,int)
