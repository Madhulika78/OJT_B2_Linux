/*program using the detach*/
#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void * threadFunc(void *arg){
	printf("Threadfunction statred");
	pthread_detach(pthread_self());
	sleep(5);
	printf("\nThread: threadfunc exiting now\n");;
}
int main(int argc, char *argv[]){
	int s;
	void *res;
	pthread_t id;
	s=pthread_create(&id,NULL,threadFunc,"Welcome");
	if(s!=0){
		perror("Thread error\n");
	}
	printf("main thread:Message from main(), pid= %d\n",getpid());

       printf("Main thread existing now\n");
      
}       
