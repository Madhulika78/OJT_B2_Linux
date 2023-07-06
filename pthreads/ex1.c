#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void * threadFunc(void *arg){
	int count =0;
	printf("Thread: thread func started\n");
	for(count=0;count<100;count++);
	sleep(5);
	printf("Tread threadfunc exiting now \n");
	if(count<500){
		return (void *) "count<500";
	}
	else{
		return (void *) "count>500";
}
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
	#if 0       
       s=pthread_join(id,&res);
       if(s!=0){
	       perror("Join error\n");
       }
       printf("main thread: Thread returned %s\n",(char *)res);
	#endif
       printf("Main thread existing now\n");
       pthread_exit(NULL);
}       
