#include <stdio.h>
#include <unistd.h>

void update_bar(int prog);

const int PROG_BAR_LENGTH = 40;

int main(void) {
    for (int i=0; i<=100; i++) {
        update_bar(i);
        usleep(20000);
    }
    printf("\n");
}

void update_bar(int percent_done) {
    int num_char = (percent_done * PROG_BAR_LENGTH) / 100;
    printf("\r[");
    for (int i=0; i<num_char; i++) {
        printf("#");
    }
    
    for (int i=0; i < (PROG_BAR_LENGTH - num_char); i++) {
        printf(" ");
    }
    
    printf("] %d%% Done", percent_done);
    fflush(stdout);
}