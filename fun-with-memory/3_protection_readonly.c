/* 
    This piece demonstrates memory protection.
    Minimum unit of read-only protection is a Page.
     
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    char *p1 = malloc(sizeof(char) * 50);
    printf("p1: %p\n", p1);
    
    return EXIT_SUCCESS;
    
}