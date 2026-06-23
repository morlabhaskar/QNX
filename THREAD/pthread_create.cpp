/*
Creates a new thread.
int pthread_create(
    pthread_t *thread,
    const pthread_attr_t *attr,
    void *(*start_routine)(void *),
    void *arg
);
Parameter	    Description
thread	        Stores thread ID
attr	        Thread attributes (usually nullptr)
start_routine	Function executed by thread
arg	            Data passed to thread
*/
#include <iostream>
#include <pthread.h>

void* worker(void* arg)
{
    std::cout << "Worker Thread Running\n";
    return nullptr;
}
//g++ thread_create.cpp -pthread
int main()
{
    pthread_t tid;
    pthread_create(&tid,
                   nullptr,
                   worker,
                   nullptr);

    pthread_join(tid, nullptr);//waiting for thread complete
    return 0;
}
/*
Worker Thread Running
*/