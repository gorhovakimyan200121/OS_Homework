#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* square(void* number){
    int n = (int*) number;
    printf("%d square is %d\n", n, n*n);
    return NULL;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    pthread_t threads[sizeof(arr)/sizeof(int)];
    
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++){
        if (pthread_create(&threads[i], NULL, square, (void*) arr[i]) != 0){
            printf("Faild to create thread!!!");
            exit(1);
        }
    }
    
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++){
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Failed to join thread");
            return 1;
        }
    }
    
    return 0;
}