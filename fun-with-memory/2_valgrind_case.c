/* We deliberately leak memory as a test case for 
* valgrind. 
* gcc -g valgrind_case.c
* valgrind ./a.out
*/
#include <stdio.h>
#include <stdlib.h>

#define NUMINTS 100

int main() {
    int *myarray = malloc(sizeof(int)*NUMINTS);
    for (int i=0; i<=NUMINTS; i++) {
        myarray[i] = i;
    }
    
    printf("Done\n");
}