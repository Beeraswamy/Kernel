#include<unistd.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	/*int shmget(key_t key, size_t size, int shmflg);
	void *shmat(int shm_id, const void *shm_addr, int shmflg);
	int shmctl(int shm_id, int cmd, struct shmid_ds *buf);
	int shmdt(const void *shm_addr); */
        struct shmid_ds buf;
	//key_t k=10;
	size_t s=20;
	int sid;
	sid= shmget((key_t)10,s,0666|IPC_CREAT);
	printf("Sh mem ID : %d\n", sid);

	int *atch;
	atch=shmat(sid, 0,0);
        printf("0x%x\n",atch);

        int con;
	con= shmctl(sid,IPC_STAT, &buf);
	printf("Control : %d\n", con);

	printf("\n\n");
	exit(0);
}
