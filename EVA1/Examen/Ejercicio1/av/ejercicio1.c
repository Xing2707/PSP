#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

#define TUBU_LOG 2
#define HIJO_LEN 2
#define BASE 10
#define READ 0
#define WRITE 1
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

    int tubo_padre_hijo1[TUBU_LOG];
    int tubo_padre_hijo2[TUBU_LOG];
    // int tubo_hijo_padre1[TUBU_LOG]; pipe(tubo_hijo_padre1) < 0 &&
    int hijos;
    char input[BUFFER];
    srand(time(NULL));
    pid_t id;

    printf("introduce longitud de numero\n");
    fgets(input,sizeof(input),stdin);
    int num_long = atoi(input);

    printf("introduce veces que repites\n");
    fgets(input,sizeof(input),stdin);
    int repite = atoi(input);

    int max_num;
    int min_num;
    for(int g = 0; g < num_long; g++){
        if(g == 0){
            min_num = 1;
        }else
        {
            min_num *= BASE;
        }        
    }
    max_num = min_num * BASE -1;

    if(pipe(tubo_padre_hijo1) == -1 || pipe(tubo_padre_hijo2) == -1){
        perror("Error de creacion de tubus\n");
        exit(EXIT_FAILURE);
    }

    for(hijos = 0; hijos < HIJO_LEN; hijos++){
        id = fork();
        if(id < 0){
            perror("Error de clonacion\n");
            exit(EXIT_FAILURE);
        }else if(id == 0){
            break;
        }
    }
    if(id > 0){
        int num_rand1;
        int num_rand2;
        int status;
        int cont = 0;
        close(tubo_padre_hijo1[READ]);
        close(tubo_padre_hijo2[READ]);

        for(int j = 0; j < repite; j++){  
            num_rand1 = rand() % (max_num - min_num) + min_num;
            write(tubo_padre_hijo1[WRITE],&num_rand1,sizeof(num_rand1));
            num_rand2 = rand() % (max_num - min_num) + min_num;
            write(tubo_padre_hijo2[WRITE],&num_rand2,sizeof(num_rand2));
        }
        close(tubo_padre_hijo1[WRITE]);
        close(tubo_padre_hijo2[WRITE]);
        for(int k = 0; k < HIJO_LEN; k++){
            wait(&status);
            if(status == 0) cont++;
            if(k == HIJO_LEN -1){
                printf("soy padre %d hay %d hijos han sobrevivido\n",getpid(),cont);
            }
        }
    }else if(id == 0){
        int num;
        
        close(tubo_padre_hijo1[WRITE]);
        close(tubo_padre_hijo2[WRITE]);
        if(hijos == 0){
            int status = 0;
            while(read(tubo_padre_hijo1[READ],&num,sizeof(num)) > 0){
                printf("soy %d he tocado %d",getpid(),num);
                printf(isPrimo(num) == 0? " no he sobrevivido\n" : " he sobrevivido\n");
                if(isPrimo(num) == 0) status = 1;
            }
            exit(status);
        }else if(hijos == 1){
            int status = 0;
            while(read(tubo_padre_hijo2[READ],&num,sizeof(num)) > 0){
                printf("soy %d he tocado %d",getpid(),num);
                printf(isPrimo(num) == 0? " no he sobrevivido\n" : " he sobrevivido\n");
                if(isPrimo(num) == 0) status = 1;
            }
            exit(status);
        }
    }
    return 0;
}