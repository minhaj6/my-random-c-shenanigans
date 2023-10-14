#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "IPC_shared_mem.h"

#define IPC_RESULT_ERROR (-1)

static int get_shared_block(char *filename, int size) {
    key_t key;

    // request a key associated with filename
    key = ftok(filename, 0);
    if (key == IPC_RESULT_ERROR) {
        return IPC_RESULT_ERROR;
    }
    
    // get or create shared block
    return shmget(key, size, 0644 | IPC_CREAT);
}

char* attach_memory_block(char *filename, int size) {
    int shared_block_id = get_shared_block(filename, size);
    char *result;
    
    if (shared_block_id == IPC_RESULT_ERROR) {
        return NULL;
    }
    
    // map the share block into current process memory
    result = shmat(shared_block_id, NULL, 0);
    if (result == (char*)IPC_RESULT_ERROR) {
        return NULL;
    }
    
    return result;
}

bool detach_memory_block(char *block) {
    return (shmdt(block) != IPC_RESULT_ERROR);
}

bool destroy_memory_block(char *filename) {
    int shared_block_id = get_shared_block(filename, 0);

    if (shared_block_id == IPC_RESULT_ERROR) {
        return NULL;
    }
    
    return (shmctl(shared_block_id, IPC_RMID, NULL) != IPC_RESULT_ERROR);
}