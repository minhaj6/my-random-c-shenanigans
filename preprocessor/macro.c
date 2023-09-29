#include <stdio.h>

// #define MIN(x, y) ((x) < (y) ? (x) : (y))
// compound macro
#define MIN(A, B) ({ \
                    typeof(A) _a = (A); \
                    typeof(B) _b = (B); \
                    _a < _b ? _a : _b; \
                    })

int getnextnum() {
    int nextnum = rand() * 100;
    printf("next -> %d\n", nextnum);
    return nextnum;
}

int main(int argc, char **argv) {
    printf("%d\n", MIN(45, 95));
    
    // problem 1, with macro, no type check
    // printf("%d\n", MIN(45, "hey there"));
    
    // problem 2, this doesn't work
    // you have to wrap x, y like (x), (y) for it 
    // to evaluate. broken. calls getnextnum three times
    int n1, n2, n3;
    // we can solve it with the compund macro with
    // typeof() and stuff
    n3 = MIN(n1=getnextnum(), n2=getnextnum());
    printf("n3 -> %d\n", n3);

    
    return 0;
}