#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig(){
	printf("Example\n");
}
int main(){
	int pid=fork();
	if((pid)==0){
		printf("Hello from the child\n");
		printf("%d\n",getpid());
		sleep(5);
	}
	else{
		(void) signal(SIGCHLD,sig);
		while(1){
		printf("Hello from the parent\n");
		printf("%d\n",getpid());
		sleep(1);
	}
}
}
