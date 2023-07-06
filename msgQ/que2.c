#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234
struct msqid_ds buf;
int main(){
	int qid;
	qid=msgget(KEY,IPC_CREAT);
	msgctl(qid,IPC_RMID,&buf);
	printf("No.of messages in queue: %d\n",buf.msg_qnum);
	printf("Current number of bytes in queue: %d\n",buf.__msg_cbytes);
}
