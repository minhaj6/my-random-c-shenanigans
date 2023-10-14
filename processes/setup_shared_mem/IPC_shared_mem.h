#pragma once

#include <stdbool.h>

/* 
* attach a shared memory block
* associate mem block with filename
* create file if it doesn't exist
*/
char *attach_memory_block(char *filename, int size);
bool detach_memory_block(char *block);
bool destroy_memory_block(char *filename);

#define BLOCK_SIZE 4096
#define FILENAME "mysharedmemory.c"