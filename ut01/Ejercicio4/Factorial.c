#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

int calFactorial(int value){
    int total = 1;
    
    for (int i = 2; i <= value; i++)
    {
        total *= i; 
    }
    return total;
}

int calFactorialRecursive(int value){
    if(value <= 1)
    {
        return 1;
    }
    else
    {
        return value * calFactorialRecursive(value -1);
    }
}

int main(void){

    printf("Introduce un numero para hace calculo factorial\n");

    pid_t id;

    id = fork();
    
    if(id != 0){
        int num,total;
        char *vacio;
        
        scanf("%d",&num);
        num = abs(num);
        total = calFactorial(num);
    
        printf("Factorial de numero %d es %d\n",num,total);

        wait(NULL);

    }else{
        int num;

        num = abs(num);

        printf("Fatorial de numero %d es %d\n",num,calFactorialRecursive(num));

    }
    
    return 0;
}
