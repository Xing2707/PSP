#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define READE 0
#define WRITE 1
#define TWO 2
#define ONE 1
#define PAR 0
#define IMPAR 1
#define NUMRANG 20

int received_num; // Variable global para mantener el número recibido

void par_handler(int signum);
void impar_handler(int signum);

int main(int argc, char const *argv[])
{
    int id_hijo[TWO];
    int num;
    int tubo[2];
    pid_t id;
    time_t t;

    if (pipe(tubo) == -ONE) {
        perror("Error! Tubo de conexion no inicializado");
        exit(1);
    }

    for (int i = 0; i < TWO; i++) {
        id = fork();
        if (id == 0) {
            id_hijo[i] = getpid();
            break;
        }
    }

    srand((unsigned)time(&t));

    if (id != 0) {
        close(tubo[READE]);

        for (int i = 0; i < NUMRANG; i++) {
            num = rand() % 100 + ONE;
            if (num % 2 == 0) {
                write(tubo[WRITE], &num, sizeof(num));
            } else {
                write(tubo[WRITE], &num, sizeof(num));
            }
        }

        close(tubo[WRITE]);
    }

    if (id == 0) {
        close(tubo[WRITE]);

        signal(SIGUSR1, par_handler);
        signal(SIGUSR2, impar_handler);

        while (read(tubo[READE], &received_num, sizeof(received_num)) > 0) {
            kill(getppid(), SIGUSR1);
        }
        exit(0); 
    }
    for (int i = 0; i < TWO; i++) {
        wait(NULL);
    }

    return 0;
}

void par_handler(int signum) {
    if (received_num % 2 == 0) {
        printf("Soy hijo par. Número par: %d\n", received_num);
    }
}

void impar_handler(int signum) {
    if (received_num % 2 != 0) {
        printf("Soy hijo impar. Número impar: %d\n", received_num);
    }
}