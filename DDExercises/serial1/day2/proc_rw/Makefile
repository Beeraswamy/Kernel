obj-m +=  proc_rw.o

all:
	make -C /home/sureshv1/kernels/linux-2.6.12 SUBDIRS=`pwd` 

clean:
	rm -f *.o *.ko *.mod.c
