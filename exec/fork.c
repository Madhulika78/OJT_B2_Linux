#include<stdio.h>
#include<unistd.h>
int main(){
	int pid=fork();
	char *args[]={"./hello",NULL};
	int a;
	if(pid<0){
		printf("Error\n");
	}
	else if(pid==0){
		printf("I am in the child process:%d\n",getpid());
		a=10;
		printf("%d\n",a);
		sleep(7);
		//execv(args[0],args);
	}
	else{
		//wait(&a);
		printf("I am in the parent process:%d\n",getpid());
		printf("%d\n",a);
		sleep(10);
		
	}


}
