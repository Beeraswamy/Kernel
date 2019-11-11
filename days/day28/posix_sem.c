#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>

#define MAX_MSG_LEN 256

sem_t sem1;
char msg1[MAX_MSG_LEN] = "1";
char msg2[MAX_MSG_LEN] = "2";
sem_t sem2;

void * thrdFun1(void*);
//void * thrdFun2(void*);

void toggleCase(char *);

int main()
{
  pthread_t thrd1;
  char argmsg1[] = "Thread1: ";
  int res;
  int thNum;
  
  res = pthread_create(&thrd1, NULL, thrdFun1, (char *) argmsg1);
  res = sem_init(&sem1, 0, 0);
  res = sem_init(&sem2, 0, 0);
  
  while(1)
  {
   printf("Enter message to send to thread\n");
   __fpurge(stdin); 
   fgets(msg1, MAX_MSG_LEN,stdin);
   
   msg1[strlen(msg1) - 1] =0;
   sem_post(&sem1);

   sem_wait(&sem2);
   printf("RESP msg: %s\n", msg2);
  }
}

void * thrdFun1(void *arg)
{
  printf("I am %s\n", arg);
  while(1)
  {
   sem_wait(&sem1);
   strcpy(msg2, msg1);
   toggleCase(msg2);
   sem_post(&sem2);
  }
}
void toggleCase(char *msg)
{
  int i=0;
  while(msg[i])
  {
   msg[i] = msg[i]^32;
   i++;
  }
}

