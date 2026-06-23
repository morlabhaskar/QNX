/*
Parent waits until child process finishes.
Prevents Zombie Processes.
pid_t wait(int *status);
waitpid(child_pid,nullptr,0); //Waits for a specific child.
*/
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        sleep(5);
        std::cout<<"Child Done"<<std::endl;
    }
    else
    {
        std::cout<<"Waiting..."<<std::endl;

        wait(nullptr);

        std::cout<<"Parent Continues"<<std::endl;
    }

    return 0;
}
/*
Waiting...
Child Done
Parent Continues
*/
