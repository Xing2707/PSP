#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <openssl/evp.h>
#include <time.h>
#include "./md5.c"


#define ASCIIA 97
#define ASCIIZ 122
#define STRSIZE 5
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3

void descifrar(int valor,char *myString){
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;
   
    char *hashs[] = {"582fc884d6299814fbd4f12c1f9ae70f","74437fabd7c8e8fd178ae89acbe446f2","28ea19352381b8659df830dd6d5c90a3","90f077d7759d0d4d21e6867727d4b2bd"};
    int lenght = sizeof(hashs) / sizeof(hashs[ZERO]);
    myString[ZERO] = valor;

    for(int y = ASCIIA; y <= ASCIIZ; y++){
        myString[ONE] = y;
        for(int j = ASCIIA; j <= ASCIIZ; j++){
            myString[TWO] = j;
            for(int k = ASCIIA; k <= ASCIIZ; k++){
                myString[THREE] = k;
                for(int l = ZERO; l < lenght; l++){
                    generateMD5(myString,result);
                    if(strcmp(result,hashs[l]) == ZERO){
                        printf("%s es: %s\n",hashs[l],myString);
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]){
    char myString[STRSIZE];
    double cup_time_used = ZERO;
    clock_t star,end;

    star = clock();
    pid_t id;

    for (int i = ASCIIA; i <= ASCIIZ; i++)
    {
        id = fork();
        if(id == ZERO){
            descifrar(i,myString);
            exit(ZERO);
        }
    }
    for (int i = ASCIIA; i <= ASCIIZ; i++)
    {
        if(id != ZERO){
            wait(NULL);
            end = clock();
            cup_time_used += ((double) (end - star))/CLOCKS_PER_SEC;
            if(i == ASCIIZ){
                printf("Tiempo de ejecucion : %.5f",cup_time_used);
            }
            
        }
    }
    
    return 0;
}
