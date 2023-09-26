// Hace una programa que pide numero para hace calculo de suma.

#include <stdio.h>

int main(void){

    int menu;
    do{
        do{
            printf("            ==============================\n");
            printf("            ==========CALCULADOR==========\n");
            printf("            ==============================\n");
            printf("            | 1. Suma                    |\n");
            printf("            | 2. Resta                   |\n");
            printf("            | 3. Multiplicacion          |\n");
            printf("            | 4. Division                |\n");
            printf("            | 5. Salir                   |\n");
            printf("            ------------------------------\n");

            printf("     Introduce numero de 1 a 5 para hacer operciones de calculador:\n");
            scanf("%d",&menu);
        }while (menu > 5);
        
        int num1;
        int num2;
        int total;
        
        switch (menu)
        {
        case 1:
            printf("   Introduce 1º numero para hace suma: \n");
            scanf("%d",&num1);

            printf("   Introduce 2º numero para hace suma: \n");
            scanf("%d",&num2);

            total = num1 + num2;
            printf("  * la suma de %d + %d es igual: %d *\n\n",num1,num2,total);
            
            break;
        case 2:
            printf("   Introduce 1º numero para hace Resta:\n");
            scanf("%d",&num1);

            printf("   Introduce 2º numero para hace Resta:\n");
            scanf("%d",&num2);

            total = num1 - num2;
            
            printf("  * la resta de %d - %d es igual: %d *\n\n",num1,num2,total);
            break;
        case 3:
            printf("   Introduce 1º numero para hace Multiplicacion:\n");
            scanf("%d",&num1);

            printf("   Introduce 2º numero para hace Multiplicacion:\n");
            scanf("%d",&num2);

            total = num1 * num2;
            
            printf("  * la resta de %d * %d es igual: %d *\n\n",num1,num2,total);
            break;
        case 4:
            printf("   Introduce dividendo:\n");
            scanf("%d",&num1);

            do{
                printf("   Introduce divisor:\n");
                scanf("%d",&num2);

                if(num2 == 0){
                    printf("   Error divisor no puede ser 0!\n");
                }
            }while (num2==0);

            total = num1 / num2;
            int cociente = num1 % num2;

            printf("  * el division de %d / %d es igual: %d,*\n",num1,num2,total);
            if(cociente > 0){
                printf("  * el cociente de division es: %d *\n\n",cociente);
            }else{
                printf("  * este division no tiene cociente *\n\n");
            }
            break;
        case 5:
            printf("            &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
            printf("            &  GRACIAS POR USA ESTE CALCULADOR  &\n");
            printf("            &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
            break;
        }
    }while(menu != 5);

    return 0;
}