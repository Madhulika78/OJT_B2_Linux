#include<stdio.h>
#include<unistd.h>
int main(){
	int pid=fork();
	if((pid)>0){
		printf("Hello fro the parent\n");
		printf("%d\n",getpid());
	}
	else{
		printf("Hello from the child\n");
		execl("./pro2","arg1","arg2",NULL);
		printf("%d\n",getpid());
	}
}
