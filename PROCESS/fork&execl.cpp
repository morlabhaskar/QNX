#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        execl("/bin/ls","ls","-l",nullptr);
    }
    else
    {
        wait(nullptr);
        std::cout<<"Child Finished"<<std::endl;
    }

    return 0;
}

/*
total 32
-rwxrwxr-x 1 v25he2m5 v25he2m5 9056 Jun 23 22:15 a.out
-rw-rw-r-- 1 v25he2m5 v25he2m5  231 Jun 23 22:04 exec.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  283 Jun 23 22:15 forkexec.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  414 Jun 23 22:08 pawn.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  538 Jun 23 22:09 process.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  325 Jun 23 22:07 thread.cpp
Child Finished
*/