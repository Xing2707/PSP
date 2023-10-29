#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1
#define TWO 2
#define ONE 1
#define ZERO 0
#define BUFFER 1024

int main(int argc, char *argv[]){
    int tubo[2];
    int file = open("output.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);
    pid_t id;

    if(pipe(tubo) == -ONE){
        perror("Error conexion de tubo incorrecto");
        exit(EXIT_FAILURE);
    }

    if(file < ZERO){
        perror("Error lectura y escritura de fichero incorrecto");
        return 1;
    }
    id = fork();

    if(id == -ONE){
        perror("Error clonacion de proceso incorrecto");
        exit(EXIT_FAILURE);
    }
    
    if(id != 0){
        char num[BUFFER];

        close(tubo[READ]);

        fgets(num,sizeof(num),stdin);
        while(atoi(num) == 0){
            printf("No puede introducir algo que no es numero\n Introduce otra vez por favor\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            fgets(num,sizeof(num),stdin);
        }
        
        int num2 = atoi(num);
        write(tubo[WRITE],&num2,sizeof(num2));
        close(tubo[WRITE]);
        
    }else{
        int num;

        wait;
        close(tubo[WRITE]);
        read(tubo[READ],&num,sizeof(num));
        close(tubo[READ]);

        printf("Proceso ha sido corrcto\n");
        
        num = num *num * num;

        dup2(file,STDOUT_FILENO);
        printf("%d",num);
        close(file);

    }
   
    
    return 0;
}