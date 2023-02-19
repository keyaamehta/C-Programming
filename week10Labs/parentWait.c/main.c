#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int runChild() 
{ 
 printf("\n I am the child! My pid is %d\n",getpid()); 
 return 0;
}

int main()
{
 if (fork() == 0)
 {
    runChild();
    exit(5);
 } else
 {
    int stat;
    wait(&stat);
    printf("Status %d \n",WEXITSTATUS(stat)); 
 }
    return 0;
}
