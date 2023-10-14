#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(int sig) {
    const char msg[] = "SIGINT received\n";
    write(0, msg, sizeof(msg));
}

int main(void) {
    struct sigaction sa = {0};
    sa.sa_handler = sigint_handler;
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Sigaction");
    }
    
    printf("Enter a string - \n");

    char buffer[200];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        perror("fgets");
    } else {
        printf("You entered - %s\n", buffer);
    }
}