#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig(int s){
	printf("I got a signal %d\n",s);
	(void) signal(SIGINT, SIG_DFL);
}
int main(){
	(void) signal(SIGINT,sig);
	printf("My process ID: %d\n",getpid());
	while(1){
		//(void) signal(SIGTERM,SIG_IGN);
		printf("Hello world\n");
		sleep(1);

	}
	return 0;
}
