#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    int file = open("output.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(file < 0){
        perror("Error in writing output.txt");
        return 1;
    }

    char *argcs[] = {"ls","-a",NULL};
    dup2(file,STDOUT_FILENO);

    execvp(argcs[0],argcs);

    close(file);

    return 0;
}