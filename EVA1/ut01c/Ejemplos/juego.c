#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>
#include <signal.h>

#define MAX_RAND 100
#define READ 0
#define WRITE 1
#define MAX_CHILDREN 7
#define INPUT_LENGHT 1024

void signal_handle(int signal){
    if(signal == SIGUSR1){
        printf("es menor que numero adivinas\n");
    }else if(signal == SIGUSR2){
        printf("es mayor que numero adivinas\n");
    }else if(signal == SIGINT){
        printf("ehorabuena has adivinado el numero\n");
        exit(EXIT_SUCCESS);
    }
}

int main(int args, char *argv[])
{
    int numRandom = 0;
    int tuboHijoPadre[2];
    pid_t id;
   if(pipe(tuboHijoPadre) < 0){
        perror("Error de creacion de tubo\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < MAX_CHILDREN; i++){
        id = fork();
        if(id < 0 ){
            perror("Error de clonacion\n");
            exit(EXIT_FAILURE);
        }
        if(id == 0){
            break;
        }
    }

    if(id < MAX_CHILDREN){
        int hijoId;
        hijoId = getpid();
        close(tuboHijoPadre[READ]);
        write(tuboHijoPadre[WRITE],&hijoId,sizeof(hijoId));
        close(tuboHijoPadre[WRITE]);

        signal(SIGUSR1,signal_handle);
        signal(SIGUSR2,signal_handle);
        signal(SIGINT,signal_handle);
        while (1)
        {
            sleep(1);
        }
    }else{
        sleep(1);
        srand(time(NULL));
        numRandom = (rand() % 99) +1 ;
        char input[INPUT_LENGHT];
        int idHijos[MAX_CHILDREN];
        int cont = 0;

        close(tuboHijoPadre[WRITE]);
        while (read(tuboHijoPadre[READ],&idHijos[cont],sizeof(idHijos[cont])) > 0)
        {
            cont ++;
        }
        close(tuboHijoPadre[READ]);

        for(int i = 0; i < MAX_CHILDREN; i ++){
            printf("Introduce numero para adivinar\n");
            printf("%d\n",numRandom);
            fgets(input,sizeof(input),stdin);
            int num = atoi(input);
            if(num < numRandom){
                kill(idHijos[i],SIGUSR1);
            }else if(num > numRandom){
                kill(idHijos[i],SIGUSR2);
            }else if(num == numRandom){
                kill(idHijos[i],SIGINT);
                exit(EXIT_SUCCESS);
            }
            sleep(1);
        }
        printf("lo siento no has podido adivinarlo\n");
    }

     return 0;
}