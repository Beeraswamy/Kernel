

obj-m += simpchar.o

all:
	gcc devread.c -o devread
	gcc devwrite.c -o devwrite
	#gcc devtest.c -o devtest
	#make -C /usr/src/linux-2.6.12 SUBDIRS=`pwd` modules
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	
clean:
	rm -f devread devwrite devtest
	rm -f *.o *.ko *.mod.c
