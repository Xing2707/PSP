#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define ONE 1
#define TWO 2
#define BUFFER 1024

int main(int argc, char *argv[]){

    int tubo[TWO];
    pid_t id;

    if(pipe(tubo) == -ONE){
        perror("Error tubo de conexion incorrecto");
        exit(EXIT_FAILURE);
    }
    id = fork();

    if(id == -1){
        perror("Error clonacion de proceso incorrecto");
        exit(EXIT_FAILURE);
    }

    if(id != 0){
        char cadena[BUFFER];
        close(tubo[READ]);
        printf("Escribete algo");
        fgets(cadena,sizeof(cadena),stdin);
        write(tubo[WRITE],cadena,sizeof(cadena));
        close(tubo[WRITE]);
    }else{
        wait;
        char cadena[BUFFER];
        close(tubo[WRITE]);
        read(tubo[READ],cadena,sizeof(cadena));
        close(tubo[READ]);
        printf("has pindato: %s\n",cadena);
    }
    return 0;
}