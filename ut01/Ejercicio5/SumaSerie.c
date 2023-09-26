#include <stdio.h>

double sumSerie(double num){
    const double uno_const = 1;
    double total = 0;
    for (int i = num; i >= uno_const; i--)
    {
        if(i == uno_const){
            total += uno_const;
        }else{
            total += uno_const/i;
        }        
    }

    return total;
}

int main(void){
    double num,total;

    printf("Introduce un numero para hace suma de serie\n");

    scanf("%lf",&num);

    total = sumSerie(num);

    printf("Suma de serie de numero %.2lf es %.2lf\n",num,total);

    return 0;
}