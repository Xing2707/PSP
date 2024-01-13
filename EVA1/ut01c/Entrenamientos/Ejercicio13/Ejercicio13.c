#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER 1024

int isPrimo(int num){
    if(num <= 1){
        return 1;
    }

    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return 1;
        }
    }
    return 0;
}


int main(int args, char *argv[]){
    if(args == 3){
            pid_t id;
            int cont = 0;
            
            for(int i =0; i < args -1; i++){
                id = fork();
                if(id < 0){
                    perror("Error de clonacion");
                    exit(EXIT_FAILURE);
                }
                if(id == 0){
                    int num = atoi(argv[i + 1 ]);
                    exit(isPrimo(num));
                }else if(id > 0){
                    int status = 0;
                    wait(&status);
                    if(WEXITSTATUS(status) == 0) cont ++;
                }
            }
                printf("hay %d numero primo entre los dos hijos\n",cont);
                    
    }else{
        printf("Error Introduce algumentos");
    }
    return 0;
}