#include <stdio.h>


int add(int a, int b) {return a+b;}
int mult(int a, int b) {return a*b;}

int do_operation ( int (*op) (int, int), int x, int y) {
    return op(x, y);
}

int main (int argc, char **argv) {
    int result1 = do_operation(add, 5, 25);
    int result2 = do_operation(mult, 5, 8);

    printf("result1 = %d\n", result1);
    printf("result2 = %d\n", result2);

    return 0;
}
