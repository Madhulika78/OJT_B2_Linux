#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<stdio.h>
#define KEY 1234

int main(){
	int sem;
	sem=semget(KEY, 1,IPC_CREAT | 0666);
	if(sem>0){
		printf("Semaphore array created");
}
}
