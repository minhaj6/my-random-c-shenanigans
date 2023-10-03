/*
    just a dummy program to look at struct allocation
    in virtual memory...
    gdb a.out eg. ..
    p t
    p sizeof(t)
    x/12xh &t 
    
    x command alternative perceptions
    x/5xh &t - (halfwords)
    x/5i &t - (instr.)
    x/5s &t - (string)
*/

/* the following makes the program slower
    but lower memory requirement. bad
*/
#pragma pack(1) /* no word aligned padding*/

#include <stdio.h>
#include <stdint.h>

typedef struct {
    int8_t hours;
    uint32_t micros;
    uint16_t seconds;
} timestuff_t;

int main() {
    timestuff_t t = {
        .hours = 6,
        .micros = 0x12345678,
        .seconds = 0xDEAD
    };

    printf("%lu", sizeof(t));
}