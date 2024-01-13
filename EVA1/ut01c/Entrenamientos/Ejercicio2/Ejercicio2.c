#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define READE 0
#define WRITE 1
#define TWO 2
#define ONE 1
#define PAR 0
#define IMPAR 1
#define NUMRANG 20


int main(int argc, char const *argv[])
{
    pid_t id;
    int tubo[TWO][TWO];
    srand(time(NULL));

    for(int i = 0; i < (sizeof(tubo) / sizeof(tubo[0])); i ++){
        if(pipe(tubo[i]) == 1){
            perror("Error de inicializacion de pipe");
        }
    }

    for (int i = 0; i < TWO; i++) {
        id = fork();
        if(id < 0){
            perror("Error de crear proceso");
            return 1;
        }
        if(id == 0){
            for(int i = 0; i < (sizeof(tubo) / sizeof(tubo[0])); i++){
                close(tubo[i][WRITE]);
            }
            
            if(i == 0){
                int num = 0;
                int total = 0;
                while (read(tubo[PAR][READE],&num,sizeof(num)) > 0)
                {
                    printf("Soy hijo %d recivo numero par: %d\n",getpid(),num);
                    total += num;
                }
                printf("total: %d\n",total);
                exit(total);
            }else{
                int num = 0;
                int total = 0;
                while (read(tubo[IMPAR][READE],&num,sizeof(num)) > 0)
                {
                    printf("Soy hijo %d recivo numero impar: %d\n",getpid(),num);
                    total += num;
                }
                printf("total: %d\n",total);
                exit(total);
            }
        }
    }
    if(id > 0){
        int total;
        for(int i = 0; i < (sizeof(tubo) / sizeof(tubo[0])); i++){
            close(tubo[i][READE]);
        }

        for(int i = 0; i < NUMRANG; i++){
            int num_rand = rand() % 100;
            if( num_rand % 2 == 0){
                write(tubo[PAR][WRITE],&num_rand, sizeof(num_rand));
            }else{
                write(tubo[IMPAR][WRITE],&num_rand, sizeof(num_rand));
            }
        }

        for(int i = 0; i < (sizeof(tubo) / sizeof(tubo[0])); i++){
            close(tubo[i][WRITE]);
        }
        wait(&total);
        printf("total: %d\n",WEXITSTATUS(total));
    }
    return 0;
}