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
    int tubo[TUBO_LONGITUD];
    char input[BUFFER];
    pid_t id;
    int total;

    if(pipe(tubo) < 0){
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
        int status = 0;
        close(tubo[READ]);
        printf("Introduce operacion suma o resta\n");
        fgets(cadenas,sizeof(cadenas),stdin);

        printf("Introduce 1º numero para hacer la operacion\n");
        fgets(input,sizeof(input),stdin);
        num1 = atoi(input);

        printf("Introduce 2º numero para hacer la operacion\n");
        fgets(input,sizeof(input),stdin);
        num2 = atoi(input);

        write(tubo[WRITE],cadenas,sizeof(cadenas));
        write(tubo[WRITE],&num1,sizeof(num1));
        write(tubo[WRITE],&num2,sizeof(num2));

        close(tubo[WRITE]);
        wait(&status);
        printf("soy el proceso padre he recivido la respuesta que es : %d\n", WEXITSTATUS(status));
    }else{
        char cadenas[BUFFER] = "";
        char ncadenas[BUFFER] ="";
        int num1 = 0;
        int num2 = 0;
        close(tubo[WRITE]);
        read(tubo[READ],cadenas,sizeof(cadenas));
        read(tubo[READ],&num1,sizeof(num1));
        read(tubo[READ],&num2,sizeof(num2));
        
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
        close(tubo[READ]);
        exit(total);
    }

    return 0;
}