/*
Waits until another thread finishes.
Without join, the main thread may exit before the worker thread completes.
int pthread_join(
    pthread_t thread,
    void **retval
);
*/
#include <iostream>
#include <pthread.h>
#include <unistd.h>

void* worker(void*)
{
    sleep(3);

    std::cout << "Thread Finished\n";

    return nullptr;
}

int main()
{
    pthread_t tid;

    pthread_create(&tid,
                   nullptr,
                   worker,
                   nullptr);

    std::cout << "Waiting...\n";

    pthread_join(tid, nullptr);

    std::cout << "Thread Joined\n";
}
/*
Waiting...
Thread Finished
Thread Joined
*/