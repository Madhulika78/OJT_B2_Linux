
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig(int s){
	printf("Wake up \n");
	alarm(2);
}
int main(){
//	(void) signal(SIGINT,sig);
	printf("My process ID: %d\n",getpid());

		(void) signal(SIGALRM,SIG_IGN);
	//	alarm(2);
		while(1);
	
	return 0;
}
