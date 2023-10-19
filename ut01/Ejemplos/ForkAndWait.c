#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int isPrimo(int num){
    if(num <= 1){
        return 0;
    }

    for(int i = 2; i * i < num; i++){
        if(num % 2 == 0){
            return 0;
        }
    }

    return 1;
}

int main(void){
    
    unsigned int n = 97;

    pid_t id;
    
    id = fork();

    if(id != 0){

        int status = 0;
        wait(&status);
        
        printf("El numero %d %s numero primo \n",n,(WEXITSTATUS(status) == 1)? "es" : "no es");

    }else{
        int primo = isPrimo(n);
        exit(primo);
    }

    return 0;

}