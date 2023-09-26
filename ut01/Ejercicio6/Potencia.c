#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int calPower(int base, int exp){
    int total = base;
    for(int i = 1; i < exp; i++){
            total *= base;
    }
    return total;
}

int main(void){
    int base,exp,total;

    printf("Introduce un numero base\n");
    scanf("%d",&base);
    printf("Introduce un numero exponete\n");
    scanf("%d",&exp);

    pid_t id;

    id = fork();

    if(id != 0){
        total = calPower(base,exp);

        printf("potencia de %d elevado %d es %d\n",base,exp,total);
        wait(NULL);

    }else{
       total = (int)pow((double)base,(double)exp);
       printf("potencia de %d elevado %d es %d\n",base,exp,total);
    }

    return 0;
}