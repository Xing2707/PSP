#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
    pid_t id;

    int n = 42;
    double pi = 3.14;

    id = fork();

    if(id != 0){
        printf("soy el padre mi id es %d y mi hijo es %d\n",getpid(),id);
        n = 1000;
        scanf("%lf",&pi);
        printf("%d\n",n);
    } else { 
        printf("soy el hijo mi id es %d y mi hijo es %d\n",getpid(),id);
        printf("%d \n",n);
    }

    return 0;
}