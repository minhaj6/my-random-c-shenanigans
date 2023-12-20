#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

typedef void * (*malloc_like_function) (size_t);
typedef void (*free_like_function) (void *);

static malloc_like_function sysmalloc = NULL;
static free_like_function sysfree = NULL;
static bool init = false;

void initcheck() {
    if (!init) {
        sysmalloc = (malloc_like_function)dlsym(RTLD_NEXT, "malloc");
        sysfree = (free_like_function)dlsym(RTLD_NEXT, "free");
    }
}

void* malloc(size_t size) {
    initcheck();
    void *result = sysmalloc(size);
    return result;
}

void free(void *p) {
    initcheck();
    sysfree(p);
}