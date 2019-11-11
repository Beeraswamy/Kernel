
obj-m +=mytasklet.o

KDIR= /lib/modules/$(shell uname -r)/build

all:
	make -C /lib/modules/$(shell uname -r)/build SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko mo* Mo* *.mod.c
