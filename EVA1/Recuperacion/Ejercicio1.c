#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>
#include <signal.h>

#define READ 0
#define WRITE 1
#define MAX_NUM 999
#define MIN_NUM 100
#define BASE 10
#define PIPE_LENGHT 2

int option = 1;
int tuboPrimo[PIPE_LENGHT];
void signal_handler(int sign){
    option = 0;
    close(tuboPrimo[WRITE]);
    int numero;
    read(tuboPrimo[READ],&numero,sizeof(numero));
    printf("suma total de numero primos enviado por hijo es %d\n",numero);
    close(tuboPrimo[READ]);
    exit(EXIT_SUCCESS);
    
}

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

int main(){
    pid_t id;
    int tuboNumero[PIPE_LENGHT];
    int idPadre = 0;
    srand(time(NULL));
    int num_rand,total = 0;

    if(pipe(tuboNumero) == -1 || pipe(tuboPrimo) == -1){
        perror("Error de creacion de tubos\n");
        exit(EXIT_FAILURE);
    }
    
    if((id = fork()) == -1){
        perror("Error de creacion de tubos\n");
        exit(EXIT_FAILURE);
    }

    if(id != 0){
        signal(SIGINT,signal_handler);
        idPadre = getpid();
        close(tuboNumero[READ]);
        while(option == 1)
        {
            num_rand = (rand() % (MAX_NUM - MIN_NUM)) + MIN_NUM;
            write(tuboNumero[WRITE],&num_rand,sizeof(num_rand));
        }
        close(tuboNumero[WRITE]);
        exit(EXIT_SUCCESS);
    }else{
        close(tuboNumero[WRITE]);
        close(tuboPrimo[READ]);
        int numero = 0;
        while (read(tuboNumero[READ],&numero,sizeof(numero)) > 0){
            if(isPrimo(numero) == 0){
                total += numero;
            }else if(numero % 10 == 0){
                kill(idPadre,SIGINT);
            }else{
                printf("soy el hijo he recipido %d\n",numero);
            }
        }
        write(tuboPrimo[WRITE],&total,sizeof(total));
        close(tuboNumero[READ]);
        close(tuboPrimo[WRITE]);
    }

    return 0;
}

