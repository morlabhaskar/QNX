#include<iostream>
#include<pthread.h>
#include <unistd.h>

void *cameraThread(void *arg)
{
    while(true)
    {
        std::cout<<"Recieved Frame !"<<std::endl;
        sleep(1);
    }
    return nullptr;
}
//g++ thread.cpp -pthread
//./a.out
int main()
{
    pthread_t tid;
    pthread_create(&tid,nullptr,cameraThread,nullptr);
    pthread_join(tid,nullptr);
}
/*
Recieved Frame !
Recieved Frame !
Recieved Frame !
Recieved Frame !
Recieved Frame !
.
.
.

*/
