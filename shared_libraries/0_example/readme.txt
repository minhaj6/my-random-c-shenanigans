This repository shows how to create and handle a shared c library.
So that I don't forget later...


`nm` prints symbols from object files
nm main.o

# Only the compilation output, no linking
gcc -c -o main.o main.c

# Compiling a shared library
gcc -o libmmath.so -fpic -shared libmmath.c

# Link with the shared library 
## the lib at the front and the .so in the back is assumed
gcc main.o -o main -lmmath -L$(pwd/libmmath)

# Run the program 
LD_LIBRARY_PATH=./libmmath ./main

# See the shared libraries linked against
ldd main

File structure 
.
├── libmmath
│   ├── libmmath.c
│   └── libmmath.so
├── main
├── main.c
├── main.o
└── readme.txt

2 directories, 6 files
