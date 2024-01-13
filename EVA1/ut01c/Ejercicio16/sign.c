#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal){
    if(signal == SIGUSR1){
        printf("Hola\n");
    }else if(signal == SIGUSR2){
        printf("Mundo\n");
    }
}
       



int main(int argc, char *argv[]){

    signal(SIGUSR1,signal_handler);

    signal(SIGUSR2,signal_handler);

     printf("Esperado seña de proceso\n");

    while (1)
    {
        fflush(stdout);
        sleep(1);
    }
    
    return 0;
}

//ps aux | grep ./signal(nombre de fiche que ejecuta la señal) se usa en el cmd para obetener el id de señal
// kill mata la señal
