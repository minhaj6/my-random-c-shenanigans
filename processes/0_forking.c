#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // getpid(), fork()
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int child_exit_status;
    
    switch(pid = fork()) {
        case -1:
            perror("Fork");
            exit(1);             // parent exits
        
        case 0:
            printf("CHILD: This is child process\n");
            printf("CHILD: Child PID = %d\n", getpid());
            printf("CHILD: Parent PID = %d\n", getppid());
            printf("CHILD: Exiting with return value 45\n");
            child_exit_status = 45;
            exit(child_exit_status);
        
        default:
            printf("PARENT: This is parent process\n");
            printf("PARENT: Child PID = %d\n", pid);
            printf("PARENT: My PID = %d\n", getpid());
            printf("PARENT: Waiting for child process to exit\n");
            
            wait(&child_exit_status);

            printf("PARENT: Child process exit status is: %d\n", WEXITSTATUS(child_exit_status));
            printf("PARENT: Exiting...");
    }
    
    return 0;
}