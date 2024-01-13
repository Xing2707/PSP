#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#define TUBO_LONGITUD 2
#define READ 0
#define WRITE 1
#define BUFFER 1024
#define SUMA "suma"
#define RESTA "resta"

int main(int args, char *argv[]){
    int tubo1[TUBO_LONGITUD],tubo2[TUBO_LONGITUD];
    char input[BUFFER];
    pid_t id;

    if(pipe(tubo1) < 0 || pipe(tubo2) < 0){
        perror("Error de creacion de tubo");
        exit(EXIT_FAILURE);
    }

    if((id = fork()) < 0){
        perror("Error de clonacion de proceso");
        exit(EXIT_FAILURE);
    }

    if(id > 0){
        char cadenas[BUFFER];
        int num1 = 0;
        int num2 = 0;
        int total = 0;
        int status = 0;
        close(tubo1[READ]);
        printf("Introduce operacion suma o resta\n");
        fgets(cadenas,sizeof(cadenas),stdin);

        printf("Introduce 1º numero para hacer la operacion\n");
        fgets(input,sizeof(input),stdin);
        num1 = atoi(input);

        printf("Introduce 2º numero para hacer la operacion\n");
        fgets(input,sizeof(input),stdin);
        num2 = atoi(input);

        write(tubo1[WRITE],cadenas,sizeof(cadenas));
        write(tubo1[WRITE],&num1,sizeof(num1));
        write(tubo1[WRITE],&num2,sizeof(num2));

        close(tubo1[WRITE]);
        wait(&status);
        
        close(tubo2[WRITE]);
        read(tubo2[READ],&total,sizeof(total));
        printf("soy el proceso padre he recivido la respuesta de operacion que es : %d\n",total);
        close(tubo2[READ]);
    }else{
        char cadenas[BUFFER] = "";
        char ncadenas[BUFFER] ="";
        int num1 = 0;
        int num2 = 0;
        int total = 0;
        close(tubo1[WRITE]);
        read(tubo1[READ],cadenas,sizeof(cadenas));
        read(tubo1[READ],&num1,sizeof(num1));
        read(tubo1[READ],&num2,sizeof(num2));
        
        for(int i = 0; i < strlen(cadenas); i++){
            if(cadenas[i] == '\n' || cadenas[i] == '\r'){
                cadenas[i] = '\0';
                break;
            }
        }

        for(int i = 0; i < strlen(cadenas); i++){
            ncadenas[i] = cadenas[i];
        }

        if(strcmp(ncadenas,SUMA) == 0){
            total = num1 + num2;
        }else if(strcmp(ncadenas,RESTA) == 0){
            total = num1 - num2;
        }
        close(tubo1[READ]);
        close(tubo2[READ]);
        write(tubo2[WRITE],&total,sizeof(total));
        exit(0);
    }

    return 0;
}