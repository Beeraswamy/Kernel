#include<stdio.h>
main()
{
int filedes[2];
if (pipe(filedes) == -1) /* Create the pipe */
perror("pipe"); 
switch (fork()) { /* Create a child process */
getcpid();
case -1: 
perror("fork"); 
case 0: /* Child */
if (close(filedes[1]) == -1)
perror("close");
/* Close unused write end */
/* Child now reads from pipe */
break;
default: /* Parent */
if (close(filedes[0]) == -1)
perror("close");
/* Close unused read end */
/* Parent now writes to pipe */
break;
}
}
