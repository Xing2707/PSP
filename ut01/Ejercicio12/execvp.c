#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    char *argcs[] = {"ip","a",NULL};
    if(execvp(argcs[0],argcs) == -1){
        perror("Erro! Ejecucion de comando");
        return 1;
    }

    return 0;
}
