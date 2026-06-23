/*
Sends signal to another process.
Can terminate, pause, continue, or notify processes.
int kill(pid_t pid, int sig);

Signal	   Purpose
SIGTERM	   Graceful termination
SIGKILL	   Force kill
SIGSTOP	   Pause
SIGCONT	   Resume
SIGUSR1	   User-defined
SIGUSR2	   User-defined
*/

#include <iostream>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();

    std::cout<<"PID : "<<pid<<std::endl;

    sleep(5);

    kill(pid,SIGTERM);

    return 0;
}
/*
PID : 12752
Terminated
*/