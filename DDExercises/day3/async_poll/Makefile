obj-m += simpchar_async.o

all:
	
	gcc devread.c -o devread
	gcc devwrite.c -o devwrite
	gcc asynread.c -o asynread
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean:
	rm -f devread devwrite 	asynread
