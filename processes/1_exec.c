/*
exec replaces the current process with a different program
*/

#include <stdio.h>
#include <unistd.h>

int main(void) {
    if (fork() == 0) {
        printf("I am the child process\n");
        execlp("ls", "ls", "-al", NULL);
        printf("Execlp is done\n"); // this never executes
    } else {
        printf("I am the parent process\n");
    }
}