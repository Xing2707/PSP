#include <stdio.h>
#include <ctype.h>

int main(void){
    int total = 0;
    int convertInt = 0;
    char caracte;

     printf("Introduce numero de suma \nPara salir y ver total introduce q\n");

    do
    {
        caracte = getchar();
        if(caracte >= '0' && caracte <= '9'){

            convertInt = convertInt * 10 +(caracte - '0');
            if(caracte != 'q'){
                total += convertInt;
            }
            convertInt = 0;
        }
        
        
    } while (tolower(caracte) != 'q');

    printf("Suma total de los numeros es: %d \n\n",total);
    
    return 0;
}