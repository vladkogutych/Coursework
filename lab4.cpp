#include <stdio.h>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h> const int thread_cnt = 4;
sem_t semph; void *thread_func(void *arg);
int main() {
    sem_init(&semph, 0, 3);
pthread_t t[thread_cnt];
for (int i = 0; i < thread_cnt; ++i) {
    pthread_create(t + i, NULL, thread_func, NULL);
}
for (int i = 0; i < thread_cnt; ++i) { pthread_join(t[i], NULL); }
sem_destroy(&semph);
return 0; }

void* thread_func(void* arg) {
    int val = 0;
    bool is_continue = true;
    while (is_continue) {
        sem_getvalue(&semph, &val);
        if (val > 0) {
            sem_wait(&semph);
            printf("Ready for exec: id = %ld\n", pthread_self() % 100);
            is_continue = false;
            printf("Sleep for 5 sec: id = %ld\n", pthread_self() % 100);
            //std::cout << "Sleep: id = " << id_thread << std::endl;
            sleep(5);
            sem_post(&semph);
        }
        else {
            printf("Wait to exec: sem val = %d id = %ld\n", val,
                pthread_self() % 100);
            sleep(1);
        }
    }
    return NULL;
}
