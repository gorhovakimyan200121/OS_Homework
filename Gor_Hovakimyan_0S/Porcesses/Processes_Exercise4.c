#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // First child process
        printf("First Child: PID = %d, exiting with status 1\n", getpid());
        exit(1);  // Exit with status 1
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Second child process
        printf("Second Child: PID = %d, exiting with status 2\n", getpid());
        exit(2);  // Exit with status 2
    }

    int status;
    waitpid(pid1, &status, 0);  // Wait for first child
    if (WIFEXITED(status)) {
        printf("First child exited with status %d\n", WEXITSTATUS(status));
    }

    waitpid(pid2, &status, 0);  // Wait for second child
    if (WIFEXITED(status)) {
        printf("Second child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
