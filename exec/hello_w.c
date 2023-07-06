#include<stdio.h>
int main(){
	char *file="ls";
	char *arg1="-a";
	char *arg2="-s";
	printf("Hi world. My id:%d\n",getpid());
	execlp(file,arg1,arg2);
	printf("Hello\n");
}

