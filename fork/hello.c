#include<stdio.h>
#include<unistd.h>
int main(){
	int pid;
	printf("Hello world\n");
	printf("My process ID:%d\n",getpid());
	printf("My parent process ID:%d\n",getppid());
	printf("bfr fork pid is %d\n",getpid());
	pid=fork();
	printf("%d pid\n",pid);
	getchar();
}
