#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

/* atomic keyword was added in C11 */

#define BIG 1000000000UL
_Atomic uint64_t atomic_counter = 0;

void* count_to_big(void *arg) {
    for (uint32_t i=0; i<BIG; i++) {
        atomic_counter++;
        /*
        atomic_counter = counter_atomics + i; is not atomics 
        the amount of atomic operation is limited
        */
    }
    return NULL;
}

int main(int argc, char **argv) {
    printf("Big atomic_counter ahead\n");

    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, count_to_big, NULL);
    pthread_create(&thread2, NULL, count_to_big, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Counter = %ld\n", atomic_counter); 
}
