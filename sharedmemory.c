#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>

#define ARRAY_SIZE 100
#define SHM_SIZE (ARRAY_SIZE * sizeof(int))

int main() {
    int shmid;
    key_t key;
    int *array_ptr;
    pid_t child_pid;

    // Generate a unique key
    key = ftok(".", 'x');
    if (key == -1) {
        perror("ftok error");
        exit(1);
    }

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget error");
        exit(1);
    }

    // Fork a child process
    child_pid = fork();
    if (child_pid < 0) {
        perror("fork error");
        exit(1);
    } else if (child_pid == 0) {
        // Child process (reader)
        array_ptr = (int *)shmat(shmid, NULL, 0);
        if (array_ptr == (int *)-1) {
            perror("shmat error (child)");
            exit(1);
        }

        // Wait for the parent process to write data
        sleep(1);  // Adding sleep to ensure parent writes before child reads

        // Read and sum the array elements
        int sum = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            sum += array_ptr[i];
        }
        printf("In child process (reader), sum: %d\n", sum);

        // Detach the shared memory segment
        shmdt(array_ptr);
    } else {
        // Parent process (writer)
        array_ptr = (int *)shmat(shmid, NULL, 0);
        if (array_ptr == (int *)-1) {
            perror("shmat error (parent)");
            exit(1);
        }

        // Write data to the shared memory
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array_ptr[i] = i + 1;  // Store integers from 1 to ARRAY_SIZE
        }

        // Wait for the child process to complete
        wait(NULL);

        // Detach the shared memory segment
        shmdt(array_ptr);

        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}