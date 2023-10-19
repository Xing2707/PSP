#include <stdio.h>
#include <string.h>

int main(void){
    char hola[] = "hola";
    if(strchr(hola,'o') == NULL){
        printf("No hay\n");
    }else
    {
        printf("Hay\n");
    }
    
}