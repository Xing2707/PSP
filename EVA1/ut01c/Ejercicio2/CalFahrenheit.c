#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

double calFahrenheit( double num){
    return ((num * 9 / 5) + 32);
}

int main(void){
    
    printf("Introduce Celsius para hace calculo de Fahrenheit\n");

    pid_t id;

    id = fork();
    
    if(id != 0){
        double num,total;
        
        scanf("%lf",&num);

        total = calFahrenheit(num);
       
        printf("Fahrenheit de %.2lf es %.2lf\n",num,total);
        
        wait(NULL);

    }else{
        char input[100];
        double num,total;
        
        fgets(input,sizeof(input),stdin);
        
        num = atof(input);
        total = calFahrenheit(num);
        printf("Fahrenheit de %.2lf es %.2lf\n",num,total);
    }
    

   

    return 0;
}