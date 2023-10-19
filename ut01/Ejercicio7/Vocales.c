#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER 1024
#define ZERO 0

int main(void){

    int cont = ZERO;
    int acum = ZERO;
    char cadenas[BUFFER];
    char resultado[BUFFER];

    printf("introduce una palabra \n");

    fgets(cadenas,sizeof(cadenas),stdin);

    for (int i = 0; i < strlen(cadenas); i++)
    {
        if(cadenas[i] == '\n' || cadenas[i] == '\r')
        {
            cadenas[i] = '\0';
            break;
        }
    }
    
    for(int i = 0; i < strlen(cadenas); i++)
    {
        resultado[i] = toupper(cadenas[i]);
    }

    for(int i = 0; i < strlen(resultado); i ++){
        if(resultado[i] == 'A' || resultado[i] == 'E' || resultado[i] == 'I' || resultado[i] == 'O' || resultado[i] == 'U'){
            cont ++;
        }
    }
    printf("la palabra %s tiene %d numeros de vocales\n",cadenas,cont);

    return 0;
}