#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();  // Create first child process
    int status;

    if (pid1 == 0) {
        // First child process
        printf("First Child Process: PID = %d\n", getpid());
    } else {
        wait(&status);  // Parent waits for the first child to finish

        pid_t pid2 = fork();  // Create second child process
        if (pid2 == 0) {
            // Second child process
            printf("Second Child Process: PID = %d\n", getpid());
        } else {
            waitpid(pid2, &status, 0);  // Parent waits for the second child to finish
            printf("Parent Process: PID = %d\n", getpid());
        }
    }

    return 0;
}
