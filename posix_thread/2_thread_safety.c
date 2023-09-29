#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

/* 
 locks have big overhead
Counter = 1000000000

real    0m15.042s
user    0m14.898s
sys     0m0.002s
*/

#define BIG 1000000000UL
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* count_to_big(void *arg) {
    for (uint32_t i=0; i<BIG; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t thread;
    pthread_create(&thread, NULL, count_to_big, NULL);
    pthread_join(thread, NULL);

    printf("Counter = %d\n", counter);
}
