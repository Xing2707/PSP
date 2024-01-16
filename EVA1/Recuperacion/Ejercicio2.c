#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>

#define BASE 100;
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

void proceso_hijo(int num){
    int min, max,cont = 0;
    min = (num + 1) * BASE;
    max = min + BASE -1;
    printf("soy hijo %d comienzo en el numero %d\n",getpid(),min);
    for(min; min < max; min++){
        if(isPrimo(min) == 0){
            printf("el primer primo es %d\n",min);
            exit(cont);
        }else
        {
            cont ++;
        }
        
    }
}
int main(int args, char *argv[]){
    int num,total = 0;
    pid_t id;
    printf("introduce numeros de hijos para crear\n");
    scanf("%d",&num);
    for(int i = 0; i < num; i++){
        id = fork();
        if(id < 0){
            perror("Error de creacion de hijos\n");
            exit(EXIT_FAILURE);
        }
        if(id == 0){
            proceso_hijo(i);
            break;
        }
    }

    for(int i = 0; i < num; i ++){
        int status = 0;
        wait(&status);
        total += WEXITSTATUS(status);
        printf("el hijo escribira en su estado %d\n",WEXITSTATUS(status));
    }

    printf("resultado de suma es: %d\n",total);
    return 0;
    
}