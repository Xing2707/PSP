#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#define BUFFER 1024

void signal_handler(){
    printf("hola soy %d\n",getpid());
    fflush(stdout);
}

void crear_mata_hijo(int num){
    pid_t id;
    for(int i =0; i < num; i++){
        if((id = fork()) < 0){
            perror("Error de clonacion");
            exit(1);
        }
        if(id == 0){
            signal(SIGUSR1,signal_handler);
            pause();
            exit(0);
        }

        if(id > 0){
            sleep(1);
            kill(id,SIGUSR1);
        }
    }
}

int main(int args , char *argv[]){
    char input[BUFFER];

    printf("Introduce numero de hijos\n");
    fgets(input,sizeof(input),stdin);

    int num = atoi(input);

    crear_mata_hijo(num);

    return 0;
}