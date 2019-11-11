CC=gcc
CFLAGS=-c 
all: hello

hello: file1.o file2.o file3.o
	$(CC) file1.o file2.o file3.o -o hello

file1.o: file1.c
	$(CC) $(CFLAGS) file1.c

file2.o: file2.c
	$(CC) $(CFLAGS) file2.c

file3.o: file3.c
	$(CC) $(CFLAGS) file3.c

clean:
	rm -rf *.o hello


