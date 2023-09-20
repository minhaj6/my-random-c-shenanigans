// compile: gcc random-ssl.c -lcrypto

#include <stdio.h>
#include <stdlib.h>
#include <openssl/rand.h>

int main(int argc, char **argv) {
    char bytes[100];
    RAND_pseudo_bytes(bytes, 100);
    printf("%d\n", bytes);
    return 0;
}
