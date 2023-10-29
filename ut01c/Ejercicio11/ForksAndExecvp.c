#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    char *date[] = {"cal",NULL};
    pid_t id;

    id = fork();

    if(id != 0){
        wait(NULL);
        printf("Soy Padre\n");
    }else{
        if(execvp(date[0],date) == -1){
            perror("Error llama a comando cal");
            return 1;
        }
    }
    return 0;
}