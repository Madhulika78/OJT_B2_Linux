#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int sval;
	sem_t *sem;
	sem=sem_open("/name_sem4",O_CREAT |O_RDWR, 0666, 1);
	if(sem== SEM_FAILED){
		perror("Sem-open failed\n");
		return -1;
	}
	else{
		printf("sem-open successfully\n");
	}
	sem_getvalue(sem,&sval);
	printf("befor sem_wait value= %d\n",sval);

	sem_wait(sem);
	sem_getvalue(sem,&sval);
	printf("after sem_wait value= %d\n",sval);

	printf("Process 1: Executing critical section\n");
	sleep(15);
	sem_post(sem);
	printf("Critical section got executed\n");
	sem_getvalue(sem,&sval);
	printf("after sem_post value= %d\n",sval);
	sem_unlink("/name_sem3");
}

