#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());
    } else {
        // Parent process doesn't wait, causing the child to become a zombie
        printf("Parent Process: PID = %d\n", getpid());
        sleep(10);  // Let the parent process sleep
    }

    return 0;
}
