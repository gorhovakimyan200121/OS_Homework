#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* threadFunction(void* id){
    for (int i = 1; i < 6; i++){
        printf("Thread with ID %lu is running with number %d\n", pthread_self(), i);
    }
    return NULL;
}

int main()
{
    int threadNumber = 3;
    pthread_t threads[threadNumber];
    
    for (int i = 0; i < threadNumber; i++){
        if (pthread_create(&threads[i], NULL, threadFunction, NULL) != 0){
            printf("Faild to create thread!!!");
            exit(1);
        }
    }
    
    for (int i = 0; i < threadNumber; i++){
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Failed to join thread");
            return 1;
        }
    }
    
    return 0;
}