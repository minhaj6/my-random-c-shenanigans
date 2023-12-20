# Fun with Memory

### 0_memory_usage.c
Demonstrates how memory resident set size increases with dynamic allocation. Uses `sys/resources.h` functionalities of glibc.

### 1_memory_gdb.c
Just a dummy script to practice debugging with GDB. Uses `#pragma pack(1)` so that the program dont have memory aligned padding

### 2_valgrind_case.c
Deliberately leak memory to test with valgrind tool.

### 3_protection_readonly.c
Uses mmap() to add readonly attribute to a piece of ram. Uses `sys/mman.h`, sysconf(), posix_memalign(), mprotect(), etc interesting functions. 

### 4_pmap_smallest_c.c
Tries to write and compile smallest C code possible. 

    `pmap` shows memory map of a process
    `strace` shows syscalls

    compile:
        gcc -g -Wall -nostdlib 4_pmap_smallest_c.c
        ./strace ./a.out
        ps aux | grep a.out  // check the process id (4122)
        pmap 4122

### 5_shared_memory_mmap()
Shows how to share a memory between two processes by setting attribute with mmap() and fork()ing. 