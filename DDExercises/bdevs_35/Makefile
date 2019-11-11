obj-m += lab2_block.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
