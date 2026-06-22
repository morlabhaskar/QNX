/*
Creates an exact copy of the current process.
Parent and Child continue execution from the next line after fork().
*/
#include <iostream>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        std::cout<<"Child Process"<<std::endl;
        std::cout<<"PID : "<<getpid()<<std::endl;
    }
    else if(pid == 1)
    {
        std::cout<<"Parent Process"<<std::endl;
        std::cout<<"Child PID : "<<pid<<std::endl;
    }
    else{
        std::cout<<"Fork is Failed"<<std::endl;
    }
    return 0;
}