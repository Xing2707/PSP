#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>

#define READ 0
#define WRITE 1
#define PIPE_LONG 2
#define BASE 10
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

void genera_nuemero(int longitud, int cantidad,int* tubo){
    int max_rang = 0,min_rang = 0;
    for(int i = 0; i < longitud; i++){
        if(i == 0){
            min_rang = 1;
        }else
        {
            min_rang *= BASE;
        }
    }
    max_rang = min_rang * BASE -1;
    
    srand(time(NULL));
    int num_rand;
    close(tubo[READ]);
    for(int i = 0; i < cantidad; i++){
        num_rand = (rand() % max_rang) + min_rang;
        write(tubo[WRITE],&num_rand,sizeof(num_rand)); 
    }
    close(tubo[WRITE]);
}

int main(int args, char *argv[]){
    pid_t hijo1,hijo2;
    int Tubo_Padre_Hijo1[PIPE_LONG];
    int Tubo_Padre_Hijo2[PIPE_LONG];
    int Tubo_Hijo_Padre1[PIPE_LONG];
    int Tubo_Hijo_Padre2[PIPE_LONG];
    char input[BUFFER];

    printf("Introduce longitud de numero\n");
    fgets(input,sizeof(input),stdin);
    int num1 = atoi(input);

    printf("Introduce veces de repetir generar numero random\n");
    fgets(input,sizeof(input),stdin);
    int num2 = atoi(input);

    if(pipe(Tubo_Padre_Hijo1) < 0 || pipe(Tubo_Padre_Hijo2) < 0 || pipe(Tubo_Hijo_Padre1) < 0 || pipe(Tubo_Hijo_Padre2)){
        perror("Error de creacion de PIPE");
        exit(EXIT_FAILURE);
    }

    hijo1 = fork();
    hijo2 = fork();
    if( hijo1 < 0 || hijo2 < 0){
        perror("Error de clonacion");
    }
    
    if(hijo1 == 0){
        close(Tubo_Padre_Hijo1[WRITE]);
        int num;
        int primo = 0;
        while (read(Tubo_Padre_Hijo1[READ],&num,sizeof(num))){
            if(isPrimo(num) == 0){
                printf("soy %d he recibido numero %d es numero primo\n",getpid(),num);
            }else{
                printf("soy %d he recibido numero %d no es numero primo\n",getpid(),num);
                primo = 1;
            }
        }
        close(Tubo_Hijo_Padre1[READ]);
        write(Tubo_Hijo_Padre1[WRITE],&primo,sizeof(primo));
        close(Tubo_Hijo_Padre1[WRITE]);
        exit(EXIT_SUCCESS);
    }else{
        genera_nuemero(num1,num2,Tubo_Padre_Hijo1);
        wait(NULL);
        int num;
        read(Tubo_Hijo_Padre1[READ],&num,sizeof(num));
        printf((num == 0)? "el hijo1 no se ha sobrevivido\n" : "el hijo1 se ha sobrevivido\n");
        close(Tubo_Hijo_Padre1[READ]);
        close(Tubo_Hijo_Padre1[WRITE]);
    }
    if(hijo2 == 0){
        close(Tubo_Padre_Hijo2[WRITE]);
        int num;
        int primo = 0;
        while (read(Tubo_Padre_Hijo2[READ],&num,sizeof(num))){
            if(isPrimo(num) == 0){
                printf("soy %d he recibido numero %d es numero primo\n",getpid(),num);
            }else{
                printf("soy %d he recibido numero %d no es numero primo\n",getpid(),num);
                primo = 1;
            }
        }
        close(Tubo_Hijo_Padre2[READ]);
        write(Tubo_Hijo_Padre2[WRITE],&primo,sizeof(primo));
        exit(EXIT_SUCCESS);
        close(Tubo_Hijo_Padre2[WRITE]);
    }else
    {
        genera_nuemero(num1,num2,Tubo_Padre_Hijo2);
        wait(NULL);
        int num;
        read(Tubo_Hijo_Padre2[READ],&num,sizeof(num));
        printf((num == 0)? "el hijo2 no se ha sobrevivido\n" : "el hijo2 se ha sobrevivido\n");
        close(Tubo_Hijo_Padre2[READ]);
        close(Tubo_Hijo_Padre2[WRITE]);
    }
    
    return 0;
}