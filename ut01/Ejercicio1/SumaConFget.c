#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   char input[100];
    int num1,num2,total;

    printf("introduce 1º numero para hace suma\n");
    fgets(input,sizeof(input),stdin);

    num1 = atoi(input);

    printf("introduce 2º numero para hace suma\n");
    fgets(input,sizeof(input),stdin);

    num2 = atoi(input);

    total =  num1 + num2;

    printf("%d + %d = %d \n",num1,num2,total);
    
    return 0;
}
