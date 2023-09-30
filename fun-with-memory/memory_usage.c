#include <stdio.h>
#include <stdlib.h>  // malloc()
#include <string.h>  // memset()
#include <sys/resource.h> // getrusage()

/* man getrusage */

long get_resident_usage() {
    struct rusage myusage;

    getrusage(RUSAGE_SELF, &myusage);
    return myusage.ru_maxrss;
}

int main() {
    long baseline = get_resident_usage();

    for (int i=0; i<100; i++) {
        char *p = malloc(1024 * 100);
        memset(p, 1, 1024*100);

        printf("Usage: %ld - %ld\n", 
                    baseline, 
                    get_resident_usage() - baseline);
    }
    return 0;
}