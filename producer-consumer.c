
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // for sleep()
#include <stdlib.h> // for rand()

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2
#define MAX_ITEM 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, empty, full;

void* producer(void* arg) {
    int item;
    for (int i = 0; i < MAX_ITEM; i++) {
        item = rand() % 100; 
        sem_wait(&empty);    // Wait for an empty slot in the buffer
        sem_wait(&mutex);    // Enter critical section
        buffer[in] = item;   // Insert item into buffer
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE; // Move to the next slot
        sem_post(&mutex);    // Exit critical section
        sem_post(&full);     // Signal that buffer is not empty
        sleep(1);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;
    for (int i = 0; i < MAX_ITEM; i++) {
        sem_wait(&full);     // Wait for buffer to become non-empty
        sem_wait(&mutex);    // Enter critical section
        item = buffer[out];  // Remove item from buffer
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE; // Move to the next slot
        sem_post(&mutex);    // Exit critical section
        sem_post(&empty);    // Signal that buffer is not full
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_threads[NUM_PRODUCERS], consumer_threads[NUM_CONSUMERS];
    
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    for (int i = 0; i < NUM_PRODUCERS; i++) 
        pthread_create(&producer_threads[i], NULL, producer, NULL);

    for (int i = 0; i < NUM_CONSUMERS; i++)
        pthread_create(&consumer_threads[i], NULL, consumer, NULL);
    
    for (int i = 0; i < NUM_PRODUCERS; i++) 
        pthread_join(producer_threads[i], NULL);
    
    for (int i = 0; i < NUM_CONSUMERS; i++) 
        pthread_join(consumer_threads[i], NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}