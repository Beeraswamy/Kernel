This folder contains sample driver module program.
This driver when loaded register itself as  a character device.

1. Build the module with make command.

   # make

2. Create two character device files with different minor numbers.

   # mknod /dev/mydev  c  42  0 

To test this driver following application programs developed.

  1. devtest.c
  2. devread.c
  3. devwrite.c

3. Build the test application programs.
   Each of the above is independent C program. You can compile the
   above programs as below.  

    $ cc  devtest.c  -o devtest
    $ cc  devread.c  -o devread
    $ cc  devwrite.c -o devwrite

The 'devtest' program opens the device, writes some data and reads
the data and prints the read data. Use can verify that the written
data and read are same or not.

The 'devwrite' program takes the one line of text data from the user
and writes it to the device. 

The 'devread' program is used to read the data from the device and
display. This program can be used to verify that the same data written
using 'devwrite' program is displayed or not.



