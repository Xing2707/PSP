#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>

#define BUFFER 1024
#define TUBO_LENG 2
#define READ 0
#define WRITE 1

void shuffleArray(int ary[],int size){
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        int j = rand()% size;
        int temp = ary[i];
        ary[i] = ary[j];
        ary[j] = temp;
    }
}

void signal_handle(int signal){
    printf("soy %d mi padre me ha matado\n",getpid());
}

int main(int args, char *argv[]){
    char input[BUFFER];
    pid_t id;
    int num;
    int tubo[TUBO_LENG];
    
    if(pipe(tubo) == -1){
        perror("error de creacion de tubos\n");
        return 1;
    }

    printf("introduce numeros de hijos va a crear\n");
    fgets(input,sizeof(input),stdin);

    if((num = atoi(input)) == 0){
        perror("numero introducido no valido\n");
        return 1;
    }

    for(int i = 0; i < num; i++){
        id = fork();
        if(id == -1){
            perror("Error de creacion de hijos\n");
        }
        if(id == 0){
            break;
        }
    }

    if(id < num){
        int myid;
        myid = getpid();
        close(tubo[READ]);
        write(tubo[WRITE],&myid,sizeof(myid));
        close(tubo[WRITE]);
        signal(SIGUSR1,signal_handle);
        sleep(10);
    }else{
        int id_hijos[num];
        int cont = 0;
        close(tubo[WRITE]);
        while (read(tubo[READ],&id_hijos[cont],sizeof(id_hijos[cont])) > 0){
            cont ++;
        }
        close(tubo[READ]);
        sleep(1);
        for(int i = 0; i < num; i++){
            kill(id_hijos[i],SIGUSR1);
        }

        for(int j = 0; j < num; j++){
            wait(NULL);
        }
    }

    return 0;

}