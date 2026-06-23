/*
Used to protect shared resources.
Without mutexes, multiple threads may corrupt shared data.
int pthread_mutex_lock(  //Locks a mutex.
    pthread_mutex_t *mutex
);
int pthread_mutex_unlock(  //Releases a mutex.
    pthread_mutex_t *mutex
);
*/
#include <iostream>
#include <pthread.h>

int counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* worker(void*)
{
    for(int i=0;i<100;i++)
    {
        pthread_mutex_lock(&mutex);

        counter++;

        pthread_mutex_unlock(&mutex);
    }

    return nullptr;
}
//g++ pthread_mutex_lock.cpp -pthread
int main()
{
    pthread_t t1,t2;

    pthread_create(&t1,nullptr,worker,nullptr);
    pthread_create(&t2,nullptr,worker,nullptr);

    pthread_join(t1,nullptr);
    pthread_join(t2,nullptr);

    std::cout << counter << std::endl;
}
/*
200
*/