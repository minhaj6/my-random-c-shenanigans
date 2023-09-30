#include <stdio.h>

int main(void) {
    int x = 4;
    int *x_ptr = &x;
    int **x_double_ptr = &x_ptr;

    printf("x=%d, x_ptr=%p\n", x, x_ptr);
    printf("*x_ptr=%d\n", *x_ptr);
    printf("x_double_ptr=%p\n", x_double_ptr);
    printf("*x_double_ptr=%p\n", *x_double_ptr);
    printf("**x_double_ptr=%d\n", **x_double_ptr);

    return 0;
}
