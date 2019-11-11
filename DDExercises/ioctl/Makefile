obj-m += ioctl_exmp.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	gcc ioctl_cp3get.c -o ioctl_cp3get
	gcc ioctl_cp3set.c -o ioctl_cp3set
	gcc ioctl_test.c -o ioctl_test

clean:
	rm -f *.o *.ko *.mod.c
