#define MYDEV_MAGIC  0xd0

#define  MYDEV_GET_CP1     _IOR(MYDEV_MAGIC,1,int )
#define  MYDEV_SET_CP2     _IOW(MYDEV_MAGIC,2,int)
#define  MYDEV_SET_CP3     _IOW(MYDEV_MAGIC,3,int)
#define  MYDEV_GET_CP3     _IOR(MYDEV_MAGIC,4,int)
