#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    // Print values before swap
    printf("Before swap: x = %d, y = %d\n", x, y);

    // Call swap function
    swap(&x, &y);

    // Print values after swap
    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}
