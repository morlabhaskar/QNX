/*
Terminates the current thread.
Only the calling thread exits.
void pthread_exit(void *retval);
*/
#include <iostream>
#include <pthread.h>

void* worker(void*)
{
    std::cout << "Doing work...\n";

    pthread_exit(nullptr);

    std::cout << "Never Executes\n";// never executes because thread exit
}
//g++ pthread_exit.cpp -pthread
int main()
{
    pthread_t tid;

    pthread_create(&tid,
                   nullptr,
                   worker,
                   nullptr);

    pthread_join(tid,nullptr);
}
/*
Doing work...
*/