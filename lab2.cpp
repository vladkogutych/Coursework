#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;

int ret1 = 0;

void* show(void* ptr) {
    printf("Thread #%ld, are in process #%d\n", syscall(__NR_gettid), getpid());
    time_t now = time(0);
    char* date = ctime(&now);
    fprintf((FILE*)ptr, "\ndate #%s", date);
    fprintf((FILE*)ptr, "This is \nThread #%ld, are in process #%d\n", syscall(__NR_gettid), getpid());
    ret1 = ++ret1;
    cout << ret1 << endl;
    pthread_exit(&ret1);

    return NULL;
}
int main() {
    pthread_t inc_x_thread1, inc_x_thread2;
    FILE* file = fopen("lab2.txt", "a");
    fork();
    if (pthread_create(&inc_x_thread1, NULL, show, (void*)file)) { fprintf(stderr, "Error creating thread\n");
    return 1; } 
    sleep(1);
    if (pthread_create(&inc_x_thread2, NULL, show, (void*)file)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    sleep(1);
    if (pthread_join(inc_x_thread1, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    } sleep(1);
    int rc;         rc = setpriority(PRIO_PROCESS, getpid(), 10);
    cout << getpriority(PRIO_PROCESS, getpid()) << endl;
    int priority = getpriority(PRIO_PROCESS, getpid());
    pthread_t thId;
    pthread_attr_t thAttr;
    int policy = 0;
    sched_param param;
    policy = SCHED_OTHER;
    pthread_setschedparam(thId, policy, &param);
    cout << pthread_getschedparam(thId, &policy, &param) << endl;
    close(getpid());
    fclose(file);

}
