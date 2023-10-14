#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// kill -USR1 11883

volatile sig_atomic_t usr1_variable;

void sigusr1_handler(int sig) {
    usr1_variable = 1;
}

int main(void) {
    struct sigaction sa = {0};
    sa.sa_handler = sigusr1_handler;

    usr1_variable = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Sigaction");
        exit(1);
    }
    
    while (!usr1_variable) {
        printf("PID: %d, working hard....\n", getpid());
        sleep(1);
    }
    
    puts("Ending the program...");
}