#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int pfds[2];
    char buf[30];

    if (pipe(pfds) == -1) {
        perror("pipe");
        exit(1);
    }
    
    const char in_string[] = "me goin thru a pipe!";
    printf("Writing to file descriptor #%d\n", pfds[1]);
    write(pfds[1], in_string, strlen(in_string));
    printf("Reading from file descriptor #%d\n", pfds[0]);
    read(pfds[0], buf, strlen(in_string));
    printf("Data: \"%s\"\n", buf);
}