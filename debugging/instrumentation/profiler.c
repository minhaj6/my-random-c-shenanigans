/* 
Compile with -finstrument-functions flag 
*/
#include <stdio.h>

void __cyg_profile_func_enter(void *this_func, void *call_site) 
__attribute__((no_instrument_function));

void __cyg_profile_func_exit(void *this_func, void *call_site) 
__attribute__((no_instrument_function));

void __cyg_profile_func_enter(void *this_func, void *call_site) {
    printf("--> %p %p\n", this_func, call_site);
}
void __cyg_profile_func_exit(void *this_func, void *call_site) {
    printf("<-- %p %p\n", this_func, call_site);
}

void f1(void) {
    printf("f1\n");
}

void f2(void) {
    printf("f2\n");
    f1();
}


int main(void) {
    f1();
    f2();
    
    return 0;
}