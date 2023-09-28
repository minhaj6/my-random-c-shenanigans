/* moving values into global variable `val`
 * using default at&t syntax assembly
 */
#include <iostream>
using namespace std;

int val = 0;

int main(void) {
    asm volatile("pushq %rax\n");       /* push rax into stack */
    asm volatile("movq $5, %rax\n");    /* move 5 into rax */
    asm volatile("movq %rax, val\n");   /* move rax into val */
    asm volatile("popq %rax\n");        /* pop rax from the stack */

    cout << "Val = " << val << endl;
}
