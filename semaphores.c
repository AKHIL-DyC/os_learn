#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_THREADS 2
int counter = 0;
 sem_t semaphore; 
 void* increment_counter(void* arg) {
for (int i = 0; i < 5; i++) {
sem_wait(&semaphore); 
counter++;
printf("Counter value: %d\n", counter);
sem_post(&semaphore);
}
pthread_exit(NULL);
}
int main() {
pthread_t threads[NUM_THREADS]; 
sem_init(&semaphore, 0, 1);
for (int i = 0; i < NUM_THREADS; i++) {
pthread_create(&threads[i], NULL, increment_counter, NULL);
}
for (int i = 0; i < NUM_THREADS; i++) {
pthread_join(threads[i], NULL);
}
sem_destroy(&semaphore);
return 0;


}