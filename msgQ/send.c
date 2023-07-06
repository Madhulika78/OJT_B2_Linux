#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234
typedef struct{
	long msgtype;
	char buffer[100];
}msg;
int main(){
	int qid;
	int i;
	qid=msgget(KEY,IPC_CREAT);
	msg m1,m2,m3;
	m1.msgtype=1;
	char a[10]="Hello";
	strcpy(m1.buffer,a);
	
	 i=msgsnd(qid,&m1,sizeof(m1),IPC_NOWAIT);
	 printf("%d\n",qid);
	 printf("return value of msgsnd = %d\n,",i);
}
