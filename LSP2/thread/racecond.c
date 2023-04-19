#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

long mails = 0;

void* routine() {
    for (long i = 0; i < 1000000000; i++){ // check for 2 thread and i<10 then i<1000 then i<100000 till here you will not see any issue.
// but when you check for i<1000000000 it becomes alarge no. of iterations and you will see a abrupt change in the output 
// this is because of concurrency and is called race cond.
        mails++;
        // read mails
        // increment
        // write mails
    }
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2, p3, p4;
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_join(p1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(p2, NULL) != 0) {
        return 4;
    } 
    printf("Number of mails: %ld\n", mails);
    return 0;
}
