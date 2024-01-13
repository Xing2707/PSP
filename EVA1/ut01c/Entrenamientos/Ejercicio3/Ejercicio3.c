#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#define ALFABETO {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
#define BUFFER 1024
#define ZERO 0
#define ONE 1
void pintaFichero(int num){
    char alfabetos[] = ALFABETO;
    char nombreFichero[BUFFER];
    char text[num + 1];
    for (int i = 0; i < num; i++)
    {
        text[i] = ' ';
    }
    
    text[num +1] ='\0';
    sprintf(nombreFichero,"datos%d.txt",num);
    FILE *archivo = fopen(nombreFichero,"w");
    if(num == 1){
        fprintf(archivo,"%s\n",alfabetos);
    }else{
        int totalCombinacion = 1;
        for(int i = 0; i < num; i++){
            totalCombinacion *= strlen(alfabetos);
        }

        for(int j = 0; j < totalCombinacion; j++){
            int temp = j;
            char letter[num];
            for (int j = 0; j < num; j++) {
                letter[j] = alfabetos[0] + temp % strlen(alfabetos);
                temp /= strlen(alfabetos);
            }
            for(int g = num-1; g >= 0; g--){
                fprintf(archivo,"%c", letter[g]);
            }
            fprintf(archivo,"\n");
        }
    }
    
    fclose(archivo);
}

int main(int args , char *argv[]){
    char input[BUFFER] = "";
    pid_t id;

    printf("Introduce numero de rango\n");
    fgets(input,sizeof(input),stdin);
    int num = atoi(input);

    for(int i = ZERO; i < num; i++){
        id = fork();
        if(id < ZERO){
            perror("Error de clonacion");
            return 1;
        } 

        if(id == ZERO){
            pintaFichero(i+ONE);
            exit(ZERO);
        }
    }

    for(int i = ZERO; i < num; i++){
        if(id > ZERO){
            wait(NULL);
        }
    }
    return 0;
}