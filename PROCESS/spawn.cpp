/*
Creates a new process and immediately loads a program into it.
Unlike fork(), it does not duplicate the parent process memory.
#include <spawn.h>
prototype:
int spawn(const char *path,int fd_count,const int fd_map[],const struct inheritance *inherit,char * const argv[],char * const envp[]);
Return: on success returns child PID (non-negative). On failure returns -1.
*/

#include<iostream>
#include<spawn.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    char *argv[] = { (char*)"/bin/ls", (char*)"-l", nullptr };
    pid_t cpid = spawn("/bin/ls", 0, nullptr, nullptr, argv, environ);
    if(cpid == -1)
    {
        std::cout<<"Spawn Failed"<<std::endl;
        return -1;
    }
    std::cout<<"Child PID : "<<cpid<<std::endl;
    waitpid(cpid,nullptr,0);
    return 0;
}