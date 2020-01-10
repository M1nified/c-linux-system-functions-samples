#include <unistd.h>
#include <stdio.h>

int main(){

    pid_t pid_base_process = getpid();

    printf("[%d] MAIN START\n", getpid());

    pid_t pid = fork();

    printf("[%d] pid_base_process = %d\n", getpid(), pid_base_process);

    if(pid == 0){
        printf("[%d] [fork()=>%d] I'm a child process.\n", getpid(), pid);
        sleep(5); // child sleeping for extra 5 seconds
    }else{
        printf("[%d] [fork()=>%d] I'm a parent process.\n", getpid(), pid);
    }

    sleep(1);

    printf("[%d] MAIN END\n", getpid());

    return 0;
}
