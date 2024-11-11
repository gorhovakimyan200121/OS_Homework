#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* calculatePartialSum(void* arr){
    int* array = (int*) arr;
    int sum = 0;
    for (int i = 0; i < sizeof(array)/sizeof(int); i++){
        sum = sum + array[i];
    }
    printf("sum is %d\n", sum);
    return NULL;
}

int main()
{
    int array[] = {30, 40, 65, 200};
    pthread_t t1;
    pthread_t t2;
    int arrSize = sizeof(array)/sizeof(int);
    int firstPartLength = (int)(arrSize/2);
    int secondPartLength = arrSize - firstPartLength;
    
    int arr1[firstPartLength];
    for(int i = 0; i < firstPartLength; i++){
        arr1[i] = array[i];
    }
    
    int arr2[secondPartLength];
    for (int i = 0; i < secondPartLength; i++){
        arr2[i] = array[arrSize - 1 - i];
    }
        
    if (pthread_create(&t1, NULL, calculatePartialSum, (void*) arr1) != 0 & pthread_create(&t2, NULL, calculatePartialSum, (void*) arr2) != 0){
        printf("one of threads not created");
        exit(1);
    }
    
    if (pthread_join(t1, NULL) != 0) {
        printf("Failed to join thread");
        return 1;
    }

    if (pthread_join(t2, NULL) != 0) {
        printf("Failed to join thread");
        return 1;
    }

    return 0;
}