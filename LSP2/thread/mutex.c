#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

long mails = 0;
pthread_mutex_t mutex;

void* routine() {
    for (long i = 0; i < 100000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
        // read mails
        // increment
        // write mails
    }
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2, p3, p4;
    pthread_mutex_init(&mutex, NULL); // Initializing the mutex
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
        perror("Error in Creating Thread 1");
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
        perror("Error in Creating Thread 2");
    }
    if (pthread_create(&p3, NULL, &routine, NULL) != 0) {
        perror("Error in Creating Thread 3");
    }
    if (pthread_create(&p4, NULL, &routine, NULL) != 0) {
        perror("Error in Creating Thread 4");
    }
    if (pthread_join(p1, NULL) != 0) {
        perror("Error in joining Thread 1");
    }
    if (pthread_join(p2, NULL) != 0) {
        perror("Error in joining Thread 2");
    }
    if (pthread_join(p3, NULL) != 0) {
	    perror("Error in joining Thread 3");
    }
    if (pthread_join(p4, NULL) != 0) {
        perror("Error in joining Thread 4");
    }
    pthread_mutex_destroy(&mutex); //// destroying the mutex
    printf("Number of mails: %ld\n", mails);
    return 0;
}
