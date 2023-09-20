#include <stdio.h>

int main(void){
    int num = 42;

    printf("Esto es un numero: %d\n",num);
    scanf("%d", &num);
    printf("El nuevo numero es: %d\n",num);

    return 0;
}