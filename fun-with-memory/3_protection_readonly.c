/* 
    This piece demonstrates memory protection.
    Minimum unit of read-only protection is a Page.
     
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h> // sysconf() lives here

int main(void) {
    int pagesize = sysconf(_SC_PAGE_SIZE); // system config page size
    if (pagesize == -1) {
        perror("sysconf");
    }
    printf("Pagesize: %d\n", pagesize);

    int buffersize = 2 * pagesize;
    
    char *p1 = malloc(sizeof(char) * 50);
    printf("p1: %p\n", p1);
    
    char *p2, *p3;
    // first method
    if(posix_memalign((void**)&p2, pagesize, buffersize)) {
        perror("posix memalign");
    } // allocates 2 pages of memeory

    // second method
    p3 = mmap(NULL, buffersize, PROT_READ | PROT_WRITE,
                MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    
    if (p3 == MAP_FAILED) {
        perror("mmap");
    }
    
    printf("p2: %p\n", p2);
    printf("p3: %p\n", p3);
    
    printf("Writing to memory...\n");
    memset(p2, 5, buffersize);
    memset(p3, 5, buffersize);
    printf("Writing done!\n");
    

    // make the second page of p2 readonly
    if (mprotect(p2+pagesize, pagesize, PROT_READ) == -1){
        perror("mprotect");
    }
    
    // this will segfault when exceeding the first page 
    // as per previous memprotect() PROT_READ
    for (int i=0; i<buffersize; i++) {
        printf("%d (%p): writing...\n", i, p2+i);
        p2[i] = 3;
    }

    return EXIT_SUCCESS;
    
}