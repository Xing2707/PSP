#include <stdio.h>
#define CINCO 5
#define UNO 1

int main(void){
    double notas[CINCO];
    double mayo = 0, meno = 0, media = 0;

    for(int i = 0; i < CINCO; i ++)
    {
        int validInput = 0;
        do{
            printf("Introduce nota de %dº examen\n",i+UNO);
            if(scanf("%lf",&notas[i]) == UNO){
                validInput = UNO;
            }else{
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                printf("Error Introduce un numero valido\n");
            
            }
        }while(!validInput);
        
        media += notas[i];
        
        if(mayo < notas[i]) mayo = notas[i];

        if(meno == 0) meno = notas[i];

        if(meno > notas[i]) meno = notas[i];
    }
        media = media/CINCO;

        printf("Las notas introducidos: \nmas alta es %.2lf\nmas baja es %.2lf\nla nota media es %.2lf ",mayo,meno,media);
        if(media >= CINCO)
        {
            printf("estas aprobado\n");
        }
        else
        {
            printf("no estas aprobado\n");
        }

    return 0;
}