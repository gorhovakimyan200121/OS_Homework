#include <stdio.h>

int main() {
    int num = 10;          // Declare and initialize an integer variable
    int *ptr = &num;       // Declare a pointer pointing to the integer

    // Print the address of the integer using the variable and pointer
    printf("Address of num using variable: %p\n", (void*)&num);
    printf("Address of num using pointer: %p\n", (void*)ptr);

    // Modify the value using the pointer
    *ptr = 20;

    // Print the new value of the integer
    printf("New value of num: %d\n", num);

    return 0;
}
