#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    char *argcs[] = {"cal",NULL};

    if(execvp(argcs[0],argcs) == -1){
        perror("Error no existe comando");
        return 1;
    }
    
   return 0;
}