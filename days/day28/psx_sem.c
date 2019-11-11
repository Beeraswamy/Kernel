#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>


void *thr_fun(char *arg);
char mes[25] = "bye";
sem_t semid;

int main() {

	int semres, thres;
	pthread_t thrid;
	void *thr_fun(char *arg);
	void *thr_res;

	semres = sem_init(&semid, 0, 0);
	if(semres == -1)
		printf("Sem not created :\n");

	thres = pthread_create(&thrid, NULL, thr_fun, (char *)mes);
	if(thres != 0)
		printf("Thread is not created\n");
	
	printf("Entering into\n");

	sem_post(&semid);
	while(strncmp(mes, "bye", 3) == 0) {
		printf("Main thread :\n");
		gets(mes);
		sem_post(&semid);
	}
	
	pthread_join(thrid, &thr_res);
	printf("Thr result is %s\n", (char *)thr_res);

	exit(0);
}

void *thr_fun(char *arg) {
	sem_wait(&semid);
	while(1) {
		printf("U have entered %d char\n", strlen(arg));
		if(strncmp(mes, "bye", 3) == 0)
			break;
		sem_wait(&semid);
	}
	pthread_exit("Bye Maulik");
}

	
