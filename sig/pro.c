#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

static void signal_h(int sig){
	if(sig=+SIGUSR2){
		printf("Child:Caught
