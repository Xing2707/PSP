#include <stdio.h>
#include <stdbool.h>

bool isPrimo(int num){
    if(num <= 1){
        return false;
    }

    for(int i = 2; i * i < num; i++){
        if(num % 2 == 0){
            return false;
        }
    }

    return true;
}

int main(void){

    int num;

    printf("Introduci un numero para hacer calculo de numero primo\n");
    
    
    scanf("%d",&num);
    
    if(isPrimo(num)){
        printf("%d es un numero primo.\n",num);
    }else{
        printf("%d no es un numero primo.\n",num);
    }
    
}