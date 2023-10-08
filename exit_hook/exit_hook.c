#include <stdio.h>
#include <stdlib.h>

void cleanup(void) {
    printf("Exiting. Thank you!");
}

int main(int argc, char **argv) {
    atexit(cleanup);    // this function gets called on exit
                        // not called on abort() or crashes
                        // can have multiple atexit()
                        // maximum 32 function pointers.
    
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int value = atoi(argv[1]);
    printf("%d^2 == %d\n", value, value*value);
    return EXIT_SUCCESS;
}