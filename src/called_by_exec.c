#include<stdio.h> 
#include<unistd.h> 
#include <stdlib.h>
  
int main() 
{ 
    int i; 
      
    printf("[%d] I was called by exec(3)\n", getpid()); 

    printf("[%d] %s\n", getpid(), getenv("SHELL"));

    sleep(1);

    printf("[%d] called_by_exec ends\n", getpid());
      
    return 0; 
} 
