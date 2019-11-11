
#obj-m += expmod.o
#obj-m += stackmod.o

obj-m += export.o
export-objs := expmod.o stackmod.o

#Obj-m := module.o
#module-objs := file1.o file2.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
#	make -C /usr/src/linux-2.6.30 SUBDIRS=`pwd` modules

clean:
	rm -f *.o *.ko *.mod.c
