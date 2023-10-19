#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

#define DIEZ 10

void imprimiTabla(int valor){
    int cont = 1;
    for(int i = 0; i <= DIEZ; i++){
        int total = cont * valor;
        printf(" %d * %d = %d ",valor,cont,total);
        cont = cont + 1;
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    pid_t id;
    int cont = 1;

    for (int i = 1; i <= 10; i++)
    {
        id = fork();
        if(id == 0){
            imprimiTabla(i);
            exit(0);
        }
    }

    for(int i = 0; i <10; i++){
        if(id != 0){
            wait(NULL);
        }
    }
    
    return 0;
}
