#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int sval,ret;
	sem_t *sem;
	sem=sem_open("/name_sem4",O_RDWR);
	if(sem== SEM_FAILED){
		perror("Sem-open failed\n");
		return -1;
	}
	else{
		printf("sem-open successfully\n");
	}
	sem_getvalue(sem,&sval);
	printf("befor sem_wait p2 value= %d\n",sval);

	ret=sem_wait(sem);

	printf("Process 2: Executing critical section\n");
	sleep(10);
	printf("ret is %d\n",ret);
	printf("process 2\n");
	sem_post(sem);
	printf("Sempahore value %d\n",sval);
	printf("Critical section got executed\n");
	sem_unlink("/name_sem3");

}

