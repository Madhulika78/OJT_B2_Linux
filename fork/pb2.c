#include<stdio.h>
#include<unistd.h>
int main(){
	int pid;
	if((pid=fork())>0){
		printf("Hello fro the parent\n");
		printf("%d\n",getpid());
	}
	else{
		printf("Hello from the child\n");
		printf("%d\n",getpid());
	}
}
