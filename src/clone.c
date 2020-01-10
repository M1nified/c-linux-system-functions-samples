#define _GNU_SOURCE  
#include <unistd.h>
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>

int fn(void * arg){
    printf("[%d] I'm a child process.\n", getpid());
    sleep(2);
    printf("[%d] Child process ends.\n", getpid());
    return 0;
}

int main(){

    pid_t pid_base_process = getpid();

    printf("PID OF BASE PROCESS: %d\n", pid_base_process);

    printf("[%d] MAIN START\n", getpid());

    void *pchild_stack = malloc(1024);
    // pid_t pid = clone(&fn, pchild_stack, CLONE_IO | SIGCHLD | CLONE_VM, 0);
    pid_t pid = clone(fn, pchild_stack + 1024, SIGCHLD, 0);

    printf("[%d] pid_base_process = %d\n", getpid(), pid_base_process);

    if(pid < 0){
        printf("[%d] !!!! clone() failed !!!!\n", getpid());
    }

    printf("[%d] [fork()=>%d] I'm a parent process.\n", getpid(), pid);

    // wait(NULL);

    // sleep(1);

    printf("[%d] MAIN END\n", getpid());

    return 0;
}
