#include <stdio.h>
#include <stdlib.h>

int main() {
    // array of 5 int
    int *arr = malloc(sizeof(int) * 5);

    arr[1] = 1337;
    arr[2] = 1024;

    for (int i=0; i<5; i++) {
        printf("%d: %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
