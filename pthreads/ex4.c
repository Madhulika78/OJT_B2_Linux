/* The program is to create two threads and check the value of global variable*/

#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global=0;
static void * threadFunc1(void *arg){
	int local;
	printf("ThreadFunc1 started\n");
	for(int i=0;i<10000;i++){
		local=global;
		local++;
		global=local;
	}
	printf("ThreadFunc1: %d\n",local);
	sleep(2);
}
static void * threadFunc2(void *arg){
        int local;
	printf("ThreadFunc2 started\n");
        for(int i=0;i<10000;i++){
                local=global;
                local++;
                global=local;
        }
	printf("ThreadFunc2:%d\n",local);
	sleep(2);
}

int main(int argc, char *argv[]){
	int s1,s2;
	pthread_t id1,id2;
	s1=pthread_create(&id1,NULL,threadFunc1,NULL);
	s2=pthread_create(&id2,NULL,threadFunc2,NULL);
	printf("Main started\n");
  	sleep(6);
	printf("Global=%d\n",global);

} 
