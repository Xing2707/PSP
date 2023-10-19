#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <openssl/evp.h>
#include "./md5.c"
#include <time.h>

#define ASCIIA 97
#define ASCIIM 109
#define ASCIIN 110
#define ASCIIZ 122
#define STRSIZE 5
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3

int main(int argc, char *argv[]){
    unsigned char result[EVP_MAX_MD_SIZE];
    unsigned int result_len;

    char myString[STRSIZE];
    char *hashs[] = {"582fc884d6299814fbd4f12c1f9ae70f","74437fabd7c8e8fd178ae89acbe446f2","28ea19352381b8659df830dd6d5c90a3","90f077d7759d0d4d21e6867727d4b2bd"};
    int lenght = sizeof(hashs) / sizeof(hashs[ZERO]);
    pid_t id;

    clock_t star,end;

    double cup_time_used;

    star = clock();

    id = fork();

    if(id != 0){
        for(int i = ASCIIA; i <= ASCIIM; i ++){
            myString[ZERO] = i;
            for(int y = ASCIIA; y <= ASCIIZ; y++){
                myString[ONE] = y;
                for(int j = ASCIIA; j <= ASCIIZ; j++){
                    myString[TWO] = j;
                    for(int k = ASCIIA; k <= ASCIIZ; k++){
                        myString[THREE] = k;
                        for(int l = 0; l < lenght; l++){
                            generateMD5(myString,result);
                            if(strcmp(result,hashs[l]) == 0){
                                printf("%s es: %s\n",hashs[l],myString);
                            }
                        }
                    }
                }
            }
        }

        wait;

        end = clock();
        cup_time_used = ((double) (end - star)) / CLOCKS_PER_SEC;
        printf("tiempo de ejecucion : %.5f\n",cup_time_used);
    }else{
        for(int i = ASCIIN; i <= ASCIIZ; i ++){
            myString[ZERO] = i;
            for(int y = ASCIIA; y <= ASCIIZ; y++){
                myString[ONE] = y;
                for(int j = ASCIIA; j <= ASCIIZ; j++){
                    myString[TWO] = j;
                    for(int k = ASCIIA; k <= ASCIIZ; k++){
                        myString[THREE] = k;
                        for(int l = 0; l < lenght; l++){
                            generateMD5(myString,result);
                            if(strcmp(result,hashs[l]) == 0){
                                printf("%s es: %s\n",hashs[l],myString);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}