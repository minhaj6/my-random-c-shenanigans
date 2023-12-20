#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define PAGESIZE 4096

uint8_t non_shared_memory = 5;

int main(void) {
    uint8_t *shared_memory = mmap(NULL, PAGESIZE,
                                PROT_READ | PROT_WRITE,
                                MAP_SHARED | MAP_ANON, -1, 0);
    
    *shared_memory = 35;

    if (fork() == 0) {
        *shared_memory = 15;
        non_shared_memory = 80;
    } else {
        wait(NULL);
    }
    
    printf("Shared memory: %d\n", *shared_memory);
    printf("Non shared memory: %d\n", non_shared_memory);
}