/*
    `pmap` shows memory map of a process
    `strace` shows syscalls
    compile:
        gcc -g -Wall -nostdlib 4_pmap_smallest_c.c
        ./strace ./a.out
        ps aux | grep a.out  // check the process id (4122)
        pmap 4122

*/

void _start() {
    while(1);
}