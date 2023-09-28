#include <stdio.h>
#include "cow.h"

int main(int argc, char *argv[]) {
    Cow* cow = new_cow();
    cow->speak(cow);
    
    return 0;
}