#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>

#define SZ     20

main()
{
    char c;
    int shmid,i;
    key_t key;
    char *shm, *s,*name;
    key = 10;

    if ((shmid = shmget(key, SZ, IPC_CREAT | 0666)) < 0)
    {
        printf("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) 
    {
        printf("shmat");
        exit(1);
    }

    s = shm;
    name="arindam";
    for(i=0;i<7;i++)
    {
     *s++=name[i];
    } 
    *s = NULL;

    while (*shm != 'A')
          sleep(1);
    for (s = shm; *s != NULL; s++)
        printf("%c",*s);
    putchar('\n');

    exit(0);
}


