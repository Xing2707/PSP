#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pids[3];

    for (int i = 0; i < 3; ++i) {
        if ((child_pids[i] = fork()) == 0) {
            // 子进程
            printf("Child process %d\n", i);
            exit(42 + i);  // 子进程退出，退出码为42+i
        } else if (child_pids[i] < 0) {
            // fork失败
            perror("fork");
            return 1;
        }
    }

    // 父进程
    for (int i = 0; i < 3; ++i) {
        int status;
        waitpid(child_pids[i], &status, 0);  // 等待指定的子进程退出

        if (WIFEXITED(status)) {
            printf("Child %d exited with status: %d\n", i, WEXITSTATUS(status));
        }
    }

    printf("Parent process\n");

    return 0;
}
