#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv) {
    char *file = argv[1];    // name of the file
    int fd;

    struct flock lock;
    
    printf("Opening the file: %s\n", argv[1]);
    fd = open(file, O_WRONLY);
    printf("Got the file, locking it..\n");
    
    // zeroing out the struct
    memset(&lock, 0, sizeof(lock));

    lock.l_type = F_WRLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("The file is locked.\n");    
    
    getchar(); // just for a pause
               // 
    printf("Releasing the lock\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    close(fd);

    return 0;
}