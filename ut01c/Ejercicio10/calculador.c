#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        for(int i = 0; i <strlen(argv[1]); i++){
            argv[1][i] = tolower(argv[1][i]);
        }

        int num1,num2,total;
        
        if((argv[2][0] != '0') || (argv[3][0] != '0')){
            printf("Error parametro de entrada solo acepta operacion y numeros \n");
            return 1;
        }

            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);

        if(strcmp(argv[1],"suma") == 0){
            total = num1 + num2;
            printf("%d + %d = %d \n",num1,num2,total);

        }else if(strcmp(argv[1],"resta") == 0){
            total = num1 - num2;
            total = abs(total);
            printf("%d - %d = %d \n",num1,num2,total);
        }else if(strcmp(argv[1],"division") == 0){
            if(num2 != 0){
                total = num1 / num2;
                printf("%d / %d = %d \n",num1,num2,total);
                if(num1 % num2 != 0){
                    int resto = num1 % num2;
                    printf("Resto: %d \n",resto);
                }
            }else{
                printf("Error no puedes dividir entre 0\n");
            }
        }else if(strcmp(argv[1],"multiplicacion") == 0){
            total = num1 * num2;
            printf("%d * %d = %d \n",num1,num2,total);
        }else{
            printf("Error Introduce una operacion valido\n");
        }
        
    }else{
        printf("Error Deben indicar que operacion y los numero para hace operacion\n");
    }
    

    return 0;
}