#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR "/sys/class/gpio/PD21/direction"
#define GPIO_VAL "/sys/class/gpio/PD21/Value"

int main(){
        int gpio_fd;
        char gpio_buf[30];
        int gpio_num=117;
        int count=10;
        gpio_fd=open(GPIO_EN,O_WRONLY);
        if(gpio_fd<0){
                printf("Unable to open the file %s\n",GPIO_EN);
                exit(0);
        }
        sprintf(gpio_buf,"%d",gpio_num);
        write(gpio_fd,gpio_buf,strlen(gpio_buf));
        close(gpio_fd);

        gpio_fd=open(GPIO_DIR,O_WRONLY);
        if(gpio_fd<0){
                printf("Unable to open the file %s\n",GPIO_DIR);
                exit(0);
        }
        write(gpio_fd,"out",3);
        close(gpio_fd);

        gpio_fd=open(GPIO_VAL,O_WRONLY);
        if(gpio_fd<0){
                printf("Unable to open the file %s\n",GPIO_VAL);
                exit(0);
        }
        printf("Toggling the GPIO_PIN\n");
        while(count--){
                write(gpio_fd,"0",1);
		sleep(2);
                write(gpio_fd,"0",0);
                sleep(2);
        }
}

