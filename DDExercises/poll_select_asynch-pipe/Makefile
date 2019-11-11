obj-m += poll_async.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
