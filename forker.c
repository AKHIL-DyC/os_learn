#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int pid, pid1, pid2;
    pid = fork(); // Create a new process

    if (pid < 0) {
        // fork() failed
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // This is the child process
        pid1 = getpid(); // Get the PID of the child process
        pid2 = getppid(); // Get the PID of the parent process
        printf("Child process:\n");
        printf("Child PID: %d\n", pid1);
        printf("Parent PID: %d\n", pid2);
    } else {
        // This is the parent process
        pid1 = getpid(); // Get the PID of the parent process
        printf("Parent process:\n");
        printf("Parent PID: %d\n", pid1);
        printf("Child PID: %d\n", pid); // pid contains the PID of the child process
    }

    return 0;
}
