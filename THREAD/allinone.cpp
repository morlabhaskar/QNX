#include <iostream>
#include <pthread.h>
#include <unistd.h>

int frameCount = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* cameraThread(void*)
{
    for(int i=0;i<5;i++)
    {
        pthread_mutex_lock(&mutex);

        frameCount++;

        std::cout
            << "Captured Frame "
            << frameCount
            << std::endl;

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(nullptr);
}

int main()
{
    pthread_t tid;

    pthread_create(&tid,
                   nullptr,
                   cameraThread,
                   nullptr);

    pthread_join(tid,nullptr);

    std::cout
        << "Total Frames = "
        << frameCount
        << std::endl;

    return 0;
}

/*
Captured Frame 1
Captured Frame 2
Captured Frame 3
Captured Frame 4
Captured Frame 5
Total Frames = 5
*/