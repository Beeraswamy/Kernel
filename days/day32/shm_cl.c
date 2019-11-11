#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SZ     20

main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    key = 10;

    if ((shmid = shmget(key, SZ, 0666)) < 0)
    {
        printf("shmget");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1)
    {
        printf("shmat");
        exit(1);
    }

    for (s = shm; *s != NULL; s++)
        printf("%c",*s);
    putchar('\n');

    *shm = 'A';

    exit(0);
}
