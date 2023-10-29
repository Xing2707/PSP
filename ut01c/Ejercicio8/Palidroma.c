#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define BUFFER 1024

int main(void){
    char cadenas[BUFFER];
    char nuevoCadenas[BUFFER];
    int nuevoLenght = 0;
    
    printf("Introduce palabras para determinar si es palidroma\n");
    fgets(cadenas,sizeof(cadenas),stdin);

    for (int i = 0; i < strlen(cadenas); i++)
    {
        if(cadenas[i] == '\n' || cadenas[i] == '\r')
        {
            cadenas[i] = '\0';
            break;
        }
    }
    

    for (int i = 0; i < strlen(cadenas); i++)
    {
        if(isalnum(cadenas[i])){
            nuevoCadenas[nuevoLenght++] = toupper(cadenas[i]);
        }
    }

    nuevoCadenas[nuevoLenght] = '\0';
    int leng = strlen(nuevoCadenas)-1;
    bool option = true;

    for(int i = 0; i < strlen(nuevoCadenas)/2 && option; i++){
        if(nuevoCadenas[i] == nuevoCadenas[leng]){
            leng--;
            option = true;
        }else{
            option = false;
        }
    }
   
    if(option)
    {
        printf("La palabra %s es palidroma\n",cadenas);
    }
    else
    {
        printf("La palabra %s no es palidroma\n",cadenas);
    }

    return 0;
    
}