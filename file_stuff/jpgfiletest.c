#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAGIC_NUM_BYTES 3
uint8_t magic_number[MAGIC_NUM_BYTES] = {0};
uint8_t expected_magic_num[MAGIC_NUM_BYTES] = {0xff, 0xd8, 0xff};

void print_debug(void);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        printf("Couldn't open file (%s)\n", filename);
        return EXIT_FAILURE;
    }


    int numbyte_read = fread(magic_number, 1, MAGIC_NUM_BYTES, fp);
    if (numbyte_read != MAGIC_NUM_BYTES) {
        printf("Couldn't read the first three bytes!\n");
        return EXIT_FAILURE;
    }

    if(!memcmp(magic_number, expected_magic_num, MAGIC_NUM_BYTES)) {
        printf("Yes, jpeg\n");
        print_debug();
    } else {
        printf("Bummber, not jpeg\n");
        print_debug();
    }

}

void print_debug(void) {
    printf("Your file signature is - \n");
    for (int i=0; i<MAGIC_NUM_BYTES; i++) {
        printf("%X ", magic_number[i]);
    }
    printf("\n");

    printf("Your expected signature is - \n");
    for (int i=0; i<MAGIC_NUM_BYTES; i++) {
        printf("%X ", expected_magic_num[i]);
    }
    printf("\n");
}