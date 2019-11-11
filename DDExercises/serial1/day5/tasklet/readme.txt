Task queues are gone in 2.5 onwards.

We used task queues in BH demo. In this BH demo, we added a 
task(function) to immediate task queue and triggered Immediate BH.

As task queues are not going to be avaialbe, this demo show the
usage of tasklets.

Tasklet structure is declared first.

  DECLARE_TASKLET (my_tasklet, do_mytasklet, 0);

Then it scheduled from ISR as shown below:

  tasklet_schedule(&my_tasklet);

