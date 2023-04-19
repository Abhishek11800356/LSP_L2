#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* roll_dice() {
    int value = (rand() % 6) + 1;
    int* result = malloc(sizeof(int));
    *result = value;
    // printf("%d\n", value);
    printf("Thread result: %p\n", result);// pointer address of result variable 
    return (void*) result;
}

int main(int argc, char* argv[]) {
    int* res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        perror("Failed to create thread");
    }
    if (pthread_join(th, (void**) &res) != 0) {
        perror("Failed to join");
    }
    printf("Main res: %p\n", res); // pinter addres of res 
				   // both result and the res are pointing to a single location.
    printf("Result: %d\n", *res);
    free(res); // so if we free up res it makes sure result is also got freed.
    return 0;
}
