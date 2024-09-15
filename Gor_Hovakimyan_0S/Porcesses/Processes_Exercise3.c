#include <stdio.h>
#include <stdlib.h>

void cleanup1() {
    printf("Cleanup function 1 executed.\n");
}

void cleanup2() {
    printf("Cleanup function 2 executed.\n");
}

int main() {
    atexit(cleanup1);  // Register cleanup1 to run at program termination
    atexit(cleanup2);  // Register cleanup2 to run at program termination

    printf("Program is about to terminate.\n");

    // Test by calling exit
    exit(0);

    return 0;
}
