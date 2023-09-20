#include <stdio.h>
#include <stdint.h>

uint8_t mem[2][8] = {{2,2,2,2, 2,2,2,2}, {2,2,2,2, 2,2,2,2}};

uint8_t afunc(void* arg);

int main() {
    afunc((void*)mem);
    return 0;
}

uint8_t afunc(void* arg) {
    uint8_t* ptmp[2] = {0,0};

    ptmp[0] = (uint8_t*)arg;
    ptmp[1] = ptmp[0] + 8;

    uint8_t value = *ptmp[0];
}
