#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Create a new process using fork()

    if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());
    } else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());
    }

    return 0;
}
