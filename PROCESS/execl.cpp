/*
Replaces the current process image with a new program.
Process ID remains the same.
fork() -> creates process
exec() -> loads another application into that process
*/

#include <iostream>
#include <unistd.h>

int main()
{
    std::cout<<"Before exec"<<std::endl;
    execl("/bin/ls","ls","-l",nullptr); //this is executed
    std::cout<<"Never executed"<<std::endl;//this is not executed because above execl is replace this process into ls -l
    return 0;
}

/*
Before exec
total 32
-rwxrwxr-x 1 v25he2m5 v25he2m5 8968 Jun 23 22:19 a.out
-rw-rw-r-- 1 v25he2m5 v25he2m5  231 Jun 23 22:04 exec.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  283 Jun 23 22:15 forkexec.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  414 Jun 23 22:08 pawn.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  461 Jun 23 22:18 process.cpp
-rw-rw-r-- 1 v25he2m5 v25he2m5  325 Jun 23 22:07 thread.cpp
*/


