
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig(int s){
	printf("SIGKILL \n");
}
void sig2(int s){
	printf("SIGHup \n");
}
int main(){
//	(void) signal(SIGINT,sig);
	printf("My process ID: %d\n",getpid());
		(void) signal(SIGHUP,sig2);
		(void) signal(SIGKILL,sig);
while(1){
		printf("Hello\n");
		sleep(1);
}
	
	return 0;
}
