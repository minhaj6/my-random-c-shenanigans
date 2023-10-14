/*
    sigaction is recommended over signal
*/


#include <stdio.h>
#include <unistd.h> // sleep(), getpid()
#include <signal.h>

void handler(int num) {
    // signal handler is async. printf is not async safe.
    // man signal-safety for more
    write(STDOUT_FILENO, "I won't get killed\n", 20);
}

int main(void) {
    signal(SIGINT, handler);
    /*
        signal(SIGTERM, handler);
        signal(SIGKILL, handler);
        signal(SIGSEGV, handler);    // segfault signal

        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);  // custom signal
    */

    while(1) {
        printf("Wasting your cycles brug, pid - %d\n", getpid());
        sleep(1);
    }
}