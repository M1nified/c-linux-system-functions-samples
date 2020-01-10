#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){

    pid_t pid_base_process = getpid();

    printf("[%d] MAIN START\n", getpid());

    char *args[]={"./called_by_exec",NULL}; 
    
    pid_t pid = fork();

    if(pid == 0){
        execvp("./called_by_exec", args);
    }

    wait(NULL); // on/off

    printf("[%d] MAIN END\n", getpid());

    return 0;
}
