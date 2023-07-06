#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define KEY 123

int main(){
        int shm;
        void *num;
        shm=shmget(KEY,8000,IPC_CREAT | 0666);
	if(shm>=0)
	{
	printf("Shard memory segement created successfully %d\n",shm);
	}
        num=shmat(shm,(const void *)0,0);
        printf("%s\n",num);
	int b= shmdt(num);
	printf("%s\n",num);
}
