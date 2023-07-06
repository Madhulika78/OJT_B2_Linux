
#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void * threadFunc(void *arg){
	printf("Threadfunction statred");
	while(1){
		sleep(1);
		printf("Exiting from loop\n");
	}
	printf("\nThread: threadfunc exiting now\n");
}
int main(int argc, char *argv[]){
	int s;
	void *res;
	int count;
	pthread_t id;
	s=pthread_create(&id,NULL,threadFunc,"Welcome");
	if(s!=0){
		perror("Thread error\n");
	}
	for(count=0;count<10;count++){
		sleep(2);
		printf("Main thread count: %d\n",count);
	}
	pthread_cancel(id);

       printf("Main thread existing now\n");
       pthread_exit(NULL);
      
}       
