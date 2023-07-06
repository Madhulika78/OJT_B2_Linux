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
	i=msgrcv(qid,&m1,sizeof(m1),1,0);
        for(int i=0;i<100;i++){
                printf("%s",m1.buffer[i]);
        }
       
}

