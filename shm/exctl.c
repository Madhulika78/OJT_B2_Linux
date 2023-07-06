#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define KEY 123
struct shmid_ds buff;
int main(){
	int shm;
	void *num;
	shm=shmget(KEY,8000,IPC_CREAT | 0666);

	int b=shmctl(shm,IPC_STAT,&buff);
	printf("Last attach time: %d\n",buff.shm_atime);
	printf("Last detach time: %d\n",buff.shm_dtime);
	printf("No. of current attaches: %d\n",buff.shm_nattch);

}

