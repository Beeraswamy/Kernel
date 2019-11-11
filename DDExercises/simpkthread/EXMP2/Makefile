obj-m :=thread.o
obj-m +=unblock_thread.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	
clean:
	rm -rf *.o *.ko *.mod.* .c* .t* test Module.symvers *.order *.markers
