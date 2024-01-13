#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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

void crearTrabajo(int min, int max){
    printf("soy hijos %d :",getpid());
    for(min; min <= max; min++){
        if(isPrimo(min) == 0){
            printf("%d ",min);
        }
    }
    printf("\n");
}

void genraprograma(int longi, int prog){
    pid_t id;
    int i =0;
    int min = 0,max = 0;

    for(int i = 0; i < longi; i++){
        if(min == 0){
            min += 1;
        }else{
            min *= 10; 
        }
    }

    max = min *10 -1;
    int min_rang = min;
    int max_rang = 0;
    int rang = max / prog;

    for(i; i < prog; i++){
        max_rang = min_rang + rang;
        if(max_rang > max){
            max_rang = max;
        }else if(i == (prog -1 )){
            int resto = max - max_rang;
            max_rang += resto;
        }
        id = fork();

        if(id == 0){
            crearTrabajo(min_rang,max_rang);
            exit(EXIT_SUCCESS);
        }

        min_rang = max_rang +1;
    }

    for(int y = 0; y < prog; y++){
        if(id > 0){
            wait(NULL);
        }
    }
}

int main(int args, char *argv[]){
    char input[BUFFER] ="";
    int num = 0;
    int num2 = 0;

    printf("Introduce longitu de numero\n");
    fgets(input,sizeof(input),stdin);
    num = atoi(input);

    printf("Introduce numero de procesos\n");
    fgets(input,sizeof(input),stdin);
    num2 = atoi(input);
    
    genraprograma(num,num2);
    return 0;
}