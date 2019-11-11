obj-m  +=tstkthread.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	rm -f *.o *.ko *.mod.c
