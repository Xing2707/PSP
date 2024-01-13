#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal){
    if(signal == SIGUSR1){
        printf("hola soy %d\n",getpid());
        fflush(stdout);
    }
}

int main(int args, char *argv[]){
    pid_t id;

    if((id = fork()) < 0){
        perror("Error de clonacion");
        exit(1);
    }

    if(id == 0){
        signal(SIGUSR1,signal_handler);
        pause();
        exit(0);
    }else{
        sleep(1);
        kill(id,SIGUSR1);
    }
    
}