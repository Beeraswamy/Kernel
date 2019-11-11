
This sample module program shows how to implement a driver which
blocks the application process when no data is available. The blocked
application process will get unblocked when another application writes
data to this device.

One can test this driver using 'devread' and 'devwrite' programs.
After loading the driver run 'devread' program from virtual terminal.
This program should block, as there is no data in the device buffer.

Now from another virtual terminal, run the 'devwrite' program. This
program writes given data to the device buffer. Now the previous program
'devread' should comeout from read() blocking and shold display the
same string as we write here.

Understanding select and other function calls
http://www.mkssoftware.com/docs/man3/select.3.asp
