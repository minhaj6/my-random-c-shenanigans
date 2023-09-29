#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* first_thread(void *arg) {
    /* doing something with the received arg */
    int *number_ptr = (int *)arg;

    for (int i=0; i<8; i++) {
        printf("%d - first thread\n", *number_ptr);
        (*number_ptr)++;
        sleep(1);
    }
    return NULL;
}

void* second_thread(void *arg) {
    for (int i=0; i<3; i++) {
        printf("%d - second thread\n", i);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char **argv){
    // variable to send into the thread
    int number = 10;
    pthread_t newthread;
    /* variable no send, no return */
    // pthread_create(&newthread, NULL, first_thread, NULL);

    /* passing one variable to the thread */
    pthread_create(&newthread, NULL, first_thread, &number);

    second_thread(NULL);
    
    pthread_join(newthread, NULL);
    printf("Threads finished\n");
    
    printf("Final value of number: %d", number);
    
    return 0;
}