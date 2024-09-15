#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Declare an array of 5 integers
    int *ptr = arr;               // Pointer to traverse the array

    // Print each element using the pointer
    printf("Original array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Modify the values of the array using pointer arithmetic
    for (int i = 0; i < 5; i++) {
        *(ptr + i) += 10;  // Add 10 to each element
    }

    // Print the modified array
    printf("Modified array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i)); // Using pointer
    }
    printf("\n");

    return 0;
}
