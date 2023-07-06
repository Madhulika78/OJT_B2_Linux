/* The program is to send data from producer thread  
 */
#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t con=PTHREAD_COND_INITIALIZER;
int done=0;
char buf[100];

//producer
void * threadFunc1(void *arg){
	printf("\nThreadFunc1 started\n");
	sleep(1);
	pthread_mutex_lock(&mut);
	printf("ThreadFunc1 critical section\n");

	//producer will produce data
	sprintf(buf,"This is buffer");
	done=1;
	pthread_cond_signal(&con);
	pthread_mutex_unlock(&mut);
}

//consumer
void * threadFunc2(void *arg){
        printf("\nThreadFunc2 started\n");
        pthread_mutex_lock(&mut);
        if(done==0)
		pthread_cond_wait(&con,&mut);
	
	//consumer will consume data here
	printf("ThreadFunc2: signal recieved from threadFunc1, execcuted after ThreadFunc1 %d\n",done);
	printf("Buffer recieved: %s\n",buf);
        pthread_mutex_unlock(&mut);
	
}


int main(int argc, char** argv){
	pthread_t id1,id2;
	pthread_create(&id1,NULL,threadFunc1,NULL);
	pthread_create(&id2,NULL,threadFunc2,NULL);
	pthread_join(threadFunc1,NULL);
       pthread_join(threadFunc2,NULL);
	printf("Main function is exiting\n");
 	return(EXIT_SUCCESS);	

} 
