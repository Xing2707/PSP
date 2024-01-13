#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#define TWO 2
#define ONE 1
#define READ 0
#define WRITE 1

void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

int main(int argc, char *argv[]){
    int num[3];
    int tubo[TWO];
    pid_t id;
    time_t t;

    if(pipe(tubo) == -ONE){
            perror("Error! conexion con el tubo no establecido!");
        }   
    
    id = fork();

    if(id == -1){
        perror("Error! clonacion ha sido fallado");
    }
    if(id != 0){
        srand((unsigned)time(&t));

        num[0] = rand() %100 +1;
        num[1] = rand() %100 +1;
        num[2] = rand() %100 +1;
        
        close(tubo[READ]);

        write(tubo[WRITE],num,sizeof(num));
        close(tubo[WRITE]);
    }else
    {
        wait(NULL);
        close(tubo[WRITE]);
        read(tubo[READ],num,sizeof(num));

        int mayor = 0,menor = 0,medio = 0,size = 0;
            size = sizeof(num) / sizeof(num[0]);
            selectionSort(num,size);
            mayor = num[size-ONE];
            medio = num[ONE];
            menor = num[0];
        FILE *f;
        f = fopen("file.txt","w");
        fprintf(f,"%d %d %d",mayor,medio,menor);
        fclose(f);
    }
    return 0;
}