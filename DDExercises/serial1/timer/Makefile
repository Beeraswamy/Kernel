obj-m += timer.o

all:
	make -C /tftpboot/linux-2.6.12 SUBDIRS=`pwd` modules

clean:
	rm -f *.o *.ko *.mod.c
