/*
pid_t getpid(void);
getppid()  //Returns Parent PID.
*/
#include <iostream>
#include <unistd.h>

int main()
{
    std::cout<<"PID : "<<getpid()<<std::endl;
}
/*
PID : 1034
*/