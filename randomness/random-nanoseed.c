#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){

    // seeding the rand with nanosecond time
    struct timespec ts;

    timespec_get(&ts, TIME_UTC);
    srand(&ts.tv_nsec);

    printf("%d\n", rand());

    return 0;
}
