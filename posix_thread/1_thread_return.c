#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* task1(void *arg) {
    int *iptr = (int *)malloc(sizeof(int));
    *iptr = 10;
    for (int i=0; i<10; i++) {
        printf("%d - Task 1\n", *iptr);
        (*iptr)++;
        sleep(1);
    }
    return iptr;
}

void other_task(void) {
    for (int i=0; i<10; i++) {
        printf("%d - Hello from other task\n", i);
        sleep(1);
    }
}

int main(int argc, char **argv) {
    int *task1_return;
    pthread_t newthread;
    pthread_create(&newthread, NULL, task1, NULL);

    other_task();

    pthread_join(newthread, (void*)&task1_return);
    printf("Task1 done, *task1_return = %d\n", *task1_return); 
    
    return 0;
}