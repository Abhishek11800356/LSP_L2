#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

long mail = 0;
pthread_mutex_t mutex;

void* routine() {
    for (long i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);
        mail++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char* argv[]) {
	int n;
	printf("Enter no. of threads you want to create\n");
	scanf("%d",&n);
    pthread_t th[n];
    int i;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < n; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Failed to create thread");
        }
        printf("Thread %d has started\n", i);
    }
    for (i = 0; i < n; i++) {
        if (pthread_join(th[i], NULL) != 0) {
           perror("Thread joining failed");
        }
        printf("Thread %d has finished execution\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %ld\n", mail);
    return 0;
}
