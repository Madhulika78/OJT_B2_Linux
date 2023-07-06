/* The program is to create two threads that will  access a single thread function.
 * By using mutex_lock and mutex_unlock we establish a perfect synchronisation between two threads.  
 */
#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global=0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static void * threadFunc1(void *arg){
	int local;
	pthread_mutex_lock(&mut);
	printf("ThreadFunc1 started\n");
	for(int i=0;i<10000;i++){
		local=global;
		local++;
		global=local;
	}
	pthread_mutex_unlock(&mut);
	printf("ThreadFunc1: %d\n",local);
	sleep(2);
}


int main(int argc, char *argv[]){
	int s1,s2;
	pthread_t id1,id2;
	s1=pthread_create(&id1,NULL,threadFunc1,NULL);
	s2=pthread_create(&id2,NULL,threadFunc1,NULL);
	printf("Main started\n");
  	sleep(6);
	printf("Global=%d\n",global);

} 
