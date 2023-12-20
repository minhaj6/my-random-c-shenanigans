#include <stdio.h>
#include <stdlib.h>  // malloc()
#include <string.h>  // memset()
#include <sys/resource.h> // getrusage()

/* man getrusage */

long get_resident_usage() {
    struct rusage myusage;  // rusage struct is defined in sys/resource.h

    // RUSAGE_SELF = Just the current process
    // RUSAGE_CHILDREN = All child process that has terminated
    // https://sourceware.org/glibc/manual/2.38/html_node/Resource-Usage.html

    getrusage(RUSAGE_SELF, &myusage);

    // The maximum resident set size used, in kilobytes. That is, the maximum 
    // number of kilobytes of physical memory that processes used simultaneously.
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