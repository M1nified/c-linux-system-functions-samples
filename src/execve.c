#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    pid_t pid_base_process = getpid();

    printf("[%d] MAIN START\n", getpid());

    printf("[%d] %s\n", getpid(), getenv("SHELL"));

    char *args[]={"./called_by_exec", NULL}; 
    char* envp[] = { "SHELL=/bin/tsch", NULL};
    
    pid_t pid = fork();

    if(pid == 0){
        execve("./called_by_exec", args, envp);
    }

    wait(NULL); // on/off

    printf("[%d] %s\n", getpid(), getenv("SHELL"));
    printf("[%d] MAIN END\n", getpid()); // Will not be executed

    return 0;
}
