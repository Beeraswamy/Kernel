obj-m += simpchar_block.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
#	make -C /usr/src/linux-2.6.30 SUBDIRS=`pwd` modules

clean:
	rm -f *.o *.ko *.mod.c
