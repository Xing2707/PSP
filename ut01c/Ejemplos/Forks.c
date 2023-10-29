#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    pid_t id;
    for (int i = 0; i < 2; i++)
    {
        id = fork();

        printf("Soy %d y mi hijo es %d\n",getpid(),id);
    }
    
}