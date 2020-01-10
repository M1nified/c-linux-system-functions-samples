#include <unistd.h>
#include <stdio.h>

int main(){

    pid_t pid_base_process = getpid();

    printf("[%d] MAIN START\n", getpid());

    char *args[]={"./called_by_exec",NULL}; 
    execvp("./called_by_exec", args);

    printf("[%d] MAIN END\n", getpid()); // Will not be executed

    return 0;
}
