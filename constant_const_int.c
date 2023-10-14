#include <stdio.h>
#include <stdbool.h>

/* in the quest of reducing the use of macros,
 * we use const int often. this come with some
 * quirks. 
 */

// #define A 10
const int A = 10;
const int B = A+1; // this works in modern compilers

// this doesn't work outside main()
// int myarray[A];


// this gives trouble with switch case too
// does not compile
// error: case label doesn't reduce to integer constant
bool ifAorB (int value) {
    switch(value) {
        case A:
        case B:
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    // this works
    int myarray[A];

    printf("&A = %p\n", &A);

    return 0;
}
